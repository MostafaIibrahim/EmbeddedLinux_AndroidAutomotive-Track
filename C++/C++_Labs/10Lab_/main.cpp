#include<iostream>
#include<typeinfo>
enum TypeVar{
    int_t , 
    char_t ,
    double_t
};
struct Vpointer{
    void *ptr;
    TypeVar data;
};
class VPointerArray{
    Vpointer *ArrVoidPtr;
    int size;
    public:
        VPointerArray() = default;
        VPointerArray(int size){
            ArrVoidPtr = new Vpointer[size];
        }
        ~VPointerArray(){
            delete[] ArrVoidPtr;
        }
        void setVal(TypeVar type , void *ptr,int index){
            ArrVoidPtr[index].data = type;
            ArrVoidPtr[index].ptr = ptr;
        }
        void* getVal(int index){
            return ArrVoidPtr[index].ptr;
        }
};

int main(){

}