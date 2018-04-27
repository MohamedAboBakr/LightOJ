#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll> pll;

int st[400010];
ll mn[400010],mx[400010];

void add(int p,int l,int r,ll val){
   if(l==r){
      st[p]=1;
      mn[p]=val;
      mx[p]=val;
      return;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   if(st[lft]==mid-l+1) add(rgt,mid+1,r,val);
   else add(lft,l,mid,val);
   if(st[rgt]==0){
      mn[p]=mn[lft];
      mx[p]=mx[lft];
   }else{
      mn[p]=min(mn[lft],mn[rgt]);
      mx[p]=max(mx[lft],mx[rgt]);
   }
   st[p]=st[lft]+st[rgt];
}

pll query(int p,int l,int r,int i,int j){
     if(i>r || j<l)   return pll(-1L,-1L);
     if(i<=l && j>=r) return pll(mn[p],mx[p]);
     int lft,rgt,mid,mn;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     pll pll1,pll2;
     pll1 = query(lft,l,mid,i,j);
     pll2 = query(rgt,mid+1,r,i,j);
     if(pll1.first==-1L) return pll2;
     if(pll2.first==-1L) return pll1;
     return pll(min(pll1.first,pll2.first),max(pll1.second,pll2.second));
}

ll getMax(pll pl1,pll pl2){
    if(pl1.first==-1) return pl2.second-pl2.first;
    if(pl2.first==-1) return pl1.second-pl1.first;
    return max(abs(pl1.first-pl2.second),abs(pl1.second-pl2.first));
}

int main(){
 int t,n,d,j=1,l,r;scanf("%d",&t);
 ll a,mxx;
 pll pl1,pl2;
 while(j<=t){
    memset(st,0,sizeof(st));
    mxx=0L;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        add(1,0,n-1,a);
    }
    l=0,r=d-1;
    while(r<n){
        pl1 = query(1,0,n-1,l,r);
        mxx = max(mxx,pl1.second-pl1.first);
        l++;r++;
    }
    printf("Case %d: %lld\n",j,mxx);
    j++;
 }
 return 0;
}
