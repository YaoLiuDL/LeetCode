/**************************************************
* Copyright: CNIC
* Author: LiuYao
* Date: 2017-9-19
* Description: leetcode 72. Edit Distance 
**************************************************/
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::min;
using std::cin;

int minDistance(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> distances(n1 + 1, vector<int>(n2 + 1, 0));
    for(int i = 0; i < n1 + 1; i++){
        distances[i][0] = i;
    }
    for(int i = 1; i < n2 + 1; i++){
        distances[0][i] = i;
    }
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            int min_distance = min(distances[i - 1][j] + 1, distances[i][j - 1] + 1);
            if(word1[i - 1] == word2[j - 1])
                distances[i][j] = min(distances[i - 1][j - 1], min_distance);
            else
                distances[i][j] = min(distances[i - 1][j - 1] + 1, min_distance);
        }
    }
    return distances[n1][n2];
}

int main(){
    string word1 = "plasma";
    string word2 = "altruism";
    int res = minDistance(word1, word2);
    cout << res << endl;
    cin.get();
    return 0;
}