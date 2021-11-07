// https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1
// Given an array arr[] of size N where every element is in the range 
// from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

// Approach: The array elements of the given array lies from 0 to n-1. Now an array 
// element is needed that can store two different values at the same time. To achieve 
// this increment every element at ith index is incremented by (arr[arr[i]] % n)*n.After 
// the increment operation of first step, every element holds both old values and new 
// values. Old value can be obtained by arr[i]%n and a new value can be obtained by arr[i]/n.

// How this can be achieved? 
// Let’s assume an element is a and another element is b, both the elements are less than n. 
// So if an element a is incremented by b*n. So the element becomes a + b*n so when a + b*n is 
// divided by n then the value is b and a + b*n % n is a.

class Solution{
    public:
    void arrange(long long arr[], int n) {
        for(int i=0;i<n;i++){
            arr[i]+=(arr[arr[i]]%n)*n;
        }
        for(int i=0;i<n;i++) arr[i]=arr[i]/n;
    }
};