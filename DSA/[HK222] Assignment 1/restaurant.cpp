#include "main.h"

template <class E>
class DLL
{
public:
    class Node
    {
    public:
        E data;
        Node *prev;
        Node *next;
        Node(const E &data = E{}, Node *next = nullptr, Node *prev = nullptr) : data(data), next(next), prev(prev) {}
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

    void add(const E &value)
    {
        // O(1)
        if (cnt == 0)
        {
            Node *node = new Node(value);
            head = node;
            tail = node;
            tail->next = nullptr;
            cnt++;
            return;
        }
        Node *node = new Node(value);
        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
        cnt++;
        return;
    }
    void add(int index, const E &e)
    {
        // O(index)
        if (index < 0 || index > cnt)
        {
            throw out_of_range("Index out of range");
        }

        if (cnt == 0)
        {
            add(e);
            return;
        }
        if (index == 0)
        {
            Node *node = new Node(e);
            node->next = head;
            head->prev = node;
            head = node;
            cnt++;
            return;
        }
        if (index == cnt)
        {
            add(e);
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // add node
        Node *addNode = new Node(e, cur->prev, cur);
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
        Node *current = head;
        while (current != tail)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        // head->next = tail;
        // tail->prev = head;
        cnt = 0;
    }
    E removeAt(int index)
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
        E res = cur->data;
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
        delete cur;
        cnt--;
        return res;
    }
    bool removeItem(const E &item)
    {
        Node *temp = head;
        for (int i = 0; temp != nullptr; i++)
        {
            if (temp->data == item)
            {
                removeAt(i);
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void printTail()
    {
        cout << "[";
        if (tail != nullptr)
        {
            cout << tail->data;
            Node *current = tail->prev;
            while (current != nullptr)
            {
                cout << "," << current->data;
                current = current->prev;
            }
        }
        cout << "]" << endl;
    }
};
// preparation of double linked list for stack and queue
template <class E>
class Stack
{
public:
    DLL<E> list;

public:
    Stack() {}

    void push(const E &item)
    {
        list.add(item); // O(1)
    }

    E pop()
    {
        if (list.empty())
        {
            throw runtime_error("Stack is empty");
        }
        return list.removeAt(list.size() - 1);
    }

    E peek()
    {
        if (list.empty())
        {
            throw runtime_error("Stack is empty");
        }
        return list.tail->data;
    }

    int size()
    {
        return list.size();
    }

    bool empty()
    {
        return list.empty();
    }
    // void debug_DLL()
    // {
    //     cout << "[";
    //     if (head != nullptr)
    //     {
    //         cout << head->data;
    //         Node *current = head->next;
    //         while (current != nullptr)
    //         {
    //             cout << "," << current->data;
    //             current = current->next;
    //         }
    //     }
    //     cout << "]" << endl;
    // }
};

template <class E>
class Queue
{
public:
    DLL<E> list;

public:
    Queue() {}

    void enqueue(const E &item)
    {
        list.add(item); // O(1)
    }

    E dequeue()
    {
        if (list.empty())
        {
            throw runtime_error("Queue is empty");
        }
        return list.removeAt(0);
    }

    E peek()
    {
        if (list.empty())
        {
            throw runtime_error("Queue is empty");
        }
        return list.head->data;
    }

    int size()
    {
        return list.size();
    }

    bool empty()
    {
        return list.empty();
    }
};
string filtCommand(string filename)
{
    string command;
    int idx = 0;
    while (idx < filename.size() && isspace(filename[idx]))
    {
        idx++;
    }
    while (idx < filename.size() && isspace(filename[idx]) == 0)
    {
        command += filename[idx];
        idx++;
    }
    return command;
}

int getID(string input)
{
    string command = input.substr(0, 3); // extract first 3 characters
    if (command == "REG")
    {
        int start = 4;
        int end = input.find(" ", start);
        if (end == string::npos)
        {
            return -100; // no ID number found, return -100
        }
        string id_str = input.substr(start, end - start); // extract ID number as string
        // cout << id_str;
        return (id_str[0] <= '9' && id_str[0] >= '0') ? stoi(id_str) : -100; // convert ID number to integer and return
    }
    else if (command == "CLE")
    {
        size_t pos = input.rfind(" ");
        string id_toCLE = input.substr(pos + 1);
        return (id_toCLE[0] <= '9' && id_toCLE[0] >= '0') ? stoi(id_toCLE) : -100;
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
    if (input.substr(0, 3) == "REG")
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

    return input;
}
int getNum(string input)
{
    // only for regm right?
    size_t pos = input.rfind(" ");
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

        size_t pos = input.rfind(" ");
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
Queue<table> waitlist;
Stack<table> history; // lưu lại danh sách người đến nhà hàng (kể cả người đợi) vào stack để lấy ra người gần nhất đến nhà hàng

// restaurant *waitlist = new restaurant();

void reg(string input, restaurant *r, Queue<table> waitlist, Stack<table> history)
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
    if (id == -100)
    {
        // truong hop ko co id
        int i = 1;

        table *tb = r->recentTable->next;
        while (i <= MAXSIZE)
        {
            if (tb->name == "")
            {
                // ban trong
                tb->name = name;
                tb->age = age;
                history.push(*tb);
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
            table *tb = new table(id, name, age, nullptr);
            waitlist.enqueue(*tb);
            history.push(*tb);
        }
    }
    else
    {
        // truong hop co id
        //  truon hop co id, duyet den ban trong
        //  truong hop co id, duyet den ban ko trong, nhung con ban khac trong
        //  truong hop full het ban

        table *tb = r->recentTable->next;
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
                break;
            }
            tb = tb->next;
            ++i;
        }
        if (i == MAXSIZE + 1)
        {
            // waitlist->recentTable = waitlist->insert(waitlist->recentTable, id, name, age);
            cout << "The restaurant is full!";
            table *tb = new table(id, name, age, nullptr); // co xoa KOO???
            waitlist.enqueue(*tb);                         // O(1).
            history.push(*tb);
        }
    }
}
// table *mergableTables(restaurant *r, int num)
// {
//     // top of the table:
//     if (num > MAXSIZE)
//     {
//         return nullptr;
//     }
//     table *possibleMerge = r->recentTable->next;
//     table *unEmptyTable = nullptr;
//     int index = -1;
//     int emptyTable = 15;
//     while (possibleMerge->ID > index && (MAXSIZE - emptyTable) <= num)
//     {
//         table *temp = possibleMerge;
//         int i = 0;
//         for (; i < num; i++, temp = temp->next)
//         {
//             if (!isEmptyTable(temp))
//             {
//                 unEmptyTable = temp;
//                 emptyTable--;
//                 break;
//             }
//         }
//         if (i == num)
//         {
//             mergedTable = possibleMerge;
//             index = possibleMerge->ID;
//             possibleMerge = possibleMerge->next;
//         }
//         else
//         {
//             possibleMerge = unEmptyTable->next;
//         }
//     }

//     return mergedTable;
// }
table *findNEmptyTables(restaurant *r, int N)
{
    table *cur = r->recentTable;
    table *start = nullptr;
    int count = 0;
    int maxID = -1;

    do
    {
        if (cur->name == "")
        {
            if (count == 0)
            {
                start = cur;
            }
            count++;
            if (count == N)
            {
                maxID = cur->ID;
                break;
            }
        }
        else
        {
            count = 0;
            start = nullptr;
        }
        cur = cur->next;
    } while (cur != r->recentTable);

    if (maxID != -1)
    {
        // Tìm thấy N bàn trống liên tiếp
        cur = start;
        while (cur->ID != maxID)
        {
            cur = cur->next;
        }
        return start->next;
    }
    else
    {
        // Không tìm thấy đủ N bàn trống liên tiếp
        return nullptr;
    }
    // return start;
}

void regm(string input)
{
    // int id = getID(input);
    string name = getName(input);

    int age = getAge(input);
    int numb = getNum(input);
    cout << name << " " << age << " number" << numb << endl;
    return;
}

void cle(string input)
{
    int id = getID(input);
    cout << "ID to CLE: " << id << endl;
    return;
}

void ps(string input, Stack<table> history)
{
    int num = getNum(input);
    if (num == -1)
    {
        // chỉ có mỗi lệnh PS thôi. ko có [NUM].
        //
    }
    table tb = history.list.tail->data;
    cout << "PS: age " << tb.age << endl;
    return;
}

void pq()
{
    return;
}

void simulate(string filename, restaurant *r)
{
    ifstream file(filename);

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

                reg(line, r, waitlist, history);
            }
            if (filtCommand(line) == "REGM")
            {
                regm(line);
            }
            if (filtCommand(line) == "CLE")
            {
                cle(line);
            }
            if (filtCommand(line) == "PS")
            {
                ps(line, history);
            }
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void printTable(restaurant r)
{
    if (r.recentTable == nullptr)
    {
        cout << "No tables in the restaurant." << endl;
        return;
    }

    cout << "Tables in the restaurant:" << endl;
    table *cur = r.recentTable->next; // start from the first table
    do
    {
        cout << "ID: " << cur->ID << ", Name: " << cur->name << ", Age: " << cur->age << endl;
        cur = cur->next;
    } while (cur != r.recentTable->next); // iterate until we reach the starting table again
}