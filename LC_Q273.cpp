// This approach converts an integer into its English words representation using recursive decomposition and a hashmap for number-to-word mapping,
// achieving an O(log n) time complexity (since the number is processed in chunks of three digits) and O(1) space complexity (excluding output storage).
// The function solve(n, m) converts numbers below 1000, handling hundreds, tens, and units separately.
// The main function numberToWords(num) processes the number in groups of thousands, millions, and billions, appending appropriate scale words. This ensures a structured and efficient conversion of large numbers into words. 
// Time  Complexity:O(1)
// Space Complexity:O(1)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string solve(int n, unordered_map<int, string>& m) {
        if (n == 0) return "";
        
        string ans = "";
        int digit = 0, f = 1;

        if ((n / 100) % 10) {
            ans += m[(n / 100) % 10];
            if(n%100!=0)
            ans += " Hundred ";
            else{
                ans+=" Hundred";
            }
        }

        int temp = n % 100;
        
        if (temp < 20) {
            ans += m[temp];
        } else {
            int x = temp / 10 * 10;
            ans += m[x];
            
            int y = temp % 10;
            if (y != 0) {
                ans += " " + m[y];
            }
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        unordered_map<int, string> m = {
            {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
            {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
            {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
            {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
            {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"},
            {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
        };
        
        string ans = "";
        string s1 = solve(num % 1000, m);
        ans = s1;
        
        num /= 1000;
        if (num > 0) {
            string s2 = solve(num % 1000, m);
            if (s2 != "") ans = s2 + " " + m[1000] + (ans.empty() ? "" : " " + ans);
        }
        
        num /= 1000;
        if (num > 0) {
            string s3 = solve(num % 1000, m);
            if (s3 != "") ans = s3 + " " + m[1000000] + (ans.empty() ? "" : " " + ans);
        }
        
        num /= 1000;
        if (num > 0) {
            string s4 = solve(num, m);
            if (s4 != "") ans = s4 + " " + m[1000000000] + (ans.empty() ? "" : " " + ans);
        }
        

        
        return ans;
    }
};
