#include<bits/stdc++.h>
/*
        penguin yes cop code
        https://codeforces.com/profile/Tuanhaiphong2
*/
using namespace std;
#define x1 o1
#define x2 o2
#define y1 o3
#define y2 o4
#define ll long long
#define fi first
#define se second
#define MOD 1000000007
//const int MOD = 998244353;
const int MAXN = 4e5+7;
const int maxn = 3e6;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,base = 131,k,a[MAXN],b[MAXN],dp[MAXN],m,cnt,o1,o2,o3,o4,ans;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
vector<array<int,2>> trie;
bool isend[maxn];
ll sz = 0;
void add(ll n){
    ll root = 0;
    string st = "";
    while(n>0){
        st+=char(n%2+'0');
        n/=2;
    }
    while(st.size()<sz)st+='0';
    for (ll i = st.size()-1;i >= 0;i--){
        k = st[i]-'0';
        if (trie[root][k]==0){
            trie.emplace_back();
            trie[root][k] = ++cnt;
        }
        root = trie[root][k];
    }
}
ll Find(ll n){
    ll root = 0;
    cnt = sz;
    ll res = 0;
    while(cnt--){
        k = (n>>cnt)&1;
        if (trie[root][k^1]!=0){
            res+=(1<<cnt);
            root = trie[root][k^1];
        }else if (trie[root][k]!=0)root = trie[root][k];
    }
    return res;
}
ll log2(ll n){
    ans = 0;
    while(n>0){
        n/=2;
        ans++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,index,note,n;
    string ss,stt,sss,str,st,s;
    trie.emplace_back();
    cin >> n;
    for (i = 1;i <= n;i++)
    cin >> a[i],sz = max(sz,log2(a[i]));
    for (i = 1;i <= n;i++)
    add(a[i]);
    for (i = 1;i <= n;i++)
    ans = max(ans,Find(a[i]));
    cout << ans;
    return (0^0)&(200+10);
}
/*
ඞඞඞඞඞ
100
010
111
110
*/