#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// A Tree node
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
        // debugPQ(pq);
        while (pq.size() != 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            // cout << left->ch << right->ch << endl;
            int sum = left->freq + right->freq;
            pq.push(getNode('~', sum, left, right));
            // debugPQ(pq);
        }

        Node *root = pq.top();

        unordered_map<char, string> huffmanCode;
        encode(root, "", huffmanCode);

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
    void debugPQ(
        priority_queue<Node *, vector<Node *>, comparator> gq)
    {
        priority_queue<Node *, vector<Node *>, comparator> g = gq;

        while (!g.empty())
        {
            cout << ' ' << g.top()->freq << "" << g.top()->ch;
            if (g.top()->left != NULL)
            {
                cout << g.top()->left->ch;
            }
            if (g.top()->right != NULL)
            {
                cout << g.top()->right->ch;
            }
            g.pop();
        }
        cout << '\n';
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
        bool isLeaf()
        {
            return (left == NULL && right == NULL);
        }
    };
    struct comparator
    {
        bool operator()(Node *a, Node *b)
        {
            if (a->freq == b->freq)
            {
                if (a->ch == b->ch)
                    return a > b;
                return a->ch > b->ch;
            }
            return a->freq > b->freq;
        }
    };
};
#define outtext freopen("output.txt", "w", stdout)
// Huffman coding algorithm
int main()
{
    outtext;
    HuffmanCoding huffman;
    string text = "Johnuigfifbahjasbdfhjbasdhjf";
    string text1 = "iuasgfuigweibjaskdfbjksadf";
    string huffman1 = huffman.HuffmanTree(text);
    cout << huffman1 << endl;
    string huffman2 = huffman.HuffmanTree(text1);
    cout << huffman2 << endl;

    return 0;
}