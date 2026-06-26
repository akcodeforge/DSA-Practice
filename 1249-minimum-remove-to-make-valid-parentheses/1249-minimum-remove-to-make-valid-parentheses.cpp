class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int n=s.length();
        stack<int> st;
        for(int i=0; i<n;i++){
            if(s[i]==')'){
                if(st.empty() || s[st.top()]!='(') st.push(i);
                else st.pop();
            }
            else if (s[i]=='('){
                st.push(i);
            }
            }
        stack<int> helper;
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        for(int i=0; i<n;i++){
            if(! helper.empty() && i==helper.top()) {
                helper.pop();
                continue;
            }
            else ans+=s[i];
        }
        return ans;
    }
};