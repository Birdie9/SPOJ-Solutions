#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define gc getchar
using namespace std;
int prefm[500][500];
int prefw[500][500];
int match[500];
int prevI;
int idx[500];
int n;
FILE* fp;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
bool check(int woman,int man)
{

    int curM=match[woman];

    if(curM==-1)
    {
        match[woman]=man;


        return true;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(prefw[woman][i]==curM) return false;
            if(prefw[woman][i]==man)
            {
                match[woman]=man;
                prevI=curM;

                return true;
            }
        }
    }
}
int main()
{
    int t;

    scanint(t);

    for(int i=0;i<t;i++)
    {



        scanint(n);
        for(int w=0;w<n;w++) match[w]=-1;
        memset(idx,0,sizeof(int)*n);
        //bool* married = (bool*) malloc(sizeof(bool)*n);
        //memset(married,false,sizeof(bool)*n);
        for(int j=0;j<n;j++)
        {
            int p;
            scanint(p);
            p--;
            for(int k=0;k<n;k++)
            {
                scanint(prefw[p][k]);
                prefw[p][k]--;
            }
        }
        for(int j=0;j<n;j++)
        {
            int p;
            scanint(p);
            p--;
            for(int k=0;k<n;k++)
            {
                scanint(prefm[p][k]);
                prefm[p][k]--;
            }
        }
        int curI=0;
        prevI=-1;
        int bach;
        while(prevI!=-1 || curI<n)
        {
            if(prevI!=-1)
                {
                    bach=prevI;
                    prevI=-1;
                }
            else {
                    bach=curI;
                    curI++;
                 }

            for(;idx[bach]<n;idx[bach]++)
            {
                int woman=prefm[bach][idx[bach]];
                if(check(woman,bach)) break;

            }
        }
        for(int p=0;p<n;p++)
        {
            printf("%d %d\n",match[p]+1,p+1);
        }
    }

    return 0;
}
