#include <iostream>
#include <vector>
#include "horse_utils.cpp"
using namespace std;

int Parent(const int);
int Left(const int);
int Right(const int);
void BuildMaxHeap(vector<int>& list, const int r);
void HeapSort(vector<int>& list);

int main()
{
    // test idx functions
    cout << "Parent of 8: " << Parent(8) << "\n";
    cout << "Parent of 13: " << Parent(13) << "\n";
    cout << "Left of 8: " << Left(8) << "\n";
    cout << "Right of 8: " << Right(8) << "\n";

    int my_array[] = {2, 8, 4, 1, 3, 0, 7, 9, 5, 10, 6, 11};
    vector<int> my_list(my_array, my_array + 12);

    // display original sequence
    cout << "Unsorted sequence: ";
    horse::DisplayVector(my_list);
    
    HeapSort(my_list);

    // display sorted sequence
    cout << "Sorted sequence: ";
    horse::DisplayVector(my_list);
}

int Parent(const int idx) 
{
    return (idx - 1) / 2;
}

int Left(const int idx)
{
    return idx * 2 + 1;
}

int Right(const int idx)
{
    return idx * 2 + 2;
}

void BuildMaxHeap(vector<int>& list, const int r) 
{
    for(int i = r; i >= (r + 1) / 2; i--)
    {
        int q = i;
        while(q > 0)
        {
            int q_val = list[q];
            int parent_idx = Parent(q);
            int parent_val = list[parent_idx];
            if(parent_val < q_val)
            {
                list[q] = parent_val;
                list[parent_idx] = q_val;
            }
            q = parent_idx;
        }
    }
}

void HeapSort(vector<int>& list)
{
    int list_end = list.size() - 1;
    for(int i = list_end; i > 0; i--)
    {
        cout << i << "\n";
        BuildMaxHeap(list, i);
        int tmp = list[0];
        list[0] = list[i];
        list[i] = tmp;
    }
}