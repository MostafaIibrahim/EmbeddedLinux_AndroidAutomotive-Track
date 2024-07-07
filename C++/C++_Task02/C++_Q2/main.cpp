#include<iostream>

using namespace std;

int main(){
    int input , hr , min , sec , remainingSec;
    cout << "Input Seconds: ";
    cin >> input;

    hr =input / 3600;
    remainingSec = input % 3600;
    min = remainingSec / 60 ;
    sec = remainingSec % 60 ;
    cout << "H:M:S - "<<hr<<":"<<min<<":"<<sec;

}
