#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const double PI = 3.14159;

class Table {
public:
    virtual double area() = 0;
    virtual string type() = 0;
    virtual ~Table() {}
};

class RectTable : public Table {
    double length, width;
public:
    RectTable(double l, double w) 
{
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    string type(){
        return "矩形桌";
    }
};

class CircleTable : public Table {
    double r;
public:
    CircleTable(double r) {
        r = r;
    }

    double area() {
        return PI * r * r;
    }

    string type() {
        return "圆桌";
    }
};

class TriangleTable : public Table {
    double a, b, c;
public:
    TriangleTable(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double area() {
        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << "三边不能构成三角形" << endl;
            return 0;
        }
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    string type() {
        return "三角桌";
    }
};

int main() {
    int n;
    cout << "输入参数个数(1圆2矩3三角): ";
    cin >> n;

    Table* t = nullptr;

    if (n == 1) {
        double r;
        cout << "半径: ";
        cin >> r;
        t = new CircleTable(r);
    }
    else if (n == 2) {
        double l, w;
        cout << "长 宽: ";
        cin >> l >> w;
        t = new RectTable(l, w);
    }
    else if (n == 3) {
        double a, b, c;
        cout << "三边: ";
        cin >> a >> b >> c;
        t = new TriangleTable(a, b, c);
    }
    else {
        cout << "输入错误" << endl;
        return 1;
    }

    cout << "类型: " << t->type() << endl;
    cout << "面积: " << t->area() << endl;

    delete t;
    return 0;
}