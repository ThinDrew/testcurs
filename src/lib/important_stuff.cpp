#include "important_stuff.h"
#include "Check_func.h"
#include "Sort.h"

#include <iostream>

std::ostream& operator<<(std::ostream& out, const Error& error)
{
    out << "Код ошибки: " << static_cast<int>(error);
    return out;
}

void check_and_sort_array(std::vector<float>& array, char* argv[], int size)
{
    int choise(0);

    choise = check_border(array.capacity(), choise, argv);

    switch (choise) {
    case 0: {
        QuickSort(array, 0, array.size() - 1);
        // Print(array);
        break;
    }

    case 1: {
        InsertSort(array, array.size());
        /*Print(array);*/
        break;
    }

    case 2: {
        mShellSort(array, array.size());
        /*Print(array);*/
        break;
    }
    }
}