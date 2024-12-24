#include <bits/stdc++.h>
using namespace std;
void shortestPath(int vertex,int src,vector<pair<int,int>> graph[]){
    int dis[vertex];   //distance array of every vertex
    for(int i=0;i<vertex;i++){
        dis[i]=1e9;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;  //queue with comparator
    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int dist=pq.top().first;
        int pre=pq.top().second;
        pq.pop();
        vector<pair<int,int>>::iterator it;
        for(auto it:graph[pre]){
            int next=it.first;
            int nextWt=it.second;
            if(dis[next]>dis[pre]+nextWt){
                dis[next]=dis[pre]+nextWt;
                pq.push({dis[next],next});
            }
        }
    }
    cout<<"Shortest distance from src to every vertex:"<<endl;
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> "<<dis[i]<<endl;
    }
}
int main(){
    int edges,vertex;
    cin>>edges>>vertex;
    vector<pair<int,int>> graph[vertex];
    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<"("<<x.first<<","<<x.second<<") ";
        }
        cout<<endl;
    }
    shortestPath(vertex,0,graph);
    return 0;
}