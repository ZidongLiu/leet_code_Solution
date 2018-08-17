
/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};


void printlist(ListNode* l){
    while(l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* Curr;
        ListNode* p1;
        ListNode* p2;
        p1 = l1;
        p2 = l2;
        int x,y,carry,sum;
        carry = 0;
        Curr = ret;
        while(p1!=NULL || p2!=NULL){
            if(p1!=NULL){
                x = p1->val;
                p1 = p1->next;
            }else{
                x = 0;
            }
            if(p2!=NULL){
                y =p2->val;
                p2 = p2->next;
            }else{
                y = 0;
            }
            sum = x+y+carry;
            Curr->next = new ListNode(sum%10);
            carry = sum/10;
            Curr = Curr->next;
        }
        if(carry>0){
            Curr->next = new ListNode(carry);
        }
        return ret->next;
    }
};

*/

