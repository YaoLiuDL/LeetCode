/**************************************************************
Copyright : CNIC
Author: LiuYao
Date: 2017-9-4
Description: leetcode 167. Two Sum II - Input array is sorted 
**************************************************************/

#include <vector>
#include <unordered_map>
#include <climits>

using std::vector;
using std::unordered_map;
using std::min;

int minSubArrayLen(int s, vector<int>& nums) {
    int left = 0, sum = 0, minLength = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        while(sum >= s){
            minLength = min(minLength, i - left + 1);
            sum -= nums[left++];
        }
    }
    return minLength == INT_MAX ? 0 : min;
}

int main(){
    return 0;
}