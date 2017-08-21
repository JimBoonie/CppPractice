#include <iostream>
#include <vector>
#include <limits>
#include "horse_utils.cpp"
using namespace std;

int FindMaxCrossingSubarray(const vector<int>&, const int, const int, int&, int&);
int FindMaxSubarray(const vector<int>&, const int, const int, int&, int&);

int main()
{
    int my_array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    vector<int> my_list(my_array, my_array + 16);

    // display original sequence
    cout << "Sequence: ";
    horse::DisplayVector(my_list);
    
    int low, high, sum;
    sum = FindMaxSubarray(my_list, 0, my_list.size() - 1, low, high);
    vector<int> subarray;
    subarray.assign(my_list.begin() + low, my_list.begin() + high + 1);

    // display maximum subarray
    cout << "Indexes: " << low << ", " << high << "\n";
    cout << "Max subarray: ";
    horse::DisplayVector(subarray);
    cout << "Sum: " << sum << "\n";
}

int FindMaxCrossingSubarray(const vector<int>& list, const int low, const int high, 
                             int& max_left, int& max_right) 
{
    // iterate from middle to left
    int mid = (high + low)/2;
    int left_sum = std::numeric_limits<int>::min();
    int sum = 0;
    for(int i = mid; i >= low; i--)
    {
        sum = sum + list[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    // iterate from middle to right
    int right_sum = std::numeric_limits<int>::min();
    sum = 0;
    for(int i = mid + 1; i <= high; i++)
    {
        sum = sum + list[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    return left_sum + right_sum;
}

int FindMaxSubarray(const vector<int>& list, const int low, const int high, 
                     int& max_low, int& max_high)
{
    // array is length 1
    if(low==high)
    {
        max_low = low;
        max_high = high;
        return list[low];
    }

    int mid = (low + high)/2;
    int left_low, left_high, left_sum;
    left_sum = FindMaxSubarray(list, low, mid, left_low, left_high);
    int right_low, right_high, right_sum;
    right_sum = FindMaxSubarray(list, mid + 1, high, right_low, right_high);
    int cross_low, cross_high, cross_sum;
    cross_sum = FindMaxCrossingSubarray(list, low, high, cross_low, cross_high);

    if(left_sum >= right_sum && left_sum >= cross_sum)
    {
        max_low = left_low;
        max_high = left_high;
        return left_sum;
    }
    else if(right_sum >= left_sum && right_sum >= cross_sum)
    {
        max_low = right_low;
        max_high = right_high;
        return right_sum;
    }
    else
    {
        max_low = cross_low;
        max_high = cross_high;
        return cross_sum;
    }
}
