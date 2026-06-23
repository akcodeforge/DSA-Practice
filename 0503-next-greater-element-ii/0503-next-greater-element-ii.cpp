class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int> st;
        // st.push(nums[n-1]);
        // ans[n-1]=nums[n-1];
        for(int i=2*(n-1);i>=0;i--){
            while(st.size()>0 && st.top()<=nums[i%n]){
                // ans[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n){
                if(st.size()==0) ans[i%n]=-1;
                else ans[i%n]=st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};