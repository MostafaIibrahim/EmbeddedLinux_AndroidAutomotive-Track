#include<iostream>

using namespace std;
int main(){
    int input{} , result{};
    cout << "Please Enter Number: " ;
    while (true){
        cin >> input ;
        if(input == 0){
            cout << "The result: " << result << endl;
            break;
        }
        result += input;
        cout << "Please Enter a New Number: " ;
    }
    
}