#include<iostream>
#include<stack>
using namespace std;
//after recursion has reversed the stack having n-1 elements we have to insert the temp elemnent at the bottom 
void push_bottom(stack<int>&s,int temp)
{
    // base case
    if(s.empty())
    {
      s.push(temp);
      return;
    }
    // recursive case
    int top = s.top(); // remove the top element of stack 
    s.pop();
    push_bottom(s,temp); // then after removing all top elements i.e stack empty insert temp 
    s.push(top); // then while returning back insert the top elemnts again 
}
void reverseStack(stack<int>&s)
{
    // base case
    if(s.empty())
    {
        return;
    }
    // recursive csse
    int temp = s.top();   // topmost element ko remove kara 
    s.pop();
    reverseStack(s);  // aur baaki stack ko reverse kara by recursion 
    push_bottom(s,temp);
}

    void printStack(stack<int>s)
    {
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }

int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
  printStack(s);
  cout<<endl; 
  reverseStack(s);
  printStack(s);
  return 0;

}
