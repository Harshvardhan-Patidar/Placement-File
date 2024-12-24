// find the shortest distance using bellman ford algorithm

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
int main(){
    int edges,vertex;
    cin>>edges>>vertex;
    vector<node> edge;
    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge.push_back(node(u,v,wt));
    }
    int dis[vertex];
    for(int i=0;i<vertex;i++){
        dis[i]=1e9;
    }
    int src=0;
    dis[src]=0;
    for(int i=0;i<vertex-1;i++){
        for(auto x:edge){
            if(dis[x.u]+x.wt<dis[x.v]){
                dis[x.v]=dis[x.u]+x.wt;
            }
        }
    }
    int count=0;
    for(auto x:edge){
        if(dis[x.u]+x.wt<dis[x.v]){
            cout<<"Negative cycle is present";
            count=1;
            break;
        }
    }
    if(count==0){
        for(int i=0;i<vertex;i++){
            cout<<i<<" -> "<<dis[i]<<endl;
        }
    }
    return 0;
}