#include <iostream>
#include <random>
#include <chrono>

using namespace std;

const int Experiment_size = 10 ;
double case1_CT [2] = {0, 0} ;
double case2_CT [6] = {0,0,0,0,0,0} ;
double Generate_normal(double mean, double sigma, int index) ;
double profit (const int Num_of_Clerks, const double rent,const  int Max_Allowed_customers) ;
bool Is_Complete_store (const int Max_Allowed_customers, const int Cust_inside) ;
int GOTO_Clerk_Number (int Num_of_Clerks);
int next_leave(int Num_of_Clerks);
void reset_clerks()  ;

int main()
{

    cout << "for the first case with 2 clerks :\nWe've total profit = " << profit(2,200,3) << endl;
//    cout << "for the second case with 6 clerks :\nWe've total profit = " << profit(6,2000,15) << endl;
    return 0;
}

double Generate_normal(double mean, double sigma, int index)
{
    int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    gen.discard(index);
    normal_distribution<double> norm_distribution(mean,sigma);
    double number = norm_distribution(gen);
    return number ;
}
double profit (const int Num_of_Clerks,const  double rent, const int Max_Allowed_customers)
{
    reset_clerks();
    bool changed = 1 ;
    double dummy ;

    double Pre_AT = 0, AT, IAT, SST, ST, WT, pre_CT ;
    int Avail_Clerk_Number, had_to_wait = 0, Cust_inside  = 0, Total_customers = 0  ;
    bool Stay = true;
    for (int i = 0 ; i < Experiment_size ; i++)
    {

        IAT = Generate_normal(1.5, 0.15, i) ;
        AT = Pre_AT + IAT ;
        double first_leave, temp;

        if (i > 0)
        {
            if(Num_of_Clerks == 2)   temp = case1_CT[GOTO_Clerk_Number(2)] ;
            else if (Num_of_Clerks == 6)    temp= case2_CT[GOTO_Clerk_Number(6)] ;
            if (Num_of_Clerks == 2 )
            {
                first_leave = temp ;
                if (changed)  {dummy = first_leave  ; changed = 0 ; }
                temp = case1_CT[next_leave(2)] ;
            }
            else
            {
                first_leave = temp ;
                if (changed)  dummy = first_leave  ;
                temp = case1_CT[next_leave(6)] ;
            }
        }

//        cout <<"%%% customers inside are = " << Cust_inside << " *************\n" ;
        if (AT >= 1060)  // arrived at 10 th hour , don't let him in
        {
            break;
        }
        else
        {
            Pre_AT = AT ;
            Stay = !Is_Complete_store(Max_Allowed_customers, Cust_inside) ;   // if stay is false , he leaves
            if (!Stay)   // he leaves
            {
                cout << "\nCust " << i+1 << " arrived at "  << AT << " so he didn't stay and left\n";
                continue ;
            }
            else         // if he stays
            {

                Avail_Clerk_Number = GOTO_Clerk_Number(Num_of_Clerks) ;
                Cust_inside += 1 ;
//                Total_customers++ ;cout << "\n-------when I got it was  " << Cust_inside << endl;
                if (Num_of_Clerks == 2)
                {
                    if (AT >= case1_CT[Avail_Clerk_Number])
                    {


                        SST = AT ;
                        WT = 0 ;
                    }
                    else
                    {
                        SST = case1_CT[Avail_Clerk_Number] ;
                        WT = SST - AT ;
                        had_to_wait++ ;
                    }

                    ST = Generate_normal(6,1, i) ;
                    pre_CT = SST + ST ;
                    case1_CT [Avail_Clerk_Number] =  pre_CT ;
                }
                else
                {
                    if (AT >= case2_CT[Avail_Clerk_Number])
                    {

                        SST = AT ;

                        WT = 0 ;
                    }
                    else
                    {
                        SST = case2_CT[Avail_Clerk_Number] ;
                        WT = SST - AT ;
                        had_to_wait++ ;
                    }
                    ST = Generate_normal(6,1, i) ;
                    pre_CT =  SST + ST ;
                    case2_CT [Avail_Clerk_Number] = pre_CT ;

                }
            }
        }
        cout << "\nCust. " << i+1 << " arrived at " << AT << " , with " << Cust_inside << " inside \n"
             << "Waiting " << WT << " .. He started at " << SST <<" and took " << ST << endl ;
        if (Num_of_Clerks == 2)
            cout << "he finshed at " << case1_CT[Avail_Clerk_Number] << " with clerk no. " << Avail_Clerk_Number << endl;
        else if (Num_of_Clerks == 6)
            cout << "he finshed at " << case2_CT[Avail_Clerk_Number] << " with clerk no. " << Avail_Clerk_Number << endl << endl;
    }
//    cout << Total_customers << endl;
    double costs = rent + 10 * had_to_wait + 20 * Num_of_Clerks * 10 ;
    double Net_profit = 22 * Total_customers  -  costs ;
    return Net_profit ;

}
bool Is_Complete_store (const int Max_Allowed_customers, const int Cust_inside )
{
    if (Max_Allowed_customers <= Cust_inside)
        return true ;
    else
        return false ;
}
int GOTO_Clerk_Number (int Num_of_Clerks)
{
    if (Num_of_Clerks == 2)
    {
        double Available_soon = min(case1_CT[0],case1_CT[1]) ;
        if (Available_soon == case1_CT[0] )
            return 0 ;
        else
            return 1 ;
    }
    else
    {
        double Available_soon = min (case2_CT[0], min (case2_CT[1], min(case2_CT[2], min(case2_CT[3], min(case2_CT[4], case2_CT[5])))) ) ;
        if      (Available_soon == case2_CT[0])
            return 0 ;
        else if (Available_soon == case2_CT[1])
            return 1 ;
        else if (Available_soon == case2_CT[2])
            return 2 ;
        else if (Available_soon == case2_CT[3])
            return 3 ;
        else if (Available_soon == case2_CT[4])
            return 4 ;
        else if (Available_soon == case2_CT[5])
            return 5 ;
    }
}

int next_leave(int Num_of_Clerks)
{
    if (Num_of_Clerks == 2)
    {
        double Available_soon = max(case1_CT[0],case1_CT[1]) ;
        if (Available_soon == case1_CT[0] )
            return 0 ;
        else
            return 1 ;
    }
    else
    {
        double Available_soon = max (case2_CT[0], min (case2_CT[1], min(case2_CT[2], min(case2_CT[3], min(case2_CT[4], case2_CT[5])))) ) ;
        if      (Available_soon == case2_CT[0])
            return 0 ;
        else if (Available_soon == case2_CT[1])
            return 1 ;
        else if (Available_soon == case2_CT[2])
            return 2 ;
        else if (Available_soon == case2_CT[3])
            return 3 ;
        else if (Available_soon == case2_CT[4])
            return 4 ;
        else if (Available_soon == case2_CT[5])
            return 5 ;
    }

}
void reset_clerks()
{
    case1_CT [0] = case1_CT [1] = case2_CT [0]  = case2_CT [1]  = case2_CT [2]  = case2_CT [3]  = case2_CT [4]  = case2_CT [5]  = 0 ;
}
