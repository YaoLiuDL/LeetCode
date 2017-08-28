/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-28
Description : leetcode 219. Contains Duplicate II 
********************************************************************/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //the mapping from integer to int position
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        if(map.find(nums[i]) != map.end() 
            && (i - map[nums[i]]) <= k )
                return true;
        map[nums[i]] = i;
    }

    return false;
}