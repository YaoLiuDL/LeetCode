#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int col_state = 1;

    for(int i = 0; i < m; i++){
        if(!matrix[i][0]) col_state = 0;
        for(int j = 0; j < n; j++){
            if(!matrix[i][j])
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 1; j--){
            if(!matrix[i][0] || !matrix[0][j]) 
                matrix[i][j] = 0;
        }
        if(!col_state) matrix[i][0] = 0;
    }
}