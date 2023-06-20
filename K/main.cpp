#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;


int main() {

    int n, M;
    cin >> n >> M;
    set<pair<int, int>> s;
    set<pair<int, int>> free;
    s.insert({ -n, 1 });
    free.insert({ 1, n });
    vector<pair<int, int>> q(M + 1);
    for (int i = 1; i <= M; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            if (s.empty()) {
                q[i] = { -1, -1 };
                cout << "-1"<<endl;
                continue;
            }
            auto cur = *s.begin();
            if (-cur.first < x) {
                q[i] = { -1, -1 };
                cout << "-1"<<endl;
                continue;
            }
            s.erase(s.begin());
            free.erase({ cur.second, -cur.first });
            q[i].first = cur.second;
            q[i].second = x;
            if (-cur.first > x) {
                s.insert({ cur.first + x, cur.second + x });
                free.insert({ cur.second + x, -cur.first - x });
            }
            cout << cur.second << endl;
        }
        else {
            x = -x;
            if (q[x] == make_pair(-1, -1)) {
                continue;
            }
            if (free.empty()) {
                free.insert({ q[x].first, q[x].second });
                s.insert({ -q[x].second, q[x].first });
                continue;
            }
            int pos = q[x].first;
            int k = q[x].second;
            auto it2 = free.lower_bound({ pos, k });
            auto it1 = it2;
            if (it2 != free.begin()) {
                --it1;
            }
            else {
                it1 = free.end();
            }
            if (it2 != free.end() && it2->first == pos + k) {
                if (it1 != free.end() && it1->first + it1->second == pos) {
                    int npos = it1->first;
                    int nk = it1->second + k + it2->second;
                    s.erase({ -it1->second, it1->first });
                    s.erase({ -it2->second, it2->first });
                    free.erase(it1);
                    free.erase(it2);
                    free.insert({ npos, nk });
                    s.insert({ -nk, npos });
                }
                else {
                    int nk = k + it2->second;
                    s.erase({ -it2->second, it2->first });
                    free.erase(it2);
                    s.insert({ -nk, pos });
                    free.insert({ pos, nk });
                }
            }
            else {
                if (it1 != free.end() && it1->first + it1->second == pos) {
                    int npos = it1->first;
                    int nk = k + it1->second;
                    s.erase({ -it1->second, it1->first });
                    free.erase(it1);
                    s.insert({ -nk, npos });
                    free.insert({ npos, nk });
                }
                else {
                    s.insert({ -k, pos });
                    free.insert({ pos, k });
                }
            }
        }
    }
}