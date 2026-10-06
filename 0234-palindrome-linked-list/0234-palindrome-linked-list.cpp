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
private:
    // Function to reverse linked list links.
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        // Reverse links one by one.
        while (current != nullptr) {
            ListNode* front = current->next;
            current->next = previous;
            previous = current;
            current = front;
        }
        return previous;
    }
public:
    // Function to check palindrome using second half reversal.
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        // Move slow to middle node.
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = secondHead;
        // Compare first half and reversed second half.
        while (second != nullptr) {
            if (first->val != second->val) {
                slow->next = reverseList(secondHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        slow->next = reverseList(secondHead);
        return true;
    }
};