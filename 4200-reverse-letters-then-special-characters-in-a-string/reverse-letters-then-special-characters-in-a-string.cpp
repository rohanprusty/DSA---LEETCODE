class Solution {
public:
    string reverseByType(string s) {
        int l=0,r=s.length()-1;
        while(l<=r)
        {
            if(!(s[l]>='a' && s[l]<='z'))
            {
                l++;
                continue;
            }
            if(!(s[r]>='a' && s[r]<='z'))
            {
                r--;
                continue;
            }
            swap(s[l],s[r]);
            l++;
            r--;
        }
        l=0,r=s.length()-1;
        while(l<=r)
        {
            if((s[l]>='a' && s[l]<='z'))
            {
                l++;
                continue;
            }
            if((s[r]>='a' && s[r]<='z'))
            {
                r--;
                continue;
            }
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};