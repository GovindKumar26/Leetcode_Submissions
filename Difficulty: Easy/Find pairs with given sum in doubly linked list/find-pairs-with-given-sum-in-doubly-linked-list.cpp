//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
      // Node* temp1 = head;
       vector<pair<int, int>> ans;
       
    //   while(temp1){
    //       Node*temp2 = temp1->next;
    //       while(temp2 && temp2->data + temp1->data <= target){
    //           if(temp1->data + temp2->data == target){
    //               ans.push_back({temp1->data, temp2->data});
    //           }
    //           temp2 = temp2->next;
    //       }
    //       temp1 = temp1->next;
    //   }
    //   return ans;
       
        Node* temp1 = head;
        Node* temp2 = head;
        while(temp2->next){
            temp2 = temp2->next;
        }
        
        while(temp1->data < temp2->data){
            if(temp1->data + temp2->data == target) {
                 ans.push_back({temp1->data, temp2->data}); 
                  temp2 = temp2->prev;
                  temp1 = temp1->next;
            }
            if(temp1->data + temp2->data > target) {
                temp2 = temp2->prev;
            }
             if(temp1->data + temp2->data < target) {
                temp1 = temp1->next;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends