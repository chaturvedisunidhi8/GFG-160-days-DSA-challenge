// Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
// If there is no non-repeating character, return '$'.
// Note: When you return '$' driver code will output -1.


class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> vis(26,-1);
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(vis[idx]==-1){
                vis[idx]=i;
            } else{
                vis[idx]=-2;
            }
        }
        int minindex=INT_MAX;
        for(int i=0; i<26;i++){
            if(vis[i]>=0){
                minindex=min(minindex,vis[i]);
            }
        }
        return(minindex ==INT_MAX)?'$':s[minindex];
        
    }
};
