#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

void insertionSort(int elementsint[], int n) {
    int i, temp, j;
    for (i = 1; i <= n+1; i++) {
        temp = elementsint[i];
        j = i - 1;

        while (j >= 0 && elementsint[j] > temp) {
            elementsint[j + 1] = elementsint[j];
            j = j - 1;
        }
        elementsint[j + 1] = temp;
    }
}

void linearSearch(int size, int elementsint[], int num, ofstream& outFile) {
    int flag = 0;
    clock_t start, end;                    //measure time take to search
    start = clock();

    insertionSort(elementsint, size);

    for (int i = 0; i <= size+1; i++) {
        if (elementsint[i] == num) {
            end = clock();
            outFile << "Input Position Search_time\n";
            outFile << num << " " << i << " " << (int)end << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        outFile << "Element not found\n";
    }
}

void binarySearch(int size, int elementsint[], int num, ofstream& outFile) {
    int left = 0;
    int right = size-1;
    clock_t start, end;                  //meaure time taken to search
    start = clock();

    insertionSort(elementsint, size);

    while (left <= right) {
        int mid = (left + right)/2;
        if (num > elementsint[mid]) {
            left = mid + 1;
        }
        else if (num < elementsint[mid]) {
            right = mid - 1;
        }
        else if (num == elementsint[mid]) {
            end = clock();
            outFile << "Input Position Search_time\n";
            outFile << num << " " << mid << " " << (int)end << endl;
            return;
        }
    }
    outFile << "Element not found\n";
}

int main() {
    int size, num, line;
    char a[20];
    char *elements = new char[3000000];

    cout << "Enter test case size from 1 to 15: ";
    cin >> line;
    if (line > 15 || line < 1) {
        cout << "Invalid size" << endl;
        exit(1);
    }

    ifstream fptr("testCaseSize.txt");
    if (!fptr) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    for(int i = 1; i <= line; i++) {
        fptr.getline(a, sizeof(a));            //jumping to line of size provided by user in testCaseSize file
    }
    fptr.close();
    size = atoi(a);

    cout << "Enter number to be searched: ";
    cin >> num;

    ifstream fptr2("searchTestCase.txt");
    if (!fptr2) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    for(int i = 1; i <= line; i++) {
        fptr2.getline(elements, 3000000);        //saving all characters of that line in char array
    }
    fptr2.close();

    int *elementsint = new int[500000];
    int i = 0;
    char *token = strtok(elements, " ");
    elementsint[0] = atoi(token);
    while ((token = strtok(NULL, " ")) != NULL) {            //tokenizing each individual element in the char array to an int array
        i++;
        elementsint[i] = atoi(token);
    }
    delete[] elements;

    ofstream outFile("linearSearchResults.txt");
    if (!outFile) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    linearSearch(size, elementsint, num, outFile);
    outFile.close();

    ofstream outFile2("binarySearchResults.txt");
    if (!outFile2) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    binarySearch(size, elementsint, num, outFile2);
    outFile2.close();
    delete[] elementsint;

    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <chrono>

// using namespace std;
// using namespace std::chrono;

// // Function to perform linear search
// pair<int, long long> linearSearch(const vector<int>& arr, int x) {
//     auto start = high_resolution_clock::now();
//     int position = -1;
//     for (int i = 0; i < arr.size(); ++i) {
//         if (arr[i] == x) {
//             position = i;
//             break;
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     return {position, duration.count()};
// }

// // Function to perform binary search
// pair<int, long long> binarySearch(const vector<int>& arr, int x) {
//     auto start = high_resolution_clock::now();
//     int low = 0, high = arr.size() - 1;
//     int position = -1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (arr[mid] == x) {
//             position = mid;
//             break;
//         } else if (arr[mid] < x) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     return {position, duration.count()};
// }

// int main() {
//     ifstream testCaseSizeFile("testCaseSize.txt");
//     ifstream searchTestCaseFile("searchTestCase.txt");
//     ofstream linearSearchResults("linearSearchResults.txt");
//     ofstream binarySearchResults("binarySearchResults.txt");

//     if (!testCaseSizeFile || !searchTestCaseFile || !linearSearchResults || !binarySearchResults) {
//         cerr << "Error opening files." << endl;
//         return 1;
//     }

//     vector<int> testCaseSizes;
//     int size;
//     while (testCaseSizeFile >> size) {
//         testCaseSizes.push_back(size);
//     }

//     for (int i = 0; i < testCaseSizes.size(); ++i) {
//         int testSize = testCaseSizes[i];
//         vector<int> testCase(testSize);
//         for (int j = 0; j < testSize; ++j) {
//             searchTestCaseFile >> testCase[j];
//         }

//         int searchElement;
//         cout << "Enter the element to search for test case " << i+1 << " (1-15): ";
//         cin >> searchElement;

//         // Perform linear search
//         auto linearResult = linearSearch(testCase, searchElement);
//         linearSearchResults << searchElement << " " << linearResult.first << " " << linearResult.second << endl;

//         // Perform binary search
//         auto binaryResult = binarySearch(testCase, searchElement);
//         binarySearchResults << searchElement << " " << binaryResult.first << " " << binaryResult.second << endl;
//     }

//     cout << "Search results saved in linearSearchResults.txt and binarySearchResults.txt." << endl;

//     testCaseSizeFile.close();
//     searchTestCaseFile.close();
//     linearSearchResults.close();
//     binarySearchResults.close();

//     return 0;
// }
