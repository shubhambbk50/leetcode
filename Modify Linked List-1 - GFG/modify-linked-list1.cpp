//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        stack<int> st;
        stack<int> st2;
        Node* slow = head;
        Node* slow2 = head;
        Node* fast = head;
        Node* temp = head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        while( fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow = slow->next;
            slow2 = slow2->next;
        }
        Node* first = head;
        while(first!=slow){
            st2.push(first->data);
            first = first->next;
        }
        if(cnt%2!=0){
            slow=slow->next;
            slow2=slow2->next;
        }
        
        while(slow!=NULL){
            st.push(slow->data);
            slow = slow->next;
        }
        
        Node* ntemp = head;
        
        while(slow2!=NULL){
            ntemp->data = st.top() - ntemp->data;
            slow2->data = st2.top();
            ntemp = ntemp->next;
            slow2 = slow2->next;
            st.pop();
            st2.pop();
        }
        
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends