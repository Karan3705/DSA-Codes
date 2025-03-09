// Approach:

// The problem requires counting the number of valid subarrays of length k that contain no adjacent equal elements in a circular array.
// Understanding the Code:

//     Initialization:
//         cnt = 0: Keeps track of the count of adjacent equal elements in the current window.
//         ans = 0: Stores the final count of valid subarrays.
//         low = 0, high = 0: Two pointers defining the sliding window.
//         n = colors.size(): Stores the size of the colors array.

//     Sliding Window Mechanism:
//         The window expands by moving high forward.
//         If colors[high] == colors[high-1], increment cnt (indicating adjacent equal elements).
//         Special case: If high == 0 and colors[n-1] == colors[0], increment cnt (handles the circular nature).

//     Calculating Window Size:
//         If high > low, compute size = high - low + 1 (normal case).
//         If high < low, compute size considering wrap-around (circular array).

//     Valid Subarray Check:
//         If size == k:
//             If cnt == 0, increment ans (valid subarray found).
//             Before sliding low forward, check if colors[low] == colors[low+1]. If true, decrement cnt (removing an adjacent pair from the window).
//             Move low forward.

//     Final Return:
//         Return ans as the count of valid alternating subarrays
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt=0,ans=0,low=0,high=0,n=colors.size();
        while(low<n){
            high=(high+1)%n;
            if(high>0 && colors[high-1]==colors[high]){
                cnt++;
            }
            else if(high==0 && colors[n-1]==colors[0]){
                cnt++;
            }
            int size;
            if(high>low){
                size=high-low+1;
            }
            else{
                int x=low-high-1;
                size=n-x;
            }
            if(size==k){
                if(cnt==0){
                    ans++;
                }
                if(low+1<n && colors[low]==colors[low+1]){
                    cnt--;
                }
                low++;
            }
        }
        return ans;
    }
};
