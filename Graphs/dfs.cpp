#include<bits/stdc++.h>
#define ll long long
#define endl  "\n"
using namespace std;
void dfs(int node, vector<int> adj[], int vis[], vector<int> &dfs_lst) {
    vis[node] = 1;
    dfs_lst.push_back(node);
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it,adj,vis,dfs_lst);
        }
    }
} 
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    int vis[n+1] = {0};
    int start = 1;
    vector<int> dfs_lst;
    dfs(start,adj,vis,dfs_lst);
    return dfs_lst;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = dfsOfGraph(n,adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size()-1) {
            cout << " -> " ;
        }
    }
    return 0;
}

// test case
//input
/*
9 9
1 2
1 6
2 3
2 4
4 5
5 8
6 7
6 9
7 8
*/
//output
// 1 -> 2 -> 3 -> 4 -> 5 -> 8 -> 7 -> 6 -> 9