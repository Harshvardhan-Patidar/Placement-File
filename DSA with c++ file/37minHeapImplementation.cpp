#include <bits/stdc++.h>
using namespace std;
class minHeap{
    public:
    int *arr;
    int capacity;
    int heapSize;
    minHeap(int cap){
        capacity = cap;
        heapSize = 0;
        arr = new int[capacity];
    }
}mh(5);
int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void insertMnHeap(int k){
    if(mh.heapSize==mh.capacity){
        cout<<"Overflow";
    }
    mh.heapSize++;
    int i=mh.heapSize-1;
    mh.arr[i]=k;
    while(i!=0 && mh.arr[parent(i)]>mh.arr[i]){
        swap(mh.arr[i],mh.arr[parent(i)]);
        i=parent(i);
    }
}
int extractMin(){
    if(mh.heapSize<=0){
        return -1;
    }
    if(mh.heapSize==1){
        mh.heapSize--;
        return mh.arr[0];
    }
    int root=mh.arr[0];
    mh.arr[0]=mh.arr[mh.heapSize-1];
    mh.heapSize--;
    minHeapify(0);   // use to convert the BT to minHeap BT
    return root;
}
void minHeapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<mh.heapSize && mh.arr[l]<mh.arr[i]){
        smallest=l;
    }
    if(r<heapSize && mh.arr[r]<mh.arr[smallest]){
        smallest=r;
    }
    swap(mh.arr[i],mh.arr[smallest]);
    minHeapify(smallest);
}
int main(){
    insertMnHeap(5);
    insertMnHeap(3);
    insertMnHeap(7);
    insertMnHeap(1);
    insertMnHeap(2);
    cout<<"Min heap: ";
    for(int i=0;i<mh.heapSize;i++){
        cout<<mh.arr[i]<<" ";
    }
    return 0;
}