/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int>nums;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=0;
            else ans[i]=nums[st.top()];
            st.push(i);
        }
        return ans;
    }
};