class Solution {
  public:
  int getSingle(vector<int> &arr) {
  unordered_map<int,int> count;
  for(int num:arr){
    if(count[num]++==2){
        count.erase(num);
    }
    }
  return count.begin()->first;
    }
};
