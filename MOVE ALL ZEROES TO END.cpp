/*You are given an array arr[] of non-negative integers.
  Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. 
  The operation must be performed in place, meaning you should not use extra space for another array.*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int j=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0)
            {
                arr[j++]=arr[i];
            }
        }
        
        while(j<arr.size())
        {
            arr[j++]=0;
        }
        
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
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends

