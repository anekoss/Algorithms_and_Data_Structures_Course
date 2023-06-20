#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char sign;
        int num;
        cin >> sign;
            if(sign=='+'||sign=='*'){
                cin>>num;
            switch (sign) {
                case '+': {
                    nums.emplace_back(num);
                    break;
                }
                case '*': {
                    int k = (nums.size() + 1) / 2;
                    nums.insert(nums.cbegin() + k, num);
                    break;
                }
            }
        } else if (sign == '-') {
            cout << nums[0]<<endl;
            nums.erase(nums.cbegin());
        }
    }
    return 0;
}