//Code to check execution time using clock
//May not show values more than 3 decimals after zero, for higher precision, use chrono

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#define PRECISION 5                     //How many decimals

using namespace std;

void constantFunction(int input)        //Decide Odd-Even
{
    string parity;
    int total = input%2;
    if(total == 0)
        parity = "even";
        else
            parity = "odd";
}

void linearFunction(int input)          //Going through a loop
{
    for(int i = 0; i < input; i++)
    {

    }
}

void quadraticFunction(int input)       //Going through a nested loop
{
    for(int i = 0; i < input; i++)
    {
        for(int j = 0; j < input; j++)
        {

        }
    }
}

void constant_time(int input)           //Check for Constant time
{
    clock_t start_time, end_time;

    start_time = clock();
    constantFunction(input);
    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Time taken by constant function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : "
    << setprecision(PRECISION) << time_taken << " sec." << endl;
}

void linear_time(int input)             //Check for Linear time
{
    clock_t start_time, end_time;

    start_time = clock();
    linearFunction(input);
    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Time taken by linear function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : "
    << setprecision(PRECISION) << time_taken << " sec." << endl;
}

void quadratic_time(int input)          //Check for Quadratic time
{
    clock_t start_time, end_time;

    start_time = clock();
    quadraticFunction(input);
    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Time taken by quadratic function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : "
    << setprecision(PRECISION) << time_taken << " sec." << endl;
}

int main()
{
    printf("\nConstant time:\n");
    for(double input = 1; input < 10000000000; input*=10)       //Loop from input 1, 10, 100, ... for constant
    {
        constant_time(input);
    }

    printf("\nLinear time:\n");
    for(double input = 1; input < 10000000000; input*=10)       //Loop from input 1, 10, 100, ... for linear
    {
        linear_time(input);
    }

    printf("\nQuadratic time:\n");
    for(double input = 1; input < 1000000; input*=10)           //Loop from input 1, 10, 100, ... for quadratic
    {
        quadratic_time(input);
    }

    return 0;
}

//Giga Hidjrika Aura Adkhy
//02/03/2022
