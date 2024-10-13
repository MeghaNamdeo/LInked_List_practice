class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

      if(head==NULL)return head;
      //create vector to store LL values
       vector<int>ans;
     
       Node* temp=head;
       while(temp)
       {
           ans.push_back(temp->data);
           temp=temp->next;
       }
       //create dummy node 
       Node* newhead=new Node(0);
       //create tail 
       Node* tail=newhead;
       
       tail->next=new Node(ans[0]);
       
       tail=tail->next;
       
       for( int i=1;i<ans.size();i++)
       {
           if(ans[i]!=ans[i-1])
           {
               tail->next=new Node(ans[i]);
               tail=tail->next;
           }
           
       }
       head = newhead->next;
       
       delete newhead;
       return head;
    }
};//TC and SC:O( n )
