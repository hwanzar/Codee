#include "main.h"
table *latestTable = nullptr;
bool checkREGM = false;

class DLL
{
public:
    class Node
    {
    public:
        int ID;
        string name;
        int age;
        Node *prev;
        Node *next;
        Node(int ID = 0, string name = "", int age = 0, Node *next = nullptr, Node *prev = nullptr) : ID(ID), name(name), age(age), next(next), prev(prev) {}
    };

public:
    Node *head;
    Node *tail;
    int cnt;

    DLL() : head(NULL), tail(NULL), cnt(0) {}
    ~DLL()
    {
        clear();
    }

    void add(int ID, string name, int age)
    {
        // O(1)
        if (cnt == 0)
        {
            Node *node = new Node(ID, name, age);
            head = node;
            tail = node;
            tail->next = nullptr;
            cnt++;
            return;
        }
        Node *node = new Node(ID, name, age);
        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
        cnt++;
        return;
    }
    void add(int index, int ID, string name, int age)
    {
        // O(index)
        if (index < 0 || index > cnt)
        {
            throw out_of_range("Index out of range");
        }

        if (cnt == 0)
        {
            add(ID, name, age);
            return;
        }
        if (index == 0)
        {
            Node *node = new Node(ID, name, age);
            node->next = head;
            head->prev = node;
            head = node;
            cnt++;
            return;
        }
        if (index == cnt)
        {
            add(ID, name, age);
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // add node
        Node *addNode = new Node(ID, name, age, cur->prev, cur);
        cur->prev->next = addNode;
        cur->prev = addNode;
        cnt++;
    }
    int size() { return cnt; }
    bool empty()
    {
        return cnt == 0;
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cnt = 0;
    }
    Node *removeAt(int index)
    {
        if (cnt == 0 || index < 0 || index >= cnt)
        {
            throw std::out_of_range("Invalid index");
        }
        Node *cur = head;
        Node *prev = nullptr;

        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        // now delete
        if (prev == nullptr)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (cur->next == nullptr)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else
        {
            prev->next = cur->next;
            (cur->next)->prev = prev;
        }
        cnt--;
        return cur;
    }
    void push_front(int ID, string name, int age)
    {
        add(0, ID, name, age);
    }
    void push_back(int ID, string name, int age)
    {
        add(ID, name, age);
    }
    void pop_front()
    {
        removeAt(0);
    }
    void pop_back()
    {
        removeAt(cnt - 1);
    }

    Node *front()
    {
        if (cnt == 0)
        {
            throw out_of_range("Deque is empty");
        }
        return head;
    }
    Node *back()
    {
        if (cnt == 0)
        {
            throw out_of_range("Deque is empty");
        }
        return tail;
    }
};

void printForward(DLL &dll, int index)
{
    if (dll.empty())
    {
        cout << "Empty\n";
        return;
    }
    if (index < 0 || index > dll.size())
    {
        throw out_of_range("Index out of range");
    }
    DLL::Node *cur = dll.head;
    for (int i = 0; i < index; i++)
    {
        // cout << i << ": " << cur->ID << " " << cur->name << " " << cur->age << endl;
        cout << cur->name << "\n";
        cur = cur->next;
    }
}

void printReverse(DLL &dll, int index)
{
    if (dll.empty())
    {
        cout << "Empty\n";
        return;
    }
    if (index < 0 || index > dll.size())
    {
        throw out_of_range("Index out of range");
    }
    DLL::Node *cur = dll.tail;
    for (int i = dll.size() - 1; i >= dll.size() - index; i--)
    {
        // cout << i << ": " << cur->ID << " " << cur->name << " " << cur->age << endl;
        cout << cur->name << "\n";
        cur = cur->prev;
    }
}

string filtCommand(string input)
{
    int pos = input.find(" ");
    string command = input.substr(0, pos);
    return command;
}

int countSpaces(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
        {
            count++;
        }
    }
    return count;
}
/* Viet ham kiem tra mot chuoi co phai la so => Thoa man stoi */
int getID(string input)
{
    string command = input.substr(0, 3); // extract first 3 characters
    int cntSpc = -1;
    string id_str = "";
    if (command == "REG")
    {
        cntSpc = countSpaces(input);
        if (cntSpc == 3)
        {
            int start = 4;
            int end = input.find(" ", start);
            id_str = input.substr(start, end - start);
            // cout << id_str << endl;
            return stoi(id_str);
        }
        else
        {
            return -100;
        }
    }
    else if (command == "CLE")
    {
        int pos = input.rfind(" ");
        string id_toCLE = input.substr(pos + 1);
        return stoi(id_toCLE);
    }
    else
    {
        return -100; // not a valid command, return -100
    }
}
string getName(string input)
{
    // int pos;
    // cout << input << endl;
    if (input.substr(0, 4) == "REG ")
    {
        int id = getID(input);
        int pos = input.find(" ");
        if (id < 0)
        {
            input = input.substr(pos + 1);
            // cout << id << " " << input << endl;
            pos = input.find(" ");
            input = input.substr(0, pos);
        }
        else
        {
            input = input.substr(pos + 1);
            // cout << input << endl;
            pos = input.find(" ");
            input = input.substr(pos + 1);
            pos = input.find(" ");
            input = input.substr(0, pos);
        }
    }
    if (input.substr(0, 4) == "REGM")
    {
        int pos = input.find(" ");
        input = input.substr(pos + 1);
        // cout << input << endl;
        // input = input.substr(pos + 1);

        input = input.substr(0, pos);
    }

    string name = input;
    return name;
}
int getNum(string input)
{
    // only for regm right?S
    int pos = input.rfind(" ");
    int num = -1;
    if (pos != string::npos)
    {
        string num_str = input.substr(pos + 1);
        num = stoi(num_str);
        cout << "NUM " << num << endl;
    }
    return num;
}
int getAge(string input)
{
    int age = 0;
    if (input.substr(0, 4) == "REG ")
    {

        int pos = input.rfind(" ");
        if (pos != string::npos)
        {
            string age_str = input.substr(pos + 1);
            age = stoi(age_str);
            // cout << "Age " << age << endl;
        }
        return age;
    }
    else if (input.substr(0, 4) == "REGM")
    {
        int pos = input.find(" ");      // find first space
        pos = input.find(" ", pos + 1); // find second space
        // pos = input.find(" ", pos + 1);        // find third space
        string ageStr = input.substr(pos + 1); // extract substring after third space
        int age = stoi(ageStr);                // convert string to integer
        cout << age << endl;                   // output: 112
        return age;
    }
    return 0; // default value
}
// change wait list to queue
// lưu lại danh sách người đến nhà hàng (kể cả người đợi) vào stack để lấy ra người gần nhất đến nhà hàng

void reg(string input, restaurant *r, DLL *waitlist, DLL *history)
{
    // neu khach hang dat ban theo ID
    //  table empty, update thong tin khach hang
    //  neu ko co ID, chon ban empty dau tien tu nho den lon

    // buoc dau tien phai loc ra id, ten, tuoi
    //  getID

    int id = getID(input);
    string name = getName(input);
    int age = getAge(input);
    if (age < 16)
        return;
    // cout << "Age: " << age << endl;
    if (waitlist->size() == MAXSIZE || history->size() == 2 * MAXSIZE)
    {
        return;
    }

    // chia hai truong hop, co id va ko co id
    table *cur = r->recentTable;
    int minID = 100000;
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (cur->ID < minID)
            minID = cur->ID;
        cur = cur->next;
    }
    table *tb = cur;
    while (tb->ID != minID)
    {
        tb = tb->next;
    }

    if (id == -100)
    {
        // truong hop ko co id
        int i = 1;

        // table *tb = r->recentTable->next;
        while (i <= MAXSIZE)
        {
            if (tb->name == "")
            {
                // ban trong
                tb->name = name;
                tb->age = age;
                history->add(id, name, age);
                latestTable = tb;
                break;
            }
            else
            {
                tb = tb->next;
                ++i;
            }
        }
        if (i > MAXSIZE)
        {
            // add to queue
            // waitlist->recentTable = waitlist->insert(waitlist->recentTable, -100, name, age);
            cout << "The restaurant is full!";
            waitlist->add(id, name, age);
            history->add(id, name, age);
        }
    }
    else
    {
        // truong hop co id
        //  truon hop co id, duyet den ban trong
        //  truong hop co id, duyet den ban ko trong, nhung con ban khac trong
        //  truong hop full het ban

        // table *tb = r->recentTable->next;
        while (tb->ID != id)
        {
            tb = tb->next;
        }
        int i = 1;
        while (i <= MAXSIZE)
        {
            if (tb->name == "")
            {
                tb->name = name;
                tb->age = age;
                history->add(id, name, age);
                latestTable = tb;
                break;
            }
            tb = tb->next;
            ++i;
        }
        if (i == MAXSIZE + 1)
        {
            // waitlist->recentTable = waitlist->insert(waitlist->recentTable, id, name, age);
            cout << "The restaurant is full!";

            waitlist->add(id, name, age);
            history->add(id, name, age);
        }
    }
}

void regm(string input, restaurant *r, DLL *history)
{
    // int id = getID(input);
    string name = getName(input);
    cout << name << endl;

    int age = getAge(input);
    if (age < 16)
        return;

    int num = getNum(input);
    cout << name << " " << age << " number" << num << endl;

    table *head = r->recentTable->next; //
    int check = 1;
    while (head->name != "")
    {
        head = head->next; // chạy tới bàn trống đầu tiên
        if (check > MAXSIZE)
        {
            return; // ko ton tai ban trong
        }
        check++;
    }
    table *tail = head;
    int cntEmpty = 1;
    int maxID = head->ID;
    bool flag = false; // check xem tim ra lien tuc chua
    table *res = nullptr;
    if (checkREGM == true)
        return;
    for (int cnt = 1; cnt <= 2 * MAXSIZE; cnt++)
    {
        if (flag == false)
        {
            if (head->name != "")
            {
                head = head->next;
            }
            else if (tail->next->name == "")
            {
                cntEmpty++;
                if (cntEmpty == num)
                {
                    flag = true; // da tim ra 1 day lien tiep
                    res = head;
                }
                tail = tail->next;
            }
            else if (tail->next->name != "")
            {
                head = head->next;
                tail = head;
                cntEmpty = 0;
            }
        }
        else if (flag == true)
        {
            // neu da tim thay 1 day lien tiep, tim max id cua head.
            if (tail->next->name == "" && maxID < head->next->ID)
            {
                // tiep tuc mo rong
                // di chuyen head
                head = head->next;
                tail = tail->next;
                maxID = head->next->ID;
                res = head;
            }
            else if (tail->next->name != "")
            {
                flag = false; // tìm tiếp 1 dãy liên tiếp mớiD
                head = tail->next;
                tail = head;
                cntEmpty = 0;
            }
        }
    }
    // dua raa ket qua la res
    tail = res;

    if (res != nullptr)
    {
        for (int i = 1; i <= num - 1; i++)
        {
            tail = tail->next;
        }
        res->next = tail->next;
        tail->next = nullptr;
        res->age = age;
        res->name = name;
        latestTable = res;
        history->add(res->ID, name, age);
        checkREGM = true;
    }
    else if (res == nullptr)
    {
        return;
    }
    return;
}

void cle(string input)
{
    int id = getID(input);
    // cout << "ID to CLE: " << id << endl;

    return;
}

void ps(string input, DLL *History)
{
    int numHistory = History->size();
    cout << numHistory << " customers now\n";
    //  xu li cai NUM

    int num = getNum(input);
    if (History->empty())
    {
        cout << "Empty";
        return;
    }

    if (num == -1 || (num > numHistory && num <= 2 * MAXSIZE))
    {
        num = numHistory;
    }

    printReverse(*History, num);
    return;
}

void pq(string input, DLL *waitList)
{
    int numWait = waitList->size();
    cout << numWait << " is waiting now\n";
    //  xu li cai NUM

    int num = getNum(input);
    if (waitList->empty())
    {
        cout << "Empty\n";
        return;
    }
    if (num == -1 || (num > numWait && num <= 2 * MAXSIZE))
    {
        num = numWait;
    }
    printForward(*waitList, num);
    return;
}

void pt(string input, restaurant *r)
{
    int id = latestTable->ID;
    cout << id;
    table *tb = r->recentTable->next;

    while (tb->ID != id)
    {
        tb = tb->next;
    }
    cout << "Table in the restaurant from PT command:\n";
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (tb->age != 0)
        {
            cout << tb->ID << "-" << tb->name << endl;
        }
        tb = tb->next;
    }
}
void printTable(restaurant *r)
{
    if (r->recentTable == nullptr)
    {
        cout << "No tables in the restaurant." << endl;
        return;
    }

    cout << "Tables in the restaurant:" << endl;
    table *cur = r->recentTable->next; // start from the first table
    do
    {
        cout << "ID: " << cur->ID << ", Name: " << cur->name << ", Age: " << cur->age << endl;
        cur = cur->next;
    } while (cur != r->recentTable->next); // iterate until we reach the starting table again
}

void simulate(string filename, restaurant *r)
{
    ifstream file(filename);
    DLL waitlist;
    DLL history;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // cout << "THE COMMAND IS: " << filtCommand(line) << endl;
            if (filtCommand(line) == "REG")
            {
                // cout << getID(line) << endl;
                // cout << getName(line) << endl;
                // cout << getAge(line) << endl;
                // printTable(*r);

                reg(line, r, &waitlist, &history);
            }
            if (filtCommand(line) == "REGM")
            {
                regm(line, r, &history);
            }
            // if (filtCommand(line) == "CLE")
            // {
            //     cle(line);
            // }
            if (filtCommand(line) == "PS")
            {
                ps(line, &history);
            }
            if (filtCommand(line) == "PQ")
            {
                pq(line, &waitlist);
            }
            if (filtCommand(line) == "PT")
            {
                pt(line, r);
            }
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}
