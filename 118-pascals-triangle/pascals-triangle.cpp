// WE ARE BASICALLY ADDING THE PAIR OF ELEMENTS FROM THE PREVIOUS ARRAY AND STORING THE SUM OF THESE PAIRS AS AN ELEMENT IN THE NEW VECTOR FOLLOWED 1'S 
// IT WILL LOOK LIKE THIS
// {1} , {1,1} , {1,2,1} , {1,3,3,1} , {1,4,6,4,1} ....AND SO ON
// JUST ANALIZE THE ANSWER AND YOU'LL UNDERSTAND THE APPROACH EASILY


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
