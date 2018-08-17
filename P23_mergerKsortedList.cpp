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
 /*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int n=k;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        vector<int> comp(k);
        for(int i=0;i<k;i++){
            comp[i] = lists[i]->val;
        }
        while(n>0){
            int min_ind = distance(comp.begin(),min(comp.begin(),comp.end()));
            cur->next = lists[min_ind];
            cur = cur->next;
            if(lists[min_ind]->next==NULL){
                --n;
                comp[min_ind] = 2000000;
            }else{
                lists[min_ind] = lists[min_ind]->next;
                comp[min_ind] = lists[min_ind]->val;
            }
        }
        return(dummy->next);
    }
};

  */

/*
#include <iostream>
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

void printlist(ListNode* l){
    while(l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int count = lists.size();
        if(count==0){
            return(NULL);
        }
        if(count==1){
            return(lists[0]);
        }
        int interval = 1;
        while(count>interval){
            for(int i=0;i<count-interval;i+=2*interval){
                merge(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return(lists[0]);
    }
private:
    void merge(ListNode* &l1, ListNode* &l2){
        if(l1==NULL){// if l1 is null
            if(l2==NULL){
                return;
            }else{
                l1 = l2;
                l2 = nullptr;
                return;
            }
        }else{// if l1 is not null
            if(l2==NULL){
                return;
            }else{
                ListNode* dummy = new ListNode(0),*cur;
                cur = dummy;
                while(!(l1==NULL&&l2==NULL)){
                    if(l1==NULL){
                        cur->next = l2;
                        break;
                    }
                    if(l2==NULL){
                        cur->next = l1;
                        break;
                    }
                    if(l1->val<l2->val){
                        cur->next = l1;
                        l1 = l1->next;
                    }else{
                        cur->next = l2;
                        l2 = l2->next;
                    }
                    cur = cur->next;
                }
                l1 = dummy->next;
                l2 = NULL;
                return;
            }
        }
    }
};

 */