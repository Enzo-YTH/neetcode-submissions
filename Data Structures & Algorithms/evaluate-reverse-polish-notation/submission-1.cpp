class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1)
            return std::stoi(tokens[0]);
        
        vector<int> num_list;
        for (int i = 0; i < tokens.size(); i++) {
            int a, b;
            if (tokens[i] == "+") {
                a = num_list.back();
                num_list.pop_back();
                b = num_list.back();
                num_list.pop_back();
                num_list.push_back(b + a);
            }
            else if (tokens[i] == "-") {
                a = num_list.back();
                num_list.pop_back();
                b = num_list.back();
                num_list.pop_back();
                num_list.push_back(b - a);
            }
            else if (tokens[i] == "*") {
                a = num_list.back();
                num_list.pop_back();
                b = num_list.back();
                num_list.pop_back();
                num_list.push_back(b * a);
            }
            else if (tokens[i] == "/") {
                a = num_list.back();
                num_list.pop_back();
                b = num_list.back();
                num_list.pop_back();
                num_list.push_back(b / a);
            }
            else {
                num_list.push_back(std::stoi(tokens[i]));
            }
        }

        return num_list.back();
    }
};
