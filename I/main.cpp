#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    int k;
    int p;
    cin >> n;
    cin >> k;
    cin >> p;
    int cnt = 0;
    vector<int> allCar(p);
    set<int> curCar;
    vector<int> carId(p,p+1);
    map<int, int> carIndex;
    for (int i = 0; i < p; i++) {
        cin >> allCar[i];
        if (carIndex.find(allCar[i]) != carIndex.end()) {
            carId[carIndex[allCar[i]]] = i;
            carIndex[allCar[i]] = i;
        } else {
            carIndex.insert(make_pair(allCar[i], i));
        }
    }
    for (int i = 0; i < p; i++) {
        if (curCar.count(i) != 0) {
            curCar.erase(i);
        } else {
            if (curCar.size() == k) {
                curCar.erase(*curCar.rbegin());
            }
            cnt++;
        }
        curCar.insert(carId[i]);
    }
    cout << cnt << endl;
}
