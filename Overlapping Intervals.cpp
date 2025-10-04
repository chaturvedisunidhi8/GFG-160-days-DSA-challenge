// Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals


class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        for(auto& interval: arr){
            if (result.empty()||result.back()[1]< interval[0]){
                result.push_back(interval);
            } else{
                result.back()[1] = max(result.back()[1],interval[1]);
            }
        }
        return result;
    }
};
