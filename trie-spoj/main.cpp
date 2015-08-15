#include <iostream>

using namespace std;

int main()
{
    char a[3][15];
    char c;
    int i=0,j=0;
    bool endw=false;
    while(true)
    {
        cin>>c;
        if(c!='\n') {
                a[i][j]=c;
                j++;
                endw=false;
        }
        else if(endw)
        {
            break;
        }
        else{
            endw=true;
            a[i][j]='\n';
            i++;
            j=0;
        }
    }



    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    return 0;
}
