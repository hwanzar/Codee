#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b)
{
  if (b != 0)
    return findGCD(b, a % b); // Euclid
  else
    return a;
}

int main()
{
  cout << findGCD(124, 32) << endl;
  cout << findGCD(24, 8) << endl;
  cout << findGCD(1000, 99) << endl;
}