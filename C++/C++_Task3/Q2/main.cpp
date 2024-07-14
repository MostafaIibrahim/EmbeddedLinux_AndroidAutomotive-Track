#include<iostream>
#include<cstdlib>
class Vertex{
    int x ;
    int y;
    public:
        Vertex() = default;
        ~Vertex() = default;
        void setVertex(int x , int y){
            this->x = x ;
            this->y = y;
        }
        int getYvertex(void){
            return y;
        }
        int getXvertex(void){
            return x ;
        }
        std::string getVertex(void){
            return std::to_string(x) + " " + std::to_string(y);
        }

};
int main(){
    Vertex p;
    std::string str; 
    p.setVertex((rand()%201),(rand()%201));
    std::cout << p.getVertex() << std::endl;
}