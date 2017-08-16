#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::vector;

vector<vector<int> > treeSum(vector<int> nums){
	std::sort(nums.begin(), nums.end());
	vector<vector<int> > res;
	for(int i = 0; i < nums.size(); i++){
		int target = 0 - nums[i];

		int front = i + 1;
		int back = nums.size() - 1;
		
		
		while(front < back){
			int sum = nums[front] + nums[back];
			if(sum < target) front++;
			else if(sum > target) back--;
			else{
				vector<int> temp(3, -1);
				temp[0] = nums[i];
				temp[1] = nums[front];
				temp[2] = nums[back];
				res.push_back(temp);
	
				while(front < back && nums[front] == temp[1]) front++;
				while(front < back && nums[back] == temp[2]) back--;
			}
		}
		while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
	}

	return res;
}

int main(){
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	std::cout << "result";
	vector<vector<int> > res = treeSum(nums);
	
	for(int j=0; j < res.size(); j++){
		for(int i=0; i < 3; i++){
			std::cout << res[j][i] << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}
