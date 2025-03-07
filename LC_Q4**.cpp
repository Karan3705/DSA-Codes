// This approach uses binary search on the smaller array to efficiently find the median of two sorted arrays in O(log(min(n, m))) time and O(1) space. 
//  We partition both arrays such that the left half contains n = (nums1.size() + nums2.size()) / 2 elements. The maximum of the left partition (x) and the minimum of the right partition (y) determine the median. 
// If x ≤ y, we have the correct partition; otherwise, we adjust the partition using binary search.
// If the total number of elements is odd, the median is y, otherwise, it's (x + y) / 2.0. 
class Solution {
public:
    int isValid(vector<int>& nums1, vector<int>& nums2, int m, int& x, int& y) {
        int n = (nums1.size() + nums2.size()) / 2;
        int n2 = n - m;
        int ans = 0;
        
        
        x = (m > 0) ? nums1[m - 1] : INT_MIN;

        if (m > 0) ans = 1;
        if (n2 > 0 && nums2[n2 - 1] > x) {
            x = nums2[n2 - 1];
            ans = 2;
        }

        int right1 = (m < nums1.size()) ? nums1[m] : INT_MAX;
        int right2 = (n2 < nums2.size()) ? nums2[n2] : INT_MAX;

        y = min(right1, right2);

        return (x <= y) ? 0 : ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);  
        
        int low = 0, high = nums1.size();
        int x, y;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int a = isValid(nums1, nums2, mid, x, y);
            if (a == 0) break;
            else if (a == 1) high = mid - 1;
            else low = mid + 1;
        }

        return ((nums1.size() + nums2.size()) % 2) ? y : (x + y) / 2.0;
    }
};
