#include <vector>

using std::vector;

bool isVlidSudoku(vector<vector<char>>& board) {
    char ch;
    for(int i = 0; i < board.size(); i++){
        vector<bool> flags(9, false);
        for(int j = 0; j < board[0].size(); j++){
            ch = board[i][j];
            if(ch != '.' && flags[ch]) return false;
            else flags[ch] = true;
        }
    }

    for(int i = 0; i < board[0].size(); i++){
        vector<bool> flags(9, false);
        for(int j = 0; j < board.size(); j++){
            ch = board[j][i];
            if(ch != '.' && flags[ch]) return false;
            else flags[ch] = true;
        }
    }

    for(int i = 0; i < 9; i++){
        vector<bool> flags(9, false);
        for(int j = 0; j < 9; j++){
            ch = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
            if(ch != '.' && flags[ch]) return false;
            else flags[ch] = true;
        }
    }
    return true;
}