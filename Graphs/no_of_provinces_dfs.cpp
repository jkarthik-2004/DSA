#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(int i = 1; i <= adj[node].size(); i++) {
        if(!vis[i] && adj[node][i] == 1) {
            dfs(i, adj, vis);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                adj[i][j] = 1;
            }
        }
    }
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    vector<int> vis(n+1,0);
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            count++;
            dfs(i, adj, vis);
        }
    }
    cout << count << endl;
}