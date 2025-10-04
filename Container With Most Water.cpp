class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 0, right = arr.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int area = height * width;
            maxArea = max(maxArea, area);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
