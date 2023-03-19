class Vector_3d{
    double x, y, z;

public:
    Vector_3d( double a = 0, double b = 0, double c = 0 ): x(a), y(b), z(c) {};
    /*Vector_3d operator= ( double x ) {
        Vector_3d v( x, 0, 0 );
        return v;
    }*/

    void print(){ cout <<"(" << x << "," << y << "," << z << ")" << endl; }
    double euc_norm() { return sqrt( x*x + y*y + z*z ); }
    double max_norm() { return max( max( abs(x), abs(y) ), abs(z) ); }
    double get_x() { return x; }
    double get_y() { return y; }
    double get_z() { return z; }
    void set( double a, double b, double c ){ x = a, y = b, z = c; }
};
