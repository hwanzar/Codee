#include "main.h"
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

/* DATA STRUCTURE */
// cần sửa huffman, đang sort theo thứ tự chư cái và tần số.
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
	string HuffmanTree(string inp)
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
			pq.push(getNode('-', sum, left, right));
		}

		Node *root = pq.top();

		unordered_map<char, string> huffmanCode;
		encode(root, "", huffmanCode);

		cout << "Encoded\n";
		for (auto pair : huffmanCode)
		{
			cout << pair.first << ": " << pair.second << '\n';
		}
		string result = "";
		for (auto ch : inp)
		{
			result += huffmanCode[ch];
		}
		return result;
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

class AVL
{
public:
};

/*=== REG Command ===*/
// helper function
string getCommand(string input)
{
	int pos = input.find(" ");
	string command = input.substr(0, pos);
	return command;
}

int BinToDec(string binary)
{
	long long decimal = 0;
	for (int i = 0; i < binary.length(); i++)
	{
		if (binary[i] == '1')
		{
			decimal += (int)pow(2, binary.length() - 1 - i);
		}
	}
	cout << "Convert to number" << decimal << endl;
	return decimal;
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

// 3. Chọn bàn
int getID(int res)
{
	int id = res % MAXSIZE;
}

void reg(string input)
{
	// cout << getCommand(input) << endl;
	// cout << getName(input) << endl;
	HuffmanCoding *huffman;
	string name = getName(input);
	string modifiedName = huffman->HuffmanTree(name);
	string newName = modifiedName.substr(modifiedName.length() - 15);
	cout
		<< "The Huffman number is\n"
		<< newName << endl;

	int Result = BinToDec(newName);

	return;
}
/*=== END REG Command ===*/

/*=== START CLE Command ===*/
// helper function

// main function
void cle(string inp)
{
	cout << "Command written" << endl;
}

/*=== END CLE Command ===*/

/*=== START printHT Command ===*/
// helper function

// main function
void printHT(string inp)
{
	cout << "Command Print Hash Table written" << endl;
	return;
}

/*=== END printHT Command ===*/

/*=== START printAVL Command ===*/
// helper function

// main function
void printAVL(string inp)
{
	cout << "Command Print AVL tree written" << endl;
	return;
}

/*=== END printAVL Command ===*/
//
//
//
/*=== START printMH Command ===*/
// helper function

// main function
void printMH(string inp)
{
	cout << "Command Print Min Heap written" << endl;
	return;
}

/*=== END printMH Command ===*/
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
			string command = getCommand(line);
			if (command == "REG")
			{
				reg(line);
			}
			if (command == "CLE")
			{
				cle(line);
			}
			if (command == "PrintHT")
			{
				printHT(line);
			}
			if (command == "PrintAVL")
			{
				printAVL(line);
			}
			if (command == "PrintMH")
			{
				printMH(line);
			}
		}

		file.close();
	}
	else
		cout << "Not found FILE" << endl;
	return;
}