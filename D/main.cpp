#include <iostream>
using namespace std;
int main() {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int e;
  for (int i = 1; i <= k; i++) {
    e = a;
    a = a * b;
    if (a < c) {
      a = 0;
      break;
    }
    a = a - c;
    if (a > d) {
      a = d;
    }
    if (a == 0 || a == e) {
      break;
    }
  }
  cout << a;
  return 0;
}