// use kadane;s algo to find minimum and maximum,and then updated maximum by absolute value of minimum.
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0,sum1=0,sum2=0;
        for(auto i:nums){
            if(sum1<0){
                sum1=0;
            }
            if(sum2>0){
                sum2=0;
            }
            sum1+=i;
            sum2+=i;
            ans=max({ans,sum1,abs(sum2)});
        }
        return ans;
    }
};
