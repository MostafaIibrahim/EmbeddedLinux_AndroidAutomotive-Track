#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
class Spinlock{
    std::atomic_flag flag;
    public:
        Spinlock():flag(ATOMIC_FLAG_INIT){

        }
        void lock(int threeshold = 20){
            int counter = 0 ;
            while(flag.test_and_set(std::memory_order_acquire)){
                if(++ counter >= threeshold){
                    std::this_thread::sleep_for(std::chrono::microseconds(20));
                    counter=0;
                }

            }   
        }
        void unlock(){
            flag.clear(std::memory_order_relaxed);
        }
};
std::atomic<int> shared_variable(1.0);

// Create a SpinLock instance
Spinlock spin_lock;
void multiply() {
    for (int i = 0; i < 10; ++i) { // Number of operations
        spin_lock.lock();
        shared_variable =shared_variable * 2;
        std::cout << "Multiplied: " << shared_variable.load() << std::endl;
        spin_lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }
}

void divide() {
    for (int i = 0; i < 10; ++i) { // Number of operations
        spin_lock.lock();
        shared_variable =shared_variable / 2;
        std::cout << "Divided: " << shared_variable.load() << std::endl;
        spin_lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }
}
int main(){
    // Create threads
    std::thread t1(multiply);
    std::thread t2(divide);

    // Start threads
    t1.join();
    t2.join();
}