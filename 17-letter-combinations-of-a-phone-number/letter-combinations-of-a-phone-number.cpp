class Solution {
    // private:
    //     void solution(string digits, int index, string temp, vector<string>& ans, string mapping[]){
    //         if(index >= digits.length()){
    //             ans.push_back(temp);
    //             return;
    //         }
    //         int value = digits[index] - '0';
    //         string elements = mapping[value];
    //         for(int i=0;i<elements.length();i++){
    //             temp.push_back(elements[i]);
    //             solution(digits,index,temp,ans,mapping);
    //             temp.pop_back();
    //         }
    //     }
public:
    vector<string> letterCombinations(string digits) {
        // vector<string> ans;
        // if(digits.length() == 0)return ans;
        // string temp = "";
        // string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // solution(digits,0,temp,ans,map);
        // return  ans;

        vector<string> ans;
        if (digits.empty()) return ans;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        queue<string> q;
        q.push("");

        for (int i = 0; i < digits.length(); i++) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                string current = q.front();
                q.pop();

                int digit = digits[i] - '0';
                for (char c : mapping[digit]) {
                    q.push(current + c);
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};