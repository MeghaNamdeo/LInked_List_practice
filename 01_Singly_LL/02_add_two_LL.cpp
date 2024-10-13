
class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* reverse(Node* curr, Node* prev)
    {
        if(curr==NULL)return prev ;
        
       
        Node* nextNode = curr->next;
        curr->next=prev;
        
        
        return reverse(nextNode ,curr);
        
    }
    Node* addTwoLists(Node* first, Node* second) {
        //reverse first LL
        first = reverse(first,NULL);
        //reverse second LL
        second = reverse(second,NULL);
        
        Node *curr1=first,*curr2=second;
        //create dummy node
        Node* head=new Node(0);
        Node* tail=head;
        int sum,carry=0;
        
        //Addition
        while(curr1&&curr2)
        {
            sum=curr1->data+curr2->data+carry;
            tail->next=new Node(sum%10);
            curr1=curr1->next;
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
            
        }
        //curr1 exist
        while(curr1)
        {
            sum=curr1->data+carry;
            tail->next=new Node(sum%10);
            curr1=curr1->next;
            tail=tail->next;
            carry=sum/10;
            
        }
        //curr2 exist
         while(curr2)
        {
            sum=curr2->data+carry;
            tail->next=new Node(sum%10);
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
            
        }
        //carry exist
         while(carry)
        {
            
            tail->next=new Node(carry%10);
            tail=tail->next;
            carry=carry/10;
            
        }
        
        //reverse LL
        //remove dummy node
        head =reverse(head->next,NULL);
        return head;
        
    }
};//TC:O(n+m),SC:O(n+m)