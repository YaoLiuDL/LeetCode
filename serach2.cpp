/**************************************************************
Copyright: CNIC
Author: LiuYao
Date: 2017-9-6
Description: leetcode 
**************************************************************/

#include <vector>

using std::vector;

bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, start = 0, length = nums.size();
    
    if(low == high) start = low;
    
    low = 0;
    high = nums.size() - 1;
    while(low  <= high){
        int mid = low + (high - low) / 2;
        int realmid = (mid + start) % length;
        if(nums[realmid] < target) low = mid + 1;
        else if(nums[realmid] > target) high = mid - 1;
        else return true;
    }
    return false;
}

int main(){
    vector<int> nums = {2,2,2,0,2,2};
    bool res = search(nums, 0);
    return 0;
}