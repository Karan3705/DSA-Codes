class Solution {
public:
    bool checkPowersOfThree(int n) {
        int temp=n;
        while(temp>0){
            if(temp%3==2){
                return false;
            }
            temp=temp/3;
        }
        return true;
    }
};
