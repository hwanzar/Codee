#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class AVL {
public:
    class Node {
        public:
            int data;
            int key;
            Node *left, *right;
            int balance_factor;
        public:
            Node(int data = 0, int key = 0, Node *left = NULL, Node *right = NULL, int balance_factor = 0){
                this->data = data;
                this->key = key;
                this->left = left;
                this->right = right;
                this->balance_factor = balance_factor;
            }
    };
public:
    class Node;


};


int main() {
    outtext;
    _io;

    return 0;
}