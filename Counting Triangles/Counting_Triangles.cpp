#include <bits/stdc++.h>

using namespace std;



int main()
{

int number,result=1;
cin>>number;
for(int i=0 ; i<number ; i++){
    
    result+=3*i;
    
}
cout<<"Number of small triangles : "<< result << endl;
}
