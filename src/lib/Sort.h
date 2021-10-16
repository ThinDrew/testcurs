#pragma once
#include "mymath.h"

#include <iostream>
#include <vector>

template <typename T>
void QuickSort(std::vector<T>& vect, int L, int R)
{
    while (L < R) {
        int i, j, med = (R + L) / 2;
        T x = vect[med];
        for (i = L, j = R; i <= j;) {
            while (i < R && (vect[i] < x))
                i++;
            while (j > L && (vect[j] > x))
                j--;

            if (i <= j) {
                std::swap(vect[i], vect[j]);
                i++;
                j--;
            }
        }

        if (j - L > R - i) {
            QuickSort(vect, i, R);
            R = j;
        } else {
            QuickSort(vect, L, j);
            L = i;
        }
    }
}

template <typename T>
void Print(std::vector<T>& vect)
{
    int i = 1;
    for (auto& p : vect) {
        std::cout << i++ << ") " << p << "\n";
    }
}

template <typename T>
void mShellSort(std::vector<T>& A, long n)
{
    int j;
    T t;

    int m = 1, z = (int)log_2(n, 2);
    while (z > 1) {
        m = 2 * m + 1;
        z -= 1;
    }

    for (int k = m; k >= 1; k = (k - 1) / 2) {
        for (int i = k; i < n; ++i) {
            t = A[i];
            for (j = i - k; j >= 0 && t < A[j]; j -= k) {
                A[j + k] = A[j];
            }
            A[j + k] = t;
        }
    }
}

template <typename T>
void InsertSort(std::vector<T>& A, long n)
{
    int i = 1, j;
    float t;
    for (i = 1; i < n; i++) {
        t = A[i];
        for (j = i - 1; j > -1 && t < A[j]; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = t;
    }
}