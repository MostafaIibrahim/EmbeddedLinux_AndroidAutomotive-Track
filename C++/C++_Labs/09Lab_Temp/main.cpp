#include<iostream>

template<typename T1,typename T2>

class KeyValuePair{
    T1 key;
    T2 value;
    public:
        KeyValuePair()=default;
        KeyValuePair(T1 key , T2 value){
            this->key = key ;
            this->value = value;
        }
        ~KeyValuePair() = default;
        void setKeyVal(T1 key , T2 Value){
            this->key = key;
            this->value = value;
        }
        T2 getValue(){
            return value;
        }
        T1 getKey(){
            return key;
        }
        void printPair(){
            std::cout << "value = " << value << "\n" << "key= " << key << std::endl;
        }

};
int main(){
    KeyValuePair<int, double> p1{0,12.5};
    std::cout << p1.getKey() << std::endl;
    std::cout << p1.getValue() << std::endl;
    std::cout << "--------------"<<std::endl;
    p1.printPair();
}
