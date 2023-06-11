#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

// here i am posting O(log^n)
vector<int>grp[200005];
int up[200005][20];
int level[200005];

void dfs(int src,int par,int lvl){
    level[src]=lvl;
    for(auto child:grp[src]){
        if(child!=par){
            dfs(child,src,lvl+1);
        }
    }
}

void binarylift(int src,int par){
    up[src][0]=par;
    for(int i=1;i<=19;i++){
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

int liftnode(int node,int level){
    if(node==-1 || level==0)return node;
    for(int i=19;i>=0;i--){
        if(level>=(1<<i)){
            return liftnode(up[node][i],level-(1<<i));
        }
    }
}

int LCA(int u,int v){
    if(level[u]<level[v]){
        swap(u,v);
    }
    u=liftnode(u,level[u]-level[v]);
    int s=0,e=level[u];
    while(s<=e){
        int mid=(s+e)/2;
        int x1=liftnode(u,mid);
        int x2=liftnode(v,mid);
        if(x1==x2){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return liftnode(u,s);

}

void solve(){
   int n,q;cin>>n>>q;
   for(int i=2;i<=n;i++){
    int a;cin>>a;
    grp[a].push_back(i);
   }
   dfs(1,-1,0);
   binarylift(1,-1);

   while(q--){
    int a,b;cin>>a>>b;
    cout<<LCA(a,b)<<"\n";
   }
}

int32_t main(){
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
}