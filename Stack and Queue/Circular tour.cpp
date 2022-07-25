// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int curr_petrol=0,prev_petrol=0,start=0;
       for(int i=0;i<n;i++){
           curr_petrol+=p[i].petrol-p[i].distance;
           if(curr_petrol<0){
               prev_petrol+=curr_petrol;
               start=i+1;
               curr_petrol=0;
           }
       }
       return curr_petrol+prev_petrol>0?start:-1;
    }
};