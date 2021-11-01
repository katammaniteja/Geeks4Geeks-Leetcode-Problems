// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
public:
    void fact(vector<int>&v,int n){
        int carry=0;
        for(int i=0;i<v.size();i++){
            int num=v[i]*n+carry;
            carry=num/10;
            v[i]=num%10;
        }
        while(carry>0){
            v.push_back(carry%10);
            carry=carry/10;
        }
    }
    vector<int> factorial(int n){
        vector<int>v;
        v.push_back(1);
        for(int i=2;i<=n;i++){
            fact(v,i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};