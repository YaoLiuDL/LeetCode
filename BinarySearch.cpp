#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int binarySearch(vector<int> nums, int target){
	int low = 0, high = nums.size() - 1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(nums[mid] < target) low = mid + 1;
		else if(nums[mid] > target) high = mid - 1;
		else return mid;
	}

	return low;
}

int main(){
	vector<int> test = {1,2,3,4,5,6,12,34,53};
	cout << "array : ";
	for(int i = 0; i < test.size(); i++){
		cout << test[i] << "\t";
	}	
	cout << endl;

	int target = -1;
	cout << "target : " << target << endl;
	cout << binarySearch(test, target) << endl;
	return 0;
}
