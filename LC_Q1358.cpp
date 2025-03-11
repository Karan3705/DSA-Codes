// Approach

//     We maintain a sliding window using two pointers (low and high) that keeps track of substrings containing at least one occurrence of all three characters (a, b, c).
//     We use an unordered_map (occ) to keep track of character frequencies within the window.
//     We expand the window (high pointer) until all three characters are present.
//     Once all three characters are in the window, we start contracting the window from the left (low pointer) to find all valid substrings starting from index low and extending up to s.size() - 1.
//     We count the number of valid substrings that can be formed by adding (s.size() - high) substrings.
//     We continue the process until the end of the string.

// Complexity Analysis

//     Each character is added at most once (high pointer moves O(n) times).
//     Each character is removed at most once (low pointer moves O(n) times).
//     Thus, the overall time complexity is O(n).
//     The space complexity is O(1) since the unordered map has at most 3 keys.
class Solution {
public:
    int numberOfSubstrings(string s) {
        int start=0;
        unordered_map<char,int> occ;
        int low=0,high=0;
        long long int cnt=0;
        while(high<s.size()){
            occ[s[high]]++;
            while(occ.size()==3){
                cnt+=s.size()-high;
                occ[s[low]]--;
                if(occ[s[low]]==0) occ.erase(s[low]);
                low++;
            }
            high++;
           
        }
        return cnt;
        
    }
};
