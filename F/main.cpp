#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> num;
    string str;
    while (cin >> str) {
        if (num.empty()) {
            num.push_back(str);
        } else {
            for (int i = 0; i < num.size(); i++) {
                if (str + num[i] > num[i] + str) {
                    num.insert(num.begin() + i, str);
                    break;
                }
                if (i == num.size() - 1) {
                    num.push_back(str);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < num.size(); i++) {
        cout << num[i];
    }
    return 0;
}