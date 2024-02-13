class Solution {
    private:
        bool helper(vector<string>& words,int& index){
            string temp = words[index];
            int i=0,j = temp.size()-1;
            while(i<=j){
                if(temp[i] != temp[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
public:
    string firstPalindrome(vector<string>& words) {
        int size = words.size();
        for(int i=0;i<size;i++){
            if(helper(words,i))return words[i];
        }
        return "";
    }
};