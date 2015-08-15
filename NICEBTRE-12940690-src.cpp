#include <iostream>
#include<cstdio>
using namespace std;

int depth(char* str){
if(str[0]=='l') return 0;
else if(str[0]=='n' ){
        int leafCount=0, nodeCount=0, i;
	for(i=1; ; i++){
		if(str[i]=='n')
			nodeCount++;
		else
			leafCount++;
		if(leafCount>nodeCount)
			break;
	}

    return max(depth(str+1),depth(str+i+1))+1;
}

}
int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
        char str[10010];
        cin>>str;
        cout<<depth(str)<<endl;
    }
    return 0;
}
