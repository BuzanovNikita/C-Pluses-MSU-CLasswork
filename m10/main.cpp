#include <iostream>
#include <cmath>

using namespace std;

struct Ex{
    string s;
    int len1, len2;
};

template <typename T>
class Vec{
    T *_v;
    int _len;
public:
    Vec( int len, T* v );
    Vec( int len );
    Vec( const Vec& ref_v );
    ~Vec(){
        delete []_v;
    }

    void set( T arg, int coord );
    T get(int coord)const;
    T* get_v()const{return _v;};
    T euc_norm()const;
    T max_norm()const;
    void print()const;
    int len()const{return _len;}

    const Vec operator+(const Vec& another)const;
    const Vec operator-(const Vec& anothet)const;
    Vec& operator=(const Vec& another);
    const Vec operator*(T a)const;
    bool operator==(const Vec& another)const;
    T operator[](int i)const;
    T& operator[](int i);
    const Vec operator+=(const Vec& another);
};

//Operators
template <typename T>
std::ostream& operator<<(ostream& os, const Vec<T>& vec){
    if (vec.len() < 0) throw "Exception: unknown error";
    os << '(' << vec.get(0) ;
    for( int i = 1; i < vec.len(); i++ ) os << ',' << vec.get(i);
    os << ')';
    return os;
}
template <typename T>
const Vec<T> operator*(T a, const Vec<T>& vec){
    if (vec.len() < 0) throw "Exception: unknown error";
    return vec * a;
}
template <typename T>
T Vec<T>::operator[](int i)const{
    if ((this->_v == nullptr) || (this->_len < 0)) throw "Exception: unknown error";
    Ex e = {"Exception: incorrect indexing: ", i, -1};
    if ((i < 0) || (i >= this->_len)) throw e;
    return (_v[i]);
}
template <typename T>
T& Vec<T>::operator[](int i){
    if ((this->_v == nullptr) || (this->_len < 0)) throw "Exception: unknown error";
    Ex e = {"Exception: incorrect indexing: ", i, -1};
    if ((i < 0) || (i >= this->_len)) throw e;
    return (_v[i]);
}
template <typename T>
bool Vec<T>::operator==(const Vec<T>& another)const{
    if ((this->_v == nullptr) || (another._v == nullptr)) throw "Exception: unknown error";
    if ((another._len < 0) || (this->_len < 0)) throw "Exception: unknown error";
    if (_len != another._len) return false;
    for(int i=0; i<_len; i++) if (_v[i] != another._v[i]) return false;
    return true;
}
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& another){
    if (this == &another) return *this;
    if ((another._v == nullptr) || (another._len < 0)) throw "Exception: unknown error";
    if (_len) delete []_v;
    _len = another._len;
    _v = new T[another._len];
    for(int i=0; i<_len; i++) _v[i]=another._v[i];
    return *this;
}
template <typename T>
const Vec<T> Vec<T>::operator*(T a)const{
    if ((this->_v == nullptr) || (this->_len < 0)) throw "Exception: unknown error";
    Vec res(this->_len);
    for(int i=0; i<_len; i++) res._v[i] = a * this->_v[i];
    return res;
}
template <typename T>
const Vec<T> Vec<T>::operator-(const Vec<T>& another)const{
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
template <typename T>
const Vec<T> Vec<T>::operator+(const Vec<T>& another)const{
    if ((this->_v == nullptr) || (another._v == nullptr)) throw "Exception: unknown error";
    if ((another._len < 0) || (this->_len < 0)) throw "Exception: unknown error";
    if (this->_len != another._len){
        Ex e = {"Exception: addition of vectors of different lengths: ", this->_len, another._len};
        throw e;
    }
    Vec sum(this->_len);
    for(int i=0; i<_len; i++){
        sum._v[i] = this->_v[i] + another._v[i];
    }
    return sum;
}
template <typename T>
T operator^(const Vec<T>& first, const Vec<T>& second){
    if ((first.get_v() == nullptr) || (second.get_v() == nullptr)) throw "Exception: unknown error";
    if ((first.len() < 0) || (second.len() < 0)) throw "Exception: unknown error";
    if (first.len() != second.len()){
        Ex e = {"Exception: multiplication of vectors of different lengths: ", first.len(), second.len()};
        throw e;
    }
    T res=0;
    for(int i=0; i<first.len(); ++i) res += first.get_v()[i] * second.get_v()[i];
    return res;
}
template <typename T>
const Vec<T> Vec<T>::operator+=(const Vec<T>& another){
    *this = *this + another;
    return *this; 
}

//Constructors
template <typename T>
Vec<T>::Vec( int len, T* v ){
    if (len < 0) throw "Exception: length error";
    if (v == nullptr) throw "Exception: unknown error";
    _len = len;
    this -> _v = new T[len];
    for ( int i = 0; i < _len; i++ ){
        (this -> _v)[i] = v[i];
    }
}
template <typename T>
Vec<T>::Vec( int len ){
    if (len < 0) throw "Exception: length error";
    _len = len;
    _v = new T[_len];
    for( int i = 0; i < _len; i++ ) _v[i] = 0;
}
template <typename T>
Vec<T>::Vec( const Vec<T>& ref_v ){
    if (ref_v._len < 0) throw "Exception: length error";
    if (ref_v._v == nullptr) throw "Exception: unknown error";
    _v = new T[ref_v._len];
    _len = ref_v._len;
    for( int i = 0; i < _len; i++ ){
        _v[i] = ref_v._v[i];
    }
}

//Functions
template <typename T>
void Vec<T>::set( T arg, int coord ){
    if ( (coord < 0) || (coord >= _len) ) throw "Exception: coordinate error in set()";
    if (_v == nullptr) throw "Exception: unknown error";
    else _v[coord] = arg;
}
template <typename T>
T Vec<T>::get(int coord)const{
    if ( (coord < 0) || (coord >= _len) ) throw "Exception: coordinate error in get()";
    if (_v == nullptr) throw "Exception: unknown error";
    else return _v[coord];
}
template <typename T>
T Vec<T>::euc_norm()const{
    if (_len < 0) throw "Exception: length error";
    if (_v == nullptr) throw "Exception: unknown error";
    T res = 0;
    for ( int i = 0; i < _len; i++ ) res = res + (_v[i] * _v[i]);
    return sqrt(res);
}
template <typename T>
T Vec<T>::max_norm()const{
    if (_len < 0) throw "Exception: length error";
    if (_v == nullptr) throw "Exception: unknown error";
    T res = abs(_v[0]);
    for ( int i = 1; i < _len; i++ ) res = max( res, abs(_v[i]) );
    return res;
}
template <typename T>
void Vec<T>::print()const{
    if (_v == nullptr) throw "Exception: unknown error";
    if ( _len > 0 ){
        cout << '(' << _v[0] ;
        for( int i = 1; i < _len; i++ ) cout << ',' << _v[i];
        cout << ')' << endl;
    }
}

int main(void)
{
    try{
        Vector();

        /*int w1[4] = {1,2,3};
        int w2[3] = {2,3,1};

        Vec <int> v1(3, w1), v2(3, w2), v3(4);
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;
        v1 = (v3 += v2);
        std::cout << "v3 = " << v3 << std::endl;
        std::cout << "v1 = " << v1 << std::endl;
        int pr = v1^v2;
        std::cout << "v1^v2 = " << pr << std::endl;
        v1[1] = 7;
        std::cout << "v[1] = " << v1[1] << std::endl;*/

    } catch(const char* ex){
        cerr << ex << endl;
    }
    catch(const Ex& ex){
        cerr << ex.s << ex.len1;
        if (ex.len2 >= 0) cerr << ' ' << ex.len2;
        cout << endl;
    }
    catch(...){
        cerr << "Exception: unknown error\n";
    }
    return 0;
}