class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
       int N = arr.size();
       if(N==1) return 0;
       sort(arr.begin(),arr.end());
       int inti_diff=arr[N-1]-arr[0];
       int result = inti_diff;
       int smallest , largest;
       for(int i =0; i<N-1; i++){
           smallest = min(arr[0]+k,arr[i+1]-k);
           largest = max(arr[N-1]-k, arr[i]+k);
           if(smallest >= 0){
               result = min(result, largest-smallest);
           }
       }
       return result;
    }
};
