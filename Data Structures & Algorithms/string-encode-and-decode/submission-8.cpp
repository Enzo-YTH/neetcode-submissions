class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())
            length.push_back(-1);
        string res;
        for(const auto& s : strs) {
            res += s;
            length.push_back(s.size());
        }
        return res;
    }

    vector<string> decode(string s) {
        if(length[0] == -1)
            return {};
        vector<string> res;
        string temp;
        int idx = 0, cnt = 0;
        for(const auto& c : s) {
            if(cnt == length[idx]) {
                res.push_back(temp);
                temp = "";
                cnt = 0;
                ++idx;
                while(true) {
                    if(length[idx] == 0) {
                        res.push_back("");
                        ++idx;
                    }
                    else
                        break;
                }
            }
            temp += c;
            ++cnt;
        }
        res.push_back(temp);
        return res;
    }
private:
    vector<int> length;
};
