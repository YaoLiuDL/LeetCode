/**************************************************************
Copyright : CNIC
Author: LiuYao
Date: 2017-9-4
Description: leetcode 167. Two Sum II - Input array is sorted 
**************************************************************/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

/**
 * Method 1:
 * Use a hash map to store the mapping from the needed number to the index.
 * time: O(n), space: O(n)
 */
vector<int> twoSum1(vector<int>& numbers, int target) {
    //the mapping from the needed number to the index
    unordered_map<int, int> map;

    for(int i = 0; i < numbers.size(); i++){
        if(map.find(numbers[i]) != map.end()) return {map[numbers[i]] + 1, i + 1};
        map[target - numbers[i]] = i;
    }
}

/**
 * Method 2: 
 * Use one pointer on the head and another pointer in the end to scan the array.
 */
vector<int> twoSum2(vector<int>& numbers, int target) {
    int front = 0, back = numbers.size() - 1, sum = 0;
    while(front < back){
        sum = numbers[front] + numbers[back];
        if(sum > target) back--;
        else if(sum < target) front++;
        else return {front + 1, back + 1};
    }
}