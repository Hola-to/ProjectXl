

#include <windows.h>
#include "geometry.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
  
    // ----- ���� �������� ������ -----
    double x1, y1, x2, y2, x3, y3;
    cout << "������� ���������� ������ ����� ===> ";
    cin >> x1 >> y1;
    cout << "������� ���������� ������ ����� ===> ";
    cin >> x2 >> y2;
    cout << "������� ���������� ������� ����� ==> ";
    cin >> x3 >> y3;

    // ----- �������� ����� - ������ ������������ -----
    Point A = Point(x1, y1),
        B = Point(x2, y2),
        C = Point(x3, y3);

    // ----- �������� �������� - ������ ������������ -----
    Segment Otrezok1 = Segment(A, B),
        Otrezok2 = Segment(B, C);

    // ----- �������� ����� - ������� ������ ������������ -----
    Point S1 = Otrezok1.getMidpoint(),
        S2 = Otrezok2.getMidpoint();

    // ----- �������� ������, ���������� ����� ������� ������������ -----
    Line line1 = Line(A, B),
        line2 = Line(B, C),
        // ----- ... � ���������� ��������������� � ���� �������� ... -----
        midperpendicular1 = line1.getPerpendicular(S1),
        midperpendicular2 = line2.getPerpendicular(S2);

    // ----- ���������� ����� ����������� ���������� ��������������� -----
    Point O = midperpendicular1.getIntersect(midperpendicular2);

    // ----- �������� ������� - ������� -----
    Segment Radius = Segment(O, A);

    // ----- �������� ���������� � �������� ������� � �������� -----
    Circle circle = Circle(O, Radius.getLength());

    // ----- ����� ���������� -----
    cout << "����� ���������� ���������� � ����� ("
        << circle.getCenter().getX() << ',' << circle.getCenter().getY()
        << "), ������ = " << circle.getR() << endl;
   
    ///////////////////////////////////////////////////////////////////////////////////////////

    cout << "������� ���������� ������ ��������� ��������:\n";
    cout << "  x1 = ";
    cin >> x1;
    cout << "  y1 = ";
    cin >> y1;
    cout << "  x2 = ";
    cin >> x2;
    cout << "  y2 = ";
    cin >> y2;
    vector square(x1, y1, x2, y2);
    cout << "����� ��������� = " << square.getLen();
    cout << "\n����� ������� �������� = " << square.getSide();
    cout << "\n������ ��������� ���������� = " << square.getRadius();

    //����� � ����
    fstream BingChilling;
    BingChilling.open("temp.txt", ios::app);
    BingChilling << "����� ��������� = " << square.getLen();
    BingChilling << "\n����� ������� �������� = " << square.getSide();
    BingChilling << "\n������ ��������� ���������� = " << square.getRadius() << endl;
    BingChilling.close();
    return 0;
}

// ================= ����� ��������� ===========================
