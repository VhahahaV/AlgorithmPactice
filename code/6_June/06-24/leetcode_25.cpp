//
// Created by VhahahaV on 2024/6/25.
//
#include <bits/stdc++.h>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur,*nex;
        cur = nex = head;
        ListNode *ans;
        ListNode *LastRankNext = nullptr;
        for(int rank = 0 ; ;rank++){
            int flag = false;
            for(int i = 0 ; i < k ; i++){
                if(!nex){
                    flag=true;
                    break;
                }
                nex = nex->next;
            }
            if(!flag){
                auto nextRank = nex;
                auto tmpLastRankNext = LastRankNext;
                LastRankNext = cur;
                while(cur != nextRank){
                    ListNode *tmp = cur->next;
                    cur->next = nex;
                    nex = cur;
                    cur = tmp;
                }
                if(rank == 0)
                    ans = nex;
                if(tmpLastRankNext)
                    tmpLastRankNext->next = nex;
                nex = nextRank;

            }
            else
                break;
        }
        return ans;
    }
};