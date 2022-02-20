/*
 * Array.h
 *
 *  Created on: 19/02/2022
 *      Author: lalaa
 */

#ifndef ARRAY_H_
#define ARRAY_H_

class Array{
private:
    int* A;
    int size;
    int length;

    void swap(int *x, int *y);
    int * merge_A(int *L, int len_l, int *H, int len_h, int arr_size);
    int * merge_sort_A(int start, int end, int arr_size);

public:
    Array();
    Array(int size);
    Array(int size, int length, int *B);
    ~Array();
    void reverse_array();
    void reverse_outside_in();
    void create();
    void test_array();
    void display();
    void append(int x);
    void insert(int index, int value);
    int binary_insert(int value);
    int remove(int index);
    int search(int value);
    int binary_search(int key);
    int get_value(int index);
    int get_param(int param);
    void set_value(int index, int x);
    void set_param(int param, int value);
    int max_value();
    int min_value();
    int sum_of_values();
    float average_value();
    void shift_left(int n);
    void shift_right(int n);
    void rotate_left(int n);
    void rotate_right(int n);
    void sign_split();
    int is_sorted();
    Array merge(Array arr1, Array arr2);
    Array merge_sort(int start, int end);
    int * merge_sort_A_handler();
    Array Union(Array arr1, Array arr2);
    Array Intersection(Array arr1, Array arr2);
    Array Difference(Array arr1, Array arr2);
};

#endif /* ARRAY_H_ */
