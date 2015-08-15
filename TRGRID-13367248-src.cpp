#include <iostream>

#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define VI vector<int>
#define PII pair<int,int>
#define gc getchar
#define PB push_back
#define MP make_pair
#define MSET(x,y) memset((x),(y),sizeof(x))
#define gc getchar
#include<cstdio>
#include<utility>
#include<vector>
#include<cstring>
#include<algorithm>
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 | c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;

int main()
{
    int t;
    cin>>t;
    int i,j,k;
    REP(i,t){
    int n,m;
    scanint(n);
    scanint(m);
    if(n==m && n%2==0){
        cout<<"L"<<endl;
    }
    else if(n==m && n%2!=0){
        cout<<"R"<<endl;
    }
    else{
        if(n<m){
            if(n%2==0){
                cout<<"L"<<endl;
            }
            else{
                cout<<"R"<<endl;
            }
        }
        else{
            if(m%2==0){
                cout<<"U"<<endl;
            }
            else{
                cout<<"D"<<endl;
            }
        }
    }
    }
    return 0;
}
