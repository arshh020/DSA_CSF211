#include <bits/stdc++.h>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    char id[20];
    float cgpa;
    Student* next;
};

Student* head = nullptr;

void insert(int position, const char name[], const char id[], float cgpa) {
    Student* newStudent = new Student;
    strcpy(newStudent->name, name);
    strcpy(newStudent->id, id);
    newStudent->cgpa = cgpa;
    newStudent->next = nullptr;

    if (position == 1) {
        newStudent->next = head;
        head = newStudent;
        return;
    }

    Student* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position\n";
        delete newStudent;
        return;
    }

    newStudent->next = temp->next;
    temp->next = newStudent;
}

int find(const char name[]) {
    Student* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (strcmp(temp->name, name) == 0) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1;
}

int deleteStudent(const char name[]) {
    int position = find(name);

    if (position == -1) {
        cout << "Student not found\n";
        return -1;
    }

    if (position == 1) {
        Student* temp = head;
        head = head->next;
        delete temp;
    } else {
        Student* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        Student* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    return position;
}

void display() {
    Student* temp = head;
    while (temp != nullptr) {
        cout << temp->name << ", " << temp->id << ", " << temp->cgpa << endl;
        temp = temp->next;
    }
}

int size() {
    Student* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool isEmpty() {
    return head == nullptr;
}

int main() {
    int choice, position;
    char name[50], id[20];
    float cgpa;

    do {
        cout << "\nList Operations:\n";
        cout << "1. Add a student record to the list\n";
        cout << "2. Find a student record by name\n";
        cout << "3. Delete a student record from the list\n";
        cout << "4. Display the list\n";
        cout << "5. isEmpty\n";
        cout << "6. Size\n";
        cout << "7. Exit\n";
        cout << "\nEnter Menu Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter ID no: ";
                cin >> id;
                cout << "Enter CGPA: ";
                cin >> cgpa;
                cout << "Enter index: ";
                cin >> position;
                insert(position, name, id, cgpa);
                cout << "Added the student record to the list\n";
                break;

            case 2:
                cout << "Enter the Name of the student: ";
                cin >> name;
                position = find(name);
                if (position != -1) {
                    cout << "The student " << name << " is present at index " << position << endl;
                } else {
                    cout << "Student not found\n";
                }
                break;

            case 3:
                cout << "Enter the Name of the student to be deleted from the list: ";
                cin >> name;
                position = deleteStudent(name);
                if (position != -1) {
                    cout << "The student " << name << " is deleted from the list." << endl;
                    cout << "There are " << size() << " records present in the list." << endl;
                    cout << "The student records present in the list are:" << endl;
                    display();
                }
                break;

            case 4:
                cout << "There are " << size() << " records present in the list. The student records present in the list are:" << endl;
                display();
                break;

            case 5:
                if (isEmpty()) {
                    cout << "The list is empty." << endl;
                } else {
                    cout << "The list is not empty." << endl;
                }
                break;

            case 6:
                cout << "The size of the list is " << size() << "." << endl;
                break;

            case 7:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}

