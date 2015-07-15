#include <iostream>
using namespace std;

/**
 * a - base
 * n - exponent
 */
int power(int a, int n) {
  if(n==1) return a;
  int temp = power(a, n/2);
  if(n%2 == 0)
    return temp*temp;
  else
    return temp*temp*a;
}

int main() {
  cout << power(5, 5) << endl;
  cout << power(7, 8) << endl;
  return 0;
}
