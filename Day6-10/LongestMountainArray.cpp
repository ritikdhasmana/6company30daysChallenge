//link - https://leetcode.com/problems/longest-mountain-in-array/
//question-
/*You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
*/


class Solution {
public:
    int longestMountain(vector<int>& A) {
       int res = 0, up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (down && A[i - 1] < A[i] || A[i - 1] == A[i]) up = down = 0;
            up += A[i - 1] < A[i];
            down += A[i - 1] > A[i];
            if (up && down) res = max(res, up + down + 1);
        }
        return res;
    }
};