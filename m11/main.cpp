#include<iostream>

class Flower{
    std::string color;
    size_t n;
    static size_t pink;
    static size_t white;
public:
    Flower(const std::string& color_, size_t n);
    static void Print_flowers(){
        std::cout << "White: " << white << " Pink: " << pink << std::endl;
    }
    ~Flower(){
        if(color == "white") --white;
        else --pink;
    }
};
size_t Flower::pink = 0;
size_t Flower::white = 0;

Flower::Flower(const std::string& color_="negr", size_t n=10){
    if(color_ == "pink"){
        color = color_;
        ++pink;
    }
    else if(color_ == "white"){
        color = color_;
        ++white;
    }
    else{
        if(pink > white){
            color = "white";
            ++white;
        }
        else if(pink < white){
            color = "pink";
            ++pink;
        }
        else{
            if(n % 2){
                color = "white";
                ++white;
            }
            else{
                color = "pink";
                ++pink;
            }
        }
    }

}


/*int main(){
Flower fl1("white", 3);
       Flower fl2("pink", 5);
       Flower fl3("white", 7);
       Flower::Print_flowers();
       Flower fl4("green");
       Flower::Print_flowers();
       Flower fl5("blue", 17);
       Flower::Print_flowers();
       Flower fl6;
       Flower::Print_flowers();
       Flower fl7;
       Flower::Print_flowers();
       return 0;
}*/