// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
#include<bits/stdc++.h>
using namespace std;
void bfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &vis, int newrow[], int newcol[], int scolor, int newColor, int n, int  m) {
    vis[row][col] = newColor;
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nrow = row + newrow[i];
            int ncol = col + newcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != newColor && image[nrow][ncol] == scolor) {
                vis[nrow][ncol] = newColor;
                q.push({nrow,ncol});
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> image(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    int scolor = image[sr][sc];
    vector<vector<int>> vis = image;
    int newrow[] = {0, 0, -1, 1};
    int newcol[] = {-1, 1, 0, 0};
    n = image.size();
    int m = image[0].size();
    bfs(sr, sc, image, vis, newrow, newcol, scolor, newColor, n, m); 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}