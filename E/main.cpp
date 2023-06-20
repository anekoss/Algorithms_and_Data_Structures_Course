#include <iostream>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    long coordStall[n];
    for (int i = 0; i < n; i++) {
        cin >> coordStall[i];
    }
    int left = 0;
    int right = coordStall[n - 1] - coordStall[0];
    int middle, result;
    while (left <= right) {
        middle = (left + right) / 2;
        int countCows = 1;
        int lastCow = coordStall[0];
        for (int i = 1; i < n; i++) {
            if (coordStall[i] - lastCow >= middle) {
                countCows++;
                lastCow = coordStall[i];
            }
            if (countCows >= k) {
                break;
            }
        }
        if (countCows >= k) {
            result = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    cout << result << endl;
    return 0;
}