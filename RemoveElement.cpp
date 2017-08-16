#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int removeElement(vector<int> nums, int val){
	int cnt = 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] == val) cnt++;
		else nums[i - cnt] = nums[i];
	}
	return nums.size() - cnt;
}

int main(){
	vector<int> test = {3,2,2,3};
	int val = 3;
	cout << removeElement(test, val) << endl;
	return 0;
}

