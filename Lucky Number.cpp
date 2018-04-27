#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;

int st[5717730];

void build(int p,int l,int r){
    if(l==r){
         if(l==0)st[p]=0;
         else st[p]=1;
         return;
    }
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    st[p]=st[lft]+st[rgt];
}

void _remove(int p,int l,int r,int index){
  if(l==r){
     st[p]=0;
     //printf("%d\n",l);
     return;
  }
  int lft,rgt,mid;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  if(st[lft]>=index) _remove(lft,l,mid,index);
  else _remove(rgt,mid+1,r,index-st[lft]);
  st[p]=st[lft]+st[rgt];
}

int _get(int p,int l,int r,int index){
  if(l==r){
      return l;
  }
  int lft,rgt,mid;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  if(st[lft]>=index) return _get(lft,l,mid,index);
  else return _get(rgt,mid+1,r,index-st[lft]);
}


int main(){
 int t,n,rm=2,j=2,tm;scanf("%d",&t);
 int mx=1429432;
 build(1,0,mx);
 while(rm<=st[1]){
      tm=0;
      for(int i=rm;i-tm<=st[1];i+=rm,tm++){
         _remove(1,0,mx,i-tm);
      }
      rm=_get(1,0,mx,j);
      j++;
 }
 j=1;
 while(j<=t){
    scanf("%d",&n);
    printf("Case %d: %d\n",j,_get(1,0,mx,n));
    j++;
 }
 return 0;
}
