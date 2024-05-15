#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

struct Student {
    char *name;
    int id;
    int enrollmentYear;
    float cgpa;
};

char *generateRandomName() {
    static const char *names[] = {
        "John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Isabella", "Oliver", "Amelia",
        "Benjamin", "Charlotte", "Elijah", "Mia", "Lucas", "Harper", "Mason", "Evelyn", "Logan", "Abigail",
        "Alexander", "Emily", "Ethan", "Elizabeth", "Jacob", "Avery", "Daniel", "Sofia", "Matthew", "Ava"
    };
    int numNames = sizeof(names) / sizeof(names[0]);
    const char *randomName = names[rand() % numNames];
    char *copiedName = new char[strlen(randomName) + 1];
    if (copiedName != nullptr) {
        strcpy(copiedName, randomName);
    }
    return copiedName;
}

void printStudents(Student arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << arr[i].name << ", ID: " << arr[i].id << ", Enrollment Year: " << arr[i].enrollmentYear
                  << ", CGPA: " << arr[i].cgpa << endl;
    }
    cout << endl;
}

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student arr[], int low, int high) {
    char *pivot = arr[high].name;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].name, pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        cout << "After iteration: " << high - low + 1 << endl;
        printStudents(arr, high - low + 1);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(nullptr));
    int numStudents = 10;
    Student students[numStudents];
    for (int i = 0; i < numStudents; ++i) {
        students[i].name = generateRandomName();
        students[i].id = 1000 + i;
        students[i].enrollmentYear = 2022 - (rand() % 5);
        students[i].cgpa = static_cast<float>(rand() % 401) / 100;
    }

    cout << "Unsorted Records:" << endl;
    printStudents(students, numStudents);

    clock_t start_time = clock();
    quickSort(students, 0, numStudents - 1);
    clock_t end_time = clock();

    double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sorted Records:" << endl;
    printStudents(students, numStudents);
    cout << "Time taken: " << execution_time << " seconds" << endl;

    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].name;
    }

    return 0;
}
