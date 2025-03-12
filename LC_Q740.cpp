// converted it into house robber
typedef long long ll;
class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        map<ll,ll> freq;
        for(auto i:nums){
            freq[i]++;
        }
        
        
        int maxi=*max_element(nums.begin(),nums.end());
        vector<ll> v(maxi+1);
        for(int i=1;i<=maxi;i++){
            v[i]=i*freq[i];
        }
        vector<ll> dp(v.size()+1);
        if(v.size()==1) return v[0];
        dp[0]=v[0];
        dp[1]=max(v[0],v[1]);

        for(int i=2;i<v.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+v[i]);
        }
        return dp[v.size()-1];

    }
};
