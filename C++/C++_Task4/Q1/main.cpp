#include <iostream>

template <typename T>
class DynamicArray{
    T *arrvec;
    T capVec;
    T currentSize;

        /*resize the array to double the size*/
    void resize(){
        currentSize *= 2 ;
        T *Newarrvec = new T[currentSize];
        for(T i = 0 ; i < capVec ; i++)
            Newarrvec[i] = arrvec[i];
        delete arrvec;
        arrvec = Newarrvec;
    }
    public:

    DynamicArray():currentSize{0},capVec{0}{
        arrvec = new T[capVec];
    }
    /*constructor with given capacity*/
    DynamicArray(T size):capVec{size} , currentSize{size}{
        arrvec = new T[capVec];
    }
    /*constructor with given capacity and initial value for all elements --> DynamicArray arr(5, 10);*/
    DynamicArray(T size , T value):capVec{size},currentSize{size}{
        arrvec = new T [capVec];
        for (T i = 0 ; i < size ; i++)
            arrvec[i] = value;
    }
    /*constructor with given capacity and initial values --> DynamicArray arr(5, new T[5]{1, 2, 3, 4, 5});*/
    DynamicArray(T size , T* values):capVec{size},currentSize{size}{
        arrvec = new T[capVec];
        for (T i = 0 ; i < size ; i++)
            arrvec[i] = values[i];
    }
    /*copy constructor*/
    DynamicArray(const DynamicArray& arr):capVec{arr.capVec},currentSize{arr.currentSize}{
        arrvec = new T[capVec] ; 
        for(T i = 0 ; i < capVec ; i++){
            arrvec[i] = arr.arrvec[i];
        }
    }
    ~DynamicArray(){
        delete arrvec;
    }

    /*- add the value to the end of the array*/
    void pushBack(T val){
        if(capVec >= currentSize){
            resize();
        }
        arrvec[capVec++] = val;
    }
    /*- remove the last element from the array*/
    T popBack(){
        T result = arrvec[--capVec];
        return result;
    }
    /*- remove the element at the given index*/
    T removeAt(T index){
        T result = arrvec[index];
        for(T i = index ; i < capVec ; i++)
            arrvec[i] = arrvec[i+1];
        capVec--;
        return result ;
    }
    /*- insert the value at the given index and shift the elements to the right*/
    void insertAt(T index,T value){
        if(capVec >= currentSize){
            resize();
        }
        for (T i = capVec+1 ; i >= index ; i--){
            if(i != index)
                arrvec[i] = arrvec[i-1];
            else
                arrvec[i] = value;
        }
        capVec++;
    }
    /*- insert the value in the middle of the array*/
    void insertMiddle(T value){
        T middle = capVec/2;
        insertAt(middle , value);
    }
    /*- remove the middle element from the array * size()*/
    void removeMiddle() {
        T middle = capVec/2;
        removeAt(middle);
    }
    /* - return the size of the array*/
    T getSize(){
        return capVec;
    }
    /*- prT the array*/
    void print(void){
        for(T i = 0 ; i < capVec ; i++)
            std::cout << arrvec[i]<<" ";
        std::cout << " " << std::endl;
    }
};



int main (){
   /* DynamicArray arr;
    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);
    arr.pushBack(40);
    arr.print();
    std::cout << "PoP Value = " << arr.popBack() << std::endl;
    arr.print();
    arr.insertAt(2,60);
    arr.print();
    std::cout << "Size = " <<  arr.getSize() << std::endl;
    std::cout << "rmv at = " <<  arr.removeAt(2)<< std::endl;
    arr.prT();*/
    DynamicArray <int> arr1(5 , new int[5]{1,2,3,4,5});
    arr1.print();
    arr1.pushBack(10);
    arr1.insertAt(2,60);
    arr1.print();
}