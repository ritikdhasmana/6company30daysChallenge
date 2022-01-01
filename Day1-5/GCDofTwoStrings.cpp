//link- https://leetcode.com/problems/greatest-common-divisor-of-strings/


//question-

//For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
//Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2


class Solution {
public:
    string gcdOfStrings(string a, string b) {
        return (a + b== b + a)  ? a.substr(0, gcd(a.length(), b.length())): "";
    }
};