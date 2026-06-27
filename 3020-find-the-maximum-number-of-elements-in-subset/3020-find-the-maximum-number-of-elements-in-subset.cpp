class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> ans;
        for (int x : nums)
            ans[x]++;
        int result = 0;
        for (auto& it : ans) {
            long long curr = it.first;
            int len=0;
            bool findmiddle=false;
            if (curr == 1) {
                    result = max(result, ans[1] % 2 == 0 ? ans[1] - 1 : ans[1]);
                    continue;
                }
            while (ans.count(curr)) {
                if (ans[curr] == 1) {
                    len++;
                    findmiddle=true;
                    break;
                } else {
                    len += 2;
                }
                if(curr>sqrt(LLONG_MAX)){
                    break;
                }
                curr = curr * curr;
            }
            if(findmiddle==false) len--;
                result=max(result,len);
        }
        return result;
    }
};