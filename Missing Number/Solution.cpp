#include <bits/stdc++.h>

using namespace std;


//function to delete the leftmost digit to make addition easy for jill

int deleteFromEnd(int n)
{
  
    int divisor = 1 ;
    for( int v = n ; v > 9 ; v /= 10 ) divisor *= 10 ;
    return n % divisor ;
}


int main()
{

    int num,result,sum=0;
    
    for(int i=0;i<99;i++){
        cin>>num;
        sum+=num;
        if(sum>=1000){
            sum=deleteFromEnd( sum);
        }
        if(sum>=100){
            sum=deleteFromEnd( sum);
        }
    }
    result=abs(50-sum);
    cout<<"Missing number is: "<<result;
}
