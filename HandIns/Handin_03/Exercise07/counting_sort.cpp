#include "counting_sort.h"

void countingSort(std::vector<int> &values)
{
    int k = values.size();

    std::vector<int> cntVec(k + 1, 0);

    for (int i = 0; i < k; i++)
    {
        cntVec[values[i]] += 1;
    }

    int pos = 0;

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < cntVec[i]; j++)
        {
            values[pos] = i;
            pos++;
        }
    }
}