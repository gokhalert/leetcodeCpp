class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0;
        int pos = 0;
        map<char, int> map;
        for(auto c : keyboard) map[c] = pos++;
        
        int prevPos = 0;
        for(auto c : word) {
            res += (abs(map[c] - prevPos));
            prevPos = map[c];
        }
        return res;
    }
};
