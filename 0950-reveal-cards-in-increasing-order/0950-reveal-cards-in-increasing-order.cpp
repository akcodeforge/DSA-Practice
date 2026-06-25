class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        stack<int>st;
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
            st.push(deck[i]);
        }
        queue<int>ans;
        while(st.size()>0){
            if(ans.size()==0) {
                ans.push(st.top());
                st.pop();
            }
            else{
                ans.push(ans.front());
                ans.pop();
                ans.push(st.top());
                st.pop();
            }
        }
        vector<int>result;
        while(ans.size()>0){
            result.push_back(ans.front());
            ans.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};