#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if (n== 0) return "";
        // compteur yabda men awel chaine 
        int i=0;
        // temchi bel ma9loub 3l chaine bech tal9a atwel prefix ymatchi suffix 
        for (int j=n-1; j>=0;j--) {
            if (s[j]==s[i]) {
                i++;
            }
        }
        // itha ken wselna lel n m3neha chaine kemla palindrome
        if (i==n) {
            return s;
        }
        // 'suf' heya l partie eli mahich palaindrome
        string suf=s.substr(i);
        string rs=suf;
        reverse(rs.begin(), rs.end());
        // tkamel l be9i bel recursivite s[0...i-1]
        return rs + s.substr(0,i)+suf;
    }
};
