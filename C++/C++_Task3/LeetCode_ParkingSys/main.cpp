#include<iostream>

class ParkingSystem {
    int big ;
    int medium;
    int small;
    int big_count;
    int med_count;
    int small_count;
public:
    ParkingSystem(int big, int medium, int small):big(big),medium(medium),small(small) {
        big_count = 0 ;
        med_count = 0 ;
        small_count = 0;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1 : if(big_count < big){
                big_count++;
                return true;
            }
            break;
            case 2 : if(med_count < medium){
                med_count++;
                return true;
            }
            break;
            case 3 : if(small_count < small){
                small_count++;
                return true;
            }
            break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
int main(){
    ParkingSystem p(3,1,0);

    std::cout << p.addCar(1) << std::endl;
    std::cout << p.addCar(2) << std::endl;
    std::cout << p.addCar(3) << std::endl;
    std::cout << p.addCar(1) << std::endl;


}