/****************************
 * Copyright: CNIC
 * Author: LiuYao
 * Date: 2017-9-18
 * Description: leetcode 282. Expression Add Operators
****************************/
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <set>

using std::vector;
using std::unordered_map;
using std::string;
using std::atoi;
using std::cout;
using std::endl;
using std::set;

struct Formula{
	string str;
	int value;
	Formula(string str, int value) : str(str), value(value){}
};

vector<Formula> getFormulas(string num, unordered_map<string, vector<Formula>>& map){
	vector<Formula> result;
	for(int i = 1; i < num.size(); i++){
		char ch = num[i];
		vector<Formula> left, right;
		string num1 = num.substr(0, i), num2 = num.substr(i);
		if(map.find(num1) != map.end())
			left = map[num1];
		else
			left = getFormulas(num1, map);
		if(map.find(num2) != map.end())
			right = map[num2];
		else 
			right = getFormulas(num2, map);
		for(Formula left_formula : left){
			for(Formula right_formula : right){
				result.push_back(Formula(left_formula.str + "+" + right_formula.str, 
								left_formula.value + right_formula.value));
				result.push_back(Formula(left_formula.str + "-" + right_formula.str,
							left_formula.value - right_formula.value));
				result.push_back(Formula(left_formula.str + "*" + right_formula.str,
							left_formula.value * right_formula.value));
			}
		}
	}
	if(result.empty()) result.push_back(Formula(num, atoi(num.c_str())));
	map[num] = result;
	return result;
}

vector<string> addOperators(string num, int target){
	unordered_map<string, vector<Formula>> map;
	vector<Formula> formulas = getFormulas(num, map);
	vector<string> result;
	for(auto formula : formulas){
		if(formula.value == target)
			result.push_back(formula.str);
	}
	set<string> s = set<string>(result.begin(), result.end());
	result = vector<string>(s.begin(), s.end());
	return result;
}

int main(){
	vector<string> result = addOperators("123", 6);
	for(auto str : result){
		cout << str << endl;
	}
	return 0;
}

