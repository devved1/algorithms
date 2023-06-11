#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
int up[200005][20];
vector<int>grp[200005];

void binarylift(int src,int par){
    
    up[src][0]=par;
    for(int i=1;i<20;i++){
        if(up[src][i-1]!=-1){
            up[src][i]=up[up[src][i-1]][i-1];
        }
        else{
            up[src][i]=-1;
        }
    }

    for(auto child:grp[src]){
        if(child!=par){
         binarylift(child,src);
        }
    }
}

int query(int node,int level){
  
  if(level==0 ||  node==-1){
    return node;
  }
  for(int i=19;i>=0;i--){
    if(level>=(1<<i)){
        return query(up[node][i],level-(1<<i));
    }
  }

}

void solve(){

int n,q;cin>>n>>q;
for(int i=2;i<=n;i++){
    int a;cin>>a;
    grp[a].push_back(i);
    grp[i].push_back(a);
}
binarylift(1,-1);
while(q--){
    int a,b;cin>>a>>b;
    cout<<query(a,b)<<"\n";
}

}
   
int32_t main(){
    //int t;cin>>t;
    int t=1;
    while(t--){
        solve();
    }
}