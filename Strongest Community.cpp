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


int st[400010],strt[100010],endd[100010],arr[100010];
void add(int p,int l,int r,int index,int v){
   if(index<l || index>r) return;
   if(l==r){
      st[p]=v;
      return;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   add(lft,l,mid,index,v);
   add(rgt,mid+1,r,index,v);
   st[p]=max(st[lft],st[rgt]);
}

int mxx(int p,int l,int r,int i,int j){
     if(j<i) return 0;
     if(i>r || j<l) return 0;
     if(i<=l && j>=r) return st[p];
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return max(mxx(lft,l,mid,i,j),mxx(rgt,mid+1,r,i,j));
}

int main(){
  int t,n,c,q,l,r,j=1; t=readInt();
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     memset(strt,0,sizeof(strt));
     memset(endd,0,sizeof(endd));
     n=readInt();c=readInt();q=readInt();

     int tmm=0;
     arr[0]=0;
     for(int i=1;i<=n;i++){
        arr[i]=readInt();
        if(arr[i]!=arr[i-1]){
            strt[arr[i]]=i;
            endd[arr[i-1]]=i-1;
            add(1,0,n,i-1,tmm);
            tmm=1;
        }else{
            tmm++;
        }
     }
     add(1,0,n,n,tmm);
     endd[arr[n]]=n;

     /*for(int i=1;i<=c;i++){
         printf("%d %d %d ---\n",i,strt[i],endd[i]);
     }*/
     for(int i=0;i<q;i++){
        l=readInt();r=readInt();
        if(arr[l]==arr[r]) printf("%d\n",r-l+1);
        else{
            int n1,n2,n3;
            n1 = endd[arr[l]]-l+1;
            n2 = r-strt[arr[r]]+1;
            n3 = mxx(1,0,n,endd[arr[l]]+1,strt[arr[r]]-1);
            printf("%d\n",max(n1,max(n2,n3)));
        }
     }

     j++;
  }
  return 0;
}
