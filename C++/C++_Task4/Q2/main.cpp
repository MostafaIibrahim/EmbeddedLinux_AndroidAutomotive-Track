#include"account.hpp"
#include<iostream>

int main(){

    Account acc(2500) ;
    Account acc1(3332500) ;
    Account acc2(522500) ;

    std::cout << acc.checkAmount() << std::endl;

    acc1.displayStatus();

}