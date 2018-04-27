#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll>pi;
typedef pair<string,pi> ppi;

int main()
{

    ll k;
    while(scanf("%lld",&k)==1){
        vector<pi> vec;
        for(ll x=1;x<=2*k;x++){
             if(x>k&&(k*x)%(x-k)==0)vec.push_back(pi((k*x)/(x-k),x));
        }
        printf("%d\n",vec.size());
        for(int i=0;i<vec.size();i++){
            printf("1/%lld = 1/%lld + 1/%lld\n",k,vec[i].first,vec[i].second);
        }
    }
    return 0;
}
