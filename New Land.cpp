#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi;

int mn[8010],val[8010],arr[2010];
int mxx,n,m;

void update(int p,int l,int r){
    if(l==r){
        val[p]=arr[l];
        mn[p]=l;
        return;
    }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   update(lft,l,mid);
   update(rgt,mid+1,r);
     if(val[lft]<=val[rgt]){
          val[p]=val[lft];
          mn[p]=mn[lft];
     }else{
          val[p]=val[rgt];
          mn[p]=mn[rgt];
      }
}


pi minn(int p,int l,int r,int i,int j){
    if(i>r || j<l)   return pi(-1,-1);
    if(i<=l && j>=r) return pi(mn[p],val[p]);
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    pi pi1,pi2;
    pi1 = minn(lft,l,mid,i,j);
    pi2 = minn(rgt,mid+1,r,i,j);
    if(pi1.first==-1) return pi2;
    if(pi2.first==-1) return pi1;
    if(pi1.second<pi2.second) return pi1;
    return pi2;
}

int maxArea(int l,int r){
   if(l>r) return -1;
   pi mnpi=minn(1,0,m-1,l,r);
   if(l==r) return mnpi.second;
   int m1,m2,m3;
   m1=maxArea(l,mnpi.first-1);
   m2=maxArea(mnpi.first+1,r);
   m3=mnpi.second*(r-l+1);
   return max(max(m1,m2),m3);
}

int main(){
  int t,j=1,cell; scanf("%d",&t);
  char c ;
  while(j<=t){
      mxx=0;
      memset(arr,0,sizeof(arr));
      scanf("%d%d",&n,&m);getchar();
      for(int i=0;i<n;i++){
           for(int k=0;k<m;k++){
               scanf("%c",&c);
               cell = c-'0';
               if(cell==1) arr[k]=0;
               else arr[k]++;
           }
           update(1,0,m-1);
           getchar();
           mxx = max(mxx,maxArea(0,m-1));
      }
      printf("Case %d: %d\n",j,mxx);
      j++ ;
  }
  return 0;
}

