class Solution {
public:
    bool isValid(string s) {
        
        if (s.size() % 2 != 0)  return false;
        std::stack<char> st;

        // "{}}{"
        for (const auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty())
                    return false;
                if (c == ')') {
                    char tmp = st.top();
                    if (tmp == '(') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else if (c == ']') {
                    char tmp = st.top();
                    if (tmp == '[') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else if (c == '}') {
                    char tmp = st.top();
                    if (tmp == '{') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {}
            }
        }

        if (st.size() != 0) return false;

        return true;

    }
};
