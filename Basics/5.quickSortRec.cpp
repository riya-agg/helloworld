// Quick sort using recursion
#include<iostream>
using namespace std;

int partition(int *arr, int s, int e) {
    // 1. set pivot
    int pivot = arr[s];
    int count = 0;
     
    // 2. count number of elements <= pivot
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot) 
            count++;
    }

    // 3. Put pivot at the right place
    swap(arr[s], arr[s+count]);

    // 4. Put all elements <= pivot to the left
    // and all elements > pivot to the right
    int i = s, j = e;
    int pivotInd = s + count;
    while(i < pivotInd && j > pivotInd) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < pivotInd && j > pivotInd) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotInd;


}

void quickSort(int *arr, int low, int high) {
    if(low >= high) 
        return;

    // 1. Partition
    int p = partition(arr, low, high);

    // 2. Recursion
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
}

int main() {

    int arr[7] = {4,5,2,3,14,6,1};
    int n = 7;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
