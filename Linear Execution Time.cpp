#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void constantFunction(int input)        //Decide Odd-Even
{
    int total = input%2;
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

void constant_time(int input)
{
    clock_t start_time, end_time;

    start_time = clock();
    constantFunction(input);
    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Time taken by constant function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : " << setprecision(5)
    << time_taken << " sec." << endl;
}

void linear_time(int input)
{
    clock_t start_time, end_time;

    start_time = clock();
    linearFunction(input);
    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Time taken by linear function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : " << setprecision(5)
    << time_taken << " sec." << endl;
}

void quadratic_time(int input)
{
    clock_t start_time, end_time;

    start_time = clock();
    quadraticFunction(input);
    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Time taken by quadratic function for input (" << fixed << setfill(' ') << setw(10) << input << ") is : " << setprecision(5)
    << time_taken << " sec." << endl;
}

int main()
{
    printf("\nConstant time:\n");
    for(double input = 1; input < 10000000000; input*=10)
    {
        constant_time(input);
    }

    printf("\nLinear time:\n");
    for(double input = 1; input < 10000000000; input*=10)
    {
        linear_time(input);
    }

    printf("\nQuadratic time:\n");
    for(double input = 1; input < 1000000; input*=10)
    {
        quadratic_time(input);
    }

    return 0;
}
