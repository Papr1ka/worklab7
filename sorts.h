#ifndef SORTS_H
#define SORTS_H

#endif // SORTS_H

#include <iostream>

using namespace std;

std::pair<int, int> makaka_sort(int size, int *array_ptr);
std::pair<int, int> bubble_sort(int size, int *array_ptr);
std::pair<int, int> gnome_sort(int size, int *array_ptr);
std::pair<int, int> hair_sort(int size, int *array_ptr);
void quick_sort(int *numbers, int left, int right);
