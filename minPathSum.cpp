#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::swap;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> cur(m, grid[0][0]);

    for(int i = 1; i < m; i++)
        cur[i] = cur[i - 1] + grid[i][0];

    for(int j = 1; j < n; j++){
        cur[0] += grid[0][j];
        for(int i = 1; i < m; i++){
            cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
    }

    return cur[m - 1];
}

int main(){
    vector<vector<int>> test(3, vector<int>(3, 1));
    test[0][1] = 3;
    test[1][1] = 5;
    test[2][0] = 4;
    test[2][1] = 2;
    cout << minPathSum(test) << endl;
    return 0;
}