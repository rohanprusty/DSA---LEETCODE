/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;
        ListNode* groupStart = head;

        // we're starting with group 1, so intended no of nodes is 1
        int groupSize = 1;
        
        // while groupStart exists
        while(groupStart){
            int actualSize = 0;
            ListNode* groupEnd = groupStart;
            
            // find the actual size of the group and the groupEnd node
            while(groupEnd && actualSize < groupSize){
                actualSize++;
                if(actualSize == groupSize || !groupEnd->next){
                    break;
                }
                groupEnd = groupEnd->next;
            }
            
            // starting group of the next is just right after the groupEnd node
            ListNode* nextGroup = groupEnd->next;
            
            // reverse only if the actual number of nodes in the current group is even
            if(actualSize % 2 == 0){
                // By starting prev as nextGroup, we automatically connect 
                // the tail of our reversed list to the next part of the list
                ListNode* prev = nextGroup;
                ListNode* curr = groupStart;

                // reversal logic
                while(actualSize--){
                    ListNode* getnext = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = getnext;
                }

                // set the new groupStart and beforeGroup after reversal
                // prev is the new head of the group
                // connect it with the last node of the group before
                prevGroup->next = prev;
                // old groupStart becomes the new tail
                prevGroup = groupStart;
            }
            // if it is odd 
            // then set prevGroup directly to groupEnd 
            // cuz that's the last node of the group before in case of odd length
            else{
                prevGroup = groupEnd;
            }

            groupStart = nextGroup;
            // process 1 node -> 1st group
            // process 2 nodes -> 2nd group 
            // process n nodes -> nth group
            groupSize++;
        }
        
        return dummy.next;
    }
};