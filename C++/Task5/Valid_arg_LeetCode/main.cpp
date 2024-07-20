class Solution {
public:
    bool isAnagram(string s, string t){ 
        int freq1[28] {0} , freq2[28] {0};
       
        if(s.length() != t.length())
            return false;
    
        for(int i = 0 ; s[i] != '\0' ; i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        for(int i = 0 ; i < 28 ; i++)
            if(freq1[i] != freq2[i] )
                return false;
        return true;
    }
};
