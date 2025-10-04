//Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not.
//An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" are an anagram of each other. 
//Strings s1 and s2 can only contain lowercase alphabets.

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        
        // Your code here
        if(s1.length()!=s2.length()) return false;
        
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) return false;

        }
        
        return true;
        
        
        
        
    }
};
