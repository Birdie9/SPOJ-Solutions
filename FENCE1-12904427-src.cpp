#include <iostream>
#include<cstdio>
#include<cmath>
#define _USE_MATH_DEFINES
using namespace std;

int main()
{
    float l;
    while(cin>>l && l){
      float i=(((l*l)/(2*M_PI)));
     printf("%.2f\n",i);
    }
    return 0;
}
