#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> oneAnswer;
 
    for(int i = 0; i < nums.size(); i++){
        while(i > 0 && nums[i] == nums[i - 1]) continue;
        int three_sum = target - nums[i];
        oneAnswer.push_back(nums[i]);

        for(int j = i + 1; j < nums.size(); j++ ){
            while(j > 0 && nums[j] == nums[j - 1]) continue;
            int two_sum = three_sum - nums[j];
            oneAnswer.push_back(nums[j]);

            unordered_map<int, int> hash;
            for(int p = j + 1; p < nums.size(); p++){
                if(hash.find(nums[p]) != hash.end()){
                    oneAnswer.push_back(nums[hash[nums[p]]]);
                    oneAnswer.push_back(nums[p]);
                    res.push_back(oneAnswer);
                    oneAnswer.pop_back();
                    oneAnswer.pop_back();
                }
                hash[two_sum - nums[p]] = p;
            }
            oneAnswer.pop_back();
        }
        oneAnswer.pop_back();
    }

    return res;
}