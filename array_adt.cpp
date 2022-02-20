#include <iostream>
#include <stdio.h>
#include "Array.h"

using namespace std;


//Array merge(Array arr1, Array arr2)
//{
//    int i,j,k, c_len;
//    i=j=k=0;
//    //Get lengths of arrays 1 & 2 (parameter 2)
//    int m = arr1.get_length();
//    int n = arr2.get_length();
//    c_len=m+n;
//    //Initialise array in heap with 10 spare
//    int *c = new int [c_len+10];
////    Array *arr3 = new Array(c_len+10,0,c);
//    Array arr3(c_len+10,0,c);
//    //Loop through arrays 1 & 2 merging to 3
//    while(i<m && j<n)
//    {
//        if(arr1.get_value[i] < arr2.get_value[j])
////            arr3.A[k++] = arr1.A[i++];
//        	arr3.set_value(k++, arr1.get_value[i++]);
//        else
////            arr3.A[k++] = arr2.A[j++];
//        	arr3.set_value(k++, arr2.get_value[j++]);
//    }
//    for(;i<m;i++)
////        arr3.A[k++] = arr1.A[i];
//    	arr3.set_value(k++, arr1.get_value[i]);
//    for(;j<m;j++)
////        arr3.A[k++] = arr2.A[j];
//    	arr3.set_value(k++, arr2.get_value[j]);
//    arr3.set_length(c_len);
//
//    return arr3;
//}


int main() {
 
    int n,key,index;
    char cont = 'y', yes = 'y';
//    Array<int> arr(20);
    Array<int> * arr = new Array<int>(20);
    // arr.create();
    arr->test_array();
    cout<<"Test array: "<<flush;
    arr->display(); cout<<endl;

    /* Testing merge_sort */
//    n = arr.get_length();
//    Array<int> arr_sorted = arr.merge_sort(0,n-1);
    int *B = arr->merge_sort_A_handler();
//    Array<int> arr_sorted(arr.get_size(),arr.get_length(),B);
    Array<int> * arr_sorted = new Array<int>(arr->get_size(),arr->get_length(),B);
    cout<<"Sorted array: "<<flush;
    arr_sorted->display(); cout<<endl;


//     /* Testing Union(), Intersection() and Difference
//      * on sorted arrays */
//    int *p = new int [10] {2,4,6,10,15,18,25,30,30,99};
//    int *q = new int[10] {3,4,7,18,18,20,101};
//    Array arr1(10,10,p);
//    Array arr2(10,7,q);
//    arr1.display(); cout<<endl;
//    arr2.display(); cout<<endl;
////    Array arr3 = arr1.Union(arr1, arr2);  //Union()
////    Array arr3 = arr1.Intersection(arr1, arr2);  //Intersection()
//    Array arr3 = arr1.Difference(arr1, arr2);  //Difference()
//    Array arr4 = arr1.Difference(arr2, arr1);  //Difference()
//    arr3.display(); cout<<endl;
//    arr4.display(); cout<<endl;

    while(cont == yes) 
    {
        // /* Testing insert()*/
        // cout<<"Input index and value: "<<flush;
        // cin>>index>>key;
        // cout<<endl;
        // arr.insert(index,key);
        // arr.display();

        // /* Testing append()*/
        // cout<<"Input value to append: "<<flush;
        // cin>>key;
        // cout<<endl;
        // arr.append(key);
        // arr.display();

        // /* Testing remove() function */
        // cout<<"Input index to remove: "<<flush;
        // cin>>index;
        // cout<<arr.remove(index)<<" removed."<<endl;
        // arr.display();

        // /* Testing linear search() */
        // cout<<"Input value to search: "<<flush;
        // cin>>key;
        // cout<<"Number: "<<key<<" found at index "<<arr.search(key)<<endl;

        // /* Testing binary_search() - is_sorted() == True */
        // if(arr.is_sorted())
        // {
        //     cout<<"Input value to binary search: "<<flush;
        //     cin>>key;
        //     cout<<"Number: "<<key<<" found at index "<<arr.binary_search(key)<<endl;
        // }

//        /* Test max, min, sum and average functions */
//        cout<<"Maximum value: "<<arr.max_value()<<endl;
//        cout<<"Minimum value: "<<arr.min_value()<<endl;
//        cout<<"Sum of values: "<<arr.sum_of_values()<<endl;
//        cout<<"Average value: "<<arr.average_value()<<endl;

//         /* Test get and set functions functions */
//         cout<<"Fetch value at index : "<<flush;
//         cin>>index;
//         cout<<arr.get_value(index)<<endl;
//         cout<<"Set value to index (val index): "<<flush;
//         cin>>key>>index;
//         arr.set_value(index,key);
//         arr.display();

//        /* Testing reverse array function */
//        // arr.reverse_array();
//        arr.reverse_outside_in();
//        arr.display();

        // /* Testing shift_left() function */
        // cout<<"Shifting left by "<<flush;
        // cin>>n;
        // arr.shift_left(n);
        // cout<<endl;
        // arr.display();

        // /* Testing shift_right() function */
        // cout<<"Shifting right by "<<flush;
        // cin>>n;
        // arr.shift_right(n);;
        // cout<<endl;
        // arr.display();

        // /* Testing rotate function */
        // cout<<"Rotating right by "<<flush;
        // cin>>n;
        // arr.rotate_right(n);
        // arr.display();
        // cout<<"Rotating left by "<<flush;
        // cin>>n;
        // arr.rotate_left(n);
        // arr.display();

        // /* Testing binary_insert() - is_sorted() == True */
        // if(arr.is_sorted())
        // {
        //     cout<<"Input value to insert: "<<flush;
        //     cin>>key;
        //     cout<<endl;
        //     cout<<key<<" inserted at index "<<arr.binary_insert(key)<<endl;
        //     arr.display();

//        /* Testing get_param() */
//        cout<<"Size: "<<arr.get_size()<<endl;
//        cout<<"Length: "<<arr.get_length()<<endl;

        cout<<"Do you wish to continue? (y/n): "<<flush;
        cin>>cont;
    }

    // /* Test sign_split() - use set_value() to set some values negative first */
    // arr.sign_split();
    // arr.display();
    
    /* Delete Array objects in heap */
    delete arr;
    delete arr_sorted;

    return 0;
}
