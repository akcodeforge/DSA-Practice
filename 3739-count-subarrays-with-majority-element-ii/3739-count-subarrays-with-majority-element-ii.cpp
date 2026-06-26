class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        int cumsum=0;
        long long validleftpoint=0;
        map[0]=1;
        long long result =0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validleftpoint +=map[cumsum];
                cumsum +=1;
            }
            else{
                cumsum -=1;
                validleftpoint -=map[cumsum];
            }
            map[cumsum] += 1;
            result +=validleftpoint;
        }
        return result;
    }
};