#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main()
{   srand(time(NULL));
    int demand , aval , holded , sales , shortage , price=450;
    double randomNO , AVprofit1 , AVprofit2 , profit , TotalProfit=0;
    /*int orderunits=1;
    cout<<"Enter how many PCs to Order weekly?!"<<endl;
    cout<<"1. Order 1 PC"<<endl;
    cout<<"2. Order 2 PCs"<<endl;
    cin>>orderunits;
    if (orderunits=1) units=1;
    if (orderunits=2) units=2; */

    for ( int numofpc = 1 ; numofpc <= 2 ; numofpc ++)
    {
            aval=0;
            profit=0;

        for(int i=0 ; i<500 ; i++)
        {
            aval=aval+numofpc;
            randomNO = (rand()) / (double(RAND_MAX) + 1.0 );    // Genrating random number

        if (randomNO >= 0.0 && randomNO < 0.2)          demand=0;
        else if (randomNO >= 0.2 && randomNO < 0.6)     demand=1;
        else if (randomNO >= 0.6 && randomNO < 0.8)     demand=2;
        else if (randomNO >= 0.8 && randomNO < 0.9)     demand=3;
        else if (randomNO >= 0.9 && randomNO < 1)       demand=4;
///========================================================
        if (demand>aval)
            {
                sales=aval;
                shortage=((demand-aval)*100);
                holded=0;
                profit=(sales*price)-(shortage+holded);
                aval=0;
              //  cout<<profit<<endl;
            }
        else if(demand<aval)
            {
                sales=demand;
                shortage=0;
                holded=((aval-demand)*50);
                profit=((sales*price)-(shortage+holded));
                aval=(aval-demand);
              //cout<<profit<<endl;
            }
        else if (demand==aval)
            {
                sales=demand;
                shortage=0;
                holded=0;
                profit=((sales*price)-(shortage+holded));
                aval=0;
               //cout<<profit<<endl;
            }
            TotalProfit=TotalProfit+profit;
            }

        if(numofpc==1)
            AVprofit1=TotalProfit /500.0;
        else if(numofpc==2)
            AVprofit2=TotalProfit /500.0 ;
        }
    cout<<" Profit by Ordering 1 unit " <<AVprofit1<<endl;
    cout<<" Profit by Ordering 2 units " <<AVprofit2<<endl;
    cout<<endl;
    if(AVprofit1>AVprofit2)
    {
        cout<<" -> So,You Should Order 1 PC Per Week"<<endl;
        cout<<" -> You will Profit Money! "<<endl;

    }
    else if(AVprofit1<AVprofit2)
    {
        cout<<" -> So,You Should Order 2 PCs Per Week"<<endl;
        cout<<" -> You will Lose Money! "<<endl;
    } cout<<endl<<endl;
    return 0;
}
