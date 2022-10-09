#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
        int len = 1;
        ListNode *cur = head -> next, *prev = head, *next;
        head -> next = NULL;
        while(cur != NULL){
            if(len == k){
                head -> next = reverseKGroup(cur, k);
                break;
            }
            else{
                next = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = next;
                len++;
            }
        }
        if(len < k){
            prev = reverseKGroup(prev, len);
        }
        return prev;
    }

void print(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head -> next;
    }
}
int main()
{
    int input[11]={1,2,3,4,5,6,7,8,9,10,11};
    int k = 3;
    ListNode* head = new ListNode(input[0]), *cur=head;
    for(int i=1;i<11;i++){
        cur -> next = new ListNode(input[i]);
        cur = cur->next;
    }
    cout<<"Given list : ";
    print(head);
    cout<<endl;
    head = reverseKGroup(head,k);
    cout<<"Modified list : ";
    print(head);
    cout<<endl;
    return 0;
}