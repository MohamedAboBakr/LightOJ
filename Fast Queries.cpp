#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int st[400010],arr[100010],tmm[100010],ans[50010];
int n;
struct query{
   int index;
   int l,r;
};

map<int , vector < query > > mp;

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


void add(int p,int l,int r,int num,int v){
    if(num<l||num>r) return;
    if(l==r){
        st[p]+=v;
        return;
    }
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    add(lft,l,mid,num,v);
    add(rgt,mid+1,r,num,v);
    st[p]=st[lft]+st[rgt];
}

int sm(int p,int l,int r,int i,int j){
     if(i>r || j<l) return 0;
     if(i<=l && j>=r) return st[p];
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return sm(lft,l,mid,i,j)+sm(rgt,mid+1,r,i,j);
}

int main(){
  int t,q,l,r,j=1,a; t=readInt();
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     memset(tmm,0,sizeof(tmm));
     mp.clear();
     n=readInt();
     q=readInt();

     for(int i=1;i<=n;i++){
        arr[i]=readInt();
     }
     for(int i=0;i<q;i++){
        query qr;
        l=readInt();r=readInt();
        qr.index=i;
        qr.l=l;
        qr.r=r;
        mp[r].push_back(qr);
     }

     for(int i=1;i<=n;i++){
         if(tmm[arr[i]]) add(1,0,n,tmm[arr[i]],-1);
         tmm[arr[i]]=i;
         add(1,0,n,tmm[arr[i]],1);
         for(int j=0;j<mp[i].size();j++){
              ans[mp[i][j].index]=sm(1,0,n,mp[i][j].l,mp[i][j].r);
         }
     }
     for(int i=0;i<q;i++){
         printf("%d\n",ans[i]);
     }
     j++;
  }
  return 0;
}


