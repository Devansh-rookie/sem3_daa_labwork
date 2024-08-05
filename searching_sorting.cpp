// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &arr, int key){
    for(int i=0;i<arr.size();i++){
        if(arr[i] == key) return i;
    }
    return -1;
}

int binary_search(vector<int> &arr, int key){
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while(high >= low){
        mid = low + (high - low)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key){
            high = mid-1;
        }
        else low = mid + 1;
    }
    return -1;
}

void printarr(vector<int>arr){
    cout << endl;
    for(int i: arr){
        cout << i;
    }
    cout<<endl;
}

void selection_sort(vector<int> arr){
    int curr = 0;
    int n = arr.size();

    for(int i=0;i<n-1;i++){
        // int val = INT_MAX;
        int index = i;
        for(int j=i;j<n;j++){
            // val = min(val, arr[j]);
            if(arr[j] < arr[index]){
                index = j;
            }
        }
        // arr[i] = val;
        swap(arr[index], arr[i]);
    }
    printarr(arr);
}

void bubble_sort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i < n;i++){
        for(int j=1;j<n;j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
    printarr(arr);
}

void insertion_sort(vector<int>arr){
    int n = arr.size();

    for(int i=1;i < n;i++){
        int key = arr[i];
        int j=i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];// shifting to the right
            j--;
        }
        arr[j+1] = key;
    }
    printarr(arr);
}

int main(){
    /*
    5
    5 3 4 1 2
    */
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i < n;i++){
        int val = 0;
        cin >> val;
        arr.push_back(val);
    }
    cout << linear_search(arr, 5);
    insertion_sort(arr);
    selection_sort(arr);
    bubble_sort(arr);
    cout << binary_search(arr, 4);
    return 0;
}