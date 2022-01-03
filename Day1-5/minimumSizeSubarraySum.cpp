//link -https://leetcode.com/problems/minimum-size-subarray-sum/

//question -
//Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=INT_MAX,w=0;
        int cursum=0;
        for(int i=0;i<nums.size();i++){
            cursum += nums[i];
            while(cursum>=target){
                l = min(l,i-w+1);
                cursum -= nums[w++];
            }
        }
        // while(cursum >= target)
        return l==INT_MAX? 0 : l;
    }
};