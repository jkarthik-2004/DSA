// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
#include<bits/stdc++.h>
#define endl  "\n"
using namespace std;
void bfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i = 1; i <= adj[node].size(); i++) {
            if(!vis[i] && adj[node][i] == 1) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int u,v;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                adj[i][j] = 1;
            }
        }
    }
    for(int j = 1; j <= m; j++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int count = 0;
    vector<int> vis(n+1,0);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            count++;
            bfs(i,adj,vis);
        }
    }
    cout << count << endl;
    return 0;
}