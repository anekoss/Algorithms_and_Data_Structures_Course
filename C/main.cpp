#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    string str;
    map<string, int> currentBlock;
    vector<map<string, int>> blocks;
    blocks.push_back(currentBlock);
    while (cin >> str) {
        if (str == "{") {
            blocks.emplace_back(map<string, int>());
        } else if (str == "}") {
            map<string, int> last = blocks[blocks.size() - 1];
            for (auto &i: last) {
                currentBlock[i.first] = i.second;
            }
            blocks.pop_back();
        } else {
            char temp = str[str.find('=', 0) + 1];
            if (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z') {
                string var1 = str.substr(0, str.find('=', 0));
                string var2 = str.substr(str.find('=', 0) + 1);
                if (blocks[blocks.size() - 1].count(var1) == 0) {
                    blocks[blocks.size() - 1][var1] = currentBlock[var1];
                }
                currentBlock[var1] = currentBlock[var2];
                cout << currentBlock[var1]<<endl;
            } else {
                string var = str.substr(0, str.find('=', 0));
                string num = str.substr(str.find('=', 0) + 1);
                if (blocks[blocks.size() - 1].count(var) == 0) {
                    blocks[blocks.size() - 1][var] = currentBlock[var];
                }
                currentBlock[var] = stoi(num);
            }
        }


    }
    return 0;
}
