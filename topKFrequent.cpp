/****************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-29
Description : 347. Top K Frequent Elements 
****************************************************/
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

using std::vector;
using std::unordered_map;
using std::map;
using std::pair;
using std::sort;
using std::priority_queue;
using std::make_pair;

/**
 * sort the pair element as ascent
 */ 
bool compartor(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

/**
 * Method 1 : 
 * Use sort function to sort the frequent
 */
vector<int> topKFrequent1(vector<int>& nums, int k) {
    //the mapping from number to the frequent
    unordered_map<int, int> num2freq;
    //the list of the number and the frequent pair
    vector<pair<int, int>> pairs;

    //First step : get the frequent of each integer
    for(int num : nums){
        num2freq[num]++;
    }

    //Second step : build the mapping from the frequent to the integer
    for(auto pair : num2freq){
        pairs.push_back(pair);
    }
    
    sort(pairs.begin(), pairs.end(), compartor);

    //Third step : get the top k key in the map which automatically sorts the key
    vector<int> res;
    int i = 0;
    for(int i = 0; i < k; i++){
        res.push_back(pairs[i].first);
    }
    
    return res;
} 

/**
 * Method 2 : 
 * Use priority container to get the top k element
 */
vector<int> topKFrequent2(vector<int>& nums, int k){
    //the mapping from the number to the frequent
    unordered_map<int, int> map;

    //First step : get the fr
    for(auto num : nums){
        map[num]++;
    }

    vector<int> res;
    priority_queue<pair<int, int>> pq;
    for(auto pair : map){
        pq.push(make_pair(pair.second, pair.first));
        if(pq.size() > map.size() - k){
            res.push_back(pq.top().second);
            pq.pop();
        }
            
    } 

    return res;
}

int main(){
    vector<int> nums = {1, 2};
    vector<int> res = topKFrequent2(nums, 2);
    return 0; 
}