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