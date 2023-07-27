#include <iostream>
#include <string>
#include <queue>
using namespace std;

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
        ~Node()
        {
            pLeft = nullptr;
            pRight = nullptr;
        }
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node *walker = this->root;
        int l = posFromRoot.length();
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
    void BFS()
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *u = q.front();
            cout << u->value << " ";
            q.pop();

            if (u->pLeft)
            {
                q.push(u->pLeft);
            }
            if (u->pRight)
            {
                q.push(u->pRight);
            }
        }
    }
    int count2ChildrenNode(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->pLeft != nullptr && root->pRight != nullptr)
            return 1 + count2ChildrenNode(root->pLeft) + count2ChildrenNode(root->pRight);
        return count2ChildrenNode(root->pLeft) + count2ChildrenNode(root->pRight);
    }
    int countTwoChildrenNode()
    {
        return count2ChildrenNode(root);
    }
    int GetHeight(Node *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(GetHeight(root->pLeft), GetHeight(root->pRight));
    }
    int getHeight()
    {
        return GetHeight(root);
    }
    string PreOrder(Node *root)
    {
        if (root == nullptr)
            return "";
        string ans = "";
        ans += to_string(root->value) + " ";
        ans += PreOrder(root->pLeft);
        ans += PreOrder(root->pRight);
        return ans;
    }
    string preOrder()
    {
        return PreOrder(root);
    }
    string InOrder(Node *root)
    {
        if (root == nullptr)
            return "";
        string ans = "";
        ans += InOrder(root->pLeft);
        ans += to_string(root->value) + " ";
        ans += InOrder(root->pRight);
        return ans;
    }
    string inOrder()
    {
        return InOrder(root);
    }
    string PostOrder(Node *root)
    {
        if (root == nullptr)
            return "";
        string ans = "";
        ans += PostOrder(root->pLeft);
        ans += PostOrder(root->pRight);
        ans += to_string(root->value) + " ";
        return ans;
    }
    string postOrder()
    {
        return PostOrder(root);
    }
    int leafSum(Node *root)
    {
        // if leaf node so it plsyu sum
        if (root == nullptr)
            return 0;
        if (root->pLeft == nullptr && root->pRight == nullptr)
        {
            return root->value;
        }
        return leafSum(root->pLeft) + leafSum(root->pRight);
    }
    int sumOfLeafs()
    {
        return leafSum(root);
    }
};
int main()
{
    // BinaryTree<int, int> binaryTree;
    // binaryTree.addNode("", 2, 4);  // Add to root
    // binaryTree.addNode("L", 3, 6); // Add to root's left node
    // binaryTree.addNode("R", 5, 9); // Add to root's right node
    // binaryTree.BFS();
    // BinaryTree<int, int> binaryTree;
    // binaryTree.addNode("", 2, 4);  // Add to root
    // binaryTree.addNode("L", 3, 6); // Add to root's left node
    // binaryTree.addNode("R", 5, 9); // Add to root's right node

    // cout << binaryTree.getHeight() << endl;
    // cout << binaryTree.preOrder() << endl;
    // cout << binaryTree.inOrder() << endl;
    // cout << binaryTree.postOrder() << endl;

    cout << endl;
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);
    binaryTree.addNode("L", 3, 6);
    binaryTree.addNode("R", 5, 9);
    cout << binaryTree.sumOfLeafs();
}
