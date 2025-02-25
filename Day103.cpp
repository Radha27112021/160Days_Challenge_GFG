class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int> st;
        vector<int> left(n,-1),right(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            right[i]=st.top();
        }
        st.push(i);
    }
    int mx=0;
    for(int i=0;i<n;i++){
        int width=right[i]-left[i]-1;
        int area=width*arr[i];
        mx=max(area,mx);
    }
    return mx;
 }
};
