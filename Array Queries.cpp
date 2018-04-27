#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int st[400010],arr[100010];

void build(int p,int l,int r){
   if(l==r){
       st[p]=arr[l];
       return;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
   st[p]=min(st[lft],st[rgt]);
}

int mnn(int p,int l,int r,int i,int j){
   if(i>r || j<l) return 1000000;
   if(i<=l && j>=r) return st[p];
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return min(mnn(lft,l,mid,i,j),mnn(rgt,mid+1,r,i,j));
}
int main(){
  int t,n,c,q,l,r,j=1; t=readInt();
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     n=readInt();q=readInt();
     for(int i=0;i<n;i++){
        arr[i]=readInt();
     }
     build(1,0,n-1);
     for(int i=0;i<q;i++){
        l=readInt();r=readInt();
        printf("%d\n",mnn(1,0,n-1,l-1,r-1));
     }

     j++;
  }
  return 0;
}
