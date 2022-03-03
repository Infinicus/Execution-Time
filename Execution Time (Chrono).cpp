//Code to check execution time using chrono
//May not show values more than 3 decimals after zero.

#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
#define PRECISION 9

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
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    constantFunction(input);
    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by constant function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : "
    << setprecision(PRECISION) << time_taken << " sec." << endl;
}

void linear_time(int input)             //Check for Linear time
{
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    linearFunction(input);
    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by linear function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : "
    << setprecision(PRECISION) << time_taken << " sec." << endl;
}

void quadratic_time(int input)          //Check for Quadratic time
{
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    quadraticFunction(input);
    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
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
//03/03/2022
