#include <iostream>
#include <algorithm>

using namespace std;

int comp(int a, int b) { return a > b; }

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int price[n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    sort(price, price + n, comp);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k != 0) {
            sum += price[i];
        }
    }
    cout << sum;
    return 0;
}
