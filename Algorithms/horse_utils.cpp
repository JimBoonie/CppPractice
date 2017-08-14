#include "horse_utils.h"

namespace horse 
{   
    void DisplayVector(const std::vector<int>& list) 
    {
        for(int i = 0; i < list.size(); i++)
        {
            std::cout << list[i];
            if(i < list.size() - 1) 
            {
                std::cout << ", ";
            }
            else 
            {
                std::cout << "\n";
            }
        }
    }
}