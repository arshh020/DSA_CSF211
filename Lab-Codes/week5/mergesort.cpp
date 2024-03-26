#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Student {
    char id[14];
    char name[50];
    int year;
    double cgpa;
};

void merge(Student *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i].name, R[j].name) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Student *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    ifstream file("studentin.dat");

    Student student;
    int size = 1;
    int index = 0;
    Student *arr = new Student[size];

    while (file >> student.id >> student.name >> student.year >> student.cgpa) {
        arr = (Student *)realloc(arr, ++size * sizeof(Student));
        arr[index++] = student;
    }

    clock_t t = clock();
    mergeSort(arr, 0, index - 1);
    t = clock() - t;

    cout << "Sort Time: " << (double)t/CLOCKS_PER_SEC << endl;
    for (int i = 0; i < index; i++) {
        student = arr[i];
        cout << i + 1 << ". ID: " << student.id << "   NAME: " << student.name << "   Year: " << student.year << "   CGPA: " << student.cgpa << endl;
    }

    delete[] arr;
    return 0;
}
