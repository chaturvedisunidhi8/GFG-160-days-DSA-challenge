class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];
            
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;
            }
            
            charIndexMap[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

