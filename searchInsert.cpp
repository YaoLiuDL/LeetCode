#include <iostream>
#include <vector>

int searchInsert(vector<int>& nums, int target){
	int low = 0, high = nums.size() - 1;
	while(low < high){
		int mid = (low + high) / 2;
		if (nums[mid] < target) low = mid + 1;
		else high = mid;
	}

	return (nums.size() > 0 && nums[nums.size() - 1] < target) ? nums.size(): low;
}
