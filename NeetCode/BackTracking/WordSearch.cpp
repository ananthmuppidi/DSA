#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, i, j, 0, word, vis)) return true;
            }
        }
        return false;

    }

    bool dfs(vector<vector<char>>& board, int i, int j, int solved, string& word, vector<vector<bool>>& vis){
        
        if(vis[i][j]) return false;
        if(solved == word.size() - 1){
            // cout << "HERE" << board[i][j] << word[solved] << endl;
            // need to check last character
            if(word[solved] == board[i][j]) return true;
            else return false;
        }   

        // check current iteration validity
        if(word[solved] != board[i][j]){
            return false;
        }

        // make direction vectors
        vector<int> v = {-1, 1, 0, 0};
        vector<int> h = {0, 0, 1, -1};

        // try all paths and use backtracking
        for(int k = 0; k < 4; k++){
            int ni = v[k] + i;
            int nj = h[k] + j;
            if(ni >= board.size() || ni < 0){}
            else if(nj >= board[0].size() || nj < 0){}
            else {
                vis[i][j] = true;
                // cout << i << " " << j << " " << board[i][j] << " -> " << ni << " " << nj << " " << board[ni][nj] <<"," << solved + 1 << endl;
                if(dfs(board, ni, nj, solved + 1, word, vis)) return true;
                vis[i][j] = false;
            }
        }
        return false;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<vector<char>> board = 
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << Solution().exist(board, "ABCCED") << endl;

}
