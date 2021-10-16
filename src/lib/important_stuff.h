#pragma once
#include <iostream>
#include <vector>

enum class Error { ERROR_OPEN_FILE = -10, ERROR_INPUT_WAS_EMPTY };

std::ostream& operator<<(std::ostream& out, const Error& error);

void check_and_sort_array(std::vector<float>& array, char* argv[], int size);