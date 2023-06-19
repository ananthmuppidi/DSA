#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, unordered_set<int>> box;
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int curr = board[i][j] - '0'; // extract the current integer
                    auto rowInsertion = row[i].insert(curr);
                    auto colInsertion = col[j].insert(curr);
                    auto boxInsertion = box[generateKey(i, j)].insert(curr);

                    if(!rowInsertion.second || !colInsertion.second ||  !boxInsertion.second){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    string generateKey(int i, int j){
        int row = i / 3; // 0,1,2 will give 0. 3,4,5 will give 1. 
        int col = j / 3;
        string key = "";
        key.append(to_string(row));
        key.append(to_string(col));
        return key;
    }
};

int main(){

}