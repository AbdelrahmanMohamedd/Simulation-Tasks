#include <iostream>
#include <cstdlib>
#include <random>
#include<time.h>
using namespace std;

double doubleRand()
{
    return double(rand()) / (double(RAND_MAX) + 1.0 ); ///Rand_MAX=372372s
}

int main()
{
    int seed;
    int sequ;
    cout <<"****************"<< endl;
    cout<<"* PRNG Program *"<<endl;
    cout <<"****************"<< endl<<endl;
    cout<<"Enter the Seed: "<<endl;
    cin>>seed;
    cout<<"How many numbers you want"<<endl;
    cin>>sequ;
    cout <<endl<<"*********************************************************"<< endl;
    srand(static_cast<unsigned int>(seed));
    cout << sequ <<" numbers Randomly chosen within the interval (0.0 : 1.0)" << endl<<endl;
    for (int i=0 ; i < sequ ; i++)
    {
        cout << doubleRand() << "\n";
    }   cout <<"*********************************************************"<< endl;
}

