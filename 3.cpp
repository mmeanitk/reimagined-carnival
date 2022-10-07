class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128,-1);
        
        int pos=0, curr_len=0, max_len = 0;
        for(int i=0;i<s.size();i++) {
            if(count[s[i]]!=-1) {
                if(pos<count[s[i]]+1) pos = count[s[i]]+1;
            }
            count[s[i]] = i;
            curr_len = (i-pos+1);
            max_len = max(max_len, curr_len);
        }
        count.clear();
        return max_len;
    }
};
