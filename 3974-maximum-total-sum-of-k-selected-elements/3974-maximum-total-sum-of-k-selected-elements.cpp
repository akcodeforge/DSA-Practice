class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long maxSum=0;
        sort(nums.begin(), nums.end());
       for(int i=n-1;i>=0 && k>0;i--){
               if(1ll*nums[i]*mul>=nums[i]) {
                   maxSum +=1ll*nums[i]*mul;
               }
               else {
                   maxSum +=nums[i];
               }
           mul--;
           k--;
       }
        return maxSum;
    }
};