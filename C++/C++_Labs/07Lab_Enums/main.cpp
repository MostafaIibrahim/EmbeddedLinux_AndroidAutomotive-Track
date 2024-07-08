#include<iostream>

enum class ErrorCode{
    Bad_Request = 400,
    Not_Found = 404,
    Server_Error = 500,
    Gateway_Timeout = 504
};
void PrintError(int  ErrorNum){
    ErrorCode msg;
    switch (ErrorNum)
    {
    case static_cast<int> (ErrorCode::Bad_Request):
        std::cout << "400 Bad Request" << std::endl;break;
    case static_cast<int> (ErrorCode::Not_Found):
        std::cout << "404 Not Found" << std::endl;break;
    case static_cast<int> (ErrorCode::Server_Error):
        std::cout << "500 Server Error" << std::endl;break;
    case static_cast<int> (ErrorCode::Gateway_Timeout):
        std::cout << "504 GatewayTimeout" << std::endl;break;
    default:
        std::cout<< "Something Went Wrong" << std::endl;
    }
}
int main(){
    int ErrorNum;
    std::cout << "Enter Error Number: ";
    std::cin >>ErrorNum;
    PrintError(ErrorNum);

}