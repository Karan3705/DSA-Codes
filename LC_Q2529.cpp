class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0, high = n - 1, firstNonNegative = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < 0) {
                low = mid + 1;
            } else {
                firstNonNegative = mid;
                high = mid - 1;
            }
        }
        
        int negativeCount = firstNonNegative;
        
        low = 0, high = n - 1;
        int firstPositive = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= 0) {
                low = mid + 1;
            } else {
                firstPositive = mid;
                high = mid - 1;
            }
        }
        
        int positiveCount = n - firstPositive;
        
        return max(negativeCount, positiveCount);
    }
};
