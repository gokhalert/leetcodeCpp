class Solution {
    int getOnes(int n) {
        int ans = 0;
        while(n) {
            ans += n & 0x1;
            n >>= 1;
        }
        return ans;
    }
    void populateMap(map<int, vector<string>>& map, int limit, bool mMap = false) {
        for(int h = 0; h <= limit; h++) {
            int numOnes = getOnes(h);
            auto s = to_string(h);
            if(mMap) if(s.length() == 1) s = "0" + s;
            map[numOnes].push_back(s);
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        // K = Number of ON LEDs, V = a set of strings representing the possible hours/ mins for that K
        map<int, vector<string>> hMap, mMap;
        populateMap(hMap, 11);
        populateMap(mMap, 59, true);
        
        vector<string> res;
        
        for(int h = 0; h <= num && h <= 4; h++) {
            if(hMap.find(h) == hMap.end()) continue;
            auto hours = hMap[h];
            
            int m = num - h;            
            if(mMap.find(m) == mMap.end()) continue;
            auto minutes = mMap[m];
            
            for(auto mn : minutes) {
                for(auto hr : hours) {
                    string s = "";
                    s += hr;
                    s += ":";
                    s += mn;
                    res.push_back(std::move(s));
                }
            }
        }
        
        return res;
    }
};
