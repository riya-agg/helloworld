// Build Max heap using Heapify Algorithm
#include<iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size = 0;

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) { 
                // max heap
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else    
                return;
        }
    }

    void print() {
        // print heap
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]) // max heap
        largest = left;
    
    if(right <= n && arr[largest] < arr[right])
        largest = right;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // O(n log(n))
    int size = n;

    while(size > 1) {

        // step1: swap
        swap(arr[size], arr[1]);
        size--;

        // step2: heapify root node
        heapify(arr, size, 1); 

    }
}

int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout<<"After heapify: "<<endl;
    for(int i=0;i<= n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    // heap sort using max heap
    heapSort(arr, n);

    cout<<"After heap sort: "<<endl;
    for(int i=0;i<= n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
// test