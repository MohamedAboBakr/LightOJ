#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll st[400010],arr[100010];

void build(int p,int l,int r){
    if(l==r){
         st[p]=arr[l];
         return;
    }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
   st[p]=st[lft]+st[rgt];
}

void add(int p,int l,int r,int index,ll val){
      if(index>r || index<l) return;
      if(l==r){
         st[p]+=val;
         return;
      }
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    add(lft,l,mid,index,val);
    add(rgt,mid+1,r,index,val);
    st[p]=st[lft]+st[rgt];
}

ll sum(int p,int l,int r,int i,int j){
   if(i>r || j<l) return 0L;
   if(i<=l && j>=r) return st[p];
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   return sum(lft,l,mid,i,j)+sum(rgt,mid+1,r,i,j);
}



int main(){
  int t,n,q,j=1,k,y; scanf("%d",&t);
  ll v;
  while(j<=t){
     printf("Case %d:\n",j);
    memset(st,0,sizeof(st));
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
         scanf("%lld",&arr[i]);
    }
    build(1,0,n-1);
    for(int i=0;i<q;i++){
         scanf("%d",&k);
         if(k==1){
             scanf("%d",&y);
             printf("%lld\n",arr[y]);
             add(1,0,n-1,y,-1*arr[y]);
             arr[y] =0L;
         }else if(k==2){
             scanf("%d%lld",&y,&v);
             arr[y]+=v;
             add(1,0,n-1,y,v);
         }else{
             scanf("%d%d",&y,&k);
             ll sm = sum(1,0,n-1,y,k);
             printf("%lld\n",sm);
         }
    }
    j++;
  }
  return 0;
}
