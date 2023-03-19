#include <iostream>
using namespace std;

class Rect{
    int _x, _y;
    unsigned int _wd, _hd;
public:
    Rect( int x, int y, unsigned int wd, unsigned int hd ): _x(x), _y(y), _wd(wd), _hd(hd){};
    Rect(): _x(0), _y(0), _wd(1), _hd(1){};
    explicit Rect( unsigned int l ): _x(0), _y(0), _wd(l), _hd(l){};
    void print_corner() const;
    void print_sz() const;
    int area() const;
    int perimeter() const;
    bool intersect( Rect r ) const;
};

void Rect::print_corner() const{ cout << '(' << _x << ',' << _y << ')' << endl;}
void Rect::print_sz() const{ cout << "wd=" << _wd << " hd=" << _hd << endl;}
int Rect::area() const{ return (int) _wd * _hd;}
int Rect::perimeter() const{ return (int) 2 * _wd + 2 * _hd;}
bool Rect::intersect ( Rect r ) const{
    if ((long) (_x - r._x) > (long)r._wd)
        return false;
    if ((long) (r._x - _x) >  (long)_wd)
        return false;
    if ((long) (r._y - _y) >  (long)_hd)
        return false;
    if ((long) (_y - r._y) >  (r._hd))
        return false;
    return true;
}

int main() {

    Rect r1(-2, -3, 4, 5);
    Rect r2;
    Rect r3(7);
    r1.print_corner();
    r1.print_sz();

    int a2 = r2.area();
    int p2 = r2.perimeter();
    cout << a2 << " " << p2 << endl;

    if (r1.intersect(r3))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;

}
