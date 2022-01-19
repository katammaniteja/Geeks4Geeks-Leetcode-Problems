// https://binarysearch.com/room/Dim-SUM(Users)-aysCNEIP8Z?questionsetIndex=2
// You are given a string s consisting of lowercase alphabet characters, digits, 
// and brackets"(" and ")". s encodes a longer string and is represented as 
// concatenation of n(t), where n is the number of times t is repeated, and t 
// is either a regular string or it's another encoded string recursively.
// Return the expanded version of s. Note that t can be the empty string.

string helper(string str,int &ind){
    if(ind>=str.length()) return "";
    string ans;
    while(ind<str.length()){
        if(str[ind]==')'){
            ind++;
            break;
        }
        else if(str[ind]>='0' && str[ind]<='9'){
            int n=str[ind]-'0';
            ind++;
            string temp=helper(str,ind);
            for(int i=1;i<=n;i++) ans+=temp;
        }
        else if(str[ind]=='(') ind++;
        else{
            ans+=str[ind];
            ind++;
        }
    }
    return ans;
}
string solve(string str) {
    int ind=0;
    return helper(str,ind);
}