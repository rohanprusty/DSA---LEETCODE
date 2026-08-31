class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first=0;
        int second=0;
        if(s.length()==0) return true;
        while(first<s.length() && second<t.length()){
            if(s[first]==t[second]){
                first++;
                second++;
            }
            else{
                second++;
            }
        }
        if(first==s.length()) return true;
        else return false;
    }
};