#include <iostream>
#include <vector>

class Parser{
    char c;
    void S();
    void A();
    void gc(){std::cin.get(c);}
    std::vector<char> vec;
public:
    void analize();
};

void Parser::analize(){
    try{
        gc();
        S();
        for(auto it=vec.begin(); it!=vec.end(); ++it) std::cout << *it;
        std::cout << std::endl;
    }
    catch(char ex){
        std::cerr << "Error in: " << c; 
    }

}

void Parser::A(){
    if(c == 'a'){
        vec.insert(vec.begin(), '2');
        gc();
        A();
        vec.push_back('a');
    }
    else if(c == 'b'){
        gc();
        A();
        vec.push_back('b');
    }
    else if(c == '\n'){}
    else throw c;
}

void Parser::S(){
    if(c == 'a'){
        vec.insert(vec.begin(), '2');
        gc();
        A();
        vec.push_back('a');
    }
    else if(c == 'b'){
        gc();
        A();
        vec.push_back('b');
    }
    else throw c;
}


int main(){
    Parser A;
    A.analize();
    return 0;
}