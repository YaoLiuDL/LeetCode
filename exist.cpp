#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::string;

struct position{
    int x;
    int y;   
    vector<int> path;   // 1 : left
                        // 2 : top
                        // 3 : right
                        // 4 : bottom
};

bool contains(vector<vector<char>>& board, position target){
    int x = target.x;
    int y = target.y;
    vector<int> path = target.path;
    bool contain = false;
    for(int i = path.size() - 1; i > -1; i --){
        switch(path[i]){
            case 1:
                if(x - 1 == target.x && y == target.y)
                    contain = true;
                x--;
                break;
            case 2:
                if(x == target.x && y - 1 == target.y)
                    contain = true;
                y--;
                break;
            case 3:
                if(x + 1 == target.x && y == target.y)
                    contain = true;
                x++;
                break;
            case 4 : 
                if(x == target.x && y + 1 == target.y)
                    contain = true;
                y++;
                break;
            default:
                break;
        }
    }

    return contain;
}

vector<position> getPosition(vector<vector<char>>& board, string& word, int end){
    vector<position> positions;
    if(end < 1) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[end]) positions.push_back(position{i, j, vector<int>()});
            }
        }
        return positions;
    }
    vector<position> temps = getPosition(board, word, end - 1);
    if(temps.size() == 0) return positions;
    for(int i = 0; i < temps.size(); i++){
        int x = temps[i].x;
        int y = temps[i].y;
        
        if(x > 0 && board[x - 1][y] == word[end]) {
            vector<int> path = temps[i].path;
            path.push_back(3);
            position newPos = position{x - 1, y, path};
            if(!contains(board, newPos))
                positions.push_back(newPos);
        }
        if(x < board.size() - 1 && board[x + 1][y] == word[end]) {
            vector<int> path = temps[i].path;
            path.push_back(1);
            position newPos = position{x + 1, y, path};
            if(!contains(board, newPos))
                positions.push_back(newPos);
        }
        if(y > 0 && board[x][y - 1] == word[end]) {
            vector<int> path = temps[i].path;
            path.push_back(4);
            position newPos = position{x, y - 1, path};
            if(!contains(board, newPos))
                positions.push_back(newPos);
        }
        if(y < board[0].size() - 1 && board[x][y + 1] == word[end]) {
            vector<int> path = temps[i].path;
            path.push_back(2);
            position newPos = position{x, y + 1, path};
            if(!contains(board, newPos))
                positions.push_back(newPos);
        }
    }

    return positions;

}

bool exist(vector<vector<char>>& board, string word) {
    vector<position> positions = getPosition(board, word, word.length() - 1);
    return positions.size();
}

int main(){
    vector<vector<char>> board = {{'a', 'a'}, {'a', 'a'}};
    string test = "aaaaa";
    bool result = exist(board, test);
    std::cout << result << std::endl;
    return 0;
}