
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        if(arr.empty()) return {};
        sort(arr.begin(),arr.end());
        vector<vector<int>> merged;
        merged.push_back(arr[0]);
        for(int i=1;i<arr.size();++i){
            if(arr[i][0]<=merged.back()[1]){
                merged.back()[1]=max(merged.back()[1],arr[i][1]);
            } else {
                merged.push_back(arr[i]);
            }
        }
        return merged;
    }
