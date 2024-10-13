class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
       node* first = new  node(0);
       first ->next=head;
       head=first;
       int x;
       node* second,*prev,*curr,*frontNode;
       while(first->next)
       {
           int x=k;
           second=first->next;
           prev=first;
           curr=first->next;
           
           while(x&&curr)
           {
               frontNode=curr->next;
               curr->next=prev;
               prev=curr;
               curr=frontNode;
               x--;
           }
           first->next=prev;
           second->next=curr;
           first=second;
        }
        
        //delete dummy node
           first=head;
           delete first;
           head=head->next;
           return head;
       }
    
};
//TC and SC:O(n)