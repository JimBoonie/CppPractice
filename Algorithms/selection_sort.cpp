#include <iostream>
#include <vector>
#include "horse_utils.cpp"
using namespace std;

void SelectionSort(vector<int>& list);

int main()
{
    int my_array[] = {5, 2, 4, 6, 1, 3};
    vector<int> my_list(my_array, my_array+6);

    // display original sequence
    cout << "Unsorted sequence: ";
    horse::DisplayVector(my_list);
    
    SelectionSort(my_list);

    // display sorted sequence
    cout << "Sorted sequence: ";
    horse::DisplayVector(my_list);
}

void SelectionSort(vector<int>& list)
{
    for(int i = 0; i < list.size() - 1; i++)
    {
        int* smallest = &list[i];
        int j = i + 1;
        while(j < list.size())
        {
            if(list[j] < *smallest)
            {
                smallest = &list[j];
            }
            j++;
        }

        // switch places
        int temp = *smallest;
        *smallest = list[i];
        list[i] = temp;
    }
}