// created prefix loss array which tells loss less before index i, and then converted it into loss array to get the loss, and then finally returning true or false, based on if any number is positive.
// Then used binary search to get minimum value of k.
class Solution {
public:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n=nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<k;i++){
            auto q=queries[i];
            int l=q[0];
            int r=q[1];
            prefix[r]+=q[2];
            if(l>0){
                prefix[l-1]-=q[2];
            }
        }
        for(int i=n-1;i>=0;i--){
            prefix[i]+=prefix[i+1];
            int loss=prefix[i];
            // nums[i]-=loss;
            if(nums[i]-loss>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int low=0,high=queries.size(),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,queries,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
       
        return ans;
        
    }
};
