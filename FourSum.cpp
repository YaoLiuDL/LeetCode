#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
 
    for(int i = 0; i < nums.size(); i++){
        int three_sum = target - nums[i];

        for(int j = i + 1; j < nums.size(); j++ ){
            int two_sum = three_sum - nums[j];

            int front = j + 1;
            int back = nums.size() - 1;

            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum > two_sum) back--;
                else if(sum < two_sum) front++;
                else{
                    vector<int> oneAnswer;
                    oneAnswer.push_back(nums[i]);
                    oneAnswer.push_back(nums[j]);
                    oneAnswer.push_back(nums[front]);
                    oneAnswer.push_back(nums[back]);
                    res.push_back(oneAnswer);
                    while(front < back && nums[front] == oneAnswer[2]) front++;
                    while(back > front && nums[back] == oneAnswer[3]) back--;
                    
                }

            }

            while(j + 1 < nums.size() && nums[j + 1] == nums[j]) j++;
        }
        while( i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
    }

    return res;
}

int main(){
    vector<int> test = {0,0,5,3,-5};
    int target = 0;
    vector<vector<int>> res = fourSum(test, target);
    return 0;
}