// using vector
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
       vector<int>ans;
       while(head1!=NULL)
       {
           ans.push_back(head1->data);
           head1=head1->next;
       }
       while(head2!=NULL)
       {
           ans.push_back(head2->data);
           head2=head2->next;
       }
       sort(ans.begin(),ans.end());
       
       Node* head= NULL;
       Node* tail=NULL;
       
       for(int i=0;i<ans.size();i++)  
         {
             Node* newNode=new Node(ans[i]);
             if(head==NULL)
             {
                 head=tail=newNode;
             }
             else
             {
                 
                 tail->next=newNode;
                 tail=newNode;
             }
       }
       return head;
       
    }
};//TC and SC:O(n)


class Solution {
  public:
    Node* sortedMerge(Node* left, Node* right) {
      
        if( left == NULL)return right;
        if(right == NULL )return left;
        
        
        //create temporary Node
        Node* ans = new Node(INT_MIN);
        Node* temp = ans;
        
        while(left!=NULL && right !=NULL)
        {
            if(left -> data <= right ->data )
            {
                temp -> next = left;
                temp = left;
                left= left->next;
                
            }
            else
            {
                temp -> next = right;
                temp =right;
                right=right->next;
                
            }
        }
        while(left!=NULL)
        {
                temp -> next = left;
                temp = left;
                left= left->next;     
        }
        
        while(right!=NULL)
        {
            temp -> next = right;
            temp =right;
            right=right -> next;
        }
        ans = ans -> next;
        return ans;
    }
};/* TC: O(n)
SC: O(log n) */
