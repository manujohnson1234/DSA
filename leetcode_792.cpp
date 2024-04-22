// Number of Matching Subsequences

//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// Input: s = "abcde", words = ["a","bb","acd","ace"]
// Output: 3

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {

    int upper(char a, map<char, vector<int>> &mp, int target){
        if(mp[a].size() == 0) return -1;

        int l = 0;
        int r = mp[a].size()-1;

        int ans = -1;

        while(l <= r){
            int m = (l+r) / 2;
            if(mp[a][m] == target){
                return target;
            }else if(mp[a][m] > target){
                ans = mp[a][m];
                r = m-1;
            }else{
                l = m + 1;
            }
        }

        // cout << ans

        return ans;
    }



public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> mp;

        for(int i=0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int cnt= 0;

        for(int i =0; i < words.size(); i++){
            bool ch = true;
            int prev = -1;
            for(int j =0; j < words[i].size(); j++){
                int val = upper(words[i][j], mp, prev+1);
                if(val == -1){
                    ch = false;
                    break;
                }
                prev = val;
            }
            if(ch) cnt++; 
        }
        return cnt;
    }
};

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> words(n);
    
    for(int i=0; i < n; i++){
        cin >> words[i];
    }

    Solution sol;
    cout << sol.numMatchingSubseq(s, words);

}