#include<iostream>
using namespace std;
// recursive implementation
bool isArraySorted(int* arr, int n) {
    if(n == 0 || n == 1) 
        return true;
    if(arr[0] > arr[1])
        return false;
    return isArraySorted(arr+1, n-1);
}

int main() {

    int arr[6
    ] = {1,2,3,4,5,1};
    
    cout << "Array is sorted?: " << isArraySorted(arr, 6) << endl;

    return 0;
}