 int myAtoi(char *s) {
        // Your code here
        int sign=1;
        long ans=0;
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]=='+' || s[i]=='-'){
            sign= (s[i]=='-')?-1:1;
            i++;
        }
       while(isdigit(s[i])){
           ans=ans*10+(s[i]-'0');
           if(sign*ans >= INT_MAX){
               return INT_MAX;
           }
           if(sign*ans<= INT_MIN){
               return INT_MIN;
           }
           i++;
       }
       return static_cast<int>(sign*ans);
    }
