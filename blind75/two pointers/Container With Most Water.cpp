// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;

        int l = 0;
        int h = height.size()-1;


        while(l < h){
            
            int len = min(height[l], height[h]);
            int bre = h - l;

            ans = max(ans, len * bre);

            if(height[l] >= height[h]){
                h--;
            }else{
                l++;
            }
        }

        return ans;
    }
};