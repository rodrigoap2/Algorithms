#include <bits/stdc++.h>
using namespace std;

vector <int> g[4];
bool vis[4];

void init(){
    for(int i = 0; i < 4; i++){
        vis[i] = false;
    }
}
void addEdge(int i, int n){
    g[i].push_back(n);
}

int bfs(int n){
    queue <int> q;
    vis[n] = true;
    q.push(n);
    while(!q.empty()){
        int s = q.front();
        cout << s << endl;
        q.pop();
        for(int i = 0; i < g[s].size(); i++){
            if(vis[g[s][i]]== false){
                vis[g[s][i]] = true;
                q.push(g[s][i]);
            }
        }
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    bfs(2);
	return 0;
}
