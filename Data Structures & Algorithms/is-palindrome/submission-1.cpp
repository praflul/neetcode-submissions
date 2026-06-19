class Solution {
public:
    bool isPalindrome(string s) {
        string s2="";
        for(char c : s){
            if(c>='a'&&c<='z') s2+=c;
            else if(c>='A'&&c<='Z') s2+=c-('A'-'a');
            else if(c>='0'&&c<='9') s2+=c;
        }
        int i=0;
        int j=s2.size()-1;
        while(i<j){
            if(s2[i]!=s2[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
