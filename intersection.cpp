/***************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-29
Description : leetcode 349. Intersection of Two Arrays 
***************************************************/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //the mapping from int to whether the integer exists
    unordered_map<int, bool> map;

    //First step: put the numbers of nums1 in the mapping 
    for(auto num : nums1){
        map[num] = true; 
    }

    //Second step: get the number exist both in map and nums2
    vector<int> res;
    for(auto num : nums2){
        if(map[num]){
            res.push_back(num);
            map[num] = false;
        }
    }

    return res;
}