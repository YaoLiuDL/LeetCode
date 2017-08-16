#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty()) return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int> > res(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(!obstacleGrid[i - 1][j - 1] == 1) 
                res[i][j] = res[i - 1][j]) + res[i][j - 1]);
        }
    }

    return res[m - 1][n - 1];
}

int main(){
    vector<vector<int>> test(2, vector<int>(3, 0));
    test[0][1] = 1;
    test[1][1] = 1;
    cout << uniquePathsWithObstacles(test) << endl;
    return 0;
}