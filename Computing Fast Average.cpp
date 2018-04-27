#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll st[400010];

void add(int p,int l,int r,int i,int j,int num){
     if(i>r || j<l) return;
     if(i<=l && j>=r){
            //printf("%d  %d  %d  ---\n",l,r,num);
            st[p]=num;
            return;
     }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   if(st[p]!=-1){
        st[lft]=st[p];
        st[rgt]=st[p];
   }
   st[p]=-1;
   add(lft,l,mid,i,j,num);
   add(rgt,mid+1,r,i,j,num);
}


ll sum(int p,int l,int r,int i,int j){
    if(i>r || j<l) return 0L;
    if(st[p]==0) return 0L;
    if(i<=l && j>=r && st[p]!=-1) return (r-l+1)*st[p];
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    if(st[p]!=-1){
        st[lft]=st[p];
        st[rgt]=st[p];
    }
    st[p]=-1;
    return sum(lft,l,mid,i,j)+sum(rgt,mid+1,r,i,j);
}

int main(){
  int t,n,q,j=1,k,l,r,v;scanf("%d",&t);
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     scanf("%d%d",&n,&q);
     for(int i=0;i<q;i++){
         scanf("%d",&k);
         if(k==1){
             scanf("%d%d%d",&l,&r,&v);
             add(1,0,n-1,l,r,v);
         }else{
             scanf("%d%d",&l,&r);
             ll nm = sum(1,0,n-1,l,r);
             ll dm = r-l+1;
             if(nm%dm==0) printf("%lld\n",nm/dm);
             else {
                    ll gcd = __gcd(nm,dm);
                    printf("%lld/%lld\n",nm/gcd,dm/gcd);
             }
         }
     }
     j++;
  }
  return 0;
}
