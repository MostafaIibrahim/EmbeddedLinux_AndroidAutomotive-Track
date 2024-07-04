#include <iostream>
#include<cstdlib>
using namespace std;
struct vector{
    int* p2s;
    int size;
    int capacity;
};
void initVect(vector& v1 , int size){
    //I should rmv * 2 
    v1.size = size ;
    v1.capacity = 0 ;
    v1.p2s =  (int*)malloc(size * sizeof(int) );
}
void pushVect(vector& v1 , int num){
    if(v1.capacity >= v1.size){
        v1.size *= 2;
        v1.p2s=(int*)realloc(v1.p2s,(v1.size*sizeof(int)));
    }
    v1.p2s[v1.capacity] = num;
    v1.capacity++;
}

void insertVect(vector& v1 , int loc,int num){
    // First we need to check if capacity > size
    if(v1.capacity > v1.size){
        // Then we need to reallocate a new space 
        v1.size *= 2 ;
        v1.p2s=(int*)realloc(v1.p2s,v1.size*sizeof(int));
    }
    for(int i = (v1.capacity + 1) ; i >= loc ; i--){
        if(i != loc){
            v1.p2s[i] = v1.p2s[i-1];
        }else{
            v1.p2s[i]= num ;
        }
    }
    //increment capacity
    v1.capacity++;
}

void deleteVect_Loc(vector v1 ,int loc){
    for(int i = loc ; i < v1.capacity ; i++){
        v1.p2s[i] = v1.p2s[i+1];
    }
    v1.capacity--;
}
void deleteVect(vector& v1){
    free(v1.p2s);
}

void printOutput(vector& v1){
    for(int i = 0 ; i < v1.capacity ; i++){
        cout << v1.p2s[i] << endl;
    }
}
void printinIndex(vector& v1 ,  int loc){
    cout << "Index number " << loc << " = " << v1.p2s[loc]<< endl;
}

int main(){
    vector  v1;
    initVect(v1,4);
    pushVect(v1,1);
    pushVect(v1,2);
    pushVect(v1,3);
    pushVect(v1,4);
    pushVect(v1,5);
    pushVect(v1,6);
    pushVect(v1,7);
    pushVect(v1,8);
    pushVect(v1,9);
    pushVect(v1,10);

    printOutput(v1);
    cout << "\n Let's try new trial" << endl;
    insertVect(v1,4,15);
    printOutput(v1);
    cout << "\n\n\n\n"<< endl;
    deleteVect_Loc(v1,4);
    printOutput(v1);
    deleteVect(v1);
}