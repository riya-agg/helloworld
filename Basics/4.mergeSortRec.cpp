// merge sort implementation
// recursively
#include<iostream>
using namespace std;

void merge(int *tmp, int low, int high) {
    
    int mid = low + ( high - low ) / 2;
    int sizeA = mid - low + 1;
    int sizeB = high - mid;

    int *arrA = new int[sizeA];
    int *arrB = new int[sizeB];

    int i = 0, j = 0, k = low;
    for(int x = 0; x < sizeA; x++) {
        arrA[x] = tmp[k++];
    }

    for(int x = 0; x < sizeB; x++) {
        arrB[x] = tmp[k++];
    }

    // merging 2 sorted arrays
    i = 0, j = 0, k = low;
    while( i < sizeA && j < sizeB) {
        if(arrA[i] < arrB[j]){
            tmp[k++] = arrA[i++];
        }
        else {
            tmp[k++] = arrB[j++];
        }
    }


    while( i < sizeA ) {
        tmp[k++] = arrA[i++];
    }

    while( j < sizeB ) {
        tmp[k++] = arrB[j++];
    }

}

void mergeSort(int *nums, int low, int high) {
    if(low >= high)
        return;
    
    int mid = low + (high - low) / 2;

    mergeSort(nums, low, mid);
    
    mergeSort(nums, mid+1, high);

    merge(nums, low, high);
}

int main() {

    int arr[6] = {3,6,1,12,5,3};
    int size = 6;

    mergeSort(arr, 0, size-1);
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}