class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for(const auto& s : strs) {
            ret += std::to_string(s.size());
            ret += '#';
            ret += s;
            //printf("%s\n", ret.c_str());
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string num;
        string e = "";
        int number = -1;
        int jump_mode = 0;
        for(const auto ch : s) {
            if(number == -1) jump_mode = 0;
            else jump_mode = 1;

            if(!jump_mode) {

                if(ch != '#')
                    num += ch;
                else{
                    number = std::stoi(num);
                    num = "";
                    if(number == 0) {
                        ret.push_back("");
                        number = -1;
                    }
                }
            }
            else {
                e += ch;
                number--;
                if(number == 0) {
                    ret.push_back(e);
                    e = "";
                    number = -1;
                }
            }
        }

        return ret;
    }
};
