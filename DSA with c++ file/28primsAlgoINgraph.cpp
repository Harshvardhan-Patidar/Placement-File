#include <bits/stdc++.h>
using namespace std;
void mst(int vertex,vector<pair<int,int>> graph[]){
    int key[vertex];
    bool visited[vertex];
    int parent[vertex];
    for(int i=0;i<vertex;i++){
        key[i]=INT_MAX;
        visited[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<vertex-1;i++){
        int min=INT_MAX;
        int u;
        for(int j=0;j<vertex;j++){
            if(!visited[j] && key[j]<min){
                min=key[j];
                u=j;
            }
        }
        visited[u]=true;
        for(auto nbr:graph[u]){
            int v=nbr.first;
            int wt=nbr.second;
            if(visited[v]==false && wt<key[v]){
                parent[v]=u;
                key[v]=wt;
            }
        }
    }
    cout<<"Minimum spanning tree:"<<endl;
    for(int i=1;i<vertex;i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
}
void mstOptimizedApproch(int vertex,vector<pair<int,int>> graph[]){
    int key[vertex];
    bool visited[vertex];
    int parent[vertex];
    for(int i=0;i<vertex;i++){
        key[i]=INT_MAX;
        visited[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});
    for(int i=0;i<vertex-1;i++){
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        for(auto nbr:graph[u]){
            int v=nbr.first;
            int wt=nbr.second;
            if(visited[v]==false && wt<key[v]){
                parent[v]=u;
                pq.push({key[v],v});
                key[v]=wt;
            }
        }
    }
    cout<<"Minimum spanning tree:"<<endl;
    for(int i=1;i<vertex;i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
}
int main(){
    int edge,vertex;
    cin>>edge>>vertex;
    vector<pair<int,int>> graph[vertex];
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<"("<<x.first<<","<<x.second<<")"<<" ";
        }
        cout<<endl;
    }
    mst(vertex,graph);
    return 0;
}