#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    int l;
    deque<pair<int, int>> num;
    for (int i = 0; i < n; i++) {
        cin >> l;
        if (num.size() != 0 && num.front().second <= i - k) {
            num.erase(num.cbegin());
        }
        while (num.size() != 0 && num.back().first >= l) {
            num.erase(num.cend());
        }
        num.insert(num.cend(), make_pair(l, i));
        if (i >= k - 1 || i == n - 1) {
            cout << num[0].first << " ";
        }
    }
    return 0;
}