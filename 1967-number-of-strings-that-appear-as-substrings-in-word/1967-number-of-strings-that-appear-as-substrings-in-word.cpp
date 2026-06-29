class Solution {
public:
bool contain(string s,string word){
    if(s.length()>word.length()) return false;
    int n=word.length();
    int m=s.length();
    for(int i=0;i<=n-m;i++){
        bool yes=true;
        for(int j=0;j<m;j++){
            if(s[j]!=word[i+j]){
                yes=false;
                break;
            }
        }
    if(yes==true) return true;
    }
    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int i=0;i<patterns.size();i++){
            if(contain(patterns[i],word)) count++;
        }
        return count;
    }
};