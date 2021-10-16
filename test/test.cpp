#include <Check_func.h>
#include <cstdlib>
#include <ctest.h>

#include <string.h>

// INT border test
CTEST(border_suite, border_int_1)
{
    int size(0);
    char arrs[20] = "test/_int.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);
    size -= 2;
    int expected = 1;
    int result = 0;

    ASSERT_EQUAL(expected, check_border(size, result, arr));
}

CTEST(border_suite, border_int_2)
{
    int size(0);
    char arrs[20] = "test/_int.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);
    size -= 1;

    int expected = 0;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

CTEST(border_suite, border_int_3)
{
    int size(0);
    char arrs[20] = "test/_int.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);

    int expected = 0;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

// FLOAT border test
CTEST(border_suite, border_float_1)
{
    int size(0);
    char arrs[20] = "test/_float.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);
    size -= 2;

    int expected = 2;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

CTEST(border_suite, border_float_2)
{
    int size(0);
    char arrs[20] = "test/_float.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);
    size -= 1;

    int expected = 0;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

CTEST(border_suite, border_float_3)
{
    int size(0);
    char arrs[20] = "test/_float.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);

    int expected = 0;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

// MINUS INT border test
CTEST(border_suite, border_minus_1)
{
    int size(0);
    char arrs[20] = "test/_minus.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);
    size -= 2;

    int expected = 2;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

CTEST(border_suite, border_minus_2)
{
    int size(0);
    char arrs[20] = "test/_minus.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);
    size -= 1;

    int expected = 0;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}

CTEST(border_suite, border_minus_3)
{
    int size(0);
    char arrs[20] = "test/_minus.txt";
    char* arr[3];
    arr[1] = arrs;
    check_size(size, arr[1]);

    int expected = 0;
    int result = 0;
    result = check_border(size, result, arr);

    ASSERT_EQUAL(expected, result);
}