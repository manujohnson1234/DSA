
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true


#include<string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        
        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int i =0; i < 26; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};