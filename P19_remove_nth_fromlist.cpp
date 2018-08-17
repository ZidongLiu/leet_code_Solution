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
// 10ms, beat 75%
/*
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

void printlist(ListNode* l){
    while(l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
}


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head,*p2 = head;
        for(int i=1;i<=n;++i){
            p2 = p2->next;
        }
        if(p2==NULL){
            return(p1->next);
        }else{
            while(p2->next!=NULL){
                p1=p1->next;
                p2=p2->next;
            }
            if(n==1){
                p1->next = NULL;
            }else{
                p1->next = p1->next->next;
            }
            return(head);
        }

    }
};

*/