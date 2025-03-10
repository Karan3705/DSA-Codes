// Approach

// The problem is to count the number of substrings of length at least kk that contain all five vowels ('a', 'e', 'i', 'o', 'u') at least once. The approach uses two-pointer (sliding window) technique with two pass difference method:

//     Sliding Window for Inclusion:
//         Maintain a frequency map of vowels and a count of non-vowel characters.
//         Expand the window by increasing high and updating the map.
//         Shrink the window from low while it remains valid (contains all vowels and at least kk non-vowel characters).
//         Count substrings using word.size() - high, as any valid start at low will contribute substrings ending at high to the end.

//     Sliding Window for Exclusion:
//         Perform the same process but for k+1 non-vowel characters to exclude substrings exceeding kk non-vowel characters.
//         Compute the final result as difference between counts from both sliding windows.

// Time Complexity (TC)

//     Each character is processed at most twice (once when expanding high and once when contracting low).
//     Overall Complexity: O(n)), where nn is the length of the string.

// Space Complexity (SC)

//     Uses a map of vowels (mp) with a fixed size of 5.
//     Overall Complexity: O(1) (constant space for frequency map).
class Solution {
public:
    bool isValid(map<char,int>& mp,int cnt,int k){
        return mp['a']>0 && mp['e']>0 && mp['i']>0 && mp['o']>0 && mp['u']>0 && cnt>=k;
    }
    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long countOfSubstrings(string word, int k) {
        map<char,int> mp;
        long long int low=0,high=0,ans=0,cnt=0;
        bool check;
        while(high<word.size()){
            if(isvowel(word[high]))
                mp[word[high]]++;
            else cnt++;
            while(isValid(mp,cnt,k)){
                ans+=word.size()-high;
                if(isvowel(word[low])){
                    mp[word[low]]--;
                }
                else cnt--;
                low++;
                
             
                
            }
            high++;
           
        }
        long long int ans2=0,k2=k+1;
        cnt=0,low=0,high=0;
        mp.clear();
        while(high<word.size()){
            if(isvowel(word[high]))
                mp[word[high]]++;
            else cnt++;
            while(isValid(mp,cnt,k2)){
                ans2+=word.size()-high;
                if(isvowel(word[low])){
                    mp[word[low]]--;
                }
                else cnt--;
                low++;
                
                    
                
            }
            high++;
           
        }
        return ans-ans2;
    }
};
