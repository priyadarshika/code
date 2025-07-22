#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}             // default constructor
    ListNode(int x) : val(x), next(nullptr) {}        // single value
    ListNode(int x, ListNode* next) : val(x), next(next) {}  // value + next
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();  // Dummy node
        ListNode* temp = dummy;            // Temp pointer to build result
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next; // Result starts after dummy
    }
};

// ---------- Helper Functions for Testing ----------

// Create linked list from vector
ListNode* createList(const vector<int>& digits) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int num : digits) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ---------- Main for testing ----------
int main() {
    // Example: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result); // Output: 7 -> 0 -> 8 (which is 807)

    return 0;
}
