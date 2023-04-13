#include <iostream>
#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>

using namespace std;

// Huffman tree node
struct Node
{
    char data;          // character
    int freq;           // frequency
    Node *left, *right; // left and right child nodes

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

bool comparator(const pair<char, int> &a, const pair<char, int> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
// compare function for priority queue
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

// traverse the Huffman tree and assign bit strings to each character
void encode(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCode[root->data] = code;
    }
    encode(root->left, code + "0", huffmanCode);
    encode(root->right, code + "1", huffmanCode);
}

// encode the original string using the Huffman codes
string encodeString(string s, unordered_map<char, string> &huffmanCode)
{
    string encoded;
    for (char c : s)
    {
        encoded += huffmanCode[c];
    }
    return encoded;
}

// decode the encoded string using the Huffman tree
string decodeString(Node *root, string encoded)
{
    string decoded;
    Node *curr = root;
    for (char c : encoded)
    {
        if (c == '0')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
        if (curr->left == nullptr && curr->right == nullptr)
        {
            decoded += curr->data;
            curr = root;
        }
    }
    return decoded;
}

int main()
{
    string s = "Johnuigfifbahjasbdfhjbasdhjf";
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    vector<pair<char, int>> Freq(freq.begin(), freq.end());

    sort(Freq.begin(), Freq.end(), comparator);
    cout << "FREQ" << endl;
    for (auto it = Freq.begin(); it != Freq.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    // create leaf nodes for each character
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (auto it = Freq.begin(); it != Freq.end(); it++)
    {
        pq.push(new Node(it->first, it->second));
    }

    // build Huffman tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // get Huffman codes for each character
    unordered_map<char, string> huffmanCode;
    encode(pq.top(), "", huffmanCode);

    // print Huffman codes
    cout << "Huffman Codes:\n";
    for (auto it = huffmanCode.begin(); it != huffmanCode.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    // encode the original string using the Huffman codes
    string encoded = encodeString(s, huffmanCode);
    cout << "Encoded String: " << encoded << endl;

    // decode the encoded string using the Huffman tree
    string decoded = decodeString(pq.top(), encoded);
    cout << "Decoded String: " << decoded << endl;

    // free memory
    delete pq.top();

    return 0;
}