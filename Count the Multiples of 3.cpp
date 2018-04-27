#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int mod_0[400010],mod_1[400010],mod_2[400010],st[400010];


void build(int p,int l,int r){
   mod_0[p]=r-l+1;
  if(l==r)return;
  int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
}

void add(int p,int l,int r,int i,int j){
     if(i>r || j<l) return;
     if(i<=l && j>=r){
            st[p]=(st[p]+1)%3;
            int n1=mod_0[p],n2=mod_1[p],n3=mod_2[p];
            mod_0[p]=n3;
            mod_1[p]=n1;
            mod_2[p]=n2;
            return;
     }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   if(st[p]==1){
        st[lft]=(st[lft]+1)%3;
        st[rgt]=(st[rgt]+1)%3;
        int n1=mod_0[lft],n2=mod_1[lft],n3=mod_2[lft];
        mod_0[lft]=n3;mod_1[lft]=n1;mod_2[lft]=n2;
        n1=mod_0[rgt];n2=mod_1[rgt];n3=mod_2[rgt];
        mod_0[rgt]=n3;mod_1[rgt]=n1;mod_2[rgt]=n2;
   }else if(st[p]==2){
        st[lft]=(st[lft]+2)%3;
        st[rgt]=(st[rgt]+2)%3;
        int n1=mod_0[lft],n2=mod_1[lft],n3=mod_2[lft];
        mod_0[lft]=n2;mod_1[lft]=n3;mod_2[lft]=n1;
        n1=mod_0[rgt];n2=mod_1[rgt];n3=mod_2[rgt];
        mod_0[rgt]=n2;mod_1[rgt]=n3;mod_2[rgt]=n1;
   }
   st[p]=0;
   add(lft,l,mid,i,j);
   add(rgt,mid+1,r,i,j);
   mod_0[p] = mod_0[lft]+mod_0[rgt];
   mod_1[p] = mod_1[lft]+mod_1[rgt];
   mod_2[p] = mod_2[lft]+mod_2[rgt];
}

int sum(int p,int l,int r,int i,int j){
   if(i>r || j<l) return 0;
   if(i<=l && j>=r) {
        return mod_0[p];
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
      if(st[p]==1){
        st[lft]=(st[lft]+1)%3;
        st[rgt]=(st[rgt]+1)%3;
        int n1=mod_0[lft],n2=mod_1[lft],n3=mod_2[lft];
        mod_0[lft]=n3;mod_1[lft]=n1;mod_2[lft]=n2;
        n1=mod_0[rgt];n2=mod_1[rgt];n3=mod_2[rgt];
        mod_0[rgt]=n3;mod_1[rgt]=n1;mod_2[rgt]=n2;
   }else if(st[p]==2){
        st[lft]=(st[lft]+2)%3;
        st[rgt]=(st[rgt]+2)%3;
        int n1=mod_0[lft],n2=mod_1[lft],n3=mod_2[lft];
        mod_0[lft]=n2;mod_1[lft]=n3;mod_2[lft]=n1;
        n1=mod_0[rgt];n2=mod_1[rgt];n3=mod_2[rgt];
        mod_0[rgt]=n2;mod_1[rgt]=n3;mod_2[rgt]=n1;
   }
   st[p]=0;
   return sum(lft,l,mid,i,j)+sum(rgt,mid+1,r,i,j);
}

int main(){
  int t,n,q,k,l,r,j=1; scanf("%d",&t);
  while(j<=t){
    printf("Case %d:\n",j);
    memset(mod_1,0,sizeof(mod_1));
    memset(mod_2,0,sizeof(mod_2));
    memset(st,0,sizeof(st));
    scanf("%d%d",&n,&q);
    build(1,0,n-1);
    while(q--){
         scanf("%d%d%d",&k,&l,&r);
         if(k==0) add(1,0,n-1,l,r);
         else{
           printf("%d\n",sum(1,0,n-1,l,r));
         }
    }
    j++;
  }
  return 0;
}
