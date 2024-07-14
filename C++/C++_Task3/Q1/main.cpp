#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Vertex{
    int x ;
    int y ;
};

int main(){
    Vertex obj[5];
    
    int elapsedtime;
    for(int i = 0 ; i < 5 ; i++){
        obj[i].x = -100 + (rand()% 201);
        obj[i].y = -100 + (rand()% 201);
    }
        for(int i = 0 ; i < 5 ; i++){
        cout << obj[i].x << " " << obj[i].y << endl; 
    }

}