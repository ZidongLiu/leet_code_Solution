//
// Created by Zidong Liu on 8/22/18.
//

////// 8ms,
////// beat 98.21%, medium solution

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return(head);
        }
        ListNode *this_node = head, *prev;
        int n=1;
        while(this_node->next!=NULL){
            n++;
            this_node = this_node->next;
        }
        this_node->next = head;
        k%=n;
        prev = this_node;
        this_node = head;
        for(int i=1;i<=(n-k);i++){
            prev = prev->next;
            this_node = this_node->next;
        }
        prev->next = NULL;
        return(this_node);
    }
    void printNode(ListNode *head){
        cout<<head->val<<"  ";
        if(head->next!=NULL){
            printNode(head->next);
        }
    }
};
