#include "main.h"
// DataStructure
class queue : public restaurant
{

public:
    // Inherit from restaurant
    table *recentCustomer;
    int size;
    queue()
    {
        recentCustomer = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    table *enqueue(table *last, int id, string name, int age)
    {
        size++;
        insert(last, id, name, age);
        return 0;
    }
    void dequeue()
    {
        // delete last->next
        // Queue is empty
        if (this->isEmpty())
            return;
        // Queue has only 1 customer
        else if (recentCustomer->next == recentCustomer)
        {
            delete recentCustomer;
            recentCustomer = nullptr;
        }
        else
        {
            table *removed = recentCustomer->next;
            recentCustomer->next = removed->next;
            delete removed;
        }
        size--;
    }
};

// Helper function
void readREG(const string &params, int &id, string &name, int &age)
{
    /*
     * Ex: inputString =  'REG 01 John 30' -> id = 01, name = 'John', age = 30
     * params = '01 John 30' or 'John 39'
     */
    // Find the first space in the input string
    string idString, nameString, ageString;
    int space1 = params.find(' ');
    int space2 = params.find(' ', space1 + 1);
    if (space2 == -1)
    {
        // No id
        idString = "-1";
        nameString = params.substr(0, space1);
        ageString = params.substr(space1 + 1);
    }
    else
    {
        idString = params.substr(0, space1);
        nameString = params.substr(space1 + 1, space2 - space1 + 1);
        ageString = params.substr(space2 + 1);
    }
    id = stoi(idString);
    name = nameString;
    age = stoi(ageString);
    // cout << id << " " << name << " " << age << endl;
}
table *getTable(int ID, restaurant *r)
{
    if (ID < 1 || ID > MAXSIZE)
    {
        throw out_of_range("Invalid ID");
    }
    table *currentTable = r->recentTable;
    if (r->recentTable != nullptr)
    {
        do
        {
            if (currentTable->ID == ID)
            {
                return currentTable;
            }
            currentTable = currentTable->next;
        } while (currentTable != r->recentTable);
    }
    return nullptr;
}

void REG(int ID, string NAME, int AGE, restaurant *r, queue *q)
{
    //'REG 01 John 30': Assume that ID<MAXSIZE
    if (AGE < 16)
        throw out_of_range("Invalid age");
    table *currentTable = r->recentTable; // last table
    if (ID == -1)
    {
        currentTable = currentTable->next; // first
        do
        {
            if (currentTable->name == " ")
            {
                currentTable->name = NAME;
                currentTable->age = AGE;
                return;
            }
            currentTable = currentTable->next;
        } while (currentTable != r->recentTable->next);
        // When the restaurant is full
        if (q->size < MAXSIZE)
        {
            q->recentCustomer = q->enqueue(q->recentCustomer, ID, NAME, AGE);
        }
    }
    else
    {
        // ID != -1
        currentTable = getTable(ID, r);
        table *tmpTable = currentTable;
        do
        {
            if (currentTable->name != " ")
            {
                currentTable = currentTable->next;
            }
            else
            {
                currentTable->name = NAME;
                currentTable->age = AGE;
                return;
            }
        } while (currentTable != tmpTable);
        // When the restaurant is full
        if (q->size < MAXSIZE)
        {
            q->recentCustomer = q->enqueue(q->recentCustomer, ID, NAME, AGE);
        }
    }
}
void readREGM(string params, string &name, int &age, int &num)
{
}
void REGM(string NAME, int AGE, int NUM)
{
}
void CLE(int ID)
{
}
void PS(int NUM)
{
}
void PQ(int NUM)
{
}
void SQ(int NUM)
{
}

void simulate(string filename, restaurant *r)
{
    // file I/O
    string line;
    ifstream inputfile(filename);
    if (inputfile.is_open())
    {
        while (getline(inputfile, line))
        // Extract input data line by line
        {
            string command = line.substr(0, line.find(' ')); // REG,REGM,CLE
            string params = line.substr(line.find(' ') + 1); //"1 Josh 20", "Kate 32"
            if (command == "REG")
            {
                // Create a queue
                queue *q = new queue();
                int id;
                string name;
                int age;
                readREG(params, id, name, age);
                cout << id << " " << name << " " << age << endl;
                REG(id, name, age, r, q);
            }
            else if (command == "REGM")
            {
            }
            else if (command == "CLE")
            {
            }
            else if (command == "PS")
            {
            }
            else if (command == "PQ")
            {
            }
            else if (command == "SQ")
            {
            }
            else
            {
            }
        }
        inputfile.close();
    }
    else
    {
        cout << "Could not open file" << endl;
    }

    // REG [ID] <NAME> <AGE>, insert
}