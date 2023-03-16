#include "main.h"

table *latestTable = nullptr;
int checkREGM = -1;
table *regm_head = nullptr;
// DLL *waitlist = new DLL();
// DLL *history = new DLL();
int num_regm = 0;

int sort_index = 0;

class DLL
{
public:
    class Node
    {
    public:
        int idx;
        int ID;
        string name;
        int age;
        Node *next;
        Node *prev;
        Node(int ID = 0, string name = "", int age = 0, Node *next = nullptr, Node *prev = nullptr) : ID(ID), name(name), age(age), next(next), prev(prev) {}

        Node(int idx, int ID, string name, int age)
        {
            this->idx = idx;
            this->ID = ID;
            this->name = name;
            this->age = age;
        }
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

    // void add(int ID, string name, int age)
    // {
    //     // O(1)
    //     Node *node = new Node(ID, name, age);
    //     if (cnt == 0)
    //     {
    //         head = node;
    //         tail = node;
    //         tail->next = nullptr;
    //         delete node;
    //         cnt++;
    //         return;
    //     }
    //     // Node *node = new Node(ID, name, age);

    //     node->prev = tail;
    //     tail->next = node;
    //     // node->next = nullptr;
    //     tail = node;
    //     node = nullptr;
    //     // delete node;
    //     cnt++;
    //     return;
    // }
    void add(int ID, string name, int age)
    {
        Node *node = new Node(ID, name, age);
        if (cnt == 0)
        {
            head = node;
            tail = node;
            cnt++;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
        cnt++;
    }

    void add(int idx, int ID, string name, int age)
    {
        // O(1)
        Node *node = new Node(idx, ID, name, age);
        if (cnt == 0)
        {
            // Node *node = new Node(idx, ID, name, age);
            head = node;
            tail = node;
            tail->next = nullptr;

            cnt++;
            return;
        }

        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;

        cnt++;
        return;
    }
    // void add(int index, int ID, string name, int age)
    // {
    //     // O(index)
    //     if (index < 0 || index > cnt)
    //     {
    //         throw out_of_range("Index out of range");
    //     }

    //     if (cnt == 0)
    //     {
    //         add(ID, name, age);
    //         return;
    //     }
    //     if (index == 0)
    //     {
    //         Node *node = new Node(ID, name, age);
    //         node->next = head;
    //         head->prev = node;
    //         head = node;
    //         cnt++;
    //         return;
    //     }
    //     if (index == cnt)
    //     {
    //         add(ID, name, age);
    //         return;
    //     }
    //     Node *cur = head;
    //     for (int i = 0; i < index; i++)
    //     {
    //         cur = cur->next;
    //     }
    //     // add node
    //     Node *addNode = new Node(ID, name, age, cur->prev, cur);
    //     cur->prev->next = addNode;
    //     cur->prev = addNode;
    //     cnt++;
    // }
    int size() { return cnt; }
    bool empty()
    {
        return cnt == 0;
    }
    bool checkItem(string name, int age)
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            if (cur->name == name && cur->age == age)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
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
            throw std::out_of_range("Invalid removee at");
        }
        Node *cur = head;
        Node *prev = nullptr;

        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        // now delete
        if (head->next == nullptr)
        {
            head->prev = nullptr;
            head = nullptr;
            tail = nullptr;
        }
        else if (prev == nullptr)
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
    void removeItem(string name, int age)
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            if (cur->name == name && cur->age == age)
            {
                // Remove the current node
                if (cur == head)
                {
                    pop_front();
                }
                else if (cur == tail)
                {
                    pop_back();
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    cnt--;
                    delete cur;
                }
                return;
            }
            cur = cur->next;
        }
        throw out_of_range("Item not found");
    }
    void push_front(int ID, string name, int age)
    {
        add(0, ID, name, age);
    }
    void push_back(int ID, string name, int age)
    {
        add(ID, name, age);
    }
    Node *pop_front()
    {
        return removeAt(0);
    }
    Node *pop_back()
    {
        return removeAt(cnt - 1);
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
        cout << cur->idx << " *** " << cur->name << "\n";
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
    for (int i = 0; i < (int)s.length(); i++)
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
        size_t pos = input.find(" ");
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
        pos = input.find(" ");
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
    size_t pos = input.rfind(" ");
    int num = -1;
    if (pos != string::npos)
    {
        string num_str = input.substr(pos + 1);
        num = stoi(num_str);
        // cout << "NUM " << num << endl;
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
        return (age >= 16 && age <= 115) ? age : 0;
    }
    else if (input.substr(0, 4) == "REGM")
    {
        int pos = input.find(" ");      // find first space
        pos = input.find(" ", pos + 1); // find second space
        // pos = input.find(" ", pos + 1);        // find third space
        string ageStr = input.substr(pos + 1); // extract substring after third space
        int age = stoi(ageStr);                // convert string to integer
        // cout << age << endl;                   // output: 112
        return (age >= 16 && age <= 115) ? age : 0;
    }
    return 0; // default value
}

int findNodeIndex(DLL *history, DLL::Node *tb)
{
    DLL::Node *node = history->head;
    int index = 0;
    while (node != nullptr)
    {
        if (node->name == tb->name && node->age == tb->age)
        {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}

void reg(string input, restaurant *r, DLL *waitlist, DLL *history, DLL *Squeue)
{
    // neu khach hang dat ban theo ID
    //  table empty, update thong tin khach hang
    //  neu ko co ID, chon ban empty dau tien tu nho den lon

    // buoc dau tien phai loc ra id, ten, tuoi
    //  getID
    // neu regm, roi reg

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
    table *tb = r->recentTable->next;

    // truong hop ko co ID`
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
            // cout << "The restaurant is full!";
            waitlist->add(id, name, age);
            Squeue->add(sort_index, id, name, age);
            sort_index++;
            cout << "index ** " << sort_index << endl;
            // kiem tra lich su xem da co chua
            DLL::Node *save = new DLL::Node(id, name, age);
            int found = findNodeIndex(history, save);
            if (found == -1)
                history->add(id, name, age);
            delete save;
        }
    }
    else
    {
        // truong hop co id
        //  truon hop co id, duyet den ban trong
        //  truong hop co id, duyet den ban ko trong, nhung con ban khac trong
        //  truong hop full het ban

        // table *tb = r->recentTable->next;
        if (id > MAXSIZE)
            return;

        int cnt = 1;
        while (tb->ID != id)
        {
            if (cnt > MAXSIZE)
                break;
            tb = tb->next;
            cnt++;
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
            // cout << "The restaurant is full!";

            waitlist->add(id, name, age);
            Squeue->add(sort_index, id, name, age);
            sort_index++;
            cout << "index ** " << sort_index << endl;
            DLL::Node *save = new DLL::Node(id, name, age);
            int found = findNodeIndex(history, save);
            if (found == -1)
                history->add(id, name, age);
            delete save;
        }
    }
}

void regm(string input, restaurant *r, DLL *history)
{
    // int id = getID(input);
    string name = getName(input);
    // cout << name << endl;

    int age = getAge(input);
    if (age < 16)
        return;

    int num = getNum(input);
    // cout << name << " " << age << " number" << num << endl;

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
    int maxEmptyID = -1;
    bool flag = false; // check xem tim ra lien tuc chua
    table *res = nullptr;
    if (checkREGM != -1)
        return;
    // table *past_head = head;
    for (int i = 0; i < 2 * MAXSIZE; i++)
    // while (head != r->recentTable)
    {
        if (flag == false)
        {
            if (head->name != "")
            {
                head = head->next;
                cntEmpty = 1;
                tail = head;
            }
            else if (cntEmpty == num)
            {
                flag = true;
                res = head;
                maxEmptyID = head->ID;
            }
            else if (tail->next->name == "")
            {
                cntEmpty++;
                if (cntEmpty == num)
                {
                    flag = true; // da tim ra 1 day lien tiep
                    res = head;
                    maxEmptyID = head->ID;
                }
                tail = tail->next;
            }
            else if (tail->next->name != "")
            {
                head = tail->next;
                tail = head;
                // cout << tail->next->age << endl;
                cntEmpty = 1;
            }
        }
        else if (flag == true)
        {
            // neu da tim thay 1 day lien tiep, tim max id cua head.
            if (tail->next->name == "" && maxEmptyID < head->next->ID)
            {
                // tiep tuc mo rong
                // di chuyen head
                head = head->next;
                tail = tail->next;
                maxEmptyID = head->ID;
                res = head;
            }
            else if (tail->next->name != "")
            {
                flag = false; // tìm tiếp 1 dãy liên tiếp mớiD
                head = tail->next;
                tail = head;
                cntEmpty = 1;
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
        r->recentTable = res;
        regm_head = res->next;
        res->next = tail->next;
        res->age = age;
        res->name = name;

        table *tmp = r->recentTable;
        while (tmp->ID < tmp->next->ID)
        {
            r->recentTable = r->recentTable->next;
            tmp = tmp->next;
        }
        history->add(res->ID, name, age);
        checkREGM = res->ID;
        // cout << "checkREGM " << checkREGM << endl;
        num_regm = num;
        // cout << num_regm << " check numreg\n";
    }
    else if (res == nullptr)
    {
        return;
    }
    return;
}

void cle(string input, restaurant *r, DLL *waitlist, DLL *history, DLL *Squeue)
{
    int id = getID(input);
    cout << "ID to CLE: " << id << endl;
    if (id > MAXSIZE)
        return;
    table *tbclr = r->recentTable->next;

    for (int i = 0; i < MAXSIZE; i++)
    {
        if (tbclr->ID == id)
        {
            break;
        }
        tbclr = tbclr->next; // đưa đến id cần tìm
        // nếu ID khác id cần tìm thì coi nhu ko tồn tại
    }
    if (tbclr->ID != id || tbclr->name == "")
        return;

    else if (tbclr->ID == checkREGM)
    {
        // kết nối lại với table* đã tách
        // kiểm tra hàng đợi.
        // truy cập vào node đó, xóa giá trị trong history

        // DLL::Node *node_cle = new DLL::Node(tbclr->ID, tbclr->name, tbclr->age, nullptr);
        // int indexTB = findNodeIndex(history, node_cle);
        // // cout << indexTB << "aaaaa" << endl;
        // history->removeAt(indexTB);
        // delete node_cle; // memory leak
        tbclr->name = "";
        tbclr->age = 0;
        tbclr->next = regm_head;
        checkREGM = -1;

        // vòng for chạy từ id cần clear, đến các giá trị trong ô gộp
        for (int i = 0; i < num_regm; i++)
        {
            if (!Squeue->empty())
            {
                DLL::Node *node = Squeue->pop_front();
                waitlist->removeItem(node->name, node->age);
                // table *tb = new table(node->ID, node->name, node->age, nullptr);

                // int indexTBQ = findNodeIndex(history, tb);
                // history->removeAt(indexTBQ);// xóa history cái queue

                string line = "REG ";
                line = line + to_string(node->ID) + " " + node->name + " " + to_string(node->age); // tạo lại hàm REG
                // cout << line << endl;
                reg(line, r, waitlist, history, Squeue); // REG vào chỗ mới
                // delete tb;//memory leak
            }
            tbclr = tbclr->next;
        }
    }
    else
    {
        // bàn đơn
        DLL::Node *node_cle = new DLL::Node(tbclr->ID, tbclr->name, tbclr->age, nullptr);
        int indexTB = findNodeIndex(history, node_cle);
        // cout << indexTB << "debug **" << endl;
        // printForward(*history, 1);
        history->removeAt(indexTB);
        delete node_cle; // memory leak
        if (!waitlist->empty())
        {
            DLL::Node *node = Squeue->pop_front();
            waitlist->removeItem(node->name, node->age);
            // history->removeAt(indexTB);
            tbclr->age = node->age;
            tbclr->ID = id;
            tbclr->name = node->name;
            latestTable = tbclr;
        }
        else
        {
            tbclr->name = "";
            tbclr->ID = id;
            tbclr->age = 0;
            latestTable = tbclr;
        }
    }

    return;
}

void ps(string input, DLL *History)
{
    int numHistory = History->size();
    // cout << numHistory << " customers now\n";
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
    // cout << numWait << " is waiting now\n";
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
    // cout << id;
    table *tb = r->recentTable->next;

    while (tb->ID != id)
    {
        tb = tb->next;
    }
    // cout << "Table in the restaurant from PT command:\n";
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (tb->age != 0)
        {
            cout << tb->ID << "-" << tb->name << endl;
        }
        tb = tb->next;
    }
}

DLL *getIdxDLL(DLL *dll)
{
    DLL::Node *cur = dll->head;
    for (int i = 0; i < dll->size(); i++)
    {
        cur->idx = i;
        cur = cur->next;
    }
    return dll;
}

void sq(string input, restaurant *r, DLL *waitlist, DLL *history, DLL *Squeue)
{
    int num = getNum(input);
    if (num == -1)
        return;

    int numQ = Squeue->size();
    if (numQ < num && num <= MAXSIZE)
    {
        num = numQ;
    }
    // DLL *waitQueue = getIdxDLL(waitlist);
    if (waitlist->size() == 0)
    {
        cout << "Empty\n";
        return;
    }
    // printForward(*Squeue, 3);
    DLL::Node *step = Squeue->head;
    DLL::Node *check = step->next;
    DLL::Node *largest = NULL;

    int savedNum = num;

    int cnt = MAXSIZE;
    int maxAge = check->age;
    int idxSorted = step->idx;
    int flag = 0;

    // selection sort
    while (step != Squeue->tail)
    {

        maxAge = step->age;
        while (check != Squeue->tail)
        {
            if ((check->age > maxAge) || (check->age == maxAge && check->idx < idxSorted))
            {
                largest = check;
                maxAge = check->age;
                idxSorted = check->idx;
                flag = 1;
            }
            check = check->next;
        }
        if ((check->age > maxAge) || (check->age == maxAge && check->idx < idxSorted))
        {
            largest = check;
            maxAge = check->age;
            idxSorted = check->idx;
            flag = 1;
        }

        if (flag)
        {
            int tmpIdx = step->idx;
            int tmpID = step->ID;
            string tmpName = step->name;
            int tmpAge = step->age;

            // cout << largest->age << " *950\n";
            step->idx = largest->idx;
            largest->idx = tmpIdx;

            step->ID = largest->ID;
            largest->ID = tmpID;

            step->name = largest->name;
            largest->name = tmpName;

            step->age = largest->age;
            largest->age = tmpAge;
        }

        step = step->next;
        check = step->next;
        flag = 0;
        idxSorted = step->idx;
        cnt--;
        num = num - 1;
        if (num == 0)
            break;
    }
        
    DLL::Node *p = Squeue->head;
    // Node *newTable = Wait->head;
    for (int i = 0; i < savedNum; i++)
    {
        cout << p->name << endl;
        // cout << p->age << endl;
        p = p->next;
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
    // for (int i = 1; i <= MAXSIZE; i++)
    // {
    //     cout << "ID: " << cur->ID << ", Name: " << cur->name << ", Age: " << cur->age << endl;
    //     cur = cur->next;
    // }
}

void simulate(string filename, restaurant *r)
{
    ifstream file(filename);
    DLL *waitlist = new DLL();
    DLL *history = new DLL();
    DLL *Squeue = new DLL();
    if (file.is_open())
    {
        string line;
        // int n = 1;
        while (getline(file, line))
        {
            // cout << "THE COMMAND IS: " << filtCommand(line) << endl;
            if (filtCommand(line) == "REG")
            {
                reg(line, r, waitlist, history, Squeue);
            }
            if (filtCommand(line) == "REGM")
            {
                regm(line, r, history);
            }
            if (filtCommand(line) == "CLE")
            {
                cle(line, r, waitlist, history, Squeue);
            }
            if (filtCommand(line) == "PS")
            {
                ps(line, history);
            }
            if (filtCommand(line) == "PQ")
            {
                pq(line, waitlist);
            }
            if (filtCommand(line) == "PT")
            {
                pt(line, r);
            }
            if (filtCommand(line) == "SQ")
            {
                sq(line, r, waitlist, history, Squeue);
            }
            // if (n >= 1)
            // {
            //     cout << filtCommand(line) << endl;
            //     cout << endl;
            //     cout << "--RESTAURANT--" << endl;
            //     cout << endl;
            //     printTable(r);

            //     if (filtCommand(line) == "PS" || filtCommand(line) == "PQ" || filtCommand(line) == "SQ" || filtCommand(line) == "PT")
            //     {
            //         sleep(10);
            //     }
            //     else
            //     {
            //         sleep(3);
            //     }
            //     system("clear");
            // }
            // n++;
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    waitlist->clear();
    history->clear();
    Squeue->clear();
    delete waitlist;
    delete history;
    delete Squeue;
    // delete latestTable;
    // delete regm_head;
}
