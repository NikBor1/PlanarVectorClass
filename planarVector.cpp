#include <iostream>
#include <cmath>

class PlanarVector
{
    int x, y;

public:

    PlanarVector(int a, int b);
    PlanarVector();

    int get_x(){return x;}
    int get_y(){return y;}

    void set_x (int a){x = a;}
    void set_y (int b){y = b;}

    PlanarVector operator+(PlanarVector);

    PlanarVector operator*(int);
    int operator*(PlanarVector);
    double operator^(PlanarVector);

    bool operator==(PlanarVector);
    bool operator!=(PlanarVector);

    friend std::ostream& operator<<(std::ostream&, const PlanarVector&);

    int getQuadraLen(PlanarVector pv){return pv.x * pv.x + pv.y * pv.y;}

    double getAngle(PlanarVector pv1, PlanarVector pv2){return asin((pv2.y / sqrt(pv2.x * pv2.x + pv2.y * pv2.y))) + asin((pv1.y / sqrt(pv1.x * pv1.x + pv1.y * pv1.y)));}
};

PlanarVector::PlanarVector(int a, int b)
{
    x = a;
    y = b;
}


PlanarVector::PlanarVector()
{
    x = 0;
    y = 0;
}

PlanarVector PlanarVector::operator+(PlanarVector pv)
{
    return PlanarVector(x + pv.x, y + pv.y);
}

PlanarVector PlanarVector::operator*(int n)
{
    return PlanarVector(x * n, y * n);
}

int PlanarVector::operator*(PlanarVector pv)
{
    return x * pv.x + y * pv.y;
}

double PlanarVector::operator^(PlanarVector pv)
{
    return sqrt(x * x + y * y) * (pv.y - y);
}

bool PlanarVector::operator==(PlanarVector pv)
{
    if(x == pv.x && y == pv.y)
        return true;
    else
        return false;
}

bool PlanarVector::operator!=(PlanarVector pv)
{
    if(x == pv.x && y == pv.y)
        return false;
    else
        return true;
}

std::ostream& operator<<(std::ostream& out, const PlanarVector& a)
{
    return out << "( " << a.x << "; " << a.y << " )";
}


int main()
{
    int x1, y1, x2, y2, n;

    std::cout << "Enter planar vectors and coefficient, please: ";

    std::cin >> x1 >>y1 >> x2 >> y2 >> n;

    PlanarVector pv1 (x1, y1);
    PlanarVector pv2 (x2, y2);

    double specMultiply = pv1 ^ pv2;

    bool eq, uneq;

    eq = (pv1 == pv2);
    uneq = (pv1 != pv2);

    PlanarVector obj(0, 0);

    std::cout << "pv1 + pv2 = " << pv1 + pv2 << std::endl;
    std::cout << "pv1 * pv2 = " << pv1 * pv2 << std::endl;
    std::cout << "pv1 ^ pv2 = " << specMultiply << std::endl;
    std::cout << "pv1 == pv2 = " << eq << std::endl;
    std::cout << "pv1 != pv2 = " << uneq << std::endl;
    std::cout << "pv1 * n = " << pv1 * n << std::endl;
    std::cout << "pv2's length square is  " << obj.getQuadraLen(pv2) << std::endl;
    std::cout << "The angle between pv1 and pv2 is " << obj.getAngle(pv1, pv2) << std::endl;


    return 0;
}
