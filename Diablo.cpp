#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int st[600010],vall[600010];

void add(int p,int l,int r,int index,int val){
     if(l==r){
         st[p]=1;
         vall[p]=val;
         return;
     }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   if(index<=mid) add(lft,l,mid,index,val);
   else add(rgt,mid+1,r,index,val);
   st[p]++;
}

int gett(int p,int l,int r,int index){
    if(l==r){
            st[p]=0;
            return vall[p];
    }
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    st[p]--;
    if(index<=st[lft]) return gett(lft,l,mid,index);
    return gett(rgt,mid+1,r,index-st[lft]);
}

void printt(){

}

int main(){
  int t,n,q,j=1,army,k; scanf("%d",&t);
  char c;
  while(j<=t){
     printf("Case %d:\n",j);
     int ln=0,tk=0;
     memset(st,0,sizeof(st));
     memset(vall,0,sizeof(vall));
     scanf("%d%d",&n,&q);
     for(int i=0;i<n;i++){
         scanf("%d",&army);
         add(1,0,150000,ln,army);
         ln++;tk++;
     }
     getchar();
     while(q--){
         scanf("%c",&c); getchar();
         if(c=='a'){
             scanf("%d",&army);getchar();
             add(1,0,150000,tk,army);
             ln++;tk++;
         }else{
             scanf("%d",&k); getchar();
             if(k>ln) printf("none\n");
             else{
                printf("%d\n",gett(1,0,150000,k));
                ln--;
             }
         }
     }
     j++;
  }
  return 0;
}
