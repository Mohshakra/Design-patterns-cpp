#include <iostream>
#include <string>
#include <memory>



class Istratgy{

    public :       
        virtual void algorithminterface(int a, int b) = 0 ;

};


class addition : public Istratgy{


    private :
        int a, b ;

    public :
        void algorithminterface(int a, int b){
            std::cout << a + b;
        }


};

class subtraction : public Istratgy{


    private :
        int a, b ;

    public :
        void algorithminterface(int a, int b){
            std::cout << a - b;
        }

};


class context{

    private :
       Istratgy *strategy;
   
    public :
        context( Istratgy * s) : strategy(s) {}

        void contextinterface(int a , int b){
            strategy->algorithminterface(a , b);
        } 

};


int main(){

    context con(new addition());
    con.contextinterface(12, 33);

    printf("\n");

    context co(new subtraction());
    co.contextinterface(12, 33);

    printf("\n");

   


    return 0 ;
}