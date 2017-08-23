/***********************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-23
Description : Given an array of integers, 
              every element appears twice except 
              for one. Find that single one.
              Your algorithm should have a linear 
              runtime complexity. Could you implement 
              it without using extra memory? 
***********************************************/

#include <vector>

using std::vector;

//Summary : find the single number, by accumulating the all numbers using XOR
int singleNumber(vector<int>& nums){
    int res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        res ^= nums[i];
    }
    return res;
}