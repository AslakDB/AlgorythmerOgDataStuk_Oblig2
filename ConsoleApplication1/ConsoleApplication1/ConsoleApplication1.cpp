#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include <chrono>
using namespace std;
using namespace std::chrono;


void swapping(vector<int> &v,int a, int b);
int quick_sort_algorithm(vector<int> &Vector, int start, int end)
{
    //Recursive function 1
    
    if (start >= end)
        return 0;

    // pivot is the first element
    
    int TempStart = start;
    int tempEnd = end;
    int pivot = Vector[start];
    
    
    while (TempStart < end || tempEnd > start)
    {
        while (Vector[TempStart] < pivot)
            TempStart++;
        while (Vector[tempEnd] > pivot)
            tempEnd--;
        
        if (TempStart <= tempEnd)
        {
            swapping(Vector, TempStart, tempEnd);
            TempStart++;
            tempEnd--;
        }

        
           else {
                if (TempStart < end)
                quick_sort_algorithm(Vector,TempStart,end);
               
                if (tempEnd > start)
                quick_sort_algorithm(Vector, start, tempEnd);
               
                return 0;
            }
        
    }
    
}

void swapping(vector<int> &v,int a, int b)
{
   
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void quick_sort_print() 
{
    //A function to keep main clean

    // start measure time taken by function to sort
    auto begin = high_resolution_clock::now();
    
    
    //srand(time(NULL));
    vector<int> v ;
    const int size = 10000;
    
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

    
    quick_sort_algorithm( v, 0, size-1);
    
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

void merge_sort_algorithm(int arr[], int left, int mid, int right)
{
    int const subarray1 = mid - left + 1;
    int const subarray2 = right - mid;

     int *leftTemp = new int [subarray1];
     int *rightTemp =  new int[subarray2];


    //here we copy data to temp arrays each itteraion
    for (int i = 0; i < subarray1; ++i)
        leftTemp[i] = arr[left + i];
    for (int j = 0; j < subarray2; ++j)
        rightTemp[j] = arr[mid + 1 + j];

    
    int T_Left= 0;
    int T_Right= 0;
    int T_Mid= left;

    while (T_Left< subarray1 && T_Right< subarray2)
    {
        if (leftTemp[T_Left] <= rightTemp[T_Right])
        {
            arr[T_Mid] = leftTemp[T_Left];
            T_Left++;
        }
        else
        {
            arr[T_Mid] = rightTemp[T_Right];
            T_Right++;
        }
        T_Mid++;
    }

    while (T_Left < subarray1)
    {
        arr[T_Mid] = leftTemp[T_Left];
        T_Left++;
        T_Mid++;
    }
    while (T_Right < subarray2)
    {
        arr[T_Mid] = rightTemp[T_Right];
        T_Right++;
        T_Mid++;
    }

    delete leftTemp;
    delete rightTemp;
    
}

int merge(int arr[], int left, int right)
{
if (left >= right)
        return 0;
    
    int mid = left + (right - left) / 2;

    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    merge_sort_algorithm(arr, left, mid, right);
    
}

void merge_sort_print()
{
    auto begin = high_resolution_clock::now();
   int Size = 10000;
    int Array[10000];
   for (int i = 0; i < Size; ++i)
   {
       Array[i] = rand() % 100;
   }

    cout<< "Before sorting: " << endl;
    for (int i = 0; i < Size; ++i)
    {
        cout << Array[i] << " ";
    }

    merge(Array, 0, Size - 1);

    cout<< "After sorting: " << endl;
    for (int i = 0; i < Size; ++i)
    {
        cout << Array[i] << " ";
    }
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - begin);
    cout << endl << "Time taken by Merge_sort function: " << elapsed.count() << " milliseconds" << endl;
}




int bubble_sort_algorithm(int arr[], int size)

{
    int i, j;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[j]> arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return 0;
}

void print_bubble_sort()
{
    auto begin = high_resolution_clock::now();

    int Array_Size = 10000;
    int Array[10000];
    for (int i = 0; i < Array_Size -1; ++i)
    {
      Array[i] = rand() % 1000;
    }

    cout<< "Before sorting: " << endl;
    for (int i = 0; i < Array_Size -1; ++i)
    {
        cout << Array[i] << " ";
    }
    cout << endl;

    
    bubble_sort_algorithm(Array, Array_Size -1);

    cout<< "After sorting: " << endl;
    for (int i = 0; i < Array_Size -1; ++i)
    {
        cout << Array[i] << " ";
    }
    auto end = high_resolution_clock::now();

    auto elapsed = duration_cast<milliseconds>(end - begin);
    cout << endl << "Time taken by bubblesort function: " << elapsed.count() << " milliseconds" << endl;
}



int main(int argc, char* argv[])
{
  //quick_sort_print();
    merge_sort_print();
   // print_bubble_sort();
    return 0;

    
}


