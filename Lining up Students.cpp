#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
int a[100010];
int st[400010],v[400010];
int id;
void build(int p,int l,int r){
  if(l==r){
    st[p]=1;
    return ;
  }
  int lft,rgt,mid;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  build(lft,l,mid);
  build(rgt,mid+1,r);
  st[p]=st[lft]+st[rgt];
}

void _insert(int p,int l,int r,int index,int val){
   if(l==r){
      id=l+1;
      v[p]=val;
      st[p]=0;
      return;
   }
  int lft,rgt,mid;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  if(st[lft]>=index) _insert(lft,l,mid,index,val);
  else _insert(rgt,mid+1,r,index-st[lft],val);
  st[p]=st[lft]+st[rgt];
}

int main(){
 int t,n,j=1,ai; scanf("%d",&t);
 while(j<=t){
    scanf("%d",&n);
    build(1,0,n-1);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-1;i>=0;i--){
        _insert(1,0,n-1,a[i]+1,i+1);
    }
    printf("Case %d: %d\n",j,n-id+1);
    j++;
 }
 return 0;
}
