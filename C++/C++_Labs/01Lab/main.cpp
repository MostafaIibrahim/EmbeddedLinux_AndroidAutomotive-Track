#include<iostream>
#include <cstring>
using namespace std;

int main(){
    int size ;
     cout << "Enter Number of strings" << endl;
     cin >> size ;

    //  char ptr[size][30];
    char *ptr[size];
     cout << "Enter Names: " << endl;
    for (int i = 0 ; i < size ; i++){
        char * p=(char*) malloc(30);
        cin >> p;
        strcpy(ptr[i] , p);
        free(p);
    }     
    for(int i = 0 ; i < size ; i++){
        cout << *ptr[i] << endl;
    }
     
}
