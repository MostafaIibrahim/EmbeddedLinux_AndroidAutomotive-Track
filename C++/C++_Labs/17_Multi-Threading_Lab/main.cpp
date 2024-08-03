#include <iostream>
#include <thread>
#include <chrono> 

void BeepFunc(int duration){

    while(true){
    std::cout << '\a' << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    }
}
void StopFunc(){
    char action;
        while(true){
        action = std::cin.get() ;
        if(action == '\n')
        exit(0);
        }

}
int main(){

    std::thread beepThread{BeepFunc,3};
    std::thread stopThread{StopFunc};
    
    stopThread.join();
    beepThread.join();

}