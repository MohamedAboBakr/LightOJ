#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

char bin[100010];
int st[400010];

void update(int p,int l,int r,int i,int j){
      if(i>r || j<l) return;
      if(i<=l && j>=r){
          st[p]++;
         return;
      }
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     st[lft]+=st[p];
     st[rgt]+=st[p];
     st[p]=0;
     update(lft,l,mid,i,j);
     update(rgt,mid+1,r,i,j);
}

int query(int p,int l,int r,int index){
    if(l==r) return st[p];
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    st[lft]+=st[p];
    st[rgt]+=st[p];
    st[p]=0;
    if(index<=mid) return query(lft,l,mid,index);
    return query(rgt,mid+1,r,index);
}

int main(){
  int t,n,q,l,r,j=1; scanf("%d",&t);getchar();
  char c;
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     scanf("%s",bin); getchar();
     n=strlen(bin);scanf("%d",&q);getchar();
     for(int i=0;i<q;i++){
         scanf("%c",&c); getchar();
         if(c=='I'){
             scanf("%d%d",&l,&r); getchar();
             update(1,0,n-1,l-1,r-1);
         }else {
             scanf("%d",&l); getchar();
             int qr = query(1,0,n-1,l-1);
             if(qr%2==0) printf("%c\n",bin[l-1]);
             else{
                 printf("%d\n",'1'-bin[l-1]);
             }
         }
     }
     //getchar();
     j++;
  }
  return 0;
}
