// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i =0; i < nums.size(); i++){
            if(i > 0 && nums[i-1] == nums[i])continue;

            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int val = nums[i] + nums[j] + nums[k];
                if(val == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j])j++;
                    while(k > j && nums[k+1] == nums[k])k--;
                }else if(val < 0){
                    j++;
                }else{
                    k--;
                }
            }
            
        }

        return ans;

    }
};