#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template <class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node *walker = this->root;
        int l = (int)posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }

    int getHeight(Node *root)
    {
        if (!root)
            return 0;
        return 1 + max(getHeight(root->pLeft), getHeight(root->pRight));
    }
    // Helping functions
    int getDiameter()
    {
        // TODO
        if (root == NULL)
            return 0;
        return 1 + getHeight(root->pLeft) + getHeight(root->pRight);
    }
    // 2
    void BFS()
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *tmp = q.front();
            q.pop();
            cout << tmp->value << " ";
            if (tmp->pLeft != nullptr)
                q.push(tmp->pLeft);
            if (tmp->pRight != nullptr)
                q.push(tmp->pRight);
        }
    }
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.

    int getHeight()
    {
        // TODO: return height of the binary tree.
        if (!this->root)
            return 0;
        return 1 + max(getHeight(this->root->pLeft), getHeight(this->root->pRight));
    }

    string preOrder()
    {
        // TODO: return the sequence of values of nodes in pre-order.
        if (!this->root)
            return "";
        string res = to_string(this->root->value) + " ";
        res += preOrder(this->root->pLeft);
        res += preOrder(this->root->pRight);
        return res;
    }

    string inOrder()
    {
        // TODO: return the sequence of values of nodes in in-order.
        if (!root)
            return "";
        string res = inOrder(root->pLeft);
        res += to_string(root->value) + " ";
        res += inOrder(root->pRight);
        return res;
    }

    string postOrder()
    {
        // TODO: return the sequence of values of nodes in post-order.
        if (!root)
            return "";
        string res = postOrder(root->pLeft);
        res += postOrder(root->pRight);
        res += postOrder(root->value) + " ";
        return res;
    }

    // STUDENT ANSWER END
};

int main()
{
    // get diameter
    // BinaryTree<int, int> binaryTree;
    // binaryTree.addNode("", 1, 4);
    // binaryTree.addNode("L", 2, 6);
    // binaryTree.addNode("R", 3, 9);
    // binaryTree.addNode("LL", 4, 10);
    // cout << binaryTree.getDiameter();
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);  // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
}
