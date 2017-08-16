#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

void sortColors(vector<int>& nums){
	if(nums.empty()) return;
	int left = 0, medium = 0, right = nums.size() - 1;

	while(medium <= right){
		if(nums[medium] == 0) swap(nums[medium], nums[left++]);
		else if(nums[medium] == 2) swap(nums[medium], nums[right++]);
		else medium ++;
	}
}

int main(){
	vector<int> test = {0};
	for(int i = 0; i < test.size(); i++){
		cout << test[i] << "\t";
	}
	cout << endl;
	return 0;
}
