#include<bits/stdc++.h>
using namespace std;

 void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>&grid) {
        vis[row][col]= 1; 
        int n = grid.size();
        int m = grid[0].size();
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol; 
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    dfs(nrow,ncol,vis,grid);
                }
            }
        }
    }
int numIslands(vector<vector<int>> &grid) {
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(!vis[row][col] && grid[row][col] == 1) {
                cnt++;
                dfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m,0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
        int ans =  numIslands(grid);
        cout << ans;
}