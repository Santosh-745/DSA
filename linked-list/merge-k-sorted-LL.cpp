//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
class compare {
public:
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution{
    private:
    Node* insertAtTail(Node* head, Node* &tail, int data) {
        Node* temp = new Node(data);
        if(!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
    
    public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node*, vector<Node*>, compare> pq;
        for (int i = 0; i < K; i++) {
            if (arr[i] != NULL) {
                pq.push(arr[i]);
            }
        }
        
        struct Node* head = NULL;
        struct Node* tail = NULL;
        while (!pq.empty()) {
            struct Node* temp = pq.top();
            pq.pop();
            
            head = insertAtTail(head, tail, temp->data);
            
            if (temp->next) {
                pq.push(temp->next);
            }
        }
        
        return head;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends

/*
4
3 1 2 3 2 4 5 2 5 6 2 7 8

*/
