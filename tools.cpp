#include <iostream>

int min(int size, int *array)
{
    int min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int max(int size, int *array)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int avg(int size, int *array)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum / size;
}

bool is_sorted(int size, int *array)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}
