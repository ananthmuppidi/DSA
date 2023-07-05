for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                ans = ans || dfs(board, i, j, 0, word, vis);                
            }
        }