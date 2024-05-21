//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

//Example 1:

//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(int i =0; i < strs.size(); i++){
            string dup = strs[i];
            sort(dup.begin(), dup.end());
            mp[dup].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};