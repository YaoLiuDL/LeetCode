#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int search(vector<int>& nums, int target){
	int left = 0, right = nums.size() - 1;
	while(left < right){
		int mid = (left + right) / 2;
		if(nums[mid] > nums[right]) left = mid + 1;
		else right = mid;
	}

	int rot = left;
	left = 0;
	right = nums.size() - 1;
	while(left < right){
		int mid = (left + right) / 2;
		int realmid = (mid + rot) % nums.size();
		if(nums[realmid] == target) return realmid;
		if(nums[realmid] < target) left= mid + 1;
		else right = mid - 1;
	}
	return -1;

}

int main(){
	vector<int> test = {4,5,6,7,0,1,2,3};
	int target = 5;
	cout << search(test, 5) << endl;
}
