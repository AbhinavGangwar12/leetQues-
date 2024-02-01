class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1)return {{1}};
        vector<vector<int>> v;
        v.push_back({1});
        v.push_back({1,1});
        int c = 1;
        while(c < n-1){
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<v[c].size()-1;i++){
                int x = v[c][i] + v[c][i+1];
                temp.push_back(x);
            }
            temp.push_back(1);
            v.push_back(temp);
            c++;
        }
        return v;
    }
};