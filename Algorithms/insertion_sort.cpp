#include <iostream>
#include <vector>
#include "horse_utils.cpp"
using namespace std;

void InsertionSort(vector<int>&, bool);

int main()
{
    int my_array[] = {5, 2, 4, 6, 1, 3};
    vector<int> my_list(my_array, my_array+6);

    // display original sequence
    cout << "Unsorted sequence: ";
    horse::DisplayVector(my_list);
    
    InsertionSort(my_list, 0);

    // display sorted sequence
    cout << "Sorted sequence: ";
    horse::DisplayVector(my_list);
}

void InsertionSort(vector<int>& list, bool direction=1)
{
    // perform insertion sort
    for(int j = 1; j < list.size(); j++)
    {
        int anchor = list[j];
        int i = j - 1;
        if(direction)
        {
            while(i >= 0 && list[i] > anchor) 
            {
                list[i + 1] = list[i];
                i--;
            }
            list[i + 1] = anchor;
        }
        else
        {
            while(i >= 0 && list[i] < anchor) 
            {
                list[i + 1] = list[i];
                i--;
            }
            list[i + 1] = anchor;
            
        }
    }
}
