// The approach uses the Sieve of Eratosthenes to mark primes up to right in O(N log log N), storing prime status in a boolean vector. It then iterates from left to right to find the closest prime pair by tracking the previous and current prime numbers, updating the minimum difference found. 
// The time complexity is O(N log log N) + O(N) ≈ O(N log log N)
// (sieve + traversal), and space complexity is O(N) due to the boolean vector storing primality information.
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(right+1,1);
        v[1]=0;
        for(int i=2;i<=right;i++){
            if(v[i]){
                for(int j=2*i;j<=right;j=j+i){
                    v[j]=0;
                }
            }
        }
        int prev=-1,curr=-1;
        vector<int> ans(2,-1);
        int mini=1e9;
        for(int i=left;i<=right;i++){
            if(v[i]){
              curr=i;
              if(prev!=-1){
                if(curr-prev<mini){
                    mini=curr-prev;
                    ans[0]=prev;
                    ans[1]=curr;
                }
              }
              prev=curr;
            }
        }
        return ans;
    }
};
