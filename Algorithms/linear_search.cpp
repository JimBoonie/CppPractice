#include <iostream>
#include <vector>
#include "horse_utils.cpp"
using namespace std;

int LinearSearch(const vector<int>&, const int);

int main()
{
    int my_array[] = {5, 2, 4, 6, 1, 3};
    vector<int> my_list(my_array, my_array + 6);

    // display sequence
    cout << "Sequence: ";
    horse::DisplayVector(my_list);

    int target = 1;
    int index = LinearSearch(my_list, target);

    // display index
    cout << "Target: " << target << "\n";
    cout << "Found at index: " << index << "\n";
}

int LinearSearch(const vector<int>& list, const int target)
{
    int target_index = -1;
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i] == target)
        {
            target_index = i;
            break;
        }
    }
    return target_index;
}