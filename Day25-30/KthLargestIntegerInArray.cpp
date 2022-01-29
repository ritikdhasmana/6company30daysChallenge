class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(begin(nums),end(nums),[](string &a, string &b){
            if(a.size()>b.size())return true;
            if(a.size()<b.size())return false;
            return a>b;
        });
        return nums[k-1];
    }
};