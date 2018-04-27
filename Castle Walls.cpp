#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;

int red[800020],blue[800020];

void add_red(int p,int l,int r,int index){
    if(index<l||index>r) return;
    if(l==r){
        red[p]++;
        return;
    }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   add_red(lft,l,mid,index);
   add_red(rgt,mid+1,r,index);
   red[p]=red[lft]+red[rgt];
}

void add_blue(int p,int l,int r,int index){
    if(index<l||index>r) return;
    if(l==r){
        blue[p]++;
        return;
    }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   add_blue(lft,l,mid,index);
   add_blue(rgt,mid+1,r,index);
   blue[p]=blue[lft]+blue[rgt];
}

int query_red(int p,int l,int r,int i,int j){
     if(i>r || j<l)   return 0;
     if(i<=l && j>=r) return red[p];
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return query_red(lft,l,mid,i,j)+query_red(rgt,mid+1,r,i,j);
}
int query_blue(int p,int l,int r,int i,int j){
     if(i>r || j<l)   return 0;
     if(i<=l && j>=r) return blue[p];
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return query_blue(lft,l,mid,i,j)+query_blue(rgt,mid+1,r,i,j);
}

int main(){
 int t,n,m,j=1,x,y; scanf("%d",&t);
 while(j<=t){
     ll ans=0;
     memset(red,0,sizeof(red));
     memset(blue,0,sizeof(blue));
     vector<ppi> peasants;
     vector<int> blues; blues.push_back(-1);
     int currb=-1;
     scanf("%d%d",&n,&m);
     for(int i=0;i<n;i++){
         scanf("%d%d",&x,&y);
         peasants.push_back(ppi(x,pi(1,y)));
     }
     for(int i=0;i<m;i++){
         scanf("%d%d",&x,&y);
         peasants.push_back(ppi(x,pi(2,y)));
     }
     sort(peasants.begin(),peasants.end());
     for(int i=0;i<n+m;i++){
         if(peasants[i].second.first==1){
             if(peasants[i].first!=currb){
                 currb=peasants[i].first;
                 for(int k=0;k<blues.size();k++){
                     add_blue(1,0,200000,blues[k]);
                 }
                 blues.clear();
             }
             ans += query_red(1,0,200000,peasants[i].second.second,200000);
             blues.push_back(peasants[i].second.second);
         }else{
             if(peasants[i].first!=currb){
                 currb=peasants[i].first;
                 for(int k=0;k<blues.size();k++){
                     add_blue(1,0,200000,blues[k]);
                 }
                 blues.clear();
             }
             ans += query_blue(1,0,200000,peasants[i].second.second,200000);
             add_red(1,0,200000,peasants[i].second.second);
         }
     }
     printf("Case %d: %lld\n",j,ans);
     j++;
 }
 return 0;
}
