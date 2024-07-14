#include<iostream>
class Car{
    std::string company;
    std::string model;
    int year;
    public:
        Car()=default;
        Car(std::string company , std::string model , int year):company(company),model(model),year(year){

        }
        ~Car() = default;
        void setYear(int year){
            this->year = year;
        }
        int getYear(void){
            return year;
        }
        void setComp(std::string comp){
            company = comp;
        }
        std::string getComp(void){
            return company;
        }
        void setModel(std::string model){
            this->model = model;
        }
        std::string getModel(void){
            return model;
        }
        void printModel(void){
            std::cout << "Company car: " << company << "\n" 
                      << "Model: " << model << "\n"
                      << "Year: "<< year << std::endl;
        }

};
int main(){
    Car c2("BMW","X6",2020);

    c2.printModel();


}