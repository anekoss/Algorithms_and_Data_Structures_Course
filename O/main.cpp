#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool colorize(vector<int> students [],
              vector<int> color, vector<bool> visitedStudent, int v, int c) {
    queue<int> q;
    q.push(v);
    visitedStudent[v] = true;
    color[v] = c;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : students[u]) {
            if (!visitedStudent[i]) {
                visitedStudent[i] = true;
                color[i] = 3 - color[u];
                q.push(i);
            } else if (color[i] == color[u])
                return false;
        }
    }
    return true;
}

int main() {
    int n;
    int m;
    int l;
    int k;
    cin >> n >> m;
    vector<int> students[n + 1];
    vector<bool> visitedStudent(n + 1);
    vector<int> color(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> l >> k;
        students[l].push_back(k);
        students[k].push_back(l);
    }
    bool res = true;
    for(int i=1;i<=n;i++){
        if(!visitedStudent[i]){
            res&= colorize(students,color,visitedStudent,i,1);
        }
    }
    if (res) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}