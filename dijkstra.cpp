#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int infinity = 10000000;
int l;
vector <ii> g[100000];
bool vis[100000];
int d[100000];

void addEdge(int u,int v, int p){
    ii k;
    k.first = v;
    k.second = p;
    g[u].push_back(k);
    ii q;
    q.first = u;
    q.second = p;
    g[v].push_back(q);
}
void init(int v){
    for(int i = 0; i < v; i++){
        vis[i] = false;
        d[i] = 10000000;
        g[i].clear();
    }
}
void dijkstra(int s){
    priority_queue < ii, vector<ii>, greater<ii> > q;
    d[s] = 0;
    pair <int,int> u(d[s],s);
    q.push(u);
    while(!q.empty()){
        ii top = q.top();
        q.pop();
        if(!vis[top.second]){
        vis[top.second] = true;
        for(int i = 0; i < g[top.second].size(); i++){
            if((top.first + g[top.second][i].second) < d[g[top.second][i].first]){
                d[g[top.second][i].first] = d[top.second] + g[top.second][i].second;
                pair <int,int> op(d[g[top.second][i].first],g[top.second][i].first);
                q.push(op);
            }
        }
    }
    }
}

