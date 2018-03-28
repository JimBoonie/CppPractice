#include <iostream>
#include <vector>
#include "horse_utils.cpp"
using namespace std;

struct Heap {
    vector<int> list;
    int heap_end;
};

int Parent(const int);
int Left(const int);
int Right(const int);
void Heapify(Heap&, const int, const bool);
void BuildHeap(Heap&, const bool);
void HeapSort(vector<int>&, const bool);

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

    HeapSort(my_list, 1);
    
    // display sorted sequence
    cout << "Sorted sequence: ";
    horse::DisplayVector(my_list);
}

inline int Parent(const int idx) 
{
    return idx - 1 >> 1;
}

inline int Left(const int idx)
{
    return (idx << 1) + 1;
}

inline int Right(const int idx)
{
    return (idx << 1) + 2;
}

void Heapify(Heap &heap, const int r, const bool direction)
{
    int left = Left(r);
    int right = Right(r);
    // if(left <= heap.heapsize)
    // {

    // }
}

void BuildHeap(Heap &heap, const bool direction) 
{
    int a = 1;
    // for(int i = r; i >= (r + 1) / 2; i--)
    // {
    //     int q = i;
    //     while(q > 0)
    //     {
    //         int q_val = heap.list[q];
    //         int parent_idx = Parent(q);
    //         int parent_val = heap.list[parent_idx];

    //         // check direction
    //         bool inequality = 0;
    //         if(direction)
    //         {
    //             inequality = parent_val < q_val;
    //         }
    //         else
    //         {
    //             inequality = parent_val > q_val;
    //         }

    //         if(inequality)
    //         {
    //             heap.list[q] = parent_val;
    //             heap.list[parent_idx] = q_val;
    //         }
    //         q = parent_idx;
    //     }
    // }
}

void HeapSort(vector<int>& list, const bool direction=1)
{
    Heap myheap;
    myheap.list = list;
    myheap.heap_end = myheap.list.size() - 1;
   
    BuildHeap(myheap, direction);
    int list_end = myheap.list.size() - 1;
    for(int i = list_end; i > 0; i--)
    {
        // exchange list[1] with list[i]
        int tmp = myheap.list[0];
        myheap.list[0] = myheap.list[i];
        myheap.list[i] = tmp;

        myheap.heap_end -= 1;
        Heapify(myheap, 0, direction);
    }
}