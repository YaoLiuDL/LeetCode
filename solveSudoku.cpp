#include <vector>

using std::vector;

vector<bool> getFlags(vector<vector<char>>& board, int i, int j){
    vector<bool> flags(9, false);
    char ch;
    for(int x = 0; x < 9; x++){
        ch = board[x][j];
        if(ch != '.') flags[ch - '1'] = true;
    }
    for(int y = 0; y < 9; y++){
        ch = board[i][y];
        if(ch != '.') flags[ch - '1'] = true;
    }

    int box_x = i - i % 3;
    int box_y = j - j % 3;

    for(int p = 0; p < 9; p++){
        ch = board[box_x + p / 3][box_y + p % 3];
        if(ch != '.') flags[ch - '1'] = true;
    }
    return flags;
}

bool fill(vector<vector<char>>& board, int lastX, int lastY){
    for(int i = lastX; i < 9; i++){
        for(int j = lastY + 1; j < 9; j++){
            if(board[i][j] != '.') continue;
            vector<bool> flags = getFlags(board, i, j);
            for(int num = 0; num < 9; num++){
                if(!flags[num]) {
                    board[i][j] = num + '1';
                    if(!fill(board, i, j)) 
                        continue;
                    else return true;
                }
            }
            board[i][j] = '.';
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.') fill(board, i, j - 1);
        }
    }
}

int main(){
    vector<vector<char>> test = {{'.','.','9','7','4','8','.','.','.'},
                                 {'7','.','.','.','.','.','.','.','.'},
                                 {'.','2','.','1','.','9','.','.','.'},
                                 {'.','.','7','.','.','.','2','4','.'},
                                 {'.','6','4','.','1','.','5','9','.'},
                                 {'.','9','8','.','.','.','3','.','.'},
                                 {'.','.','.','8','.','3','.','2','.'},
                                 {'.','.','.','.','.','.','.','.','6'},
                                 {'.','.','.','2','7','5','9','.','.'}};
    solveSudoku(test);
    return 0;
}