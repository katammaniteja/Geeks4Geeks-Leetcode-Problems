// https://practice.geeksforgeeks.org/problems/tower-of-hanoi/1
// The tower of Hanoi is a famous puzzle where we have three rods 
// and N disks. The objective of the puzzle is to move the entire 
// stack to another rod. You are given the number of discs N. 
// Initially, these discs are in the rod 1. You need to print all 
// the steps of discs movement so that all the discs reach the 3rd rod. 
// Also, you need to find the total moves.
// Note: The discs are arranged such that the top disc is numbered 1 and 
// the bottom-most disc is numbered N. Also, all the discs have different 
// sizes and a bigger disc cannot be put on the top of a smaller disc.


class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long count=0;
    long long toh(int n, int from, int to, int aux) {
        
        if(n==1){
            count++;
            cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
            return count;
        }
        toh(n-1,from,aux,to);
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        count++;
        toh(n-1,aux,to,from);
    }

};