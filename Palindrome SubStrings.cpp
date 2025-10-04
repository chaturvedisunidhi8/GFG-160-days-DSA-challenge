class Solution {
public:
    int countPS(string s) {
        int n = s.length();
        int count = 0;

        for (int center = 0; center < n; ++center) {
            count += expandAroundCenter(s, center, center);
            count += expandAroundCenter(s, center, center + 1);
        }

        return count;
    }

private:
    int expandAroundCenter(string& s, int left, int right) {
        int cnt = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if ((right - left + 1) >= 2)
                cnt++;
            left--;
            right++;
        }
        return cnt;
    }
};
