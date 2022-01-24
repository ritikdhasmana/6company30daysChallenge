//link- https://leetcode.com/problems/find-in-mountain-array/

//question-
/*
This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.
*/


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mtn) {
        int n = mtn.length(), l, r, m, peak = 0;
        l  = 0;
        r = n - 1;
        while(l<r){
            m = l + (r-l)/2;
            if(mtn.get(m)<mtn.get(m+1)){
                l=m+1;
                peak =l;
            }else r = m;
            
        }
        
        l = 0, r = peak;
        while(l<r){
            m=(l+r)/2;
            if(mtn.get(m)>=target)r = m;
            else l = m+1;
        }
        if(mtn.get(l)==target)return l;
        l = peak;
        r = n - 1;
        while (l <r) {
            m = (l + r) / 2;
            if (mtn.get(m) > target)
                l = m + 1;
            else if (mtn.get(m) <= target)
                r = m ;
           
        }
        if(mtn.get(l)==target)return l;
        return -1;
    }
};
