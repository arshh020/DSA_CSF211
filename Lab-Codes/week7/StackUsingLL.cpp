#include <bits/stdc++.h>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct LinkedList {
    Node* head;
};

LinkedList create_stack() {
    LinkedList l;
    l.head = nullptr;
    return l;
}

void push(int p, LinkedList* l) {
    Node* newnode = new Node;
    if (newnode == nullptr) {
        return;
    }

    newnode->info = p;
    if (l->head == nullptr) {
        newnode->next = nullptr;
    }
    else {
        newnode->next = l->head;
    }
    l->head = newnode;
}

void pop(LinkedList* l) {
    if (l->head == nullptr) {
        cout << "Can't delete anymore\n";
    }
    else if (l->head->next == nullptr) {
        delete l->head;
        l->head = nullptr;
    }
    else {
        Node* temp = l->head;
        l->head = temp->next;
        delete temp;
    }
}

void check_emptiness(LinkedList* l) {
    if (l->head == nullptr) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
}

void display_all_elements(LinkedList* l) {
    Node* temp = l->head;
    if (l->head == nullptr) {
        cout << "The linked list is empty\n";
    }
    else {
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    LinkedList myList = create_stack();
    int choice = 0;
    while (choice != 5) {
        cout << "1. Push\n2. Pop\n3. Check emptiness\n4. Display all elements\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int ele;
            cout << "Enter an element that you want to push: ";
            cin >> ele;
            push(ele, &myList);
        }
        else if (choice == 2) {
            pop(&myList);
        }
        else if (choice == 3) {
            check_emptiness(&myList);
        }
        else if (choice == 4) {
            display_all_elements(&myList);
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
