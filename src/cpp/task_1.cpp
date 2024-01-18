#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class Problem1 {
public:
    void mergeNodes(Node* start, Node* end) {
        if (start == nullptr || start->next == nullptr || start->next == end)
            return;

        int sum = 0;
        Node* curr = start->next;
        while (curr != end) {
            sum += curr->val;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        start->next = new Node(sum);
        start->next->next = end;
    }

    void processLinkedList(Node* head) {
        // Q1: Start state
        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == 0 && curr->next->val == 0) {
                // Q2: Found two consecutive zeros
                Node* nextZero = curr->next->next;
                mergeNodes(curr, nextZero);
                // Q3: Merged nodes and updated the linked list
            }
            curr = curr->next;
        }
        // Q4: End state
    }

    void printLinkedList(Node* head) {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 3, 4, 5, 0, 6, 0, 7, 8, 0};

    Node* head = new Node(0);
    Node* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new Node(nums[i]);
        curr = curr->next;
    }


    Problem1 problem;
    problem.processLinkedList(head);
    problem.printLinkedList(head);

    curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
