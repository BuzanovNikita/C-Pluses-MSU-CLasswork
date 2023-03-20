#include <iostream>
#include <cmath>

using namespace std;

struct Ex{
    string s;
    int len1, len2;
};

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
    double get(int coord)const;
    double euc_norm()const;
    double max_norm()const;
    void print()const;
    int len()const{return _len;}

    const Vec operator+(const Vec& another)const;
    const Vec operator-(const Vec& anothet)const;
    Vec& operator=(const Vec& another);
    const Vec operator*(double a)const;
    bool operator==(const Vec& another)const;
    double& operator[](int i)const;
};

std::ostream& operator<<(ostream& os, const Vec& vec){
    if (vec.len() < 0) throw "Exception: unknown error";
    os << '(' << vec.get(0) ;
    for( int i = 1; i < vec.len(); i++ ) os << ',' << vec.get(i);
    os << ')';
    return os;
}
const Vec operator*(double a, const Vec& vec){
    if (vec.len() < 0) throw "Exception: unknown error";
    return vec * a;
}
double& Vec::operator[](int i)const{
    if ((this->_v == nullptr) || (this->_len < 0)) throw "Exception: unknown error";
    Ex e = {"Exception: incorrect indexing: ", i, -1};
    if ((i < 0) || (i >= this->_len)) throw e;
    return (_v[i]);
}
bool Vec::operator==(const Vec& another)const{
    if ((this->_v == nullptr) || (another._v == nullptr)) throw "Exception: unknown error";
    if ((another._len < 0) || (this->_len < 0)) throw "Exception: unknown error";
    if (_len != another._len) return false;
    for(int i=0; i<_len; i++) if (_v[i] != another._v[i]) return false;
    return true;
}
Vec& Vec::operator=(const Vec& another){
    if (this == &another) return *this;
    if ((another._v == nullptr) || (another._len < 0)) throw "Exception: unknown error";
    if (_len) delete []_v;
    _len = another._len;
    _v = new double[another._len];
    for(int i=0; i<_len; i++) _v[i]=another._v[i];
    return *this;
}
const Vec Vec::operator*(double a)const{
    if ((this->_v == nullptr) || (this->_len < 0)) throw "Exception: unknown error";
    Vec res(this->_len);
    for(int i=0; i<_len; i++) res._v[i] = a * this->_v[i];
    return res;
}
const Vec Vec::operator-(const Vec& another)const{
    if ((this->_v == nullptr) || (another._v == nullptr)) throw "Exception: unknown error";
    if ((another._len < 0) || (this->_len < 0)) throw "Exception: unknown error";
    char str[] = "Exception: addition of vectors of different lengths: ";
    Ex e = {str, this->_len, another._len};
    if (this->_len != another._len) throw &e;
    Vec sum(this->_len);
    for(int i=0; i<_len; i++){
        sum._v[i] = this->_v[i] - another._v[i];
    }
    return sum;
}
const Vec Vec::operator+(const Vec& another)const{
    if ((this->_v == nullptr) || (another._v == nullptr)) throw "Exception: unknown error";
    if ((another._len < 0) || (this->_len < 0)) throw "Exception: unknown error";
    Ex e = {"Exception: addition of vectors of different lengths: ", this->_len, another._len};
    if (this->_len != another._len) throw e;
    Vec sum(this->_len);
    for(int i=0; i<_len; i++){
        sum._v[i] = this->_v[i] + another._v[i];
    }
    return sum;
}
Vec::Vec( int len, double* v ){
    if (len < 0) throw "Exception: length error";
    if (v == nullptr) throw "Exception: unknown error";
    _len = len;
    this -> _v = new double[len];
    for ( int i = 0; i < _len; i++ ){
        (this -> _v)[i] = v[i];
    }
}
Vec::Vec( int len ){
    if (len < 0) throw "Exception: length error";
    _len = len;
    _v = new double[_len];
    for( int i = 0; i < _len; i++ ) _v[i] = 0;
}
Vec::Vec( const Vec& ref_v ){
    if (ref_v._len < 0) throw "Exception: length error";
    if (ref_v._v == nullptr) throw "Exception: unknown error";
    _v = new double[ref_v._len];
    _len = ref_v._len;
    for( int i = 0; i < _len; i++ ){
        _v[i] = ref_v._v[i];
    }
}
void Vec::set( double arg, int coord ){
    if ( (coord < 0) || (coord >= _len) ) throw "Exception: coordinate error in set()";
    if (_v == nullptr) throw "Exception: unknown error";
    else _v[coord] = arg;
}
double Vec::get(int coord)const{
    if ( (coord < 0) || (coord >= _len) ) throw "Exception: coordinate error in get()";
    if (_v == nullptr) throw "Exception: unknown error";
    else return _v[coord];
}
double Vec::euc_norm()const{
    if (_len < 0) throw "Exception: length error";
    if (_v == nullptr) throw "Exception: unknown error";
    double res = 0;
    for ( int i = 0; i < _len; i++ ) res = res + (_v[i] * _v[i]);
    return sqrt(res);
}
double Vec::max_norm()const{
    if (_len < 0) throw "Exception: length error";
    if (_v == nullptr) throw "Exception: unknown error";
    double res = abs(_v[0]);
    for ( int i = 1; i < _len; i++ ) res = max( res, abs(_v[i]) );
    return res;
}
void Vec::print()const{
    if (_v == nullptr) throw "Exception: unknown error";
    if ( _len > 0 ){
        cout << '(' << _v[0] ;
        for( int i = 1; i < _len; i++ ) cout << ',' << _v[i];
        cout << ')' << endl;
    }
}

/*int main(void)
{
    try{
        //error();
        double y1[4] = {1,2,3,4};
        double y2[4] = {-2,1,3,-3};

        Vec u(4, y1), v(4, y2);
        Vec w(4);

        cout << "u = " << u << endl;
        cout << "v = " << v << endl;
        w = u = u;
        cout << "w = u = " << w << endl;
        w = 4.*u + v*3;
        cout << "w = 4.*u + v*3 = " << w << endl;
        w[2] = 3;
        w[0] = -1;
        cout << "w = " << w << endl;
    } catch(const char* ex){
        //cout << "string ex\n";
        cerr << ex << endl;
    }
    catch(const Ex& ex){
        //cout << "struct ex\n";
        cerr << ex.s << ex.len1;
        if (ex.len2 >= 0) cerr << ' ' << ex.len2;
        cout << endl;
    }
    catch(...){
        cerr << "Exception: unknown error\n";
    }
    return 0;
}*/