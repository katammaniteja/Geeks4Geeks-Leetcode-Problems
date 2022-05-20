// https://leetcode.com/problems/furthest-building-you-can-reach/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                pq.push(heights[i]-heights[i-1]);
                if(pq.size()>ladders){
                    if(bricks<pq.top()) return ans+ladders;
                    else{
                        bricks-=pq.top();
                        pq.pop();
                        ans++;
                    }
                }
            }
            else ans++;
        }
        return ans+pq.size();
    }
};