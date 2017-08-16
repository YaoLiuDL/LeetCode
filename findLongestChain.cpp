#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

void find(vector<vector<int>>& pairs, int next, vector<vector<vector<int>>>& candidates){
    bool insert = false;
    for(int i = candidates.size() - 1; i > -1; i--){
        vector<vector<int>>& candidate = candidates[i];
        bool flag = false;
        int pos = 0;
        for(int j = 0; j < candidate.size(); j++){
            if((j < candidate.size() - 1 && candidate[j][1] < pairs[next][0] && pairs[next][1] < candidate[j + 1][0])
                || (j == candidate.size() - 1 && candidate[j][1] < pairs[next][0]) ){
                flag = true;
                insert = true;
                pos = j + 1;
            }
        }
        if(flag) candidate.insert(candidate.begin() + pos, pairs[next]);
        else if(insert) candidates.erase(candidates.begin() + i);
    }
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), comparator);
    vector<vector<vector<int>>> candidates(1, vector<vector<int>>(1, pairs[0]));
    for(int i = 1; i < pairs.size(); i++){
        find(pairs, i, candidates);
    }
    return candidates[0].size();
}

int main(){
    vector<vector<int>> test = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    cout << findLongestChain(test) << endl;
    return 0;
}
