// https://leetcode.com/problems/happy-number/
class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n){
            int temp=n%10;
            sum+=(temp*temp);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow=digitSum(slow);
            fast=digitSum(fast);
            fast=digitSum(fast);
        }while(slow!=fast);
        return slow==1;
    }
};