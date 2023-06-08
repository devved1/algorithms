#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
 int n,m,k;cin>>n>>m>>k;
 vector<int>grp[n+5];
 int dis[n+5]={0};
 int nodes[n+5]={0};
 bool vis[n+5]={false};
 for(int i=0;i<k;i++){
    cin>>nodes[i];
 }
  queue<int>qu;
 for(int i=0;i<k;i++){
   int dist;cin>>dist;
   dis[nodes[i]]=max(dist-1,dis[nodes[i]]);
   if(!vis[nodes[i]]){
   qu.push(nodes[i]);}
   vis[nodes[i]]=true;
 }
 

 for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    grp[a].push_back(b);
    grp[b].push_back(a);
 }
 while(!qu.empty()){
    int node=qu.front();
    qu.pop();
    if(dis[node]==0)continue;
    for(auto x:grp[node]){
        if(dis[x]<dis[node]){
            vis[x]=true;
            dis[x]=dis[node]-1;
            qu.push(x);
        }
    }
 }

 for(int i=1;i<=n;i++){
    if(!vis[i]){
        cout<<"NO"<<"\n";return;
    }
 }
 cout<<"YES"<<"\n";

}
int32_t main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}