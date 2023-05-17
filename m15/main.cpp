#include <iostream>

class Parcer{
private:
    static char c;
    static void gc(){std::cin.get(c);}
    static void S();
    static void A();
    static void B();
public:
    static bool analyze();
};
char Parcer::c = 'p';
void Parcer::S(){
    if(c == 'a'){
        gc();
        A();
        B();
    }
    else if(c == 'b'){
        gc();
        B();
    }
    else throw c;
}

void Parcer::A(){
    if(c == 'a'){
        gc();
        A();
    }
    else if (c == 'b'){
        gc();
        return;
    }
    else throw c;
}

void Parcer::B(){
    if(c == 'b'){
        gc();
        B();
    }
    else if(c == '\n') return;
    else throw c;
}

bool Parcer::analyze(){
    try {gc(); S();}
    catch(...){
        return false;
    }
    return c == '\n';
}


int main(){
    if(Parcer::analyze()) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}