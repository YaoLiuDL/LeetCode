#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

vector<int> searchRange(vector<int>& nums, int target){
	vector<int> res(2, -1);
       	if(!nums.size()) return res;
       	int left = 0, right = nums.size() - 1;
       	while(left < right){
       		int mid = (left + right) / 2;
       		if(nums[mid] < target) left = mid + 1;
       		else right = mid;
       	}
       	if(nums[left] != target) return res;
       	else res[0] = left;
       	
       	right = nums.size() - 1;
       	while(left < right){
       		int mid = (left + right) / 2 + 1;
       		if(nums[mid] > target) right = mid - 1;        		
		else left = mid;
       	}
       	res[1] = right;
       	return res;
}

int main(){
	vector<int> test = {-1};
	int target = 0;
	vector<int> res = searchRange(test, target); 
	cout << "("<< res[0] << "," << res[1] << ")"<< endl;
	return 0;
}
