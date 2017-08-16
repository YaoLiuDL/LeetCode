#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::cout;


int threeSumClosest(vector<int> nums, int target){
	if(nums.size() < 3) return 0;
	
	std::sort(nums.begin(), nums.end());
	
	int cloest = nums[0] + nums[1] + nums[2];
	for(int i=0; i < nums.size(); i++){
		int need = target - nums[i];
		int front = i + 1;
		int back = nums.size() - 1;
		
		while(front < back){
			int sum = nums[front] + nums[back];
			if(abs(need - sum) < abs(cloest - target))
				cloest = nums[i] + nums[front] + nums[back];

			if(sum < need)  front++;
			else if(sum > need) back--;
			else break;
		}
	}

	return cloest;

}

int main(){
	// vector<int> test = {1,2,4,8,16,32,64,128};
	// int target = 82;
	vector<int> test = {0, 1, 2};
	int target = 0;
	cout <<	threeSumClosest(test, target) << std::endl;
	return 0;
}
