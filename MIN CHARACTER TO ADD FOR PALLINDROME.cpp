//Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.
//Note: A palindrome string is a sequence of characters that reads the same forward and backward.


class Solution {
  public:
    int minChar(string& s) {
        // Write your code h
        string rev= s;
        reverse(rev.begin(),rev.end());
        string complete=s+'$'+rev;
        int n=complete.length(),i=0,j=1;
        vector<int> lps(n,0);
        
        while(j<n){
            if(complete[i]==complete[j]) lps[j++]=++i;
            else if(i!=0)i=lps[i-1];
            else j++;
            
            
        }
        
        return s.length()-i;
        
    }
};

