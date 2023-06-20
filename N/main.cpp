#include <iostream>
#include <vector>

using namespace std;

void colorize(vector<vector<int>> graph, bool used[], int j) {
    used[j] = true;
    for (int i = 0; i < graph[j].size(); i++) {
        if (used[graph[j][i]]== false) {
            colorize(graph, used, graph[j][i]);
        }
    }
}

int main() {
    int n;
    int cnt = 0;
    bool used[100];
    vector<vector<int>> graph;
    cin >> n;
    graph.assign(n, {});
    int l;
    for (int i = 0; i < n; i++) {
        cin >> l;
        graph[i].push_back(l - 1);
        graph[l - 1].push_back(i);
        used[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            cnt++;
            colorize(graph, used, i);
        }
    }
    cout << cnt;
    return 0;
}