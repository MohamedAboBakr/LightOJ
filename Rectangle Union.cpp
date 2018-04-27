#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
map<int,ll> mp1;
map<ll,int> mp2;
map<ll, vector < pll > > strt,endd;
set<ll> OX,OY;

ll st[240010];
int active[240010];

ll getYdist(int a,int b){
   return mp1[b]-mp1[a];
}

void add_seg(int p,int l,int r,int i,int j){
     if(i>r || j<l) return;
     if(i<=l && j>=r){
          if(!active[p])st[p]=getYdist(l,r);
          active[p]++;
          return;
     }
    if(r-l==1) return;
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    add_seg(lft,l,mid,i,j);
    add_seg(rgt,mid,r,i,j);
    if(!active[p]){
            st[p]=st[lft]+st[rgt];
    }
}

void remove_seg(int p,int l,int r,int i,int j){
     if(i>r || j<l) return;
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     if(i<=l && j>=r){
          active[p]--;
          if(!active[p]){
               if(r-l==1) st[p]=0L;
               else{
                  st[p]=st[lft]+st[rgt];
               }
          }
          return;
     }
    if(r-l==1) return;
    remove_seg(lft,l,mid,i,j);
    remove_seg(rgt,mid,r,i,j);
    if(!active[p])st[p]=st[lft]+st[rgt];
}


int main(){
  int t,n,j=1,c; scanf("%d",&t);
  ll x1,x2,y1,y2,area;

  while(j<=t){
     memset(st,0L,sizeof(st));
     memset(active,0,sizeof(active));
     mp1.clear();mp2.clear();strt.clear();endd.clear();
     OX.clear();OY.clear();
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
         OX.insert(x1);OX.insert(x2);
         OY.insert(y1);OY.insert(y2);
         strt[x1].push_back(pll(y1,y2));
         endd[x2].push_back(pll(y1,y2));
     }

     c=0;
     set<ll>::iterator it=OY.begin();
     for(;it!=OY.end();it++){
         mp1[c]=*it;
         mp2[*it]=c;
         c++;
     }
     ll lastX=0L;
     area=0L;
     it=OX.begin();
     for(;it!=OX.end();it++){
         area += st[1]*(*it-lastX);
         if(strt.find(*it)!=strt.end()){
             for(int i=0;i<strt[*it].size();i++){
                 add_seg(1,0,OY.size()-1,mp2[strt[*it][i].first],mp2[strt[*it][i].second]);
                 //printf("%d  %d **\n",mp2[strt[*it][i].first],mp2[strt[*it][i].second]);
             }
         }
         if(endd.find(*it)!=endd.end()){
             for(int i=0;i<endd[*it].size();i++){
                 remove_seg(1,0,OY.size()-1,mp2[endd[*it][i].first],mp2[endd[*it][i].second]);
             }
         }
         lastX= *it;
     }
     printf("Case %d: %lld\n",j,area);
     j++;
  }
  return 0;
}
