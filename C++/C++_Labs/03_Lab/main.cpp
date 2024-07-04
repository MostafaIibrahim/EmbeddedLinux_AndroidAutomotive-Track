#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
typedef int* (*CallbackFunc)(int** arr_2d,int size, int *row_size , int (*Func)(int* arr,int size));



int* arr2D_Res(int** arr_2d,int size, int *row_size , int (*Func)(int* arr,int size)){

    int* resault_arr = (int*) malloc(size * sizeof(int));
    for(int i = 0 ; i < size ; i++)
        resault_arr[i] = Func(arr_2d[i] , row_size[i]);
    return  resault_arr;
}

int sumFunc(int* arr , int size){
    int result = 0 ;
    for(int i = 0 ; i < size ; i++)
        result += arr[i];
    return result;
}
int main(){

    int arr1[5] {1,2,4,5,7};
    int arr2[3] {2,5,8};
    int arr3[4] {9,8,7,5};
    int arr4[6] {2,3,4,5,6,7};

    int* arr2d[4]   {arr1,arr2,arr3,arr4};
    int row_size[4] {5,3,4,6};
    CallbackFunc LocalFunc = arr2D_Res;
    int* resault = LocalFunc(arr2d,4,row_size,sumFunc);

    for(int i = 0 ; i < 4 ; i++)
        cout << resault[i] << " " ;

    free(resault);

}