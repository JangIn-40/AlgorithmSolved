#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class TreeNode
{
public:
    char val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* MakeTree(string& binaryNumber, int left, int right)
{
    if(left > right)
    {
        return nullptr;
    }
    
    int mid = (left + right) / 2;

    TreeNode* node = new TreeNode(binaryNumber[mid]);

    node->left = MakeTree(binaryNumber, left, mid - 1);
    node->right = MakeTree(binaryNumber, mid + 1, right);

    return node;
    
}

bool CheckExpressBinaryTree(TreeNode* node, bool rootNodeIsZero)
{
    if (!node)
    {
        return true;
    }

    if (rootNodeIsZero && node->val == '1')
    {
        return false;
    }

    bool nodeIsZero = node->val == '0';
    return CheckExpressBinaryTree(node->left, nodeIsZero) && CheckExpressBinaryTree(node->right, nodeIsZero);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (auto& l : numbers)
    {
        string binaryNumber;
        while (l)
        {
            binaryNumber = char(l % 2 + '0') + binaryNumber;
            l /= 2;
        }

        int count{ 1 };
        int nodeSize = pow(2, count) - 1;
        while (binaryNumber.size() > nodeSize)
        {
            ++count;
            nodeSize = pow(2, count) - 1;
        }

        binaryNumber.insert(0, nodeSize - binaryNumber.size(), '0');

        if (binaryNumber.size() == 1)
        {
            if (binaryNumber[0] == '0')
            {
                answer.push_back(0);
            }
            else
            {
                answer.push_back(1);
            }
            continue;
        }

        TreeNode* root = MakeTree(binaryNumber, 0, binaryNumber.size() - 1);
        if (root->val == 0)
        {
            answer.push_back(0);
            continue;
        }

        if (CheckExpressBinaryTree(root, false))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }

    return answer;
}