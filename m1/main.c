#include <iostream>
#include <cmath>
using namespace std;

char* right(char* str, int N){
    int i;
    for( i = 0; i<= 100; i++ ) if ( str[i] == '\0' ) break;
    if ( str[i] != '\0' ) return NULL;
    i -= N;
    if ( i < 0 ) i = 0;
    return &(str[i]);
}

unsigned long right(unsigned long num, int N){
    if ( N > (int) (3*sizeof(unsigned long)) ) return num;
    return num % (unsigned long)pow(10,N);
}

int main() {

    unsigned long k;
    int N;
    char str[101];
    string s;
    cin >> s;
    if ( s == "string" ){
        cin.getline( str, 100, '\n' );
        cin.getline( str, 100, '\n' );
        cin >> N;
        if ( N < 0 ) {
            cout << 0 << endl;
            return 0;
        }
        cout << right( str, N ) << endl;
    }
    else if ( s == "number" ){
        cin >> k;
        cin >> N;
        if ( N < 0 ) {
            cout << 0 << endl;
            return 0;
        }
        cout << right( k, N ) << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
