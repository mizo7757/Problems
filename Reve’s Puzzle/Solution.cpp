#include <bits/stdc++.h>
using namespace std;

// A , B , C , D are pegs names

int moves=0;

//=====================================================================================

// Basic 3 Towers of Hanoi solution
void ToH3 (int disks ,char source, char destination, char med)
{
    if(disks==1)
    {
        cout << source << " -----> "<< destination<<endl;
        moves++;
        return;
    }
    ToH3(disks - 1, source, med, destination);
    cout << source << " -----> "<<destination<<endl;
    moves++;
    ToH3 (disks - 1 , med, destination, source);
}

//=====================================================================================

void ToH4 ( int disks ,char source , char destination ,char mid1 ,char mid2) 
{
    if(disks==0)
        return;
    if(disks==1)
    {
        cout << source << " -----> " << destination << endl;
        moves++;
        return;
    }

    ToH4 (disks - 2 , source , mid1 , mid2 , destination );

    cout << source << " -----> "<< mid2 <<endl;
    cout << source << " -----> "<< destination <<endl;
    cout << mid2 << " -----> "<< destination <<endl;
    moves+=3;
    
    ToH4(disks - 2, mid1 , destination , source , mid2);
}

//=====================================================================================

//K is the integer that is subtracted from disks to get the optimal number of moves
void solve (int disks , char source , char destination , char mid1 , char mid2, int k)
{
    ToH4 (disks - k , source , mid2 , destination , mid1);
    ToH3 (k , source , destination , mid1);
    ToH4 (disks - k , mid2 , destination , source , mid1);
    cout << endl;
}

//=====================================================================================

int main()
{
    int disks;
    cout << "Enter the number of disks "<< endl;
    cin >> disks;
    cout << endl;
    int k=disks/2;

    solve(disks, 'A', 'B', 'C','D' , k);
    cout<<"The total number of moves = "<<moves;
    return 0;
}
