#include<iostream>


int main(){
    std::string text = "The cycle of life is a cycle of cycles";
    int position_cyc = text.find("cycle");

    while(position_cyc != std::string::npos){
        text.replace(position_cyc , 5 , "circle");
        position_cyc = text.find("cycle");
    }
    std::cout << text << std::endl;

    std::string word = "circle";
    int first_pos = text.find("circle") ;
    text.insert((first_pos-1)," great");
    std::cout << text << std::endl;

    int first = text.find("circle",first_pos+word.length());
    int second= text.find("circle" , first+word.length());

    std::cout << text.insert(second,"never_ending ") << std::endl;


}