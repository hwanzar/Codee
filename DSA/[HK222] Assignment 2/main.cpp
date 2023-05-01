#include "main.h"
#include "debug_restaurant.cpp"

#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main(int argc, char *argv[])
{
    // for (int i = 0; i < 20; i++)
    // {
    //     string fileName = "input" + to_string(i) + ".txt";
    //     string str_i = to_string(i);
    //     const char *got = ("got" + str_i + ".txt").c_str();
    //     freopen(got, "w", stdout);
    //     simulate(fileName);
    // }
    outtext;
    string fileName = "input10.txt";
    // string fileName = "test.txt";
    simulate(fileName);
    return 0;
}
