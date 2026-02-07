class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map1;
        unordered_map<string,char> map2;

        vector<string> words;
        stringstream ss(s); // y string ko alg alg words me jd dega taaki ek element ek word ko map kr ske
        string temp;

        while(ss >> temp)
        {
            words.push_back(temp);
        }

        if(pattern.length() != words.size())
        {
            return false;
        }


        for(int i = 0; i < pattern.length(); i++)
        {
            char c = pattern[i];
            string word = words[i];

            if(map1.count(c))
            {
                if(map1[c] != word)
                {
                    return false;
                }
            }
                else
                {
                    map1[c] = word;
                }
            if(map2.count(word))
            {
                if(map2[word] != c)
                {
                    return false;
                }
            }
                else
                {
                    map2[word] = c;
                }
        }
        return true;
    }
};