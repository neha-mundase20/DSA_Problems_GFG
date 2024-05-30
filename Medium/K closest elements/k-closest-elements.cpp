//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
private:
    struct Element {
        int value;
        int difference;
    };

public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<Element> elements;

        // Filter out x if it exists in the array and compute differences
        for (int i = 0; i < n; ++i) {
            if (arr[i] != x) {
                elements.push_back({arr[i], abs(arr[i] - x)});
            }
        }

        // Sort elements based on the custom criteria using a lambda function
        sort(elements.begin(), elements.end(), [](const Element &a, const Element &b) {
            if (a.difference == b.difference) {
                return a.value > b.value; // If differences are the same, prioritize the greater element
            }
            return a.difference < b.difference; // Otherwise, prioritize the smaller difference
        });

        // Collect the top K closest elements
        vector<int> result;
        for (int i = 0; i < k && i < elements.size(); ++i) {
            result.push_back(elements[i].value);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends