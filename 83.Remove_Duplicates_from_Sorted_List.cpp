// Q: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp_head = head;
        while (temp_head != NULL && temp_head->next != NULL)
        {
            ListNode *temp = temp_head->next;
            while (temp != NULL && temp_head->val == temp->val)
                temp = temp->next;
            temp_head->next = temp;
            temp_head = temp_head->next;
        }
        return head;
    }
};