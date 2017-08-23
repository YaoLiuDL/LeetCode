#include <vector>

using std::vector;

/* the program is wrong */
int maximalRectangle(vector<vector<char>>& matrix) {
    int maxArea = 0;
    int width = 0;
    int height = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            //find the longest width from point(i, j)
            for(int m = i; m < matrix.size(); i++){
                if(matrix[i][j] == '0'){
                    width = m - i;
                    break;
                } 
            }
            
            //find the longest height from point(i, j)
            for(int n = j; j < matrix[0].size(); n++) {
                if(matrix[i][j] == '0'){
                    height = n - j;
                    break;
                }
            }

            maxArea = width * height > maxArea ? width * height : maxArea;
        }
    }

    return maxArea;
}