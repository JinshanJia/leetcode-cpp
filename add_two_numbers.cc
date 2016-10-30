#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummyHead = ListNode(0);
    ListNode* currentNode = &dummyHead;
    int carry = 0;
    ListNode* head1 = l1;
    ListNode* head2 = l2;
    int sum = 0;
    while(head1 != nullptr || head2 != nullptr) {
      sum = carry;
      if (head1 != nullptr) {
        sum += head1->val;
        head1 = head1->next;
      }
      if (head2 != nullptr) {
        sum += head2->val;
        head2 = head2->next;
      }
      currentNode->next = new ListNode(sum % 10);
      carry = sum / 10;
      currentNode = currentNode->next;
    }
    if (carry > 0) {
      currentNode->next = new ListNode(carry);
    }
    return dummyHead.next;
  }
};

ListNode* getNodeFromVector(vector<int> v) {
  ListNode* result = nullptr;
  ListNode* currentNode = result;
  for (int i : v) {
    if (currentNode == nullptr) {
      result = new ListNode(i);
      currentNode = result;
    } else {
      currentNode->next = new ListNode(i);
      currentNode = currentNode->next;
    }
  }
  return result;
}

void printList(ListNode* list) {
  while (list != nullptr) {
    cout << list->val << "->";
    list = list->next;
  }
  cout << endl;
}

void deleteList(ListNode* head) {
  ListNode* currentNode = head;
  ListNode* next = nullptr;
  while(currentNode != nullptr) {
    next = currentNode->next;
    delete(currentNode);
    currentNode = next;
  }
}


int main() {
  Solution s;
  vector<int> l1({2, 4, 3});
  vector<int> l2({9, 9, 9, 9});

  ListNode* list1 = getNodeFromVector(l1);
  ListNode* list2 = getNodeFromVector(l2);

  ListNode* result = s.addTwoNumbers(list1, list2);

  printList(result);

  deleteList(list1);
  deleteList(list2);
  deleteList(result);
  return 0;
}
