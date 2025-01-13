#include <string>
#include <vector>
#include <iostream>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n) : group(n), data(n)
    {
        for (int i = 0; i < n; ++i)
        {
            group[i] = i;
        }
    }

    int Find(int p)
    {
        if (p != group[p])
        {
            group[p] = Find(group[p]);
        }

        return group[p];
    }

    void Union(int p, int q)
    {
        int pid = Find(p);
        int qid = Find(q);

        if (pid == qid)
        {
            return;
        }

        if (data[pid].empty())
        {
            group[pid] = qid;
        }
        else if (data[qid].empty())
        {
            group[qid] = pid;
        }
        else
        {
            group[qid] = pid;
        }
        
        for (int i = 0; i < group.size(); ++i)
        {
            Find(i);
        }
    }

    void Update1(int r, int c, const string& value)
    {
        int idx = Find(r * 50 + c);
        data[idx] = value;
    }

    void Update2(string value1, const string& value2)
    {
        for (int i = 0; i < data.size(); ++i)
        {
            if (Find(i) == i && data[i] == value1)
            {
                data[i] = value2;
            }
        }
    }

    void UnMerge(int r, int c)
    {
        int idx = Find(r * 50 + c);
        string value = data[idx];

        for (int i = 0; i < group.size(); ++i)
        {
            if (Find(i) == idx)
            {
                group[i] = i;
                data[i] = "";
            }
        }

        data[Find(r * 50 + c)] = value;
    }

    string Print(int r, int c)
    {
        int idx = Find(r * 50 + c);
        return data[idx].empty() ? "EMPTY" : data[idx];
    }

private:
    vector<int> group;
    vector<string> data;
};

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    UnionFind uf(2500);

    for (auto& command : commands)
    {
        vector<string> parts;
        string current;

        for (char ch : command)
        {
            if (ch == ' ')
            {
                if (!current.empty())
                {
                    parts.push_back(current);
                    current.clear();
                }
            }
            else
            {
                current += ch;
            }
        }

        if (!current.empty())
        {
            parts.push_back(current);
        }

        const string& order = parts[0];

        if (order == "UPDATE")
        {
            if (parts.size() > 3)
            {
                int row = stoi(parts[1]) - 1;
                int col = stoi(parts[2]) - 1;
                const string& value = parts[3];
                uf.Update1(row, col, value);
            }
            else
            {
                const string& value1 = parts[1];
                const string& value2 = parts[2];
                uf.Update2(value1, value2);
            }
        }
        else if (order == "MERGE")
        {
            int r1 = stoi(parts[1]) - 1;
            int c1 = stoi(parts[2]) - 1;
            int r2 = stoi(parts[3]) - 1;
            int c2 = stoi(parts[4]) - 1;
            int pid = r1 * 50 + c1;
            int qid = r2 * 50 + c2;
            uf.Union(pid, qid);
        }
        else if (order == "UNMERGE")
        {
            int row = stoi(parts[1]) - 1;
            int col = stoi(parts[2]) - 1;
            uf.UnMerge(row, col);
        }
        else if (order == "PRINT")
        {
            int row = stoi(parts[1]) - 1;
            int col = stoi(parts[2]) - 1;
            string result = uf.Print(row, col);
            answer.push_back(result);
        }
    }

    return answer;
}
