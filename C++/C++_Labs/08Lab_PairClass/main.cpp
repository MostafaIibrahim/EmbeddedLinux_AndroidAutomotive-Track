#include<iostream>
class Pair{
    int first_arg;
    int second_arg;
    public:
    Pair()=default;
    Pair(int arg1 , int arg2):first_arg(arg1),second_arg(arg2){

    }
    ~Pair() = default;
    void setFirst(int arg1){
        first_arg = arg1;
    }
    void setSecond(int arg2){
        second_arg = arg2;
    }
    void setPair(int arg1 , int arg2){
        first_arg = arg1;
        second_arg = arg2;
    }
    int getFirst(){
        return first_arg;
    }
    int getSecond(){
        return second_arg;
    }
    void printPair(){
        std::cout << "First arg: " << first_arg<<"\n"
                 << "Second arg: " << second_arg<<std::endl;
    }
    void swap(){
        first_arg +=  second_arg ;
        second_arg = first_arg - second_arg ;
        first_arg = first_arg - second_arg ;
    }
};

int main(){
    Pair pi(2 , 200);
    std::cout << "First argument: " << pi.getFirst() << std::endl;
    std::cout << "Second argument: " << pi.getSecond() << std::endl;

    pi.setFirst(30);
    std::cout << "Print the fitst arg: " << pi.getFirst() << std::endl;

    pi.swap();
    pi.printPair();

    


}