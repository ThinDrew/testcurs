#include "Check_func.h"
#include "Record.h"
#include "important_stuff.h"

#include <iostream>
#include <locale>
#include <vector>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian_Russia.1251");

    int size = 0;
    
    if (argc < 2) {
        std::cout << Error::ERROR_INPUT_WAS_EMPTY;
        exit(0);
    }

    // Создание и заполнение массива
    check_size(size, argv[1]);
    std::vector<float> array(size);
    array.resize(0);
    record_array(array, argv[1]);

    check_and_sort_array(array, argv, size);

    output_data(array, argv, argc);
}
