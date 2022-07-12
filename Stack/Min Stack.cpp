// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int>s1,s2;
    void push(int val) {
        s1.push(val);
        if(!s2.size() || val<=getMin()) s2.push(val);
    }
    
    void pop() {
        if(getMin()==s1.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};