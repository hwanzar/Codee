#include "main.h"
#include "debug_restaurant.cpp"

#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main(int argc, char *argv[])
{
    outtext;
    // string fileName = "test_demo_input.txt";
    // string fileName = "test.txt";
    string fileName = "input1.txt";
    simulate(fileName);

    return 0;
}
