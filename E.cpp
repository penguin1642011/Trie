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
static ll Hash,base = 131,k,sz = 30,a[MAXN],b[MAXN],dp[MAXN],m,cnt,o1,o2,o3,o4,ans;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
vector<array<int,2>> trie,d;
static int isend[maxn];
void add(ll n){
    ll root = 0;
    string s = "";
    while(n>0){
        s = char(n%2+'0')+s;
        n>>=1;
    }
    while(s.size()<sz)s = '0'+s;
    for (ll i = 0;i < s.size();i++){
        k = s[i]-'0';
        if (trie[root][k]==0){
            trie.emplace_back();
            d.emplace_back();
            trie[root][k] = ++cnt;
        }
        d[root][k]++;
        root = trie[root][k];
    }
    isend[root] = true;
}
ll Find(ll n){
    ll root = 0;
    ll tt = sz;
    ans = k = 0;
    while(tt--){
        if (trie[root][k]==0&&trie[root][k^1]==0)return ans;
        if (d[root][k]>=n&&trie[root][k]!=0){
            if (isend[root]!=0)n-=isend[root];
            root = trie[root][k];
        }else {
             n-=d[root][k];
             if (n<=0)break;
             if (isend[root]!=0)n-=isend[root];
             ans+=(1<<tt);
             root = trie[root][k^1];
        }
        if (n<=0) return ans;
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
    cin >> tt;
    trie.emplace_back();
    while(tt--){
        cin >> x >> n;
        if (x==1)add(n);
        else cout << Find(n) << '\n';
    }
    return (0^0)&(200+10);
}
/*
ඞඞඞඞඞ
001
100
010
111
110
*/