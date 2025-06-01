// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        int countOne=0;
        int countZero=0;
        int maxCountZero=0;
        int maxCountOne=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                countOne++;
                countZero=0;
            }
            else{
                countZero++;
                countOne=0;
            }
            
            maxCountZero = max(maxCountZero, countZero);
            maxCountOne = max(maxCountOne, countOne);
        }
        return max(maxCountOne,maxCountZero);
    }
};