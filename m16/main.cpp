#include <iostream>
#include <vector>

class Parser{
    char c;
    void S();
    void A();
    void gc(){std::cin.get(c);}
    int cnt;
    std::vector<char> vec;
public:
    void analize();
};

void Parser::analize(){
    try{
        cnt = 0;
        gc();
        S();
        for(int i=0; i<cnt; ++i) std::cout << '2';
        for(auto it=vec.begin(); it!=vec.end(); ++it) std::cout << *it;
        std::cout << std::endl;
    }
    catch(char ex){
        std::cerr << "Error in: " << c; 
    }

}

void Parser::A(){
    if(c == 'a'){
        ++cnt;
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
        ++cnt;
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