#include<iostream>
template <typename T>

class Pair{

    T first_arg;
    T second_arg;

    public:
    Pair()=default;
    Pair(T arg1 , T arg2):first_arg(arg1),second_arg(arg2){

    }
    ~Pair() = default;
    void setFirst(T arg1){
        first_arg = arg1;
    }

    void setSecond(T arg2){
        second_arg = arg2;
    }
    void setPair(T arg1 , T arg2){
        first_arg = arg1;
        second_arg = arg2;
    }
    T getFirst(){
        return first_arg;
    }
    T getSecond(){
        return second_arg;
    }
    void prTPair(){
        std::cout << "First arg: " << first_arg<<"\n"
                 << "Second arg: " << second_arg<<std::endl;
    }
    void swap(){
        T temp;
        temp = first_arg;
        first_arg = second_arg;
        second_arg = temp;
        }
};

int main(){
    Pair<std::string>pi("Ahmed" , "Mostafa");
    std::cout << "First argument: " << pi.getFirst() << std::endl;
    std::cout << "Second argument: " << pi.getSecond() << std::endl;

    pi.setFirst("El Sayed");
    std::cout << "PrT the fitst arg: " << pi.getFirst() << std::endl;

    pi.swap();
    pi.prTPair();
}