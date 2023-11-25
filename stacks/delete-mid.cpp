//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    void solve(stack<int>&s, int sizeOfStack, int count) {
        if(sizeOfStack / 2 == count) {
            s.pop();
            return ;
        }
        
        int tmp = s.top();
        s.pop();
        
        solve(s, sizeOfStack, count+1);
        
        s.push(tmp);
    }
    
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        solve(s, sizeOfStack, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int sizeOfStack;
      cin>>sizeOfStack;
      
      stack<int> myStack;
      
      for(int i=0;i<sizeOfStack;i++)
      {
          int x;
          cin>>x;
          myStack.push(x);    
      }

          Solution ob;
          ob.deleteMid(myStack,myStack.size());
          while(!myStack.empty())
          {
              cout<<myStack.top()<<" ";
              myStack.pop();
          }
      cout<<endl;
    return 0;
}

// } Driver Code Ends

/*
4
1 2 3 4 

5
1 2 3 4 5
*/
