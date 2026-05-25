#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void siftDown(int x[], int root, int size)
{
    while (true)
    {
        int largest = root;
        int left    = 2 * root + 1;
        int right   = 2 * root + 2;

        if (left  < size && x[left]  > x[largest]) largest = left;
        if (right < size && x[right] > x[largest]) largest = right;

        if (largest != root)
        {
            int temp      = x[root];
            x[root]       = x[largest];
            x[largest]    = temp;
            root = largest;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int x[], int n)
{
    // Step 1: build max-heap
    for (int i = n/2 - 1; i >= 0; i--)
        siftDown(x, i, n);

    // Step 2: extract max one by one
    for (int end = n-1; end > 0; end--)
    {
        int temp = x[0];
        x[0]     = x[end];
        x[end]   = temp;

        siftDown(x, 0, end);
    }
}

int main()
{
    srand(time(0));

    int sizes[]  = {10, 100, 1000, 5000, 10000, 20000, 50000};
    int numSizes = 7;

    cout << "Heap Sort Results\n";
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

        HeapSort(data, N);

        auto end = chrono::high_resolution_clock::now();
        double timeTaken = chrono::duration<double, milli>(end - start).count();

        cout << N << "\t\t" << timeTaken << " ms\n";

        delete[] data;
    }

    return 0;
}