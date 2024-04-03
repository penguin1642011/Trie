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
const int maxn = 1e7;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,base = 131,k,a[MAXN],b[MAXN],dp[5007],m,cnt,o1,o2,o3,o4,ans;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
vector<array<int,26>> trie;
bool isend[maxn];
void add(string s){
    ll root = 0;
    for (ll i = 0;i < s.size();i++){
        k = s[i]-'a';
        if (trie[root][k]==0){
            trie.emplace_back();
            trie[root][k] = ++cnt;
        }
        root = trie[root][k];
    }
    isend[root] = true;
}
void Find(string s){
    ll root;
    for (ll i = 0;i < s.size();i++){
        root = 0;
        for (ll j = i;j < s.size();j++){
            k = s[j] - 'a';
            if (trie[root][k]==0)break;
            root = trie[root][k];
            if (isend[root])dp[j+1]+=dp[i]%MOD;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,index,note,n;
    string ss,stt,sss,str,st,s;
    cin >> st;
    trie.emplace_back();
    cin >> tt;
    while(tt--){
        cin >> s;
        add(s);
    }
    ans = 1e18;
    dp[0] = 1;
    Find(st);
    n = st.size();
    cout << dp[n]%MOD;
    return (0^0)&(200+10);
}
/*
ඞඞඞඞඞ
  4 9 2 4
1 0 0 0 0
9 0 1 1 1
7 0 1 1 1
3 0 1 1 1
4 0 1 1 2
5 6
-2 3 2 3 3
-2 1 3 7 10
 T

 5
5 5 5 4 5
4 5 5 5 5
    1 1 1

1 2 4 5 20
0 1 
5
1 2 3 1 2
3
1
2 3 5 7
2 7
5 7
3
2 7 3
5 7 3

  2 3 5 7
0 0 1 1 
1 0 1
2 1 1
*/