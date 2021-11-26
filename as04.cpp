#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

/*  
    Isaias Zamora
    izamora@pengo.cabrillo.edu
    Preffered email: Leezam01@gmail.com
    as04.cpp
    assingment name: Radix/Bucket Sort hybrid, assignment number: 4
    
    The purpose of this program is to combine the radix sort and 
    bucket sort to get O(n) implementation.
    
    Code status: working/tested
*/

const int bucketSize = 10;
void radixSort(std::vector<int> &vec, int size)
{
    std::vector<int> bucket[bucketSize];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int r = (int)(vec[j] / pow(10, (i))) % 10;
            bucket[r].push_back(vec[j]);
        }
        int index = 0;
        for (int b = 0; b < bucketSize; b++)
        {
            for (int k = 0; k < bucket[b].size(); k++, index++)
                vec[index] = bucket[b][k];
            bucket[b].clear();
        }
    }
}

int main()
{
    std::vector<int> testVec;
    int vecNum;
    while (std::cin >> vecNum)
        testVec.push_back(vecNum);
    radixSort(testVec, testVec.size());
    for (int i = 0; i < testVec.size(); i++)
        std::cout << std::setfill('0') << std::setw(9) << testVec[i] << std::endl;
}