//STATIC APPROACH
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define SIZE 5

int front = 0;
int rear = -1;
char inp_array[SIZE][100];
char gpastorage[SIZE][5];
int j = 0;
int temp = 0;

void enqueue(char inp[100]) {

    if (rear == SIZE - 1) {        
        rear = -1;
    }
    
    rear = rear + 1;
    strcpy(inp_array[rear], inp);
}

void dequeue(ofstream &outFile) {

    char gpa[20];
    strncpy(gpa, inp_array[front] + 26, 4);           
    float gpaint = atof(gpa);

    if (gpaint < 9) {
        strncpy(gpastorage[j], inp_array[front] + 12, 4);    
        j++;
    }

    outFile << inp_array[front] << endl;
    cout << inp_array[front];
    
    if (front == SIZE - 1) {            
        front = 0;
    } else {
        front = front + 1;
    }

    temp++;
}

int main() {
    char a[100];
    ifstream fptr("studentin.dat");
    ofstream outFile("studentout.dat");

    if (!fptr || !outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    while (fptr.getline(a, sizeof(a))) {
        enqueue(a);
    }

    fptr.close();

    while (temp < SIZE) {
        dequeue(outFile);
        cout << endl;
    }

    cout << "Students with GPA < 9:" << endl;
    outFile << "Students with GPA < 9:" << endl;
    
    for (int i = 0; i < j; i++) {
        cout << gpastorage[i] << endl;
        outFile << gpastorage[i] << endl;            
    }

    outFile.close();

    return 0;
}
