#include "main.h"
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class HuffmanCoding
{
public:
	class Node;
	class comparator;

	Node *getNode(char ch, int freq, Node *left, Node *right)
	{
		Node *node = new Node();

		node->ch = ch;
		node->freq = freq;
		node->left = left;
		node->right = right;

		return node;
	}

	void HuffmanTree(string inp)
	{
		// inp is the input, so called plain text.
		unordered_map<char, int> freq;
		for (char ch : inp)
		{
			freq[ch] += 1;
		}
		// initialize priority queue, start building Huffman tree from this.
		priority_queue<Node *, vector<Node *>, comparator> pq;

		for (auto item : freq)
		{
			pq.push(getNode(item.first, item.second, nullptr, nullptr));
		}
		// cout << "Debug the priority queue: " << endl;
		// while (!pq.empty())
		// {
		// 	cout << pq.top()->ch << ": " << pq.top()->freq << "\n";
		// 	pq.pop();
		// }

	}

	void encode(Node *root, string str, unordered_map<char, string> &HuffmanCode)
	{
		if (root = nullptr)
			return;

		if (!root->left && !root->right)
			HuffmanCode[root->ch] = str;

		encode(root->left, str + "0", HuffmanCode);
		encode(root->right, str + "1", HuffmanCode);
	}

public:
	class Node
	{
	public:
		char ch;
		int freq;
		Node *left, *right;

	public:
		Node()
		{
			this->ch = ch;
			this->freq = freq;
		}
	};
	class comparator
	{
		bool operator()(Node *left, Node *right)
		{
			return left->freq > right->freq;
		}
	};
};

string getCommand(string input)
{
	int pos = input.find(" ");
	string command = input.substr(0, pos);
	return command;
}

string getName(string input)
{
	string lastWord;
	size_t pos = input.find_last_of(' ');
	if (pos != string::npos)
	{
		lastWord = input.substr(pos + 1);
	}
	else
	{
		lastWord = input;
	}
	return lastWord;
}

void reg(string input)
{
	// cout << getCommand(input) << endl;
	// cout << getName(input) << endl;

	return;
}

void simulate(string filename)
{
	_io;
	outtext; // this line for output in another file
	ifstream file(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			if (getCommand(line) == "REG")
			{
				reg(line);
			}
		}

		file.close();
	}
	else
		cout << "Not found FILE" << endl;

	return;
}