#include "sorts.h"

std::pair<int, int> makaka_sort(int size, int *array_ptr)
{
    bool sorted = false;
    int pos1, pos2;
    int temp;
    int counter = 0;
    int iterations = 0;
    int swipes = 0;
    while (counter < 1000)
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            iterations++;
            if (array_ptr[i] > array_ptr[i + 1])
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
        {
            break;
        }
        else
        {
            iterations++;
            pos1 = rand() % size;
            pos2 = rand() % size;
            temp = array_ptr[pos1];
            array_ptr[pos1] = array_ptr[pos2];
            array_ptr[pos2] = temp;
            swipes++;
        }
        counter++;
    }
    if (counter >= 1000)
    {
        swipes = 1000;
    }
    return std::pair<int, int>(swipes, iterations);
}


void quick_sort(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];

    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
        {
            right--;
        }

        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }

        while ((numbers[left] <= pivot) && (left < right))
        {
            left++;
        }

        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }

    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    if (left < pivot)
    {
        quick_sort(numbers, left, pivot - 1);
    }
    if (right > pivot)
    {
        quick_sort(numbers, pivot + 1, right);
    }
}


std::pair<int, int> bubble_sort(int size, int *array_ptr)
{
    int temp;
    int swipes = 0;
    int iterations = 0;
    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (array_ptr[j] > array_ptr[j + 1])
            {
                temp = array_ptr[j];
                array_ptr[j] = array_ptr[j + 1];
                array_ptr[j + 1] = temp;
                swipes++;
            }
            iterations++;
        }
    }
    return std::pair<int, int>(swipes, iterations);
}


std::pair<int, int> gnome_sort(int size, int *array_ptr)
{
    int i = 0;
    int swipes = 0;
    int iterations = 0;
    int temp;
    while (i < size - 1)
    {
        iterations++;
        if (array_ptr[i] > array_ptr[i + 1])
        {
            swipes++;
            temp = array_ptr[i];
            array_ptr[i] = array_ptr[i + 1];
            array_ptr[i + 1] = temp;
            if (i > 0)
            {
                i--;
            }
        }
        else
        {
            i++;
        }
    }
    return std::pair<int, int>(swipes, iterations);
}

std::pair<int, int> hair_sort(int size, int *array_ptr)
{
    int step = size - 1;
    bool flag = true;
    int i;
    int temp;
    int iterations = 0;
    int swipes = 0;
    while (step > 1 or flag)
    {
        if (step > 1)
        {
            step = step / 1.247;
        }
        flag = false;
        i = 0;
        while (i + step < size)
        {
            iterations++;
            if (array_ptr[i] > array_ptr[i + step])
            {
                temp = array_ptr[i];
                array_ptr[i] = array_ptr[i + step];
                array_ptr[i + step] = temp;
                flag = true;
                swipes++;
            }
            i++;
        }
    }
    return std::pair<int, int>(swipes, iterations);
}
