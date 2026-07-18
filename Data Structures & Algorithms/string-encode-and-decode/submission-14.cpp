class Solution {
public:

    string encode(vector<string>& strs) {

        string ret;
        for(const auto& s : strs) {
            ret += std::to_string(s.size());
            ret += '#';
            ret += s;
            //printf("%s\n", ret.c_str());
        }

        return ret;  // 5#Hello5#World, 0#
    }

    vector<string> decode(string s) {
        vector<string> ret;
        bool decode_mode = 0;
        string decode_str = "";
        int num = 0;
        string num_str = "";
        for(const auto& c : s) {
            if(decode_mode == 1) {
                decode_str += c;
                num -= 1;
                if(num == 0) {
                    decode_mode = 0;
                    ret.push_back(decode_str);
                    decode_str = "";
                }         
            }
            else { // decode_mode = 0
                if(c != '#') {
                    num_str += c;
                }
                else {
                    num = std::stoi(num_str);
                    decode_mode = 1;
                    num_str = "";
                    if(num == 0) {
                        ret.push_back("");
                        decode_mode = 0;
                    }
                }
            }
        }
        return ret;
    }
};
