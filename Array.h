/*
 * Array.h
 *
 *  Created on: 19/02/2022
 *      Author: lalaa
 */

#ifndef ARRAY_H_
#define ARRAY_H_

template<class T>

class Array{
private:
    T* A;
    int size;
    int length;

    void swap(T *x, T *y);
    T * merge_A(T *L, int len_l, T *H, int len_h, int arr_size);
    T * merge_sort_A(int start, int end, int arr_size);

public:
    Array();
    Array(int size);
    Array(int size, int length, T *B);
    ~Array();
    void reverse_array();
    void reverse_outside_in();
    void create();
    void test_array();
    void display();
    void append(T x);
    void insert(int index, T value);
    int binary_insert(T value);
    T remove(int index);
    int search(T value);
    int binary_search(T key);
    T get_value(int index);
    int get_size();
    int get_length();
    void set_value(int index, T x);
    void set_size(int sz);
    void set_length(int len);
    T max_value();
    T min_value();
    T sum_of_values();
    float average_value();
    void shift_left(int n);
    void shift_right(int n);
    void rotate_left(int n);
    void rotate_right(int n);
    void sign_split();
    int is_sorted();
    Array merge(Array arr1, Array arr2);
    Array merge_sort(int start, int end);
    T * merge_sort_A_handler();
    Array Union(Array arr1, Array arr2);
    Array Intersection(Array arr1, Array arr2);
    Array Difference(Array arr1, Array arr2);
};

#endif /* ARRAY_H_ */
