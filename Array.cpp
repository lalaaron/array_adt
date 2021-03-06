/*
 * Array.cpp
 *
 *  Created on: 19/02/2022
 *      Author: lalaa
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

using namespace std;

template<class T>
Array<T>::Array(){
	cout << "Array created" << endl;
	this->A = NULL;
    this->size=0;
    this->length=0;
}

template<class T>
Array<T>::Array(int size){
	cout << "Array created" << endl;
    this->size = size;
    this->length=0;
    A = new T [size];
}

template<class T>
Array<T>::Array(int size, int length, T *B){
	cout << "Array created" << endl;
    this->size = size;
    this->length = length;
    A = B;
}

template<class T>
Array<T>::~Array(){
    delete[] A;
    cout << "Array destroyed" << endl;
}

template<class T>
void Array<T>::reverse_array()
{
    int i,j;
    T *B = new T [size];
    for(i=0,j=length-1; i<length; i++,j--)
    {
        B[i]=A[j];
    }
    delete[] A;
    A=B;
}

template<class T>
void Array<T>::swap(T *x, T *y)
{
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

template<class T>
void Array<T>::reverse_outside_in()
{
    int i,j;
    for(i=0,j=length-1; i<j; i++,j--)
    {
        swap(&A[i], &A[j]);
    }
}

template<class T>
void Array<T>::create(){
    cout << "Enter number of elements: " << flush;
    cin >> length;
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < length; i++){
        cout << "Array element: " << i << " = " << flush;
        cin >> A[i];
    }
}

template<class T>
void Array<T>::test_array()
{
    int i;
    //int temp_arr[size] = {4,8,10,15,18,21,24,27,29,33,34,37,39,41,43};
    length=20;
    for(i=0;i<length;i++)
    {
        //A[i]=temp_arr[i];
        A[i] = rand() % 100 - 50;
    }
    for(i=length;i<size;i++)
    	A[i]=0;
}

template<class T>
void Array<T>::display(){
    for (int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout<<flush;
}

template<class T>
void Array<T>::append(T x)
{

    if(length<size)
    {
        A[length++]=x;
        // length++;
        // cout<<x<<" added, Length = "<<length<<endl;
    }
    else cout<<"Max array size reached. Append aborted!"<<endl;
}

template<class T>
void Array<T>::insert(int index, T value)
{
    if(length>=size)
        cout<<"Array size at maximum. Insert aborted!"<<endl;
    else if((index>length)||(index<0))
        cout<<"Index "<<index<<" out of range. Insert aborted!"<<endl;
    else
    {
        for(int i=length;i>index;i--)
            A[i]=A[i-1];
        A[index]=value;
        length++;
        // cout<<value<<" added at index "<<index<<", Length = "<<length<<endl;
    }
}

template<class T>
int Array<T>::binary_insert(T value)
{
    int low=0,high=length,mid,i;
    if(length>=size)
        return -1;
    else
    {
        while(low<high)
        {
            mid=(low+high)/2;
            if(value>A[mid])
                low=mid+1;
            else if(value<=A[mid])
                high=mid;
        }
    }
    if(low!=high)
        return -1;
    for(i=length;i>low;i--)
        A[i]=A[i-1];
    A[low]=value;
    length++;
    return low;
}

template<class T>
T Array<T>::remove(int index)
{
    T x;
    int i;
    if(index>=0 && index<length)
    {
        x=A[index];
        length--;
        for(i=index;i<length;i++)
            A[i]=A[i+1];
        A[length]=0;
        // cout<<x<<" removed from index "<<index<<", length = "<<length<<endl;
        return x;
    }
    cout<<"Index "<<index<<" out of range. Remove aborted!"<<endl;
    return 0;
}

template<class T>
int Array<T>::search(T value)
{
    int i;

    // // Linear search (O(n))
    // for(i=0;i<length;i++)
    // {
    //     if(value==A[i])
    //         return i;
    // }

    // // Transposition
    // for(i=0;i<length;i++)
    // {
    //     if(value==A[i])
    //     {
    //         if(i>0)
    //             swap(&A[i], &A[i-1]);
    //         return i;
    //     }
    // }

    // Move to front
    for(i=0;i<length;i++)
    {
        if(value==A[i])
        {
            if(i>0)
                swap(&A[i], &A[0]);
            return i;
        }
    }

    // Value not found
    return -1;
}

template<class T>
int Array<T>::binary_search(T key)
{
    /* Iterative algorithm based on tail recursion */
    int mid, low=0, high=length-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(key==A[mid])
            return mid;
        if(key>A[mid])
            low=mid+1;
        else if(key<A[mid])
            high=mid-1; }
    return -1;

    // /* Tail recursion algorithm:
    // int binary_search(int key, int low, int high) */
    // if(low<=high) {
    //     int mid=(low+high)/2;
    //     // Base case
    //     if(key==A[mid])
    //         return mid;
    //     // Recursion
    //     if(key>A[mid])
    //         return binary_search(key,mid+1,high);
    //     else  // (key<A[mid])
    //         return binary_search(key,low,mid-1);
    // }
    // // Match not found
    // return -1;
}

template<class T>
T Array<T>::get_value(int index)
{
    if(index>=0 && index<length)
        return A[index];
    cout<<"Invalid index "<<flush;
    return -1;
}

template<class T>
int Array<T>::get_size()
{
    return size;
}

template<class T>
int Array<T>::get_length()
{
    return length;
}

template<class T>
void Array<T>::set_value(int index, T x)
{
    if(index>=0 && index<length)
        A[index]=x;
    else
        cout<<"Invalid index"<<flush;
}

template<class T>
void Array<T>::set_size(int sz)
{
	size = sz;
}

template<class T>
void Array<T>::set_length(int len)
{
	length = len;
}

template<class T>
T Array<T>::max_value()
{
    int i;
    T max = A[0];
    for(i=1;i<length;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

template<class T>
T Array<T>::min_value()
{
    int i;
    T min = A[0];
    for(i=1;i<length;i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

template<class T>
T Array<T>::sum_of_values()
{
    int i;
    T total = 0;
    for(i=0;i<length;i++)
        total+=A[i];
    return total;
}

template<class T>
float Array<T>::average_value()
{
    return float(sum_of_values())/length;
}

template<class T>
void Array<T>::shift_left(int n)
{
    if(n<=length && n>0)
    {
        int i,j,k=length-n;
        for(i=0,j=n; i<k; i++,j++)
        {
            A[i]=A[j];
        }
        for(i=k;i<length;i++)
            A[i]=0;
    }
    else
        cout<<"Invalid number of places "<<endl;
}

template<class T>
void Array<T>::shift_right(int n)
{
    if(n<=length && n>0)
    {
        int i,j,k=length-1;
        for(i=k,j=k-n; i>=n; i--,j--)
        {
            A[i]=A[j];
        }
        for(i=n-1;i>=0;i--)
            A[i]=0;
    }
    else
        cout<<"Invalid number of places "<<endl;
}

template<class T>
void Array<T>::rotate_left(int n)
{
    if(n>0)
    {
        int i,j;
        n%=length;
        int B[n];   //temp array
        cout<<"Rotate left by "<<n<<". "<<endl;
        for(j=0;j<n;j++)
            B[j] = A[j];
        for(i=0,j=n; j<length; i++,j++)
            A[i] = A[j];
        for(i=length-n,j=0; i<length; i++,j++)
            A[i] = B[j];
    }
    else
        cout<<"Invalid argument: must be n>0 "<<endl;
}

template<class T>
void Array<T>::rotate_right(int n)
{
    if(n>0)
    {
        int i,j;
        n%=length;
        int B[n];   //temp array
        cout<<"Rotate right by "<<n<<". "<<endl;
        for(i=length-n,j=0; j<n; i++,j++)
            B[j] = A[i];
        for(i=length-1,j=i-n; j>=0; i--,j--)
            A[i] = A[j];
        for(j=0; j<n; j++)
            A[j] = B[j];
    }
    else
        cout<<"Invalid argument: must be n>0 "<<endl;
}

template<class T>
void Array<T>::sign_split()
{
    int i=0, j=length-1;
    while(i<j)
    {
        while(A[i]<0){i++;}
        while(A[j]>=0){j--;}
        if(i<j)
            swap(&A[i], &A[j]);
    }
}

template<class T>
int Array<T>::is_sorted()
{
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]<A[i-1])
            return 0;
    }
    return 1;
}

template<class T>
Array<T> Array<T>::merge(Array<T> arr1, Array<T> arr2)
{
//	/* Debug output */
//    cout<<"Merging: {"<<flush;
//    arr1.display();
//    cout<<"} with {"<<flush;
//    arr2.display(); cout<<"}"<<endl;
//    /***************/

	int i,j,k, c_len;
    i=j=k=0;
    //Get lengths of arrays 1 & 2 (parameter 2)
    int m = arr1.get_length();
    int n = arr2.get_length();
    c_len=m+n;
    //Initialise array in heap with 10 spare
    T *c = new T [c_len+10];
//    Array *arr3 = new Array(c_len+10,0,c);
    Array arr3(c_len+10,0,c);
//    cout<<"Created "<<flush;  //debug
//    arr3.display(); cout<<endl;  //debug
    //Loop through arrays 1 & 2 merging to 3
    while(i<m && j<n)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else
            arr3.A[k++] = arr2.A[j++];
    }
    for(;i<m;i++)
        arr3.A[k++] = arr1.A[i];
    for(;j<n;j++)
        arr3.A[k++] = arr2.A[j];
    arr3.set_length(c_len);

    return arr3;
}

template<class T>
Array<T> Array<T>::merge_sort(int start, int end)
{
//	cout<<"Sorting index["<<start<<":"<<end<<"]"<<endl;  //debug
	if(end <= start)
	{
		int value = A[start];
//		cout<<"Created "<<flush;  //debug
		T *p = new T [1] {value};
		Array arr0(1,1,p);
//		arr0.display(); cout<<endl;  //debug
		return arr0;
	}
	int mid = (start+end)/2;
	Array arr_low = merge_sort(start,mid);
//	cout<<"Created "<<flush;  //debug
//	arr_low.display(); cout<<endl;  //debug
	Array arr_high = merge_sort(mid+1,end);
//	cout<<"Created "<<flush;  //debug
//	arr_high.display(); cout<<endl;  //debug
	Array sorted_array = merge(arr_low, arr_high);
//	cout<<"Created "<<flush;  //debug
//	sorted_array.display(); cout<<endl;  //debug
	return sorted_array;
}

template<class T>
T * Array<T>::merge_A(T *L, int len_l, T *H, int len_h, int arr_size)
{
//	/* Debug output */
//    cout<<"Merging: {"<<flush;
//    arr1.display();
//    cout<<"} with {"<<flush;
//    arr2.display(); cout<<"}"<<endl;
//    /***************/

	int i,j,k, len_m;
    i=j=k=0;
    len_m = len_l + len_h;
    //Initialise array in heap with 10 spare
    T *M = new T [arr_size];  //[len_m];
//    cout<<"Heap array["<<len_m<<"] created"<<endl;
    //Loop through arrays 1 & 2 merging to 3
    while(i<len_l && j<len_h)
    {
        if(L[i] < H[j])
            M[k++] = L[i++];
        else
            M[k++] = H[j++];
    }
    for(;i<len_l;i++)
        M[k++] = L[i];
    for(;j<len_h;j++)
        M[k++] = H[j];

    return M;
}

template<class T>
T * Array<T>::merge_sort_A(int start, int end, int arr_size)
{
//	cout<<"Sorting index["<<start<<":"<<end<<"]"<<endl;  //debug
	if(end <= start)
	{
		int value = A[start];
		T *s = new T [1] {value};
//		cout<<"Heap array[1] created"<<endl;
		return s;
	}
	int len_l, len_h, mid, half_size;
	mid = (start+end)/2;
	len_l = (mid-start)+1;
	len_h = end-mid;
	half_size = arr_size / 2;
//	len_s = (end-start)+1;

	T *l;  // = new int [len_l];
//	cout<<"Heap array["<<len_l<<"] created"<<endl;
	l = merge_sort_A(start,mid,half_size);

	T *h;  // = new int [len_h];
//	cout<<"Heap array["<<len_h<<"] created"<<endl;
	h = merge_sort_A(mid+1,end,half_size);

	T *s;
	s = merge_A(l, len_l, h, len_h, arr_size);

	delete [] l;
//	cout<<"Heap array["<<len_l<<"] destroyed"<<endl;
	delete [] h;
//	cout<<"Heap array["<<len_h<<"] destroyed"<<endl;

	return s;
}

template<class T>
T * Array<T>::merge_sort_A_handler()
{
	T *sorted;  // = new int [size];
//	cout << "Primary heap array[" << size << "] created" << endl;
	sorted = merge_sort_A(0, length-1, size);
	return sorted;
}

template<class T>
Array<T> Array<T>::Union(Array<T> arr1, Array<T> arr2)
{
//	/* Debug output */
//    cout<<"Uniting: {"<<flush;
//    arr1.display();
//    cout<<"} with {"<<flush;
//    arr2.display(); cout<<"}"<<endl;
//    /***************/

	int i,j,k, c_len;
    i=j=k=0;
    //Get lengths of arrays 1 & 2 (parameter 2)
    int m = arr1.get_length();
    int n = arr2.get_length();
    c_len=m+n;
    //Initialise array in heap with 10 spare
    T *c = new T [c_len+10];
//    Array *arr3 = new Array(c_len+10,0,c);
    Array arr3(c_len+10,0,c);
//    cout<<"Created "<<flush;  //debug
//    arr3.display(); cout<<endl;  //debug
    //Loop through arrays 1 & 2 merging to 3
    while(i<m && j<n)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            arr3.A[k++] = arr2.A[j++];
        else
        {
        	arr3.A[k++] = arr1.A[i++];
        	j++;
        }
    }
    for(;i<m;i++)
        arr3.A[k++] = arr1.A[i];
    for(;j<n;j++)
        arr3.A[k++] = arr2.A[j];
    arr3.set_length(k);

    return arr3;
}

template<class T>
Array<T> Array<T>::Intersection(Array<T> arr1, Array<T> arr2)
{
//	/* Debug output */
//    cout<<"Intersecting: {"<<flush;
//    arr1.display();
//    cout<<"} with {"<<flush;
//    arr2.display(); cout<<"}"<<endl;
//    /***************/

	int i,j,k, c_len;
    i=j=k=0;
    //Get lengths of arrays 1 & 2 (parameter 2)
    int m = arr1.get_length();
    int n = arr2.get_length();
    c_len=m+n;
    //Initialise array in heap with 10 spare
    T *c = new T [c_len+10];
//    Array *arr3 = new Array(c_len+10,0,c);
    Array arr3(c_len+10,0,c);
//    cout<<"Created "<<flush;  //debug
//    arr3.display(); cout<<endl;  //debug
    //Loop through arrays 1 & 2 merging to 3
    while(i<m && j<n)
    {
        if(arr1.A[i] < arr2.A[j])
            i++;
        else if(arr2.A[j] < arr1.A[i])
            j++;
        else if(arr2.A[j] == arr1.A[i])
        {
        	arr3.A[k++] = arr1.A[i++];
        	j++;
        }
    }
    arr3.set_length(k);

    return arr3;
}

template<class T>
Array<T> Array<T>::Difference(Array<T> arr1, Array<T> arr2)
{
//	/* Debug output */
//    cout<<"Uniting: {"<<flush;
//    arr1.display();
//    cout<<"} with {"<<flush;
//    arr2.display(); cout<<"}"<<endl;
//    /***************/

	int i,j,k, c_len;
    i=j=k=0;
    //Get lengths of arrays 1 & 2 (parameter 2)
    int m = arr1.get_length();
    int n = arr2.get_length();
    c_len=m+n;
    //Initialise array in heap with 10 spare
    T *c = new T [c_len+10];
//    Array *arr3 = new Array(c_len+10,0,c);
    Array arr3(c_len+10,0,c);
//    cout<<"Created "<<flush;  //debug
//    arr3.display(); cout<<endl;  //debug
    //Loop through arrays 1 & 2 merging to 3
    while(i<m && j<n)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
        	j++;
        else
        	{j++; i++;}
    }
    for(;i<m;i++)
        arr3.A[k++] = arr1.A[i];
    arr3.set_length(k);

    return arr3;
}

