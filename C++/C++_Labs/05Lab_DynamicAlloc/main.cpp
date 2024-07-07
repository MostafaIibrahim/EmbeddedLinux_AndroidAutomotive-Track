#include<iostream>
namespace DynamicAlloc{
    int ** arr2D = nullptr;
    static int Cap = 0 ;
    void create2DArray(int col , int row){
        Cap = col;
        arr2D = new int*[col];
        for (int i = 0; i < row; i++) {
            arr2D[i] = new int;  
        }
    }
    void Insert2D( int col , int num){
        *arr2D[col]= num ;
    }
    void Print2D(){
        for(int i = 0 ; i < Cap ; i++){
            std::cout << *arr2D[i] << std::endl;
        }
    }
    void delete2DArray(){
        delete[] arr2D;
    }
}

int main(){
    DynamicAlloc::create2DArray(5,5);
    DynamicAlloc::Insert2D(0,6);
    DynamicAlloc::Insert2D(1,7);
    DynamicAlloc::Insert2D(2,8);
    DynamicAlloc::Insert2D(3,9);
    DynamicAlloc::Insert2D(4,10);
    DynamicAlloc::Print2D();
    DynamicAlloc::delete2DArray();

}