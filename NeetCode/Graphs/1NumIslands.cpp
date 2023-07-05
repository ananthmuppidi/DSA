#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j){
        if(vis[i][j]) return;
        if(grid[i][j] == '0') return;
        vis[i][j] = true;
        // make direction vectors
        vector<int> v = {1, -1, 0, 0};
        vector<int> h = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++){
            if(v[k] + i < 0 || v[k] + i >= grid.size()){}
            else if(h[k] + j < 0 || h[k] + j >= grid[0].size()){}
            else dfs(grid, vis, i + v[k], j + h[k]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                // only continue of there is a node present at i, j
                if(grid[i][j] != '0'){
                    if(!vis[i][j]){
                        ans++;
                        dfs(grid,vis, i, j);                
                    }
                }
            }
        }
        return ans;
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
