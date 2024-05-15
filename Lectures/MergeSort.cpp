#include <bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedVec(vector<int> &a, vector<int> &b){
    int i = 0, j = 0, k = 0;
    vector<int> ans(a.size() + b.size());

    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            ans[k] = a[i];
            i++;
            k++;
        }
        else{
            ans[k] = b[j];
            j++;
            k++;
        }
    }

    while(i < a.size()){
        ans[k] = a[i];
        i++;
        k++;
    }

    while(j < b.size()){
        ans[k] = b[j];
        j++;
        k++;
    }

    return ans;
}

vector<int> mergeSort(vector<int> &vec, int low, int high){
    if(low >= high){
        vector<int> ba;
        ba.push_back(vec[low]);
        return ba;
    }

    int mid = (low + high)/2;
    vector<int> first = mergeSort(vec, low, mid);
    vector<int> second = mergeSort(vec, mid + 1, high);
    vector<int> sorted = mergeTwoSortedVec(first, second);

    return sorted;
}

int main(){
    int num;
    cout << "Enter num of elements: " << endl;
    cin >> num;
    vector<int> vec;
    cout << "Enter elements: " << endl;
    for(int i = 0; i<num; i++){
        int inp;
        cin >> inp;
        vec.push_back(inp);
    }

    vector<int> ans = mergeSort(vec, 0, num - 1);
    cout << "Sorted vector: " << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}