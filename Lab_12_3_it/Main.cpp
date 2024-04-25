#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

pair<Node*, Node*> createLists(int values[], int size) {
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node();
        newNode->data = values[i];
        if (values[i] >= 0) {
            if (head1 == nullptr) {
                head1 = newNode;
                tail1 = newNode;
            }
            else {
                tail1->next = newNode;
                newNode->prev = tail1;
                tail1 = newNode;
            }
        }
        else {
            if (head2 == nullptr) {
                head2 = newNode;
                tail2 = newNode;
            }
            else {
                tail2->next = newNode;
                newNode->prev = tail2;
                tail2 = newNode;
            }
        }
    }

    return make_pair(head1, head2);
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    int values[] = { 1, -2, 3, -4, 5, -6, 7, -8, 9 };
    int size = sizeof(values) / sizeof(values[0]);

    pair<Node*, Node*> lists = createLists(values, size);

    cout << "List of elements with positive values:" << endl;
    printList(lists.first);

    cout << "List of elements with negative values:" << endl;
    printList(lists.second);

    return 0;
}
