#include <iostream>
#include <vector>
#include <limits>
#include "horse_utils.cpp"
using namespace std;

void Merge(const int, const int, const int, vector<int>&);
void MergeSort(const int, const int, vector<int>&);

int main()
{
    int my_array[] = {5, 2, 4, 6, 1, 8, 3, 7};
    vector<int> my_list(my_array, my_array + 8);

    // display original sequence
    cout << "Unsorted sequence: ";
    horse::DisplayVector(my_list);
    
    MergeSort(0, my_list.size() - 1, my_list);

    // display sorted sequence
    cout << "Sorted sequence: ";
    horse::DisplayVector(my_list);
}

void Merge(const int p, const int q, const int r, vector<int>& list) 
{
    vector<int> left_list (list.begin() + p, list.begin() + q + 1);
    left_list.push_back(std::numeric_limits<int>::max());
    vector<int> right_list (list.begin() + q + 1, list.begin() + r + 1);
    right_list.push_back(std::numeric_limits<int>::max());

    int i = 0;
    int j = 0;
    for(int k = p; k <= r; k++)
    {
        if(left_list[i] <= right_list[j])
        {
            cout << left_list[i] << " (l), ";
            list[k] = left_list[i];
            i++;
        }
        else
        {
            cout << right_list[j] << " (r), ";
            list[k] = right_list[j];
            j++;
        }
    }
    cout << "\n";
}

void MergeSort(const int p, const int r, vector<int>& list)
{
    // perform merge sort
    if(p < r)
    {
        int q = (p + r)/2;
        MergeSort(p, q, list);
        MergeSort(q + 1, r, list);
        Merge(p, q, r, list);
    }
}
