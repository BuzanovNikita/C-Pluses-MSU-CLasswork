#include <iostream>
#include <cstring>
using namespace std;
#define N 20

char c;
char* arr;
int i=0;

void gc () {
    cin.get(c);
    if(i > N-1){
        char* newarr = new char[N + i];
        memcpy(newarr, arr, i);
        delete[] arr;
        arr = newarr;
    }
    arr[i] = c;
    ++i;
} // считать очередной символ из входной цепочки

bool scan_G ()
    {
    enum state { H, B, AC, S, ER };
    state CS; // CS —— текущее состояние
    CS = H;
    do{
        gc ();
        switch (CS){
            case H: if ( c == 'a' ){
                        CS = AC;
                    }
                    else
                    CS = ER;
                    break;
            case B: if ( c == 'a' ){
                        CS = AC;
                    }
                    else if( c == '\n' )
                        CS = S;
                    else
                        CS = ER;
                    break;
            case AC: if ( c =='a' ){
                        CS = B;
                    }
                    else if ( c == 'd' ){
                        CS = AC;
                    }
                    else
                        CS = ER;
                    break;
            case S:
                if (c == '\n' ) CS = ER;
                break;
            case ER: break;
            }
    }
    while ( CS != S && CS != ER);
    return CS == S; // true, если CS != ER, иначе false
}

void Analyzer(){
    if(scan_G()){
        cout << arr;
    }
    else{
        cerr << "Error in Lexcem: " << c << endl;
    }
}


int main(){
    arr = new char[N];
    Analyzer();
    delete[] arr;
    return 0;
}