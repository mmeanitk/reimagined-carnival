class Solution {
public:
    int myAtoi(string s) {
         int i=0, sign=1;
        int ans=0;
        bool digitFound = false;
        while(i<s.size() && s[i]==' ') i++;
        
        if(i<s.size() && (s[i]=='+' || s[i]=='-')) {
            if(s[i]=='-') sign = -1;
            i++;
        }
        
        for(;i<s.size();i++) {
            if(s[i]>='0' && s[i]<='9') {
                if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (s[i]-'0')>INT_MAX%10)) {
                    if(sign==-1) return INT_MIN;
                    return INT_MAX;
                }
                ans = ans*10 + (s[i]-'0');
            }
            else break;
        }
        
        ans*= sign;
        return ans;
    }
};
//O(N)
//O(M)
