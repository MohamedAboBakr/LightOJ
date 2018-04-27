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

map<int,int>mp;
set<int> sett;
int st[600010];
void add(int p,int l,int r,int i,int j){
    if(i>r || j<l) return;
    if(i<=l && j>=r){
        st[p]++;
        return;
    }
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    st[lft]+=st[p]; st[rgt]+=st[p]; st[p]=0;
    add(lft,l,mid,i,j);add(rgt,mid+1,r,i,j);
}

int sum(int p,int l,int r,int index){
   if(l==r) return st[p];
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    st[lft]+=st[p]; st[rgt]+=st[p]; st[p]=0;
    if(index<=mid) return sum(lft,l,mid,index);
    return sum(rgt,mid+1,r,index);
}

int main(){
  int t,n,c,q,l,r,j=1; t=readInt();
  while(j<=t){
     printf("Case %d:\n",j);
     memset(st,0,sizeof(st));
     mp.clear();
     sett.clear();
     vector<pi>segs;
     vector<int> querys;
     n=readInt();q=readInt();
     for(int i=0;i<n;i++){
        l=readInt();r=readInt();
        segs.push_back(pi(l,r));
        sett.insert(l);sett.insert(r);
     }
     for(int i=0;i<q;i++){
        l=readInt();
        querys.push_back(l);
        sett.insert(l);
     }
     c=0;
     set<int>::iterator it=sett.begin();
     for(;it!=sett.end();it++){
         mp[*it]=c++;
     }
     int ind1,ind2;
     for(int i=0;i<n;i++){
         ind1=mp[segs[i].first];ind2=mp[segs[i].second];
         add(1,0,150000,ind1,ind2);
     }
     for(int i=0;i<q;i++){
          ind1 = mp[querys[i]];
          printf("%d\n",sum(1,0,150000,ind1));
     }
     j++;
  }
  return 0;
}
