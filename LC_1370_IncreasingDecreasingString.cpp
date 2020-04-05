class Solution {
public:
    string sortString(string s) {
        map<char, int> map;
        for(auto c : s) map[c]++;
        
        string res;
        auto empty = false;
        while(!empty) {
            empty = true;
            for(auto it = map.begin(); it != map.end(); it++) {
                if(it->second > 0) {
                    res += it->first;
                    it->second--;
                    empty = false;
                }
            }
            
            empty = true;
            for(auto it = map.rbegin(); it != map.rend(); it++) {
                if(it->second > 0) {
                    res += it->first;
                    it->second--;
                    empty = false;
                }
            }      
        }
        return res;      
    }
};
