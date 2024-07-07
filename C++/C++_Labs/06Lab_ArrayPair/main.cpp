#include<iostream>
#include<utility>
using Pair  = std::pair<int,int> ;
namespace ArrayPair{
     
    Pair* CreateArray(int size){
        Pair* ptr = new std::pair<int,int>[size];
        return ptr;
    }
    void deleteArray(Pair* ptr){
        delete[] ptr;
    }
    void setPair(Pair* ptr ,int index , int arg1 , int arg2){
        ptr[index] = {arg1,arg2};
    }
    Pair getPair(Pair* ptr , int index){
         return ptr[index];
    }
    void printArray(Pair* ptr , int size){
        for(int i = 0 ; i < size ; i++){
            std::cout << "ptr["<<i+1<<"].first= " << ptr[i].first 
                << "  " << "ptr["<<i<<"].second= " << ptr[i].second << std::endl;
        }
    }
}

int main(){
    Pair* ptr = ArrayPair::CreateArray(3);
    Pair val ;
    ArrayPair::setPair(ptr,0,2,3);
    ArrayPair::setPair(ptr,1,5,6);
    ArrayPair::setPair(ptr,2,8,9);
    std::cout << "Print array" << std::endl;
    ArrayPair::printArray(ptr,3);
    std::cout << "Print Get Array index" << std::endl;
    val = ArrayPair::getPair(ptr,2);
    std::cout << val.first << "    " << val.second << std::endl;

}