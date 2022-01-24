//link- https://leetcode.com/problems/split-array-largest-sum/

/*
question-
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.
*/


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l=0,r=0;
        l=*max_element(begin(nums),end(nums)), r= accumulate(begin(nums),end(nums),0);
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(nums,m-1,mid))r =mid-1;
            else l=mid+1;
        }
        return l;
    }
private :
    bool check(const vector<int>& nums, int cuts, long long max) {
        int acc = 0;
        for (auto num : nums) {

            if (num > max) return false;
            else if (acc + num <= max) acc += num;
            else {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
};
