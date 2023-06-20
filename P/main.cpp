#include <iostream>

using namespace std;

int n;
int count;
bool graph[1000][1000];

void dfs(int type, int k, bool used[]) {
    count++;
    used[k] = true;
    for (int i = 0; i < n; i++) {
        if (type == 1) {
            if (graph[i][k] && !used[i])
                dfs(type, i, used);
        } else {
            if (graph[k][i] && !used[i])
                dfs(type, i, used);
        }
    }
}

int main() {
    int plane[1000][1000];
    cin >> n;
    bool used[n];
    int left = 0;
    int l;
    int right = 1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> l;
            if (l > 0) {
                plane[i][j] = l;
            }
        }
    }
    while (left < right) {
        int mid = (left + right) / 2;
        count = 0;
        for (int i = 0; i < n; i++) {
            used[i] = false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (plane[i][j] > mid)
                    graph[i][j] = false;
                else graph[i][j] = true;
            }
        }
        dfs(0, 0, used);
        if (count != n) {
            left = mid + 1;
        } else {
            for (int i = 0; i < n; i++) {
                used[i] = false;
            }
            count = 0;
            dfs(1, 0, used);
            if (count != n) left = mid + 1;
            else right = mid;
        }
    }
    cout << left;
    return 0;
}