#include <iostream>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    multimap<int, char> alpabet;
    for (char i = 'a'; i <= 'z'; i++) {
        cin >> k;
        alpabet.insert(make_pair(k, i));
    }
    map<char, int> weight;
    for (char &i: s) {
        if (!weight.count(i)) {
            weight.insert(make_pair(i, 1));
        } else {
            weight[i]++;
        }
    }
    string result = "";
    for (auto const &entry: alpabet) {
        if (weight.count(entry.second)) {
            if (weight[entry.second] == 2) {
                result = entry.second + result + entry.second;
            } else if (weight[entry.second] > 2) {
                string l = "";
                for (int j = 0; j < weight[entry.second] - 2; j++) {

                    l = l + entry.second;
                }
                result = entry.second + result.substr(0, result.length() / 2) + l +
                         result.substr(result.length() / 2, result.length()) + entry.second;
            } else if (weight[entry.second] == 1) {
                result = result.substr(0, result.length() / 2) + entry.second +
                         result.substr((result.length() / 2), result.length());
            }
        }
    }
    cout << result;
}