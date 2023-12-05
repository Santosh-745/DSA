//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        vector<int> ans(n);
        stack<int> s;
        
        s.push(-1);
        for(int i = 0; i < n; i++) {
            while(s.top() >= arr[i]) {
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
        cin>>a[i];
    
    Solution ob;
    vector<int> ans = ob.leftSmaller(n, a);
    for(int i = 0;i < n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
// } Driver Code Ends
