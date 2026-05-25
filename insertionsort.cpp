#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void insertionsort(int x[], int n)
{
    int j, k, y;

    for (k = 1; k < n; k++)
    {
        /* insert x[k] into sorted file */
        y = x[k];

        /* move down all elements greater than y */
        for (j = k-1; j >= 0 && y < x[j]; j--)
        {
            x[j+1] = x[j];
        }

        /* insert y at proper position */
        x[j+1] = y;
    }
}

int main()
{
    srand(time(0));

    int sizes[]  = {10, 100, 1000, 5000, 10000, 20000, 50000};
    int numSizes = 7;

    cout << "Insertion Sort Results\n";
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

        insertionsort(data, N);

        auto end = chrono::high_resolution_clock::now();
        double timeTaken = chrono::duration<double, milli>(end - start).count();

        cout << N << "\t\t" << timeTaken << " ms\n";

        delete[] data;
    }

    return 0;
}