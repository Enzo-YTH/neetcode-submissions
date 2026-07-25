class Solution {
public:
    bool isValid(string s) {
        string valid = "";
        for (const auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                valid += c;
            }
            else {
                if ((c == ')' && valid.back() == '(') || 
                    (c == ']' && valid.back() == '[') ||
                    (c == '}' && valid.back() == '{')) {
                        valid.pop_back();
                    }
                else {
                    return false;
                }   
            }
        }
        return (valid == "") ? true : false;
    }
};
