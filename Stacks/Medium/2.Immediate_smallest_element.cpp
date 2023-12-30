
#include <iostream>
#include <vector>
using namespace std;

vector<int> nextSmaller(vector<int> &Arr, int N)
{
    vector<int> result(N, -1); // Initialize result vector with -1
                               // BRUTE FROCE METHOD
    for (int i = 0; i < N - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
        {
            result[i] = Arr[i + 1]; // Update current index to the next smaller element
        }
    }

    // return result;
    // or
    for (int i = 0; i < N; i++)
    {
        Arr[i] = result[i];
    }
}