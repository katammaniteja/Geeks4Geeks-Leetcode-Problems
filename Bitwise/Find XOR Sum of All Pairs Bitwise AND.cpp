// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// The XOR sum of a list is the bitwise XOR of all its elements. If the list
// only contains one element, then its XOR sum will be equal to this element.

// For example, the XOR sum of [1,2,3,4] is equal to 1 XOR 2 XOR 3 XOR 4 = 4,
//  and the XOR sum of [3] is equal to 3.


class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1=0,xor2=0;
        for(int i=0;i<arr1.size();i++) xor1^=arr1[i];
        for(int i=0;i<arr2.size();i++) xor2^=arr2[i];
        return (xor1&xor2);
    }
};