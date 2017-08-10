#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>&);

int main()
{
    int my_array[] = {5, 2, 4, 6, 1, 3};
    vector<int> my_list(my_array, my_array+6);
    InsertionSort(my_list);
}

void InsertionSort(vector<int>& list)
{
    for(int i=0; i<list.size(); i++)
    {
        cout << list[i] << "\n";
    }
}
