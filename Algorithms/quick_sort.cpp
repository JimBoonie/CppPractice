#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "horse_utils.cpp"
using namespace std;

void QuickSort(vector<int>&);
int RandIdx(const vector<int>&);

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

int RandIdx(const vector<int>& list)
{
	srand(time(NULL));
	return rand() % list.size();
}

void QuickSort(vector<int>& list)
{
    cout << RandIdx(list) << "\n";
}