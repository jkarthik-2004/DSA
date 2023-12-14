#include<bits/stdc++.h>
#define ll long long
#define endl  "\n"
using namespace std;
vector<int> bfsOfGraph(vector<int> adj[], int n) {
    int vis[n+1] = {0};
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 1; i  <= m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfsOfGraph(adj, n);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size()-1){
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
//1 -> 2 -> 6 -> 3 -> 4 -> 7 -> 9 -> 5 -> 8