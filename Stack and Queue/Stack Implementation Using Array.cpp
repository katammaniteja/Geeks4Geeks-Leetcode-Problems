// https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209
// Stack class.
class Stack {
    
public:
    int *arr;
    int tp=0,capacity;
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        this->capacity=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(tp<capacity) arr[tp++]=num;
    }

    int pop() {
        // Write your code here.
        if(tp>0){
            tp--;
            return arr[tp];
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(tp==0) return -1;
        return arr[tp-1];
    }
    
    int isEmpty() {
        // Write your code here.
        return tp==0;
    }
    
    int isFull() {
        // Write your code here.
        return tp==capacity;
    }
    
};