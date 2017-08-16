#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

void jumpIn(vector<int>& nums, int count, int begin, int& value){
    if(begin == nums.size() - 1) {
        if (count < value) value = count;
        return;
    }
    for(int i = 1; i <= nums[begin]; i++){
        if(begin + i < nums.size()){
            jumpIn(nums, ++count, begin + i, value);
            count--;
        }
        else break;
    }
}

int jump(vector<int>& nums){
    int count = 0;
    int begin = 0;
    int value = INT_MAX;
    jumpIn(nums, count, begin, value);
    return value;
}

int main(){
    vector<int> test = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    cout << jump(test) << endl;
    return 0;
}