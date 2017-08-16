#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;
    int i, j;

    while(low <= high){
        int mid = low + (high - low) / 2;
        i = mid / n;
        j = mid % n;
        if(matrix[i][j] < target) low = mid + 1;
        else(matrix[i][j] > target) high = mid - 1;
        else return true;
    }

    return false;
}