/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //TC: O(N)
 //SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ///Here temp (keep head next), revLink(reverse the head->next)
        ListNode *temp, *revLink = NULL; 

        while(head)
        {
            temp = head->next; ///keep head->next in temp var

            head->next = revLink; ///reverse (a->b as a<-b). head->next point the revLink 
            revLink = head;//revLink store the values of head

            head = temp; //taking head to the next.
        }

        return revLink; /// revLink is the new Linked List (reversed order) 
    }
};
