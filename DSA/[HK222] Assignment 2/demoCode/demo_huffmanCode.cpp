#include <iostream>
#include <string>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class HuffmanCoding
{
public:
    class Node;
    struct comparator;
    Node *root;

public:
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

        priority_queue<pair<Node *, int>, vector<pair<Node *, int>>, comparator> pq;

        for (auto item : freq)
        {
            pair<Node *, int> node;
            node.first = getNode(item.first, item.second, nullptr, nullptr);
            node.second = 0;
            pq.push(node);
        }
        // debugPQ(pq);
        int order = 0;
        while (pq.size() != 1)
        {
            Node *left = pq.top().first;
            pq.pop();
            Node *right = pq.top().first;
            pq.pop();
            // cout << left->ch << right->ch << endl;
            int sum = left->freq + right->freq;
            pq.push(make_pair(getNode('~', sum, left, right), ++order));

            // debugPQ(pq);
        }

        Node *root = pq.top().first;
        unordered_map<char, string> huffmanCode;
        if (freq.size() == 1)
        {
            for (auto item : freq)
            {
                huffmanCode[item.first] = "1";
            }
        }
        else
        {
            encode(root, "", huffmanCode);
        }

        // cout << "Encoded\n";
        // for (auto pair : huffmanCode)
        // {
        // 	cout << pair.first << ": " << pair.second << '\n';
        // }
        string result = "";
        for (auto ch : inp)
        {
            result += huffmanCode[ch];
        }

        delete root;
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
    void clear(Node *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    // void debugPQ(
    // 	priority_queue<Node *, vector<Node *>, comparator> gq)
    // {
    // 	priority_queue<Node *, vector<Node *>, comparator> g = gq;

    // 	while (!g.empty())
    // 	{
    // 		cout << ' ' << g.top()->freq << "" << g.top()->ch;
    // 		if (g.top()->left != NULL)
    // 		{
    // 			cout << g.top()->left->ch;
    // 		}
    // 		if (g.top()->right != NULL)
    // 		{
    // 			cout << g.top()->right->ch;
    // 		}
    // 		g.pop();
    // 	}
    // 	cout << '\n';
    // }

public:
    class Node
    {
    public:
        char ch;
        int freq;
        Node *left, *right;

    public:
        // Node()
        // {
        //     this->ch = ch;
        //     this->freq = freq;
        // }
        Node(char c = '\0', int f = 0, Node *l = nullptr, Node *r = nullptr)
            : ch(c), freq(f), left(l), right(r)
        {
        }
        ~Node()
        {
            delete left;
            delete right;
        }
        bool isLeaf()
        {
            return (left == NULL && right == NULL);
        }
    };
    struct comparator
    {
        bool operator()(pair<Node *, int> a, pair<Node *, int> b)
        {
            if (a.first->freq == b.first->freq)
            {
                if (a.first->ch == b.first->ch)
                    return a.second > b.second;
                return a.first->ch > b.first->ch;
            }
            return a.first->freq > b.first->freq;
        }
    };
};
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
    return decimal;
}
#define outtext freopen("output.txt", "w", stdout)
// Huffman coding algorithm
int main()
{
    outtext;
    HuffmanCoding huffman;
    string text = "Johnuigfifbahjasbdfhjbasdhjf";
    string text1 = "aaaaaaaaaa";
    string huffman1 = huffman.HuffmanTree(text);
    cout << huffman1 << endl;
    string newName = huffman1;
    newName = newName.substr(newName.length() - 15, newName.length());
    cout << newName << endl;
    int ans = BinToDec(newName);
    cout << ans << endl;
    huffman.clear(huffman.root);
    return 0;
}