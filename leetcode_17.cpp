// Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {

    void backtrack(string digits, unordered_map<char, string> &mp, int ind, string a, vector<string> &ans){
        if(ind == digits.size()){
            ans.push_back(a);
            return;
        }

        for(int i =0; i < mp[digits[ind]].size(); i++){
            a += mp[digits[ind]][i];
            backtrack(digits, mp, ind+1, a, ans);
            a.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};


        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";


        vector<string> ans;
        string a = "";
        backtrack(digits, mp, 0, a, ans);
        return ans;

    }
};


int main(){
    string digits;
    cin >> digits;

    Solution sol;

    vector<string> ans = sol.letterCombinations(digits);

    for(auto it: ans){
        cout << it << " ";
    }

}