class Solution {
    stack<int> st;
    int mini;
  public:

    Solution() {
        // code here
     while(!st.empty()) st.pop();
     mini=INT_MAX;
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
         if(st.empty()){
             mini=x;
             st.push(x);
         } else if(x<=mini){
             st.push(mini);
             mini=x;
         }
        st.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()) return;
        int temp=st.top();
        st.pop();
        if(temp==mini && !st.empty()){
            mini=st.top();
            st.pop();
        } 
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()) return -1;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty()) return -1;
        return mini;
    }
};
