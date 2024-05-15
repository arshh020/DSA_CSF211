#include <bits/stdc++.h>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

LinkedList create_queue() {
    LinkedList l;
    l.head = nullptr;
    l.tail = nullptr;
    return l;
}

void enqueue(int p, LinkedList* l) {
    Node* newnode = new Node;
    newnode->info = p;
    newnode->next = nullptr;

    if (l->head == nullptr && l->tail == nullptr) {
        l->head = newnode;
        l->tail = newnode;
    }
    else {
        l->tail->next = newnode;
        l->tail = newnode;
    }
}

void dequeue(LinkedList* l) {
    if (l->head == nullptr && l->tail == nullptr) {
        cout << "Can't delete anymore\n";
    }
    else if (l->head == l->tail) {
        delete l->head;
        l->head = nullptr;
        l->tail = nullptr;
    }
    else {
        Node* temp = l->head;
        l->head = temp->next;
        delete temp;
    }
}

void check_emptiness(LinkedList* l) {
    if (l->head == nullptr && l->tail == nullptr) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
}

void display_all_elements(LinkedList* l) {
    Node* temp = l->head;
    if (l->head == nullptr && l->tail == nullptr) {
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
    LinkedList myList = create_queue();
    int choice = 0;
    while (choice != 5) {
        cout << "1. Enqueue\n2. Dequeue\n3. Check emptiness\n4. Display all elements\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int ele;
            cout << "Enter an element that you want to enqueue: ";
            cin >> ele;
            enqueue(ele, &myList);
        }
        else if (choice == 2) {
            dequeue(&myList);
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
