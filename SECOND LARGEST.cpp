//Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        if (n < 2) return -1;
        
        int first = INT_MIN, second = INT_MIN;
        
        for (int num:arr){
            if(num>first){
                second = first;
                first = num;
            } else if (num>second && num< first) {
                second = num;
            }
       
        }
        return (second == INT_MIN ) ? -1 : second;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

