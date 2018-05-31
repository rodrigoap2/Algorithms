#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int infinity = ~(1 << 31);
vector <ii> g[100000];
bool vis[100000];
int d[100000];

void addEdge(int u, int v, int p){
    g[u].push_back(ii(v, p));
    g[v].push_back(ii(u, p));
}
void init(int v){
    for(int i = 0; i < v; i++){
        vis[i] = false;
        d[i] = infinity;
        g[i].clear();
    }
}
void dijkstra(int s){
    priority_queue < ii, vector<ii>, greater<ii> > q;
    d[s] = 0;
    q.push(ii(d[s],s));
    while(!q.empty()){
        ii top = q.top();
        q.pop();
        if(vis[top.second] == false){
            vis[top.second] = true;
            for(int i = 0; i < g[top.second].size(); i++){
                if(g[top.second][i].second < d[g[top.second][i].first] &&
                   !vis[g[top.second][i].first]){
                    d[g[top.second][i].first] = g[top.second][i].second;
                    q.push(ii(d[g[top.second][i].first],g[top.second][i].first));
                }
            }
        }
    }
}