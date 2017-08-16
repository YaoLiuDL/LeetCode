#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::vector;

int removeDuplicates(vector<int>& nums){
	if(nums.size() < 2) return nums.size();
	int i = 0;
	int j = i + 1;
	while(j < nums.size()){
		if(nums[j] == nums[i]) j++;
		else{
			if(i + 1 != j){
				int temp = nums[i + 1];
				nums[i + 1] = nums[j];
				nums[j] = temp;
			}
			i++;
			j++;
		}
	}
	return i + 1;
}

int main(){
	vector<int> test = {1,1,2,3,3,4,4,4};
	cout << removeDuplicates(test) << endl;
}
