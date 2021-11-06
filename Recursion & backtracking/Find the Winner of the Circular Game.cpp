// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// There are n friends that are playing a game.
// The friends are sitting in a circle and are
// numbered from 1 to n in clockwise order. More 
// formally, moving clockwise from the ith friend 
// brings you to the (i+1)th friend for 1 <= i < n, 
// and moving clockwise from the nth friend brings you 
// to the 1st friend.
class Solution {
public:
    int find(int n,int k){
        if(n==1) return 0;
        else return (find(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return 1+find(n,k);
    }
};

