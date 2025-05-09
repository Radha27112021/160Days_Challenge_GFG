class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int s=0, e=arr.size()-1;
        int diff =INT_MAX;
        vector<int> ans;
        while(s<e){
            int pairsum =arr[s]+arr[e];
            if(abs(target-pairsum)<diff){
                diff= min(abs(target-pairsum),diff);
                ans={arr[s],arr[e]};}
                if(pairsum<target) s++;
                else if(pairsum>target) e--;
                else return ans;
            }
            return ans;
        
        
    }
};
