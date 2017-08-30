/***********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : leetcode 350. Intersection of Two Arrays II 
***********************************************************************/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    //the mapping from the number to the count of the special number
    unordered_map<int, int> map;
    //First step: build the hash table of nums1
    for(auto num : nums1){
        map[num] ++;
    }
    //Second step: put the key whose value more than 0 in res, 
    //and substract the value at the meanwhile
    for(auto num : nums2){
        if(map[num]-- > 0) res.push_back(num);
    }

    return res;
}