#include <iostream>
#include <vector>

using std::vector;
using std::swap;

int removeDuplicates(vector<int>& nums) {
    int end = nums.size() - 1;
    int count = 1, duplicate = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i - 1]) count++;
        else count = 1;
        if(count > 2) {
            duplicate++;
        }else{
            nums[i - duplicate] = nums[i];
        }
    }       
    return nums.size() - duplicate;
}