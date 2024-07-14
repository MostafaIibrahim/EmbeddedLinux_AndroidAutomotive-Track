#include<iostream>
#include<vector>
using mvector = std::vector<std::vector<int>>;
//It should be generic so that u can enter 3*3 , 4*2 , 2*5 , 5*5
// s
mvector Swap_2DVec(mvector vec , int row_num , int col_num){ //3,2
    int row_index , col_index ; 
    mvector nvec(col_num,std::vector<int>(row_num)); //2,3

    for(row_index = 0 ; row_index < row_num ; row_index++){ //2

         for( col_index = 0 ; col_index < col_num ; col_index++ ){ //4
              nvec[col_index][row_index]  = vec[row_index][col_index];
             }
    }
    return nvec;
}
void print2D_vec(mvector vec){
    for(const auto &row:vec){
        for (const auto& elem:row){
            std::cout << elem << " " ;
        }
    std::cout << std::endl;
    }
}
int main(){
    // Enter the vector
    mvector v1 = { {1,2,3,10}, 
                   {4,5,6,11},
                   {7,8,9,12} }; 

    // mvector v1 = { {1,2},
    //                {3,4},
    //                {5,6}};       
    int row_num = static_cast<int>( v1.size());
    int col_num =  static_cast<int>(v1[0].size());
    // Call function that takes 2D_vec and return 2D_vec
    mvector result = Swap_2DVec(v1,row_num,col_num);

    // Call print function and send to it 2D_vec as a parameter
    print2D_vec(result);

    return 0;
    
}