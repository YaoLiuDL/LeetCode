/*******************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-28
Description : leetcode 217. Contains Duplicate 
*******************************************************/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool containsDuplicate(vector<int>& nums) {
    //the mapping from integer to existing
    unordered_map<int, bool> map; 
    for(auto i : nums){
        if(map[i]) return true;
        map[i] = true;
    }
    return false;
}