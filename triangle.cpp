

#include <windows.h>
#include "geometry.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
  
    // ----- ввод исходных данных -----
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты первой точки ===> ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки ===> ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей точки ==> ";
    cin >> x3 >> y3;

    // ----- создание точек - вершин треугольника -----
    Point A = Point(x1, y1),
        B = Point(x2, y2),
        C = Point(x3, y3);

    // ----- создание отрезков - сторон треугольника -----
    Segment Otrezok1 = Segment(A, B),
        Otrezok2 = Segment(B, C);

    // ----- создание точек - середин сторон треугольника -----
    Point S1 = Otrezok1.getMidpoint(),
        S2 = Otrezok2.getMidpoint();

    // ----- создание прямых, проходящих через стороны треугольника -----
    Line line1 = Line(A, B),
        line2 = Line(B, C),
        // ----- ... и серединных перепндикуляров к этим сторонам ... -----
        midperpendicular1 = line1.getPerpendicular(S1),
        midperpendicular2 = line2.getPerpendicular(S2);

    // ----- нахождение точки пересечения серединных перпендикуляров -----
    Point O = midperpendicular1.getIntersect(midperpendicular2);

    // ----- создание отрезка - радиуса -----
    Segment Radius = Segment(O, A);

    // ----- создание окружности с заданным центром и радиусом -----
    Circle circle = Circle(O, Radius.getLength());

    // ----- вывод результата -----
    cout << "Центр окружности расположен в точке ("
        << circle.getCenter().getX() << ',' << circle.getCenter().getY()
        << "), радиус = " << circle.getR() << endl;
   
    ///////////////////////////////////////////////////////////////////////////////////////////

    cout << "Введите координаты концов диагонали квадрата:\n";
    cout << "  x1 = ";
    cin >> x1;
    cout << "  y1 = ";
    cin >> y1;
    cout << "  x2 = ";
    cin >> x2;
    cout << "  y2 = ";
    cin >> y2;
    vector square(x1, y1, x2, y2);
    cout << "Длина диагонали = " << square.getLen();
    cout << "\nДлина стороны квадрата = " << square.getSide();
    cout << "\nРадиус Описанной окружности = " << square.getRadius();

    //Вывод в файл
    fstream BingChilling;
    BingChilling.open("temp.txt", ios::app);
    BingChilling << "Длина диагонали = " << square.getLen();
    BingChilling << "\nДлина стороны квадрата = " << square.getSide();
    BingChilling << "\nРадиус Описанной окружности = " << square.getRadius() << endl;
    BingChilling.close();
    return 0;
}

// ================= конец программы ===========================
