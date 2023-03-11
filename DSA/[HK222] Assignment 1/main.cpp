#include "main.h"
#include "restaurant.cpp"
// #include "bao_restaurant.cpp"
int main(int argc, char *argv[])
{
    restaurant *r = new restaurant();
    string fileName = "zar_test.txt";
    // string fileName = "test.txt";
    // initialize table with ID, name and age
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable, i, "", 0);
    }
    simulate(fileName, r);
    cout << endl;
    printTable(*r);

    delete r;
    return 0;
}
