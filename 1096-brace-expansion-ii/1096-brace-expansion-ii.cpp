class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> result;
        vector<set<string>> groups;

        set<string> current;
        current.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                for (auto x : current)
                    result.insert(x);

                current.clear();
                current.insert("");
                i++;
            }

            else if (s[i] == '{') {
                i++; // skip {

                set<string> inside = solve(s, i);

                set<string> temp;

                for (auto a : current) {
                    for (auto b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;

                i++;
            }

            else {
                string ch(1, s[i]);
                set<string> temp;

                for (auto x : current) {
                    temp.insert(x + ch);
                }

                current = temp;

                i++;
            }
        }

        for (auto x : current)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};