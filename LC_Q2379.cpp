// The approach uses the sliding window technique to find the minimum number of 'W' characters that need to be changed to 'B' in any contiguous substring of length k.
// We maintain a window of size k using two pointers (low and high) and count the number of 'W' characters within it.
// As we expand the window, we update the count of 'W's and, once the window reaches size k, we record the minimum number of changes required. 
// Before sliding the window forward, we adjust the count if the leftmost character was 'W'. 
// Time  Complexity:O(n) in the worst case
// Space Complexity:O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int low=0,high=0,cnt=0,ans=1e9;
        while(high<blocks.size()){
            if(blocks[high]=='W'){
                cnt++;
            }
            if(high-low+1==k){
                ans=min(ans,cnt);
                if(blocks[low]=='W'){
                    cnt--;
                }
                low++;
            }
            high++;
        }
        return ans;
    }
};
