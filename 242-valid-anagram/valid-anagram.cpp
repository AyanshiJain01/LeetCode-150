class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;

        if(s.length() != t.length())
        {
            return false;
        }

        for(char c : s)
        {
            map[c]++;
        }

        for(char c : t)
        {
            map[c]--;
            if(map[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};