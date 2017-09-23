/**********************************************************
Copyright: CNIC
Author: LiuYao
Date: 2017-9-7
Description: leetcode 215. Kth Largest Element in an Array 
**********************************************************/

#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::priority_queue;
using std::swap;
using std::greater;

/**
 * Method 1:
 * Use a max heap of n-k size
 * time: O(nlog(n-k)), space O(n-k) 
 */
int findKthLargest1(vector<int>& nums, int k) {
    priority_queue<int> pq;
    int top_k = INT_MAX;
    for(auto i : nums){
        pq.push(i);
        if(pq.size() > nums.size() - k){
            if(pq.top() < top_k) top_k = pq.top();
            pq.pop();
        }
    }
    return top_k;
}

/**
 * Method 2:
 * Force search, put the top i element in the i-1 postion 
 * time: O(kn), space: O(1)
 */
 int findKthLargest2(vector<int>& nums, int k) {
    int top_idx;
    for(int j = 0; j < k; j++){
        top_idx = 0 + j;
        for(int i = 1 + j; i < nums.size(); i++){
            if(nums[i] > nums[top_idx]) top_idx = i;
        }
        swap(nums[0 + j], nums[top_idx]);
    }
    return nums[k - 1];
}

bool comparator(int x1, int x2){
    return x1 > x2;
}

/**
 * Method 3:
 * stay a min heap, the top element is the result.
 * time: O(nlogk), space: O(k)
 */
int findKthLargest3(vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++){
        pq.push(nums[i]);
    }

    for(int i = k; i < nums.size(); i++){
        if(nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main(){
    return 0;
}