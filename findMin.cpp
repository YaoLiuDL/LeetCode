/**************************************************************
Copyright : CNIC
Author: LiuYao
Date: 2017-9-4
Description: leetcode 167. Two Sum II - Input array is sorted 
**************************************************************/

#include <vector>

using std::vector;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[high]) low = mid + 1;
        else if(nums[mid] < nums[high]) high = mid;
        else{
            if(nums[mid] == nums[low]) low++;
            else if(nums[mid] > nums[low]) return nums[low];
            else high = mid;
        }
    } 
    return nums[low == high ? low : 0];
}