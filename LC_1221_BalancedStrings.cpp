class Solution {
public:
    int balancedStringSplit(string s) {
        auto lCount = 0;
        auto rCount = 0;
        auto ans = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'L') lCount++;
            else rCount++;
            
            if(lCount == rCount) {
                ans++;
                lCount = rCount = 0;
            }
        }
        return ans;
    }
};
