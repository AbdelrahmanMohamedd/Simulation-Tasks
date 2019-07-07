#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout <<"******************************************"<< endl;
    cout<<"* Pseudo Random Number Generator Program *"<<endl;
    cout <<"******************************************"<< endl<<endl;
    cout<<"Enter the Seed: "<<endl;   ///Max 9 Digits (999999999)
    int seed;
    cin>>seed;
    cout <<endl<<"*********************************************************"<< endl;
    for (int i=0 ; i<100 ; i++)
    {
        seed=seed+984589;
        std::string s = to_string(seed);
        cout<<"0."<<s.substr(3,5)<<s.substr(0,2)<<s.substr(6,8)<<endl;
        int reseed = std::stoi(s);
        seed=reseed;
    }
    cout<<"*********************************************************"<< endl;
    cout<<"Here 100 Randomly Generated numbers "<<endl<<endl;
}
