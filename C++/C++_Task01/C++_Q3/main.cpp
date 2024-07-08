#include<iostream>
#include <string>
#include<cmath>
using namespace std;

void converBin2Num(string binary){
    int resault{} ;
    int length = binary.length();
    for(int i = 0 ; i < length ; i++){
        if(binary[length-i-1] == '1')
            resault += pow(2,i);
    }
    cout << binary << " = " << resault << endl;
}
void ConvertNum2Bin(int num){
    bool resault  ;
    for(int i = 0 ; i < 8 ; i++){
        resault = ( num >> (7 - i) & 1 ) ? 1 : 0 ;
        cout << resault;
    }
}
int main(){
    bool choice;
    string container;
    int num;
    cout << "Choose 0) Binary\n1)Number: " ;
    cin >> choice;

    cout << "Enter the Input: ";
    
    if(!choice){
        cin >> container;
        converBin2Num(container);
    }else{
        cin >> num ;
        ConvertNum2Bin(num);
    }


}