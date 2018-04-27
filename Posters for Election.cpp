#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

set<int> posters;
int sec[800010];

void add(int p,int l,int r,int i,int j,int num){
     if(i>r || j<l) return;
     if(i<=l && j>=r){
            sec[p]=num;
            return;
     }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   if(sec[p]!=-1){
        sec[lft]=sec[p];
        sec[rgt]=sec[p];
   }
   sec[p]=-1;
   add(lft,l,mid,i,j,num);
   add(rgt,mid+1,r,i,j,num);
}

void count_(int p,int l,int r){
   if(sec[p]==0) return;
   if(sec[p]!=-1){
            posters.insert(sec[p]);
            return;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   count_(lft,l,mid);
   count_(rgt,mid+1,r);
}

int main(){
  int t,n,l,r,j=1;scanf("%d",&t);
  while(j<=t){
    memset(sec,0,sizeof(sec));
    posters.clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%d%d",&l,&r);
         add(1,0,2*n-1,l-1,r-1,i+1);
    }
    count_(1,0,2*n-1);
    int ans = posters.size();
    printf("Case %d: %d\n",j,ans);
    j++;
  }
  return 0;
}
