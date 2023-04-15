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
	struct comparator;

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
		// build huffman tree
		//  inp is the input, so called plain text.
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
		priority_queue<Node *, vector<Node *>, comparator> pq_cpy;
		pq_cpy = pq;
		cout << "Debug the priority queue:x " << endl;
		while (!pq_cpy.empty())
		{
			cout << pq_cpy.top()->ch << ": " << pq_cpy.top()->freq << "\n";
			pq_cpy.pop();
		}
		while (pq.size() != 1)
		{
			Node *left = pq.top();
			pq.pop();
			Node *right = pq.top();
			pq.pop();

			int sum = left->freq + right->freq;
			pq.push(getNode('~', sum, left, right));
		}

		Node *root = pq.top();

		unordered_map<char, string> huffmanCode;
		encode(root, "", huffmanCode);

		cout << "Encoded------------------\n";
		for (auto pair : huffmanCode)
		{
			cout << pair.first << ": " << pair.second << '\n';
		}
	}

	void encode(Node *root, string str, unordered_map<char, string> &HuffmanCode)
	{
		if (root == nullptr)
			return;

		if (!root->left && !root->right)
			HuffmanCode[root->ch] = str;

		encode(root->left, str + "0", HuffmanCode);
		encode(root->right, str + "1", HuffmanCode);
	}
	void decode(Node *root, int &index, string str)
	{
		if (root == nullptr)
		{
			return;
		}

		// found a leaf node
		if (!root->left && !root->right)
		{
			cout << root->ch;
			return;
		}

		index++;

		if (str[index] == '0')
			decode(root->left, index, str);
		else
			decode(root->right, index, str);
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
	struct comparator
	{
		bool operator()(Node *left, Node *right)
		{
			if (left->freq == right->freq)
			{
				return left->ch >= right->ch;
			}
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
	HuffmanCoding *huffman;
	string name = getName(input);
	huffman->HuffmanTree(name);
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