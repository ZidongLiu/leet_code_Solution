//
// Created by Zidong Liu on 6/4/18.
//
/*
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode* generate_list(vector<int> input){
    ListNode *dummy = new ListNode(0),*cur;
    cur = dummy;
    for(int i=0;i<input.size();i++){
        cur->next = new ListNode(input[i]);
        cur = cur->next;
    }
    return(dummy->next);
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return(NULL);
        }
        if(head->next==NULL){
            return(head);
        }
        ListNode *temp;
        temp = head->next;
        temp->next = head;
        temp->next->next = swapPairs(head->next->next);
        return(temp);
    }
};

 */

/*
 *  excellent solution
 *
 *
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head;
        ListNode *a = nullptr;
        ListNode *b = nullptr;
        while((a = *pp) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};
 */