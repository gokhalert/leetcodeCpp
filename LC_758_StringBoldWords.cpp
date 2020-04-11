class Solution {
    void findAll(string const& w, string const& s, vector<int>& mask) {
        auto pos = 0;
        while(1) {
            pos = s.find(w, pos);
            if(pos == string::npos) break;
            mask[pos]++;
            mask[pos + w.length()]--;
            pos++;
        }
    }
public:
    string boldWords(vector<string>& words, string S) {
        vector<int> mask;
        mask.resize(S.length() + 1);
        
        for(auto w : words) {
            findAll(w, S, mask);
        }
        string res = "";
        int og = 0;
        for(int i = 0; i < mask.size(); i++) {
            int prevOg = og;
            og += mask[i];
            if(og > 0 && prevOg == 0) {
                res += "<b>";
            } else if (og == 0 && prevOg > 0) {
                res += "</b>";
            }
            if(i != S.length()) res += S[i];
        }
        return res;
    }
};
