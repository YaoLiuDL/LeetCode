#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void getSubsets(vector<int>& nums, int next, vector<vector<int> >& results){
	if(next < 0) {
		results.push_back(vector<int>(0));
		return;
	}
	getSubsets(nums, next - 1, results);
	for(int i = results.size() - 1; i > -1 ; i--){
		vector<int> temp = vector<int>(results[i]);
		temp.push_back(nums[next]);
		results.push_back(temp);
	}

}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int> > results = vector<vector<int>>(0, vector<int>(0));        
	getSubsets(nums, nums.size() - 1, results);
	return results;
}

int main(){
	vector<int> test = {1,2,3};
	vector<vector<int>> results = subsets(test);
	return 0;
}
