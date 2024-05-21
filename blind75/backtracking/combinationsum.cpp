class Solution {
    void combination(vector<int> &arr, int ind, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(ind == arr.size())return;

        if(target-arr[ind] >= 0){
            temp.push_back(arr[ind]);
            combination(arr, ind,target-arr[ind],ans,temp);
            temp.pop_back();
        }
        combination(arr, ind+1, target, ans,temp);


    }



public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        combination(candidates, 0, target, ans, temp);
        return ans;
    }
};