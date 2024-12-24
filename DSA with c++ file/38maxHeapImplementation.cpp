#include <bits/stdc++.h>
using namespace std;
class maxHeap{
    public:
    int *arr;
    int heapSize;
    int capacity;
    maxHeap(int cap){
        capacity=cap;
        heapSize=0;
        arr=new int[cap];
    }
    void insertMaxHeap(int k){
        if(heapSize==capacity){
            cout<<"Overflow";
        }
        heapSize++;
        int i=heapSize-1;
        arr[i]=k;
        while(i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    int extractMax(){
        if(heapSize<=0){
            return -1;
        }
        if(heapSize==1){
            heapSize--;
            return arr[0];
        }
        int root=arr[0];
        arr[0]=arr[heapSize-1];
        heapSize--;
        maxHeapify(0);
        return root;
    }
    void maxHeapify(int i){
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l<heapSize && arr[l]>arr[i]){
            largest=l;
        }
        if(r<heapSize && arr[r]>arr[largest]){
            largest=r;
        }
        swap(arr[i],arr[largest]);
        maxHeapify(largest);
    }
};
int main(){
    maxHeap mh(5);
    mh.insertMaxHeap(5);
    mh.insertMaxHeap(4);
    mh.insertMaxHeap(3);
    mh.insertMaxHeap(2);
    mh.insertMaxHeap(1);
    cout<<"Max heap: ";
    for(int i=0i<mh.heapSize;i++){
        cout<<mh.arr[i]<<" ";
    }
    return 0;
}