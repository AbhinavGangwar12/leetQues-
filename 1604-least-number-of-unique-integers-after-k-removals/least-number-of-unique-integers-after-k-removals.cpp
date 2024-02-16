class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<int> fq;
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
                m[arr[i]]++;
        }
        for(auto p : m){
            fq.push_back(p.second);
        }
        sort(fq.begin(),fq.end());
        int count=0;
        for(int i=0;i<fq.size();i++){
            if(k>fq[i]){
                k -= fq[i];
                fq[i] = 0;
            }
            else{
                fq[i] -= k;
                k = 0;
            }
            if(fq[i]!=0)count++;
        }
        return count;
    }
};