#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


ll st[400010],arr[100010];
ll mod=1000000007;
map<ll,int> mp;
set<ll> sett;

void add(int p,int l,int r,int index,ll val){
   if(index<l||index>r) return;
   if(l==r){
      st[p]=(st[p]+val)%mod;
      return;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   add(lft,l,mid,index,val);
   add(rgt,mid+1,r,index,val);
   st[p]=(st[lft]+st[rgt])%mod;
}

ll sum(int p,int l,int r,int i,int j){
    if(i>r || j<l) return 0L;
    if(i<=l && j>=r) return st[p];
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    return (sum(lft,l,mid,i,j)+sum(rgt,mid+1,r,i,j))%mod;
}


int main(){
  int t,n,q,l,r,j=1; scanf("%d",&t);
  while(j<=t){
     ll ans=0L;
     memset(st,0,sizeof(st));
     mp.clear();
     sett.clear();
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         scanf("%lld",&arr[i]);
         sett.insert(arr[i]);
     }
     q=0;
     set<ll>::iterator it=sett.begin();
     for(; it!= sett.end();it++){
          mp[*it]=q++;
     }
     for(int i=0;i<n;i++){
         int index=mp[arr[i]];
         ll sm = sum(1,0,n-1,0,index-1);
         ans = ((ans+sm)%mod+1)%mod;
         add(1,0,n-1,index,(sm+1)%mod);
     }
     printf("Case %d: %lld\n",j,ans);
     j++;
  }
  return 0;
}
