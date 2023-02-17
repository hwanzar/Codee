#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int n) {
     if (n == 0)
    return 0;
  else {
    return (n % 2 + 10 * decimalToBinary(n / 2));
  }
}

int main() {
  cout << decimalToBinary(20) << '\n';
  cout << decimalToBinary(100) << '\n';
  cout << decimalToBinary(15) << endl;
}
