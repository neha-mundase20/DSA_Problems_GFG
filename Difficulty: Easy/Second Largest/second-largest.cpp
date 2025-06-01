class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int first = INT_MIN;
        int second = INT_MIN;

        for (int num : arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num < first && num > second) {
                second = num;
            }
        }

        return (second == INT_MIN) ? -1 : second;
    }
};