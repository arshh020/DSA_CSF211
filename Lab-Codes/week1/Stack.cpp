#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define MAX_SIZE 100
#define MAX_NAME_LEN 20
#define MAX_DATE_LEN 10

struct student {
  char id[12];
  char name[MAX_NAME_LEN];
  char dob[MAX_DATE_LEN];
  float cgpa;
};

student studenStack[MAX_SIZE];
int top = -1;

bool isFull() {
  return top == MAX_SIZE - 1;
}

bool isEmpty() {
  return top == -1;
}

void push(student data) {
  if (isFull()) {
    cout << "Stack overflow" << endl;
    return;
  }
  studenStack[++top] = data;
}

student pop() {
  if (isEmpty()) {
    cout << "Stack underflow" << endl;
  }
  return studenStack[top--];
}

void printStudent(student student) {
  cout << student.id << " " << student.name << " " << student.dob << " " << student.cgpa << endl;
}

int main() {
  ifstream in("studentin.dat");
  ofstream out("studentout.dat");

  if (!in.is_open()) {
    cout << "Error opening input file" << endl;
    return 1;
  }

  if (!out.is_open()) {
    cout << "Error opening output file" << endl;
    in.close();
    return 1;
  }

  student current_student;
  while (in >> current_student.id >> current_student.name >> current_student.dob >> current_student.cgpa) {
    push(current_student);
  }

  while (!isEmpty()) {
    student popped_student = pop();
    printStudent(popped_student);
    out << popped_student.id << " " << popped_student.name << " " << popped_student.dob << " " << popped_student.cgpa << endl;
  }

  in.close();
  out.close();

  return 0;
}
