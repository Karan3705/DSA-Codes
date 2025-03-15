// The problem aims to find the minimum capability required to pick k non-adjacent elements from the array nums such that the maximum value among the selected elements is minimized. 
// To solve this, we use binary search on the range of possible capabilities, from min(nums) to max(nums).
// For each mid-point in this range, we check if it's possible to pick k elements with values ≤ mid while ensuring no two picked elements are adjacent. 
// If it's possible, we update the answer and search the left half to minimize mid; otherwise, we search the right half.
// The smallest mid that satisfies the condition is the minimum capability, achieved in O(n × log(max - min)) time.
class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                k--;
                if(k==0) return true;
                i++;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end()),high=*max_element(nums.begin(),nums.end()),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
