// The goal is to rearrange the given array nums such that:

//     All elements less than pivot appear first.
//     All occurrences of pivot appear in the middle.
//     All elements greater than pivot appear last.

// First Pass: Count the number of elements less than (cnt1) and greater than (cnt2) the pivot.
// Second Pass: Create a new array ans initialized with the pivot at all positions.

//     Use two pointers:
//         i = 0 to place elements less than pivot.
//         j = nums.size() - cnt2 to place elements greater than pivot.
// Time Complexity:O(n)
// Space Complexity:O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt1=0,cnt2=0;
        for(auto i:nums){
            if(i<pivot){
                cnt1++;
            }
            else if(i>pivot){
                cnt2++;
            }
        }
        vector<int> ans(nums.size(),pivot);
        int i=0,j=nums.size()-cnt2;
        for(auto& num:nums){
            if(num<pivot){
                ans[i++]=num;
            }
            else if(num>pivot){
                ans[j++]=num;
            }
        }
        return ans;
    }
};
