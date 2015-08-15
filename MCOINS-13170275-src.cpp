#include <iostream>

using namespace std;
int mex(int x,int y){
for(int i=0;;i++){
    if(i!=x&&i!=y)return i;
}
}
int mex(int x,int y,int z){
for(int i=0;;i++){
    if(i!=x&&i!=y&&i!=z)return i;
}
}
int gr[1000010];
int main()
{
    int k,l,m;
    cin>>k>>l>>m;
    int g[m],mxm=0;
    for(int i=0;i<m;i++){
        cin>>g[i];
        if(mxm<g[i]) mxm=g[i];
    }
    gr[0]=0;
    gr[1]=1;
    for(int i=2;i<k;i++){
        if(i%2==0)gr[i]=0;
        else gr[i]=1;
    }
    gr[k]=mex(gr[k-1],gr[0]);
    for(int i=k+1;i<l;i++){
        gr[i]=mex(gr[i-k],gr[i-1]);
    }
    gr[l]=mex(gr[l-1],gr[0],gr[l-k]);
    for(int i=l+1;i<=mxm;i++){
        gr[i]=mex(gr[i-1],gr[i-l],gr[i-k]);
    }
    for(int i=0;i<m;i++){
        if(gr[g[i]]!=0) cout<<"A";
        else cout<<"B";
    }
    cout<<endl;
    return 0;
}
