#include "important_stuff.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void check_size(int& size, char* argv)
{
    std::ifstream out(argv);

    if (!out.is_open()) {
        std::cout << Error::ERROR_OPEN_FILE;
        exit(0);
    }

    std::string str;
    while (getline(out, str, '\n')) {
        size++;
    }
}

bool check_value(float buffer)
{
    float a;
    a = buffer - static_cast<int>(buffer);
    return (a != 0) or (buffer < 0);
}

int check_type(int s_i, int choise, char* argv)
{
    std::ifstream out(argv);

    if (!out.is_open()) {
        std::cout << Error::ERROR_OPEN_FILE;
        exit(0);
    }

    std::string str;
    std::stringstream mystream;
    float buffer;

    for (int i = 0; i < s_i; i++) {
        out >> str;
        mystream << str;
        mystream >> buffer;
        if (check_value(buffer)) {
            return choise = 2;
        }
        mystream.str("");
        mystream.clear();
    }

    return choise;
}

int check_border(int size, int choise, char* argv[])
{
    if (size < 1000) {
        choise = 1;
        std::cout << argv[1];
        choise = check_type(size, choise, argv[1]);
    }
    return choise;
}