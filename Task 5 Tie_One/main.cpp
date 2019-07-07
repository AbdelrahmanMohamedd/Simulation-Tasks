#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int Clerks,Spaces;
double Generate_NormalDis(double mean, double sigma);
int Number_of_Customers = 5;  // number of experiments
double AT=0, Pre_AT=0, IAT, SST, ST, WT, CT, Sales, Wait_Cost, Profit1, Profit2;
//Arrivaltime,prearrivaltime,interarrivaltime,servicetime,servicestarttime,StartEntrancetime,waittime,complitiontime

int main()
{
    for ( int trial = 1 ; trial < 2 ; trial ++)
    {
        if (trial=1)
        {
            Clerks=2;
            Spaces=3;
        }
        else if (trial=2)
        {
            Clerks=6;
            Spaces=15;
        }
        int Number_of_Customers = 5;
        double Avail_Clerks[Clerks]= {0};
        double Avail_Spaces[Spaces]= {0};

            for (int i=1 ; i<Number_of_Customers ; i++ )
            {
                IAT=Generate_NormalDis(1.5,0.15);  /// customer inter arrival time
                if (i>1)
                {

                  AT = IAT + Pre_AT ; //Arrival Time of i
                Pre_AT = AT ;
                }
                else  AT = IAT ;


                if (SST<=AT)    // client came and found one or more available space
                {
                    SST = AT ;
                    ST=Generate_NormalDis(6,1);
                    Spaces--;
                    WT = 0 ;
                }
                else
                {
                    SST=CT;
                    ST=Generate_NormalDis(6,1);
                    WT = SST - AT ;
                    Spaces--;
                }
                CT = SST + ST ;
                Spaces++;

        if(AT>(10*60))   break;   ///open time (in minutes) has ended


        Sales=Number_of_Customers*22;
        if(Pre_AT>AT)  WT++;
        Wait_Cost=(WT*(10/60));
        }

    if (trial == 1)
        Profit1 = Profit1 - 200-(20*Clerks*10);  ///20$ 3clerks 10hours_work (per day)
    else if (trial=2)
        Profit2 = Profit2 - 2000-(20*Clerks*10); ///20$ 6clerks 10hours_work (per day)
    }
cout<<" Profit by the first configuration " <<Profit1<<endl;
cout<<" Profit by the second configuration " <<Profit2<<endl;
cout<<endl;
if (Profit1 > Profit2)cout<<" Use the first configuration"<<endl;
else  cout<<" Use the second configuration"<<endl;
cout<<endl<<endl;
//    cout<<Profit1<<endl;
//    cout<<Profit2<<endl;
//    cout<<Spaces<<endl;

}
///======================================================================= Normal Distribution Generator
double Generate_NormalDis(double mean, double sigma)
{
    int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    normal_distribution<double> Norm_Dist(mean,sigma);
    double Num = Norm_Dist(gen);
    return Num ;
}
