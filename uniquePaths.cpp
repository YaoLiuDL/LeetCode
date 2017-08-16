#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int uniquePaths(int m, int n){
    vector<vector<int> > steps(m, vector<int>(n, 1));
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            steps[i][j] = steps[i - 1][j] + steps[i][j - 1];
        }
    }

    return steps[m - 1][n - 1];
}


int main(){
    cout << uniquePaths(2, 2) << endl;
    return 0;
}