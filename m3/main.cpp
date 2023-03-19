#include <iostream>
#include <cmath>

using namespace std;

class Vec{
    double *_v;
    int _len;
public:
    Vec( int len, double* v );
    Vec( int len );
    Vec( const Vec& ref_v );
    ~Vec(){
        delete []_v;
    }

    void set( double arg, int coord );
    double get(int coord);
    double euc_norm();
    double max_norm();
    void print();
};

Vec::Vec( int len, double* v ){
    _len = len;
    this -> _v = new double[len];
    for ( int i = 0; i < _len; i++ ){
        (this -> _v)[i] = v[i];
    }
}
Vec::Vec( int len ){
    _len = len;
    _v = new double[_len];
    for( int i = 0; i < _len; i++ ) _v[i] = 0;
}
Vec::Vec( const Vec& ref_v ){
    _v = new double[ref_v._len];
    _len = ref_v._len;
    for( int i = 0; i < _len; i++ ){
        _v[i] = ref_v._v[i];
    }
}
void Vec::set( double arg, int coord ){ if ( (coord >= 0) && (coord < _len) ) _v[coord] = arg; }
double Vec::get(int coord){ if ( (coord >= 0) && (coord < _len) ) return _v[coord]; else return 0; }
double Vec::euc_norm(){
    double res = 0;
    for ( int i = 0; i < _len; i++ ) res = res + (_v[i] * _v[i]);
    return sqrt(res);
}
double Vec::max_norm(){
    double res = abs(_v[0]);
    for ( int i = 1; i < _len; i++ ) res = max( res, abs(_v[i]) );
    return res;
}
void Vec::print(){
    if ( _len > 0 ){
        cout << '(' << _v[0] ;
        for( int i = 1; i < _len; i++ ) cout << ',' << _v[i];
        cout << ')' << endl;
    }
}

int main(void)
{
    double y1[3] = {1,2,3};
    double y2[5] = {2,1,0,5,7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;

    y.print();
    x.print();
    z.print();
    u.print();

    x.set(23, 2);  u.set(34, 1);  z.set(-3, 3);
    cout << "x[2] = " << x.get(0) << endl;
    cout << "u[1] = " << u.get(1) << endl;
    cout << "euc_norma y: " << y.euc_norm() << endl;
    cout << "max_norma z: " << z.max_norm() << endl;
    return 0;
}
