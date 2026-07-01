class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                    int p=sum%10;
                    long long f=sum;
                    while(f>=10){
                        f/=10;
                    }
                    if(p==f && f==x) count++;
                }
            }
        return count;
    }
};