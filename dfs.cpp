#include <bits/stdc++.h>
using namespace std;

vector<int> adj[4];
bool vis[4];

void addEdge(int i, int j){
    adj[i].push_back(j);
}

void init(){
	for(int i = 0; i < 4; i++){
		vis[i] = false;
	}
}

void dfs(int v){
    cout << v << endl;
    vis[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        if(!vis[adj[v][i]]){
            dfs(adj[v][i]);
        }
    }
}

int main(){
	init();
	addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    dfs(0);

	return 0;
}