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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *Dummy = new ListNode(0);
        Dummy->next=head;
        ListNode * point = Dummy;

        while(point->next!=NULL && point->next->next!=NULL){
            ListNode* swap1=point->next;
            ListNode* swap2=point->next->next;
            swap1->next=swap2->next;
            swap2->next=swap1;
            point->next=swap2;
            point=swap1;
        }
        return Dummy->next;
    }
};