#include <bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int wt;
    node(int x,int y,int z){
        u=x;
        v=y;
        wt=z;
    }
};
bool comp(node a,node b){
    return a.wt<b.wt;
}
int findParent(int node,int parent[]){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findParent(parent[node],parent);
}
int Union(int u,int v,int parent[],int rank[]){
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(),edges.end(),comp);
    int parent[n];
    int rank[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto x:edges){
        if(findParent(x.v,parent)!=findParent(x.u,parent)){
            cost+=x.wt;
            mst.push_back({x.u,x.v});
            Union(x.u,x.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    for(auto x:mst){
        cout<<x.first<<"-"<<x.second<<endl;
    }
    return 0;
}