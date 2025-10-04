// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
// Note: Return an empty list in case of no occurrences of pattern.



class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> res;
        int m =pat.length(), n=txt.length();
        vector<int> lps(m,0);
        int len =0;
        for(int i =1;i<m;){
            if(pat[i]==pat[len]){
                lps[i++] =++len;
            } else if(len>0){
                len =lps[len-1];
            } else{
                lps[i++]=0;
            }
        }
        int i =0,j=0;
        while(i<n){
            if(txt[i] == pat[j]){
                i++; j++;
            }
            if(j ==m){
                res.push_back(i-j);
                j=lps[j-1];
            } else if(i<n && txt[i] !=pat[j]){
                if(j>0)
                    j=lps[j-1];
                else
                i++;
            }
        }
        return res;
    }
};
