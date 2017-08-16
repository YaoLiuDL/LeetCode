#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


void search(vector<int>& nums, int target, vector<vector<int> >& res, vector<int>& combination, int begin){
	if(!target){
		res.push_back(combination);
		return;
	}

	for(int i = begin; i < nums.size(); i++){
		combination.push_back(nums[i]);
		if(target - nums[i] >= 0)
			search(nums, target - nums[i], res, combination, i);
		combination.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int>& nums, int target){
	vector<vector<int> > res;
	vector<int> combination;
	search(nums, target, res, combination, 0);
	return res;
}
int main(){
	vector<int> test = {8,7,4,3};
	int target = 11;
	vector<vector<int> > res = combinationSum(test, target);
        for(int i = 0; i < res.size(); i++){
		cout << endl;
		vector<int> temp = res[i];
		for(int j = 0; j < temp.size(); j++){
			cout << temp[j] << "\t";
		}
	}	
	return 0;
}
