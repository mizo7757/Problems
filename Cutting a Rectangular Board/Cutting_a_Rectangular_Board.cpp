#include <bits/stdc++.h>
using namespace std;

//===================================================================

int cuts_number1=0,cuts_number2=0;

//===================================================================

int vertical_cut(int start , int end){
    
    if (start==end)
        {return 0;}
    int mid = (start + end) / 2;
    vertical_cut(start,mid);
    cuts_number1++;
    vertical_cut( mid+1 , end);
    
    return cuts_number1;
}

//===================================================================

int horizontal_cut(int start , int end){
    
    if (start==end)
        return 0;
        
    int mid = (start + end) / 2;
    horizontal_cut(start,mid);
    cuts_number2++;
    horizontal_cut(mid+1 , end);
    
    return cuts_number2;
}

//===================================================================

int cut (int length , int width){
    
    return horizontal_cut(1,length) + vertical_cut(1, width) ;
}

//===================================================================


int main()
{
    int length,width;
    cout<<"Enter the rectangle length : "<<endl;
    cin>>length;
    cout<<"Enter the rectangle width : "<<endl;
    cin>>width;
    cout<<"Number of total cuts is " << cut(length,width);
    
}
