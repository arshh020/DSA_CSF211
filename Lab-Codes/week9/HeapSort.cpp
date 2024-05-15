#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void swap(string& str1, string& str2) {
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

int compare(const string& arg1, const string& arg2) {
    return arg1.compare(arg2);
}

void heapify(vector<string>& array, size_t size, int index) {
    int root = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && compare(array[left], array[root]) > 0) {
        root = left;
    }

    if (right < size && compare(array[right], array[root]) > 0) {
        root = right;
    }

    if (root != index) {
        swap(array[root], array[index]);
        heapify(array, size, root);
    }
}

void heap_sort(vector<string>& array, size_t size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
    
    for (int i = size - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void print_array(const vector<string>& array) {
    for (const auto& str : array) {
        cout << str << " ";
    }
    cout << "\nSize: " << array.size() << endl;
}

int main() {
    vector<string> array;

    string input = "#$BiT, Raj1, Boy2, 1Kind, &zebra, Gate2, joKe1, poKer3, tRicK4, 3Dial, 1RoaD, QueeN7";
    string delimiter = ", ";
    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        array.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    array.push_back(input); 
    
    print_array(array);
    heap_sort(array, array.size());
    cout << "------------------------------------------------------" << endl;
    print_array(array);

    return 0;
}
