#include "important_stuff.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void record_array(std::vector<float>& array, char* argv)
{
    std::ifstream out(argv);

    if (!out.is_open()) {
        std::cout << Error::ERROR_OPEN_FILE;
        exit(0);
    }

    std::string str;
    std::stringstream mystream;
    float buffer;

    for (long unsigned int i = 0; i < array.capacity(); i++) {
        out >> str;
        mystream << str;
        mystream >> buffer;
        array.push_back(buffer);
        mystream.str("");
        mystream.clear();
    }
}

void output_data(std::vector<float>& array, char** argv, int argc)
{
    std::string name_file("Sorted_file.txt");
    if (argc >= 3) {
        name_file = argv[2];
    }
    std::ofstream cin(name_file);

    for (auto& ptr : array) {
        cin << ptr << "\n";
    }
}