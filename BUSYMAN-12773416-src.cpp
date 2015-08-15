#include <iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int> p1,pair<int,int> p2){
return(p1.second<p2.second);
}
int main()
{
    int t,n;
   cin>>t;
   for(int i=0;i<t;i++){
        vector< pair<int,int> > act;
    cin>>n;
    for(int j=0;j<n;j++){
            int start,fin;
            cin>>start>>fin;
       act.push_back( pair<int,int>(start,fin));
    }
sort(act.begin(),act.end(),comp);

vector<pair<int,int> >::iterator it=act.begin();
int time=(*it).second,sum=0;
sum++;
for(vector<pair<int,int> >::iterator it=act.begin()+1;it!=act.end();it++){
    if((*it).first>=time){
            sum++;
    time=(*it).second;
    }
}
cout<<sum<<endl;
   }
    return 0;
}
