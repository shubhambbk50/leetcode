//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   Node*re(Node*n){

        Node*N;

        Node*pre=NULL;

        while(n){

            N = n->next;

            n->next = pre;

            pre = n;

            n = N;

        }

        n = pre;

        return n;

   }                                    //0 1 2 3 4 5

   Node *reverse(Node *head, int k)

    {

        // code here

        Node*cur = head;

        Node*dum = new Node(0);

        Node*c= dum;

        while(k>0){

            Node*n = new Node(head->data);

             c->next = n;

             head = head->next;

             c = c->next;

             k--;

        }

        Node* f = re(dum->next);

        Node * dum1= new Node(0);

        Node * a = dum1;

        while(head){

            Node*n = new Node(head->data);

            a->next = n;

            head = head->next;

            a = a->next;

        }

        Node *s = re(dum1->next);

        Node * ans = new Node(0);

        Node* b = ans;

        while(f){

             Node*n = new Node(f->data);

             b->next = n;

             b = b->next;

             f = f->next;

        }

        while(s){

             Node*n = new Node(s->data);

             b->next = n;

             b = b->next;

             s = s->next;

        }

        return ans->next;

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends