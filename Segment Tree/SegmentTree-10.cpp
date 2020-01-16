/**
@author mann2108
Problem : Segment Tree of LCM in range type queries
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAX =1e5+10;
ll t[4*MAX];

ll lcm(ll x,ll y){
    return ((x*y)/__gcd(x,y));
}

void build(ll a[],ll v,ll tl,ll tr){
    if(tl==tr){
        t[v]=a[tl];
    }
    else{
        ll tm=(tl+tr)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v]=lcm(t[2*v],t[2*v+1]);
    }
}

void update(ll v,ll tl,ll tr,ll pos,ll val){
    if(tl==tr){
        t[v]=val;
    }
    else{
        ll tm=(tl+tr)/2;
        if(pos<=tm){
            update(2*v,tl,tm,pos,val);
        }
        else{
            update(2*v+1,tm+1,tr,pos,val);
        }
        t[v]=lcm(t[2*v],t[2*v+1]);
    }
}

ll query(ll v,ll tl,ll tr,ll l,ll r){
    if(l>r)return 0;
    if(tl==l and tr==r)return t[v];
    ll tm=(tl+tr)/2;
    return lcm(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
}

int main(){
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(a,1,1,n);
    ll q;
    cin>>q;
    while(q--){
        ll choice;
        cin>>choice;
        if(choice==1){
            ll pos,val;
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}

