#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class TreeNode 
{
public:
	TreeNode(int val, int x, TreeNode* left, TreeNode* right) : val(val),  indexX(x), left(left), right(right) {}
    
public:
    bool visited = false;
	int val;
    int indexX;
	TreeNode* right;
	TreeNode* left;
};

void InsertNode(TreeNode* current, TreeNode* node)
{
	if (current->indexX < node->indexX)
	{
		if (!current->right)
		{
			current->right = node;
		}
		else
		{
			InsertNode(current->right, node);
		}
	}
	else
	{
		if (!current->left)
		{
			current->left = node;
		}
		else
		{
			InsertNode(current->left, node);
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	int n = nodeinfo.size();
	for (int i = 0; i < n; ++i)
	{
		nodeinfo[i].push_back(i + 1);
	}

	sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> a, vector<int> b) {
		if (a[1] != b[1])
		{
			return a[1] > b[1];
		}
		
		return a[0] < b[0];
	});

	TreeNode* root = new TreeNode(nodeinfo[0][2], nodeinfo[0][0], nullptr, nullptr);
	TreeNode* current = root;
	for (int i = 1; i < n; ++i)
	{
		TreeNode* node = new TreeNode(nodeinfo[i][2], nodeinfo[i][0], nullptr, nullptr);
		InsertNode(current, node);
	}

	answer.resize(2);
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* node = s.top();
		s.pop();

		answer[0].push_back(node->val);
		if (node->right)
		{
			s.push(node->right);
		}
		if (node->left)
		{
			s.push(node->left);
		}
	}

	s.push(root);
	while (!s.empty())
	{
		TreeNode* node = s.top();
		if (node->left && !node->left->visited)
		{
			s.push(node->left);
		}
		else
		{
			if (node->right && !node->right->visited)
			{
				s.push(node->right);
			}
			else
			{
				node->visited = true;
				answer[1].push_back(node->val);
				s.pop();
			}
		}
	}

	return answer;
}