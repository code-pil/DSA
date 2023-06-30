#include<bits/stdc++.h>
using namespace std;

class heap{

public:

    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size += 1;
        int index = size;
        arr[index]=val;

        while(index > 1){
            int parent = index/2;
            if(arr[index] < arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else return;
        }
    }

    void deletFromHeap(){
        arr[1] = arr[size];
        
        size -= 1;
        int index=1;

        while(index < size){
            int lchild = index*2;
            int rchild = index*2+1;

            if(lchild < size && arr[index] > arr[lchild]){
                swap(arr[index], arr[lchild]);
                index = lchild;
            }
            else if(rchild < size && arr[index] > arr[rchild]){
                swap(arr[index], arr[rchild]);
                index = rchild;
            }
            else return;
        }

    }

    void print(){
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

};

//MIN HEAP
void heapify_min(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[smallest] > arr[left]) smallest = left;
    if(right <= n && arr[smallest] > arr[right]) smallest = right;

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify_min(arr, n, smallest);
    }
    return;
}

//MAX HEAP
void heapify_max(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]) largest = left;
    if(right <= n && arr[largest] < arr[right]) largest = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify_max(arr, n, largest);
    }
    return;
}


void heapSort(int arr[], int n){
    int size = n;

    while(size>1){
        swap(arr[size], arr[1]);
        size--;
        heapify_max(arr, size, 1);
    }
}

int main(){

    heap h;
    h.insert(10);
    h.insert(9);
    h.insert(8);
    h.insert(50);
    h.print();
    h.deletFromHeap();
    h.print();

    //Heapify Algorithm
    int arr[6] = {-1,5,4,3,2,1};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify_max(arr, n, i);
    }

    cout << "Heap" << endl;
    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }cout << endl;

    cout << "Heap Sort" << endl;

    heapSort(arr, 5);

    for(int i=1;i<=n;i++){
        cout << arr[i] << " " ;
    }cout << endl;


    return 0;
}