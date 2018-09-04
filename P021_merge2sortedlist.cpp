//
// Created by Zidong Liu on 6/3/18.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 14ms, beat 61%
 /*
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL){
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                l2 = l2->next;
                continue;
            }
            if(l2==NULL){
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                l1=l1->next;
                continue;
            }
            if(l1->val<l2->val){
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }

            cur = cur->next;
        }
        return(dummy->next);
    }
};
  */