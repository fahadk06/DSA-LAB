#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void Selectionsort(int x[], int n)
{
    int key;

    for (int a = 0; a < n; a++)
    {
        key = a;

        for (int b = a+1; b < n; b++)
        {
            if (x[b] < x[key])
                key = b;
        }

        if (key > a)
        {
            int temp = x[a];
            x[a]     = x[key];
            x[key]   = temp;
        }
    }
}

int main()
{
    srand(time(0));

    int sizes[]  = {10, 100, 1000, 5000, 10000, 20000, 50000};
    int numSizes = 7;

    cout << "Selection Sort Results\n";
    cout << "------------------------------\n";
    cout << "N\t\tTime(ms)\n";
    cout << "------------------------------\n";

    for (int s = 0; s < numSizes; s++)
    {
        int N = sizes[s];

        int* data = new int[N];
        for (int i = 0; i < N; i++)
            data[i] = rand() % 100000;

        auto start = chrono::high_resolution_clock::now();

        Selectionsort(data, N);

        auto end = chrono::high_resolution_clock::now();
        double timeTaken = chrono::duration<double, milli>(end - start).count();

        cout << N << "\t\t" << timeTaken << " ms\n";

        delete[] data;
    }

    return 0;
}