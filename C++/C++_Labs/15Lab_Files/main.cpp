#include<iostream>
#include<iomanip>
#include<fstream>

int main(){
    std::fstream infile;
    std::fstream outfile;

    int max = 0 , min = 0 , avr = 0 , sum = 0 ;
    int i = 0 ; 
    std::string str;
    infile.open("input.txt",std::ios::in);
    if(infile.is_open()){
        getline(infile,str);
        min = max = stoi(str);
        infile.seekg(0,std::ios::beg);
    
        while(infile.eof() == false){
            getline(infile,str);
            sum += stoi(str);
            i++;
            if(min > stoi(str))
                min = stoi(str);
            if(max < stoi(str))
                max = stoi(str);
        }
    outfile.open("output.txt" , std::ios::out);
    outfile << std::setw(65) << std::setfill('-') << ""<< std::endl;
    outfile << "|" << std::setw(8) << std::setfill(' ') << std::right<<"sum" << std::setw(8) << "|"<<  std::setw(8) <<"max"<< std::setw(8) << "|"<<std::setw(8) <<"min" << std::setw(8) << "|" <<std::setw(8) << "Avr" << std::setw(8)<<"|"<<std::endl;   
    outfile << std::setw(65) << std::setfill('-') <<""<< std::endl;
    outfile << "|" << std::setw(8) << std::setfill(' ')<< sum << std::setw(8) << "|"<<  std::setw(8) <<  max << std::setw(8) << "|"<< std::setw(8) << min << std::setw(8) << "|"<<std::setw(10) << std::setprecision(2) << std::fixed << static_cast<float>(sum/i)<<std::setw(6)<<"|" <<std::endl;
    outfile << std::setw(65) << std::setfill('-') <<""<< std::endl;
    }else{
        std::cout << "Failed to open the file" << std::endl;
    }
}