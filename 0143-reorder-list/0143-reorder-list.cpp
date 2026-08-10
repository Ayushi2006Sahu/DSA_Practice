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
    ListNode* middle(ListNode* head){
        ListNode* fir = head;
        ListNode* sec = head;
        while(sec!=NULL && sec->next!=NULL){
            fir = fir->next;
            sec = sec->next->next;
        }
        return fir;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next =prev;
            prev = temp;
            temp = front;
        }
        return prev;

    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode* mid = middle(head);
        ListNode* sec = reverse(mid->next);
        ListNode* first = head;
        mid->next = NULL;
        while(sec!=NULL){
            ListNode* t1 = first->next;
            ListNode* t2 = sec->next;
            first->next = sec;
            sec->next =t1;
            first = t1;
            sec = t2;
        }
    }
};