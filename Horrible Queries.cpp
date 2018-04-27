#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;

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

ll st[400010],val[400010];

void add(int p,int l,int r,int i,int j,ll v){
   if(i>r || j<l) return;
   if(i<=l && j>=r){
      st[p]+=v;
      return;
   }
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     st[lft]+=st[p]; st[rgt]+=st[p];
     val[p]+= st[p]*(r-l+1); st[p]=0;
     if(i>=l&&j<=r) val[p]+= (j-i+1)*v;
     else if(i>=l)  val[p]+= (r-i+1)*v;
     else if(j<=r)  val[p]+= (j-l+1)*v;
     add(lft,l,mid,i,j,v);
     add(rgt,mid+1,r,i,j,v);
}

ll sum(int p,int l,int r,int i,int j){
  if(i>r || j<l) return 0L;
  if(i<=l && j>=r){
      return (st[p]*(r-l+1)+val[p]);
  }
  int lft,rgt,mid;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  st[lft]+=st[p]; st[rgt]+=st[p];
  val[p]+= st[p]*(r-l+1); st[p]=0;
  return sum(lft,l,mid,i,j)+sum(rgt,mid+1,r,i,j);
}

int main(){
  int t,n,c,q,l,r,j=1; t=readInt();
  ll v;
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     memset(val,0,sizeof(val));
     n=readInt();q=readInt();
     while(q--){
        c=readInt();l=readInt();r=readInt();
        if(c==0){
            scanf("%lld",&v);
            add(1,0,n-1,l,r,v);
        }
        else printf("%lld\n",sum(1,0,n-1,l,r));
     }
     j++;
  }
  return 0;
}
