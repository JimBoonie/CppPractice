#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "horse_utils.cpp"
using namespace std;

int RandIdx(const int, const int);
int RandomPartition(vector<int>&, int, int);
void QuickSortRange(vector<int>&, int, int);
void QuickSort(vector<int>&);

int main()
{
    int my_array[] = {2, 8, 4, 1, 3, 0, 7, 9, 5, 10, 6, 11};
    vector<int> my_list(my_array, my_array + 12);

    // display original sequence
    cout << "Unsorted sequence: ";
    horse::DisplayVector(my_list);
    
    QuickSort(my_list);

    // display sorted sequence
    cout << "Sorted sequence: ";
    horse::DisplayVector(my_list);
}

int RandIdx(const int lower, const int upper)
{
	srand(time(NULL));
	return rand() % (upper + 1) + lower;
}

int RandomPartition(vector<int>& list, int p, int r)
{
    // find pivot point
    int rand_idx = RandIdx(p, r);

    // swap pivot point with end of list
    int tmp = list[r];
    list[r] = list[rand_idx];
    list[rand_idx] = tmp;

    // sort partition
    int pivot_val = list[r];
    int i = p - 1;
    for(int j = p; j < r; j++)
    {
        if(list[j] <= pivot_val)
        {
            i += 1;
            tmp = list[j];
            list[j] = list[i];
            list[i] = tmp;
        }
    }
    i += 1;
    tmp = list[r];
    list[r] = list[i];
    list[i] = tmp;
    return i;
}

void QuickSortRange(vector<int>& list, int p, int r)
{
    if(p < r)
    {
        int q = RandomPartition(list, p, r);
        QuickSortRange(list, p, q - 1);
        QuickSortRange(list, q + 1, r);
    }
}

void QuickSort(vector<int>& list)
{
    QuickSortRange(list, 0, list.size() - 1);
}