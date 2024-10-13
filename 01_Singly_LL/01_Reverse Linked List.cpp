// Method 1: using array

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //create temporary node store head
        ListNode* temp = head;

        //create array to store linkedList
        vector<int> arr;

        //copy all the element of LL to the array
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int i=arr.size()-1;
        temp = head;

        //update LL element 
        while (temp != NULL) {
           temp->val=arr[i];
           i--;
           temp = temp->next;
        }

        return head;

    }
};//TC and SCO(n)

// Method 2:using previous and next pointer 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //create temporary node store head
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
     

        //traverse LL
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr=nextNode;
         
           
        }      

        return prev;

    }
};//TC:O(n) and SC: O(1)

// or  using previous and next pointer 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //create temporary node store head
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
     

        //traverse LL
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr=nextNode;
         
           
        }      

        head= prev;
        return head;

    }
};//TC:O(n) and SC: O(1)

//Method 3
class Solution {
public:
    ListNode* reverse(ListNode* prev, ListNode* curr) {
        //base case
        if (curr == nullptr) {
            return prev;
        }

        //one case
        ListNode* nextNode = curr->next;
        curr->next = prev;
        //recursion call
        return reverse(curr, nextNode);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};//TC and SC:O(n)