// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Given a stack, the task is to sort it such that the
// top of the stack has the greatest element.

void insert(stack<int>&s,int a){
    if(!s.size() || s.top()<=a){
        s.push(a);
        return;
    }
    int insert_top=s.top();
    s.pop();
    insert(s,a);
    s.push(insert_top);
}
void SortedStack :: sort()
{
   if(s.size()==1) return;
   int a=s.top();
   s.pop();
   sort();
   insert(s,a);
}