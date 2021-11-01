// https://leetcode.com/problems/set-mismatch/

// You have a set of integers s, which originally contains all the 
// numbers from 1 to n. Unfortunately, due to some error, one of the 
// numbers in s got duplicated to another number in the set, which 
// results in repetition of one number and loss of another number.

// Find the number that occurs twice and the number that is missing
//  and return them in the form of an array.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v;
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]==i+1) i++;
            else{
                if(nums[i]==nums[nums[i]-1]) i++;
                else swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(i=0;i<n;i++){
            if(nums[i]!=i+1){
                v.push_back(nums[i]);
                v.push_back(i+1);
                break;
            }
        }
        return v;
    }
};