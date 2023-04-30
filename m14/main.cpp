#include <iostream>
#include <cstring>
using namespace std;
#define N 20

char c;
int n;

void gc () {
    cin.get(c);
} // считать очередной символ из входной цепочки

bool scan_G ()
    {
    enum state {Space, S, O, D, DD, DDD, DDDD, DDDH, DDH, DDHH, DH, DHH, DHHH, H, HH, HHH, HHHH, HHHD, HHD, HHDD, HD, HDD, HDDD, ER};
    state CS; // CS —— текущее состояние
    CS = O;
    do{
        gc ();
        switch (CS){
            case O: if ( c == '.' ){
                        CS = D;
                    }
                    else if ( c == '-' ){
                        CS = H;
                    }
                    else{
                        CS = ER;
                    }
                    break;
            case D: if ( c == '.' ){
                        CS = DD;
                    }
                    else if( c == '-' )
                        CS = DH;
                    else{
                        CS = ER;
                    }
                    break;
            case H: if ( c =='.' ){
                        CS = HD;
                    }
                    else if ( c == '-' ){
                        CS = HH;
                    }
                    else
                        CS = ER;
                    break;
            case DD: if ( c =='.' ){
                        CS = DDD;
                    }
                    else if ( c == '-' ){
                        CS = DDH;
                    }
                    else{
                        CS = ER;
                    }
                    break;
            case DH:if ( c == '-' ){
                        CS = DHH;
                    }
                    else
                        CS = ER;
                    break;
            case HH: if ( c =='.' ){
                        CS = HHD;
                    }
                    else if ( c == '-' ){
                        CS = HHH;
                    }
                    else
                        CS = ER;
                    break;
            case HD: if ( c =='.' ){
                        CS = HDD;
                    }
                    else
                        CS = ER;
                    break;
            case DDD: if ( c =='.' ){
                        CS = DDDD;
                    }
                    else if ( c == '-' ){
                        CS = DDDH;
                    }
                    else
                        CS = ER;
                    break;
            case DDH: if ( c == '-' ){
                        CS = DDHH;
                    }
                    else
                        CS = ER;
                    break;
            case DHH: if ( c == '-' ){
                        CS = DHHH;
                    }
                    else
                        CS = ER;
                    break;
            case HHH: if ( c == '-' ){
                        CS = HHHH;
                    }
                    else if ( c == '.' ){
                        CS = HHHD;
                    }
                    else
                        CS = ER;
                    break;
            case HHD: if ( c == '.' ){
                        CS = HHDD;
                    }
                    else
                        CS = ER;
                    break;
            case HDD: if ( c == '.' ){
                        CS = HDDD;
                    }
                    else
                        CS = ER;
                    break;
            case DDDD: if ( c == '.' ){
                        n = 5;
                        CS = Space;
                    }
                    else if( c == '-' ){
                        n = 4;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case DDDH: if ( c == '-' ){
                        n = 3;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case DDHH: if ( c == '-' ){
                        n = 2;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case DHHH: if ( c == '-' ){
                        n = 1;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case HHHH: if ( c == '-' ){
                        n = 0;
                        CS = Space;
                    }
                    else if ( c == '.' ){
                        n = 9;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case HHHD: if ( c == '.' ){
                        n = 8;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case HHDD: if ( c == '.' ){
                        n = 7;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case HDDD: if ( c == '.' ){
                        n = 6;
                        CS = Space;
                    }
                    else
                        CS = ER;
                    break;
            case Space:
                if ((c != '\n') && (c != ' ')) CS = ER;
                else CS = S;
                break;
            case S:
                break;
            case ER: 
                break;
            }
    }
    while (CS != S && CS != ER);
    return CS == S; //true, если CS != ER, иначе false
}

void Analyzer(){
    int arr[20];
    int size = 0;
    while (c != '\n'){
        if(scan_G()){
            arr[size] = n;
            ++size;
        }
        else{
            cerr << "Error in Lexeme: " << c << endl;
            return;
        }
    }
    for (int i=0; i<size; ++i) cout << arr[i];
}


int main(){
    Analyzer();
    return 0;
}