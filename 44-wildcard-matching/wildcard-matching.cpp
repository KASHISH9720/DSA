class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.size()) {
            // Characters match or '?'
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Found '*'
            else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }
            // Backtrack to last '*'
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }
            // No match
            else {
                return false;
            }
        }

        // Skip remaining '*'
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};