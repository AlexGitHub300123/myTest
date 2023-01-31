#include "Curves.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846
//-------------------------------------------------------------------------
TPoint::TPoint()
    {
        x0 = rand() % 100 + 1; //random nullpoint x0
        y0 = rand() % 100 + 1; //random nullpoint y0
        z0 = 0.0;
    }
void TPoint::SetXYZT(double T)
    {
      t=T;
    }
void TPoint::PrintR()
    {
        //
    }
void TPoint::PrintNullPoint()
    {
        std::cout << "Xo: " << x0 << std::endl;
        std::cout << "Yo: " << y0 << std::endl;
        std::cout << "Zo: " << z0 << std::endl;
    }
void TPoint::PrintPoint()
    {
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
        std::cout << "Z: " << z << std::endl;
    }
TPoint::~TPoint(){}
//------------------------------------------------------------------------
TCircle::TCircle()
        {
            R = rand() % 10 + 1;
        }
double TCircle::GetR() { return R; }
void TCircle::SetXYZT(double T)
        {
            x = x0 + R*cos(T);
            y = y0 + R*sin(T);
            z = 0.0;
            dx = -R*sin(T);
            dy = R*cos(T);
            dz = z;
            t = T;
        }
void TCircle::PrintNullPoint()
        {
            std::cout << "Center of circle Xo: " << x0 << std::endl;
            std::cout << "Center of circle Yo: " << y0 << std::endl;
            std::cout << "Center of circle Zo: " << z0 << std::endl<< std::endl;
        }
void TCircle::PrintR()
        {
            std::cout << "Radius of circle: " << GetR() << std::endl<< std::endl;
        }
void TCircle::PrintPoint()
        {
            std::cout << "X = " << x << " <-- coordinate circle point for T (PI/4) = " << t << std::endl;
            std::cout << "Y = " << y << " <--coordinate circle point for T (PI/4) = " << t << std::endl;
            std::cout << "Z = " << z << " <--coordinate circle point for T (PI/4) = " << t << std::endl<< std::endl;
            std::cout << "dX = " << dx << " <--increment for 2nd point of vector of tangent to circle for T (PI/4) = " << t << std::endl;
            std::cout << "dY = " << dy << " <--increment for 2nd point of vector of tangent to circle for T (PI/4) = " << t << std::endl;
            std::cout << "dZ = " << dz << " <--increment for 2nd point of vector of tangent to circle for T (PI/4) = " << t << std::endl<< std::endl;
        }
//--------------------------------------------------------------------------------------------------
TEllipse::TEllipse()
        {
            R = rand() % 10 + 1;
            r = rand() % 10 + 1;
        }
double TEllipse::GetR() { return R; }
double TEllipse::Getr() { return r; }
void TEllipse::SetXYZT(double T)
        {
            x = x0 + R*cos(T);
            y = y0 + r*sin(T);
            z = 0.0;
            dx = -R*sin(T);
            dy = r*cos(T);
            dz = z;
            t = T;
        }
void TEllipse::PrintNullPoint()
        {
            std::cout << "Center of ellipse Xo: " << x0 << std::endl;
            std::cout << "Center of ellipse Yo: " << y0 << std::endl;
            std::cout << "Center of ellipse Zo: " << z0 << std::endl<< std::endl;
        }
void TEllipse::PrintR()
        {
            std::cout << "Radius  R of ellipse: " << GetR() << std::endl;
            std::cout << "Radius  r of ellipse: " << Getr() << std::endl<< std::endl;
        }
void TEllipse::PrintPoint()
        {
            std::cout << "X = " << x << " <--coordinate ellipse point for T (PI/4) = " << t << std::endl;
            std::cout << "Y = " << y << " <--coordinate ellipse point for T (PI/4) = " << t << std::endl;
            std::cout << "Z = " << z << " <--coordinate ellipse point for T (PI/4) = " << t << std::endl<< std::endl;
            std::cout << "dX = " << dx << " <--increment for 2nd point of vector of tangent to ellipse for T (PI/4) = " << t << std::endl;
            std::cout << "dY = " << dy << " <--increment for 2nd point of vector of tangent to ellipse for T (PI/4) = " << t << std::endl;
            std::cout << "dZ = " << dz << " <--increment for 2nd point of vector of tangent to ellipse for T (PI/4) = " << t << std::endl<< std::endl;
        }
//------------------------------------------------------------------------------------------------------------------------------------
THelix::THelix()
        {
            R = rand() % 10 + 1;
            S = rand() % 5 + 1;
        }
double THelix::GetR() { return R; }
double THelix::GetS() { return S; }
void THelix::SetXYZT(double T)
        {
            x = x0 + R*cos(T);
            y = y0 + R*sin(T);
            z = z0 + (S*T)/(2*M_PI);
            dx = -R*sin(T);
            dy = R*cos(T);
            dz = S/(2*M_PI);
            t = T;
        }
void THelix::PrintNullPoint()
        {
            std::cout << "Axis line of helix at Xo: " << x0 << std::endl;
            std::cout << "Axis line of helix at Yo: " << y0 << std::endl;
            std::cout << "Axis line of helix at Zo: " << z0 << std::endl<< std::endl;
        }
void THelix::PrintR()
        {
            std::cout << "Radius of helix: " << GetR() << std::endl;
            std::cout << "Step of helix: " << GetS() << std::endl<< std::endl;
        }
void THelix::PrintPoint()
        {
            std::cout << "X = " << x << " <--coordinate helix point for T (PI/4) = " << t << std::endl;
            std::cout << "Y = " << y << " <--coordinate helix point for T (PI/4) = " << t << std::endl;
            std::cout << "Z = " << z << " <--coordinate helix point for T (PI/4) = " << t << std::endl<< std::endl;
            std::cout << "dX = " << dx << " <--increment for 2nd point of vector of tangent to helix for T (PI/4) = " << t << std::endl;
            std::cout << "dY = " << dy << " <--increment for 2nd point of vector of tangent to helix for T (PI/4) = " << t << std::endl;
            std::cout << "dZ = " << dz << " <--increment for 2nd point of vector of tangent to helix for T (PI/4) = " << t << std::endl<< std::endl;
        }
//-------------------------------------------------------------------------------------------------------------------------------------
