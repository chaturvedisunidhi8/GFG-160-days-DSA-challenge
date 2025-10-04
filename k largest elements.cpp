class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : arr) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        sort(result.rbegin(), result.rend());
        return result;
    }
};
