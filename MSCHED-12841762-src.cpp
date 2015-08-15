#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int comp(pair<int,int> p1,pair<int,int> p2){
return(p1.first>p2.first);
}
int main()
{

    int n,time=0;
    vector<pair<int,int> > c;
  scanint(n);
    for(int i=0;i<n;i++){
        int g,d;
       scanint(g);
       scanint(d);
        c.push_back(make_pair(g,d));
        if(d>time)time=d;
    }
    sort(c.begin(),c.end(),comp);
   int schd[time];
  memset(schd,0,sizeof schd);

   for(vector<pair<int,int> >::iterator it=c.begin();it!=c.end();it++)
{
    int d=(*it).second-1;
    while(d>=0 && schd[d]!=0 ){
        d--;
    }
    if(d>=0) schd[d] = (*it).first;
}
int sum=0;
 for(int k=0;k<time;k++){
    sum+=schd[k];
 }
 cout<<sum;
    return 0;
}
