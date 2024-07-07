#include<iostream>
#include<math.h>
namespace MathFunctions{
    void PrintSquareRoot(int num){
        std::cout << "Square root of " << num << " = " << sqrt(num) << std::endl ;
    }

}
namespace StringFunctions{
    
    void PrintStringUpper(char* String){
        for(int i = 0 ; String[i] != '\0' ; i++ ){
            if(String[i] >= 'a' && String[i] <= 'z'){
                String[i] = (char)toupper(String[i]) ;
            }

        }
        for(int i = 0 ; String[i] != '\0';i++)
            std::cout << String[i] ;
    }
}
namespace ArrayFunctions{
    void PrintArrayReversed(int *arr , int size){
        for(int i = size-1 ; i >= 0 ; i--){
            std::cout << arr[i] ;
        }
    }   
}

int main(){
    int num = 25 ;
    char name[] = "mostafa";
    int arr[6] {1,2,3,4,5,6};
    MathFunctions::PrintSquareRoot(num);
    StringFunctions::PrintStringUpper(name);
    ArrayFunctions::PrintArrayReversed(arr,6);
}
