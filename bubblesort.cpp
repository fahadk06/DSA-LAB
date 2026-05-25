#include <iostream>
#include <cstdlib> //used for random number generation func like rand() and srand()
#include <ctime>   //used for generating time()  
#include <chrono> //used for measuring execution time 
using namespace std;

#define TRUE  1 //define constants used as flags in sorting
#define FALSE 0

void Bubble(int x[], int n)
{
    int hold, j, pass;
    int switched = TRUE;

    for (pass = 0; pass < n-1 && switched == TRUE; pass++) //outer loop 
    {
        switched = FALSE;

        for (j = 0; j < n-pass-1; j++) //inner loop
        {
            if (x[j] > x[j+1])
            {
                switched = TRUE;
                hold     = x[j];
                x[j]     = x[j+1];
                x[j+1]   = hold;
            }
        }
    }
}

int main()
{
    srand(time(0));  //initilizes random no. generator

    int sizes[]  = {10, 100, 1000, 5000, 10000, 20000, 50000};
    int numSizes = 7;

    cout << "Bubble Sort Results\n";
    cout << "------------------------------\n";
    cout << "N\t\tTime(ms)\n";
    cout << "------------------------------\n";

    for (int s = 0; s < numSizes; s++)
    {
        int N = sizes[s];

        int* data = new int[N];
        for (int i = 0; i < N; i++)
            data[i] = rand() % 100000; //create random data for sorting 

        auto start = chrono::high_resolution_clock::now(); //start timer

        Bubble(data, N);

        auto end = chrono::high_resolution_clock::now(); //end timer
        double timeTaken = chrono::duration<double, milli>(end - start).count();

        cout << N << "\t\t" << timeTaken << " ms\n";

        delete[] data;
    }

    return 0;
}