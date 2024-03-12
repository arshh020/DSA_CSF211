#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> &vec, int n) {
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        // Move elements of vec[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
    return vec;
}

int main() {
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;

    vector<int> vec;
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++) {
        int inp;
        cin >> inp;
        vec.push_back(inp);
    }

    vector<int> ans = InsertionSort(vec, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
