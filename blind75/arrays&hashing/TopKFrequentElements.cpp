#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        vector<int> adj[n+1];

        for(int i =0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            adj[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--){
            for(auto it: adj[i]){
                ans.push_back(it);
                k--;
                if(k == 0){
                    return ans;
                }
            }
        }
        return ans;
    }
};