#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort():
// void combination(vector<int>&, int, vector<vector<int> >, vector<int>&, int);

void combinate(vector<int>& candinates, int target, vector<vector<int> >& res, vector<int>& combination, int begin){
	if(!target){
		res.push_back(combination);
		return;
	}
	for(int i = begin; i < candinates.size() ; i++){
		combination.push_back(candinates[i]);
		if(i && candinates[i] == candinates[i-1]) continue;
		if(target - candinates[i] >= 0)
			combinate(candinates, target - candinates[i], res, combination, i + 1);
		combination.pop_back();
		

	}
}
vector<vector<int> > combinationSum2(vector<int>& candinates, int target){
	sort(candinates.begin(), candinates.end());
	vector<vector<int> > res;
	vector<int> combination;
	combinate(candinates, target, res, combination, 0);
	return res;
}



int main(){
	vector<int> test = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	vector<vector<int> > res = combinationSum(test, target);
        for(int i = 0; i < res.size(); i++){
		cout << endl;
		vector<int> temp = res[i];
		for(int j = 0; j < temp.size(); j++){
			cout << temp[j] << "\t";
		}
	}	
	system("pause");
	return 0;
}
