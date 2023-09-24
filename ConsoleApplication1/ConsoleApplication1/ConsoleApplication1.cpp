#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include <chrono>
using namespace std;
using namespace std::chrono;

int QuickSortAlgorithm(vector<int> &v, int start, int end)
{
    //Recursive function 1
    
    if (start >= end)
        return 0;

    // pivot is the first element
    int pivot = v[start];
    int i = start + 1;
    int j = end;
    int temp;
    
    while (i <= j)
    {
        while (v[i] <= pivot && i <= end)
            i++;
        while (v[j] >= pivot && j >= start + 1)
            j--;
        
        if (i < j)
        {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    
    temp = v[start];
    v[start] = v[j];
    v[j] = temp;
    
    QuickSortAlgorithm(v, start, j - 1);
    QuickSortAlgorithm(v, j + 1, end);
    
    return 0;
}

void QuickSortPrint()
{
    //A function to keep main clean

    // start measure time taken by function to sort
    auto begin = high_resolution_clock::now();
    
    vector<int> v;
   
    const int size = 10;
    for (int i = 0; i < size; ++i)
    {
        v.push_back(1 + rand() % 100);
    }
    
    cout<< "Before sorting: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    
    QuickSortAlgorithm( v, 0, size - 1);
    cout<< "After sorting: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout<< v[i] << " ";
    }

    // stop measure time taken by function to sort
    auto end = high_resolution_clock::now();
    //measure time taken in milliseconds
    auto elapsed = duration_cast<milliseconds>(end - begin);
    cout << endl << "Time taken by quicksort function: " << elapsed.count() << " milliseconds" << endl;
}

int MergeSortAlgorithm( )
{
    return 0;
}


int BubbleSortAlgorithm( )
{
    return 0;
}



int main(int argc, char* argv[])
{
QuickSortPrint();
    
    return 0;
    
}


