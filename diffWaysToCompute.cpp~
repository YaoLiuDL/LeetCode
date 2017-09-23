#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

using std::string;
using std::vector;
using std::atoi;
using std::ordered_map;

/**
 * Method 1: 
 * use the recursive to compute
 */
vector<int> diffWaysToCompute1(string input){
	int size = input.size();
	vector<int> result;
	for(int i = 0; i < size; i++){
		char ch = input[i];
		vector<int> left, right;
		if(ch == '+' || ch == '-' || ch == '*'){
			left = diffWaysToCompute(input.substr(0, i));
			right = diffWaysToCompute(input.substr(i+1));
			for(auto n1 : left){
				for(auto n2 : right){
					if(ch == '+') result.push_back(n1 + n2);
					else if(ch == '-') result.push_back(n1 - n2);
					else result.push_back(n1 * n2);
				}
			}	
		
		}
	}
	if(result.size() == 0) result.push_back(atoi(input.c_str());
	return result;
} 

vector<int> diffWaysToCompute2(string input){
	unordered_map<string, vector<int>> map;
	return compute(input, map);
}

vector<int> compute(string str, unordered_map<string, vector<int>>& map){
	vector<int> result;
	for(int i = 0; i < str.size(); i++){
		char ch = str[i];
		vector<int> left, right;
		if(ch == '+' || ch == '-' || ch == '*'){
			string str1 = str.substr(0, i);
			string str2 = str.substr(i + 1);
			if(map.find(str1) != map.end())
				left = map[str1];
			else 
				left = compute(str1, map);
			if(map.find(str2) != map.end())
				right = map[str2];
			else 
				right = compute(str2, map);
			for(auto n1 : left){
				for(auto n2 : right){
					if(ch == '+') result.push_back(n1 + n2);
					else if(ch == '-') result.push_back(n1 - n2);
					else result.push_back(n1 * n2);
				}
			}
		}
	}
	if(result.empty()) result.push_back(atoi(str.c_str()));
	map[str] = result;
	return result;
}
