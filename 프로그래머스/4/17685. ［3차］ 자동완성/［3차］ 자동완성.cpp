#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
	unordered_map<char, TrieNode*> children;
	bool sameLetter;

	TrieNode() : sameLetter(false) {};
};

class Trie
{
public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(const string& word)
	{
		TrieNode* current = root;
		for (char ch : word)
		{
			if (current->children.find(ch) == current->children.end())
			{
				current->children[ch] = new TrieNode();
			}
			else
			{
				current->children[ch]->sameLetter = true;
			}
			current = current->children[ch];
		}
	}

	int search(const string& prefix)
	{
		TrieNode* current = root;
		int count{};
		for (const auto& ch : prefix)
		{
			++count;
			current = current->children[ch];
			if (!current->sameLetter)
			{
				return count;
			}
		}
		return count;
	}

private:
	TrieNode* root;
};

int solution(vector<string> words) 
{
	int answer = 0;
	Trie trie;
	
	for (auto& str : words)
	{
		trie.insert(str);
	}

	for (auto& str : words)
	{
		answer += trie.search(str);
	}

	return answer;
}

