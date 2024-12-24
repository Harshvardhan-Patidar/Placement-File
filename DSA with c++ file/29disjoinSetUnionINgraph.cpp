#include <bits/stdc++.h>
using namespace std;
int findParent(int node,int parent[]){
    if(node==parent[node]){
        return node;      //if element is parent of itself then return that element
    }
    return parent[node]=findParent(parent[node],parent);   //path compression step
}
void Union(int u,int v,int parent[],int rank[]){
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rank[u]<rank[v]){          //greater rank combination will be now the parent of lesser rank combination
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{                 //if rank is similar then rank of one will be increase
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int n=5;
    int parent[n];
    int rank[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    Union(0,2,parent,rank);
    Union(2,4,parent,rank);
    Union(1,3,parent,rank);
    if(findParent(0,parent)==findParent(4,parent)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}