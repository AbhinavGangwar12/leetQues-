class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> rev;
        for(auto i:s){
            rev.push(i);
        }
        int x = 0;
        while(!rev.empty()){
            s[x++] = rev.top();
            rev.pop();
        }
    }
};