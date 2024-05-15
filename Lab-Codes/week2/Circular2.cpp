//REVISED CODE
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
using namespace std;

#define CAPACITY 10

struct Student {
    char id[14];
    char name[50];
    char dob[20];
    double cgpa;
};

struct Queue {
    Student data[CAPACITY];
    int first;
    int last;
};

void enqueue(Queue*, Student);
void dequeue(Queue*);
void display(Queue*);

int main() {
    Student student;
    Queue queue;
    queue.first = queue.last = -1;
    ifstream file("studentin.dat");
    while (file >> student.id >> student.name >> student.dob >> student.cgpa) {
        enqueue(&queue, student);
    }
    file.close();

    display(&queue);

    while (queue.first < (queue.last) % CAPACITY) {
        dequeue(&queue);
    }
}

void enqueue(Queue *queue, Student student) {
    if (queue->first == (queue->last + 1) % CAPACITY) {
        cout << "Queue Overflow\n";
        return;
    }
    queue->last = (queue->last + 1) % CAPACITY;
    queue->data[queue->last] = student;
}

void dequeue(Queue *queue) {
    if (queue->first == -1 && queue->last == -1) {
        cout << "Queue Underflow\n";
        return;
    }
    queue->first = (queue->first + 1) % CAPACITY;
    cout << "Dequeued Record: ID: " << queue->data[queue->first].id
              << ", Name: " << queue->data[queue->first].name
              << ", DOB: " << queue->data[queue->first].dob
              << ", CGPA: " << queue->data[queue->first].cgpa << endl;
}

void display(Queue *queue) {
    ofstream file("studentout.dat");

    cout << "Student Records:" << endl;
    file << "Student Records in FIFO order:" << endl;
    for (int i = queue->first + 1; i < (queue->last + 1); ++i) {
        cout << "ID: " << queue->data[i].id
                  << ", Name: " << queue->data[i].name
                  << ", DOB: " << queue->data[i].dob
                  << ", CGPA: " << queue->data[i].cgpa << endl;
        file << "ID: " << queue->data[i].id
             << ", Name: " << queue->data[i].name
             << ", DOB: " << queue->data[i].dob
             << ", CGPA: " << queue->data[i].cgpa << endl;
    }

    file.close();

    cout << "Students With CGPA Less Than 9:" << endl;

    for (int i = queue->first + 1; i < (queue->last + 1); ++i) {
        if (queue->data[i].cgpa < 9.0) 
            std::cout << queue->data[i].name << endl;
    }
}
