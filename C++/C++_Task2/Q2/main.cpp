#include<iostream>
#include<cmath>

class Calculator{
    int add(int arg1 , int arg2){
        return arg1 + arg2;
    }
    int sub(int arg1 , int arg2){
        return arg1>arg2 ? arg1 - arg2 : arg2-arg1;
    }
    int mul(int arg1 , int arg2){
        return arg1 * arg2;
    }
    int power(int arg1 , int power){
        return std::pow(arg1,power);
    }
    double div(int arg1,int arg2){
        return static_cast<double>(arg1 / arg2);
    }
    double sqr(int num){
        return std::sqrt(num);
    }
    public:
    Calculator() = default;
    ~Calculator() = default;
    void mathOp(int arg1 , int arg2 , char type){
        double res;
        switch(type){
            case '+': res = add(arg1,arg2); break;
            case '-': res = sub(arg1,arg2); break;
            case '*': res = mul(arg1,arg2); break;
            case '/': res = div(arg1,arg2); break;
            case 'S': res = sqr(arg1);break;
            case '^': res=power(arg1,arg2);break;
        }
        std::cout << "Result of " << type <<" = " << res << std::endl;
    }
};

int main(){
    Calculator obj;
    obj.mathOp(20, 25, '*');
    obj.mathOp(20, 5, '/');
    obj.mathOp(20, 2, '^');
    obj.mathOp(25, 0, 'S');}