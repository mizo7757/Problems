#include <bits/stdc++.h>
using namespace std;

void odometer_ones(int digits){
    
    int ones_readings=pow(10,digits)-pow(9,digits);
    cout<< "The total number of readings with digit 1 is equal to "<<ones_readings<<endl;
    int ones_times= 6*pow(10,6)/10;
 cout<<"One will appear in all the readings number of times = "<<ones_times<<endl;
    
}


int main(){
    
       cout<<"Enter Odometer number of digits : "<<endl;
    int digits;
    cin>>digits;
    odometer_ones(digits);
    
}
