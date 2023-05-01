#include "main.h"

class table
{
public:
    int id;
    string name;
    int result;
    int dish;
    int recentOrder;
    int typeArea;
    table(int id = 0, string name = "", int result = 0, int dish = 0, int recentOrder = 0, int typeArea = 0)
    {
        this->id = id;
        this->name = name;
        this->result = result;
        this->dish = dish;
        this->recentOrder = recentOrder;
        this->typeArea = typeArea;
    }
    bool operator==(const table &other) const
    {
        return id == other.id && name == other.name && result == other.result && dish == other.dish && recentOrder == other.recentOrder && typeArea == other.typeArea;
    }
};

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

        while (!pq.empty())
        {
            delete pq.top().first;
            pq.pop();
        }
        // delete root;
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
class HashTable
{
public:
    map<int, table> hashTable;
    int tableCnt;
    HashTable()
    {
        for (int i = 0; i < MAXSIZE / 2; i++)
        {
            hashTable[i] = table(0, "", 0, 0, 0, 0);
        }
        tableCnt = 0;
    }
    int hashFx(int res)
    {
        return res % (MAXSIZE / 2);
    }

public:
    void insert(int key, table tb)
    {
        int newkey = hashFx(key);
        while (hashTable[newkey].name != "")
        {
            if (newkey == MAXSIZE / 2 - 1)
            {
                newkey = 0;
            }
            else
            {
                newkey++;
            }
        }
        hashTable[newkey] = tb;
        tableCnt++;
    }
    void remove(int id)
    {
        // int key = hashFx(id);
        int key = 0;

        while (hashTable[key].id != id)
        {
            key++;
        }
        if (key >= MAXSIZE / 2)
        {
            return;
        }
        hashTable[key] = table(0, "", 0, 0, 0, 0);
        tableCnt--;
    }

    void displayDebug()
    {
        cout << "==== AREA 1 - HASH TABLE ====\n";
        for (auto pair : hashTable)
        {
            cout << pair.first << " " << pair.second.id << ": " << pair.second.result << endl;
        }
        cout << "=============================\n";
    }
    void display()
    {
        for (int i = 0; i < hashTable.size(); i++)
        {
            if (hashTable[i].name != "")
            {
                cout << hashTable[i].id << "-" << hashTable[i].result << "-" << hashTable[i].dish << "\n";
            }
        }
    }
    bool isFull()
    {
        if (tableCnt == MAXSIZE / 2)
            return true;
        return false;
    }
    bool containsID(int ID)
    {
        if (ID < 0 || ID > MAXSIZE)
            return false;
        for (int key = 0; key < MAXSIZE / 2; key++)
        {

            if (hashTable[key].id == ID)
            {
                return true;
            }
        }
        return false;
    }
    void AddDish(string name)
    {
        for (int i = 0; i < MAXSIZE / 2; i++)
        {
            if (hashTable[i].name == name)
            {
                hashTable[i].dish++;
                return;
            }
        }
        return;
    }
    void changeInfo(table &oldTable, table &newTable)
    {
        for (int i = 0; i < MAXSIZE / 2; i++)
        {
            if (hashTable[i].name == oldTable.name)
            {
                hashTable[i] = newTable;
                return;
            }
        }
    }
};

class AVL
{
public:
    class Node; // contain key == Result, ID ==

public:
    Node *root;
    int cnt;

public:
    AVL()
    {
        root = nullptr;
        cnt = 0;
    }
    // ~AVL()
    // {
    //     while (root != nullptr)
    //     {
    //         deleteAVLTree(root->key);
    //     }
    // }

public:
    int height(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = 1 + height(root->left), rightHeight = 1 + height(root->right);
        return max(leftHeight, rightHeight);
    }
    int getBalanceFactor(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }
        return height(x->left) - height(x->right);
    }
    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        y->bal_factor = getBalanceFactor(y);
        x->bal_factor = getBalanceFactor(x);
        return y;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        y->bal_factor = getBalanceFactor(y);
        x->bal_factor = getBalanceFactor(x);
        return y;
    }
    Node *LeftRightRotate(Node *x)
    {
        x->left = leftRotate(x->left);
        return rightRotate(x);
    }
    Node *RightLeftRotate(Node *x)
    {
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }
    Node *balanced(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        root->bal_factor = getBalanceFactor(root);
        if (root->bal_factor > 1)
        {
            if (getBalanceFactor(root->left) >= 0)
            {
                root = rightRotate(root);
            }
            else
            {
                root = LeftRightRotate(root);
            }
        }
        else if (root->bal_factor < -1)
        {
            if (getBalanceFactor(root->right) > 0)
            {
                root = RightLeftRotate(root);
            }
            else
            {
                root = leftRotate(root);
            }
        }
        return root;
    }
    Node *addAVL(Node *root, int key, table tb)
    {
        if (root == nullptr)
        {
            root = new Node(key, tb);
            cnt++;
        }
        else
        {
            if (key < root->key)
            {
                root->left = addAVL(root->left, key, tb);
            }
            else
            {
                root->right = addAVL(root->right, key, tb);
            }
            root = balanced(root);
        }
        return root;
    }
    Node *findMaxValue(Node *x)
    {
        Node *temp = x;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp;
    }
    Node *findMinValueRight(Node *x)
    {
        Node *temp = x;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *deleteAVL(Node *root, int key, string name)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key <= root->key && name != root->tb.name)
        {
            root->left = deleteAVL(root->left, key, name);
        }
        if (key >= root->key && name != root->tb.name)
        {
            root->right = deleteAVL(root->right, key, name);
        }
        if (key == root->key && name == root->tb.name)
        {
            if (root->left == nullptr || root->right == nullptr)
            {
                Node *temp = (root->left == nullptr ? root->right : root->left);
                if (temp == nullptr)
                {
                    temp = root;
                    delete temp;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                    delete temp;
                    temp = nullptr;
                }
                cnt--;
            }
            else
            {
                Node *temp = root->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                // cout << root->key << endl;
                // cout << temp->key << endl;
                root->key = temp->key;
                root->tb = temp->tb;

                root->right = deleteAVL(root->right, temp->key, temp->tb.name);
            }
        }
        return balanced(root);
    }

    void addDish(Node *&cur, int key, string name)
    {
        if (cur == nullptr)
            return;
        if (cur->tb.name == name)
        {
            cur->tb.dish++;
            return;
        }
        addDish(cur->left, key, name);
        addDish(cur->right, key, name);
    }
    void AddDish(int key, string name)
    {
        addDish(this->root, key, name);
    }

    void changeInfo(table &oldTable, table &newTable)
    {
        if (!contains(root, oldTable.id))
            return;
        deleteAVLTree(oldTable.result, oldTable.name);
        addAVLTree(newTable.result, newTable);
    }

    string toStringPreOrder(Node *root, string ans = "") const
    {
        if (root == nullptr)
        {
            return "";
        }
        ans = ("(key = " + to_string(root->key) + ") " + " (" + to_string(root->tb.id) + ")\n");

        ans += toStringPreOrder(root->left, ans);
        ans += toStringPreOrder(root->right, ans);
        return ans;
    }
    void PrintBFT(Node *root) const
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                // ans += ("Result (KEY): " + to_string(curr->tb.result) + "    " + to_string(curr->tb.id) + "\n");
                cout << curr->tb.id << "-" << curr->tb.result << "-" << curr->tb.dish << "\n";
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }
            }
        }
    };

public:
    void addAVLTree(int key, table tb)
    {
        root = addAVL(root, key, tb);
    }
    void deleteAVLTree(int key, string name)
    {
        root = deleteAVL(root, key, name);
    }
    int size() const
    {
        return this->cnt;
    }
    string toStringPreOrder() const
    {
        string ans = "==> AREA 2 - AVL <==\n";
        ans += toStringPreOrder(root, ans);
        // ans[ans.length() - 1] = ']';

        return ans + "==================\n";
    }
    void clear(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
    void clear()
    {
        clear(this->root);
        this->cnt = 0;
    }
    void printBFTDebug() const
    {
        cout << "==> AREA 2 - AVL(BFT) <==\n";

        PrintBFT(root);
        cout << "=======================\n";
    }
    void printBFT() const
    {
        PrintBFT(root);
    }
    bool contains(Node *root, int ID)
    {

        if (root == nullptr)
        {
            return false; // The tree is empty, so the element is not in the tree
        }
        if (root->tb.id == ID)
        {
            return true; // Found the element
        }
        bool containedLeft = false;
        containedLeft = contains(root->left, ID);
        if (containedLeft == 1)
            return containedLeft;

        bool containedRight = false;
        containedRight = contains(root->right, ID);
        if (containedRight == 1)
            return containedRight;
        return false;
    }
    bool containsID(int ID)
    {
        return contains(root, ID);
    }

public:
    class Node
    {
    public:
        int key;
        table tb;
        Node *left, *right;
        int bal_factor;
        friend class AVL;

    public:
        Node(int key = 1, table tb = table(0, "", 0, 0), Node *left = nullptr, Node *right = nullptr, int bal_fac = 0)
        {
            this->key = key;
            this->tb = tb;
            this->left = left;
            this->right = right;
            this->bal_factor = bal_fac;
        }
    };
};

class MinHeap
{
public:
    std::vector<table> heapArray;
    int capacity;
    // int recentOrder;

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        // this->recentOrder = recentOrder;
    }

    // Insert an element into the heap
    void insert(table tb)
    {
        if (heapArray.size() == capacity)
        {
            return;
        }

        heapArray.push_back(tb);
        // ++recentOrder;
        int index = heapArray.size() - 1;
        reheapUp(index);
    }

    // Remove and return the smallest element from the heap
    int removeMin()
    {
        if (heapArray.empty())
        {
            throw std::runtime_error("Heap underflow");
        }

        int minElement = heapArray[0].dish;
        int lastIndex = heapArray.size() - 1;
        heapArray[0] = heapArray[lastIndex];
        heapArray.pop_back();
        reheapDown(0);
        return minElement;
    }
    void remove(int pos)
    {
        int size = heapArray.size();
        if (size == 0 || pos >= size || pos < 0)
        {
            return;
        }
        swap(heapArray[pos], heapArray[size - 1]);
        heapArray.pop_back();
        reheapDown(pos);
    }

    int findIndex(const string name)
    {
        for (int i = 0; i < heapArray.size(); i++)
        {
            if (heapArray[i].name == name)
            {
                return i;
            }
        }
        return -1;
    }
    // Get the number of elements in the heap
    int size()
    {
        return heapArray.size();
    }

public:
    // Reheap Up
    void reheapUp(int pos)
    {
        if (pos <= 0)
            return;
        int parent = (pos - 1) / 2;
        if ((pos > 0 && heapArray[pos].dish < heapArray[parent].dish) || (heapArray[pos].dish == heapArray[parent].dish && heapArray[pos].recentOrder < heapArray[parent].recentOrder))
        {
            swap(heapArray[pos], heapArray[parent]);
            reheapUp(parent);
        }
        else
            return;
    }

    // Reheap Down
    void reheapDown(int pos)
    {
        int leftPos = 2 * pos + 1;
        int rightPos = 2 * pos + 2;
        if (leftPos >= heapArray.size() || pos >= heapArray.size())
            return;

        if (leftPos >= heapArray.size())
            return;
        if (rightPos >= heapArray.size())
            rightPos = -1;

        int smallestPos = 0;
        if (rightPos == -1)
        {
            smallestPos = leftPos;
        }
        else
        {
            if (heapArray[leftPos].dish < heapArray[rightPos].dish)
            {
                smallestPos = leftPos;
            }
            else if (heapArray[leftPos].dish == heapArray[rightPos].dish)
            {
                if (heapArray[leftPos].recentOrder < heapArray[rightPos].recentOrder)
                {
                    smallestPos = leftPos;
                }
                else
                {
                    smallestPos = rightPos;
                }
            }
            else
            {
                smallestPos = rightPos;
            }
        }
        if (heapArray[smallestPos].dish < heapArray[pos].dish || (heapArray[smallestPos].dish == heapArray[pos].dish && heapArray[smallestPos].recentOrder < heapArray[pos].recentOrder))
        {
            swap(heapArray[pos], heapArray[smallestPos]);
            reheapDown(smallestPos);
        }
        else
            return;
    }
    void printPreOrderHelper(int index)
    {
        if (index >= heapArray.size())
        {
            return;
        }

        // cout << index << ": " << heapArray[index].id << "-" << heapArray[index].dish << "-" << heapArray[index].recentOrder << "\n";
        cout << heapArray[index].id << "-" << heapArray[index].dish << "\n";
        printPreOrderHelper(2 * index + 1);
        printPreOrderHelper(2 * index + 2);
    }
    void printPreOrder()
    {
        if (heapArray.empty())
        {
            // cout << "Empty heap" << endl;
            return;
        }

        // std::cout << 0 << ": " << heapArray[0].id << "-" << heapArray[0].dish << "-" << heapArray[0].recentOrder << "\n";
        cout << heapArray[0].id << "-" << heapArray[0].dish << "\n";
        printPreOrderHelper(1);
        printPreOrderHelper(2);
        // std::cout << std::endl;
    }
};

/*----------DEFINE DATA STRUCTURE-------------*/
unordered_map<string, table> listName;
vector<table> fifo;
vector<table> lrco;
MinHeap lfco = MinHeap(MAXSIZE);
HashTable area1;
AVL area2; // area2 AVL
int RecOrder = 0;

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
    int ID = res % MAXSIZE + 1;
    return ID;
    // return ID;
}

int SelectArea(int res)
{
    if (res % 2 != 0)
    {
        if (!area1.isFull())
        {
            return 1;
            // insert hash table
        }
        else
            return (area2.size() < MAXSIZE / 2) ? 2 : 3;
    }

    else if (res % 2 == 0)
    {
        if (area2.size() < MAXSIZE / 2)
        {
            return 2;
            // insert AVL
        }
        else
            return (!area1.isFull()) ? 1 : 3;
    }
    return 3; // the restaurant is full.
}

bool checkName(unordered_map<string, table> restaurant, string name)
{
    for (auto pair : restaurant)
    {
        if (pair.second.name == name)
            return true;
    }
    return false;
}

void reg(string input)
{
    HuffmanCoding *huffman = new HuffmanCoding();
    string name = getName(input);
    string binaryName = huffman->HuffmanTree(name);
    int binNameLen = binaryName.length();
    string newName = (binNameLen > 15) ? binaryName.substr(binNameLen - 15) : binaryName;
    delete huffman;
    // cout << "== Debug HUFFMAN ==\n"
    //  << newName << endl;

    int Result = BinToDec(newName);
    // cout << Result << endl;

    // get full information:
    int ID = getID(Result);
    // while (true)
    // {
    // 	if (ID > MAXSIZE)
    // 		ID = 1;
    // 	if (!area2.containsID(ID) && !area1.containsID(ID))
    // 		break;
    // 	else
    // 		ID++;
    // }

    int select_area = SelectArea(Result);

    if (!checkName(listName, name))
    {
        if (select_area != 3)
        {

            while (true)
            {
                if (ID > MAXSIZE)
                    ID = 1;
                if (!area2.containsID(ID) && !area1.containsID(ID))
                    break;
                else
                    ID++;
            }
            table tb = table(ID, name, Result, 1, RecOrder, select_area);
            listName[name] = tb;
            fifo.push_back(tb);
            lrco.push_back(tb);
            lfco.insert(tb);
            RecOrder++;
            if (select_area == 1)
            {
                area1.insert(tb.result, tb);
            }
            if (select_area == 2)
            {
                area2.addAVLTree(tb.result, tb);
            }
        }
        else
        {
            int opt = Result % 3;
            if (opt == 0)
            {
                // delete
                table prevTable = fifo[0];
                for (int i = 0; i < lrco.size(); i++)
                {
                    if (lrco[i].name == prevTable.name)
                    {
                        lrco.erase(lrco.begin() + i);
                        break;
                    }
                }
                fifo.erase(fifo.begin());
                lfco.remove(lfco.findIndex(prevTable.name));
                listName.erase(prevTable.name);

                // create neww table, new name
                table newTable = table(prevTable.id, name, Result, 1, RecOrder, 0);

                // insert back new table
                fifo.push_back(newTable);
                lrco.push_back(newTable);
                lfco.insert(newTable);
                listName[name] = newTable;
                RecOrder++;
                // avl and hash
                if (area1.containsID(newTable.id))
                {
                    newTable.typeArea = 1;
                    area1.changeInfo(prevTable, newTable);
                }
                else if (area2.containsID(newTable.id))
                {
                    newTable.typeArea = 2;
                    area2.changeInfo(prevTable, newTable);
                }
            }
            else if (opt == 1)
            {
                table prevTable = lrco[0];
                for (int i = 0; i < fifo.size(); i++)
                {
                    if (fifo[i].name == prevTable.name)
                    {
                        fifo.erase(fifo.begin() + i);
                        break;
                    }
                }
                lrco.erase(lrco.begin());
                lfco.remove(lfco.findIndex(prevTable.name));
                listName.erase(prevTable.name);

                table newTable = table(prevTable.id, name, Result, 1, RecOrder, prevTable.typeArea);

                fifo.push_back(newTable);
                lrco.push_back(newTable);
                lfco.insert(newTable);
                listName.insert({name, newTable});
                RecOrder++;

                if (area1.containsID(newTable.id))
                {
                    area1.changeInfo(prevTable, newTable);
                }
                else if (area2.containsID(newTable.id))
                {
                    area2.changeInfo(prevTable, newTable);
                }
            }
            else if (opt == 2)
            {
                table prevTable = lfco.heapArray[0];
                lfco.remove(0);

                for (int i = 0; i < fifo.size(); i++)
                {
                    if (fifo[i].name == prevTable.name)
                    {
                        fifo.erase(fifo.begin() + i);
                        break;
                    }
                }
                for (int i = 0; i < lrco.size(); i++)
                {
                    if (lrco[i].name == prevTable.name)
                    {
                        lrco.erase(lrco.begin() + i);
                        break;
                    }
                }

                listName.erase(prevTable.name);

                table newTable = table(prevTable.id, name, Result, 1, RecOrder, prevTable.typeArea);

                fifo.push_back(newTable);
                lrco.push_back(newTable);
                lfco.insert(newTable);
                listName.insert({name, newTable});
                RecOrder++;
                if (area1.containsID(newTable.id))
                {
                    area1.changeInfo(prevTable, newTable);
                }
                else if (area2.containsID(newTable.id))
                {
                    area2.changeInfo(prevTable, newTable);
                }
            }
        }
    }
    else
    {
        // update LRCO
        listName[name].dish++;
        table tmpTable = listName[name];
        for (int i = 0; i < fifo.size(); i++)
        {
            if (fifo[i].name == name)
            {
                fifo[i].dish++;
                break;
            }
        }
        for (int i = 0; i < lrco.size(); i++)
        {
            if (lrco[i].name == name)
            {
                lrco.erase(lrco.begin() + i);
                break;
            }
        }
        // cout << "HELLO: " << lfco.findIndex(name)<< endl;
        lfco.remove(lfco.findIndex(name));
        lrco.push_back(tmpTable);

        lfco.insert(tmpTable);

        if (area2.containsID(listName[name].id))
        {
            area2.AddDish(Result, name);
        }
        else if (area1.containsID(listName[name].id))
        {
            area1.AddDish(name);
        }
    }

    return;
}
/*=== END REG Command ===*/

/*=== START CLE Command ===*/

int getNum(string inp)
{
    string tempInp = inp;
    int pos = tempInp.find_last_of(" ");
    if (pos != string::npos)
    {
        tempInp = tempInp.substr(pos + 1);
    }
    return stoi(tempInp);
}

// main function
void cle(string inp)
{
    // cout << "Command CLE written" << endl;
    // string num = getNum(inp);
    // bool check = true;
    // int NUM = checkNum(num, check);

    // if (!check)
    // 	return;
    int NUM = getNum(inp);
    if (NUM < 1)
    {
        queue<table> toBeDelete;
        for (int i = 0; i < fifo.size(); i++)
        {
            if (area1.containsID(fifo[i].id))
            {
                toBeDelete.push(fifo[i]);
                lfco.remove(lfco.findIndex(fifo[i].name));
                listName.erase(fifo[i].name);
                // area1.remove(fifo[i].id);
                for (int j = 0; j < lrco.size(); j++)
                {
                    if (fifo[i].name == lrco[j].name)
                    {
                        lrco.erase(lrco.begin() + j);
                        break;
                    }
                }
                area1.remove(fifo[i].id);
            }
        }
        while (!toBeDelete.empty())
        {
            for (int i = 0; i < fifo.size(); i++)
            {
                if (toBeDelete.front().name == fifo[i].name)
                {
                    fifo.erase(fifo.begin() + i);
                    break;
                }
            }
            toBeDelete.pop();
        }
    }
    else if (NUM > MAXSIZE)
    {
        // xoa ban
        queue<table> toBeDelete;
        for (table x : fifo)
        {
            // cout << x.name << endl;
            if (area2.containsID(x.id))
            {

                // cout << "have to delete: " << x.result << endl;s
                // cout << area2.containsID(27) << endl;

                int lrcoIndex = 0;
                for (table tmp : lrco)
                {
                    if (x.name == tmp.name)
                    {
                        lrco.erase(lrco.begin() + lrcoIndex);
                        break;
                    }
                    lrcoIndex++;
                }
                // cout << lfco.findIndex(x.name) << " ";
                // if (lfco.findIndex(x.name) == -1)
                // {
                //     cout << x.name << endl;
                // }
                lfco.remove(lfco.findIndex(x.name));
                listName.erase(x.name);
                area2.deleteAVLTree(x.result, x.name);
                toBeDelete.push(x);
            }
        }
        while (!toBeDelete.empty())
        {
            for (int i = 0; i < fifo.size(); i++)
            {
                if (toBeDelete.front().name == fifo[i].name)
                {
                    fifo.erase(fifo.begin() + i);
                    break;
                }
            }
            toBeDelete.pop();
        }
    }
    else
    {
        // xoa ban co ID = NUM
        table toBeDelete;
        for (auto pair : listName)
        {
            if (pair.second.id == NUM)
            {
                toBeDelete = pair.second;
                break;
            }
        }
        listName.erase(toBeDelete.name);
        for (int i = 0; i < fifo.size(); i++)
        {
            if (toBeDelete.name == fifo[i].name)
            {
                fifo.erase(fifo.begin() + i);
                break;
            }
        }
        for (int i = 0; i < lrco.size(); i++)
        {
            if (toBeDelete.name == lrco[i].name)
            {
                lrco.erase(lrco.begin() + i);
                break;
            }
        }
        lfco.remove(lfco.findIndex(toBeDelete.name));
        if (area1.containsID(NUM))
        {
            area1.remove(NUM);
        }
        if (area2.containsID(NUM))
        {
            area2.deleteAVLTree(toBeDelete.result, toBeDelete.name);
        }
    }
}

/*=== END CLE Command ===*/

/*=== START printHT Command ===*/
// helper function

// main function
void printHT(string inp)
{
    area1.display();
    return;
}

/*=== END printHT Command ===*/

/*=== START printAVL Command ===*/
// helper function

// main function
void printAVL(string inp)
{
    if (area2.size() <= 0)
        return;
    area2.printBFT();
    return;
}

/*=== END printAVL Command ===*/

/*=== START printMH Command ===*/
// helper function

// main function
void printMH(string inp)
{
    lfco.printPreOrder();
    return;
}

/*=== END printMH Command ===*/
void simulate(string filename)
{
    // outfile.open("got" + to_string(testcase) + ".txt");
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        fifo.clear();
        lrco.clear();
        lfco.heapArray.clear();
        lfco.capacity = MAXSIZE;
        listName.clear();
        RecOrder = 0;
        area2.root = nullptr;
        area2.cnt = 0;
        area1.tableCnt = 0;
        area1.hashTable.clear();

        int numLine = 1;

        for (int i = 0; i < MAXSIZE / 2; i++)
        {
            area1.hashTable[i] = table(0, "", 0, 0, 0, 0);
        }
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
    // cout.close();

    return;
}