#include <vector>
#include <iostream>
using namespace std;

vector<int> toCompleteParallelogram(int rows, int cols, char** positionsInPark, int euclidX, int euclidY, int monteX,int monteY){
    int x, y;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(char[i][j] ==  '+'
                && (i != euclidX && j != euclidY)
                && (i != monteX && j != monteY)){
                    x = i;
                    y = j;
                }
        }
    }

    vector<int> res;
    res.push_back(monteX - x + euclidX);
    res.push_back(monteY - y + euclidY);

    return res;
}

int main(){
    char[][] chs = {{1,2,3},{2,3,4}};
    vector<int> res = toCompleteParallelogram
    return 0;
}