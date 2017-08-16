#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

int firstMissingPositive(vector<int>& nums){
	for(int i = 0; i < nums.size(); i++){
		while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
			swap(nums[i], nums[nums[i] - 1]);
	}

	for(int i = 0; i < nums.size(); i++){
		if(nums[i] != i + 1)
			return i + 1;
	}
	return nums.size() + 1;
}

int main(){
	vector<int> test = {3,4,-1,1};
	cout << firstMissingPositive(test) << endl;
	return 0;
}
