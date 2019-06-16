#pragma once

#include <ostream>
#include "Geom.h"

class VecPosition;
struct TVec2
{
	double X = 0.0;
	double Y = 0.0;

    TVec2() = default;
    TVec2( VecPosition _pos );

    operator VecPosition();

    friend std::ostream &operator<< ( std::ostream & oo , const TVec2 & _vec ) {
        oo << "X: " << _vec.X << ", Y: " << _vec.Y << std::endl;
        return oo;
    }
};

struct TVec3
{
	double X;
	double Y;
	double Z;
};

TVec2 Vec2 ( double X , double Y );
TVec2 Vec2 ( double a = 0.0f );
TVec3 Vec3 ( double X , double Y , double Z );
TVec3 Vec3 ( double a = 0.0f );

TVec2 operator + ( const TVec2 & a , const TVec2 & b );
TVec2 operator - ( const TVec2 & a , const TVec2 & b );
TVec2 operator * ( const TVec2 & a , const TVec2 & b );
TVec2 operator / ( const TVec2 & a , const TVec2 & b );
TVec2 operator * ( const TVec2 & a , const double b );
TVec2 operator / ( const TVec2 & a , const double b );
TVec2 operator += ( TVec2 & a , const TVec2 & b );
TVec2 operator -= ( TVec2 & a , const TVec2 & b );
TVec2 operator *= ( TVec2 & a , const TVec2 & b );
TVec2 operator /= ( TVec2 & a , const TVec2 & b );
TVec2 operator *= ( TVec2 & a , const double b );
TVec2 operator /= ( TVec2 & a , const double b );

TVec3 operator + ( const TVec3 & a , const TVec3 & b );
TVec3 operator - ( const TVec3 & a , const TVec3 & b );
TVec3 operator * ( const TVec3 & a , const TVec3 & b );
TVec3 operator / ( const TVec3 & a , const TVec3 & b );
TVec3 operator * ( const TVec3 & a , const double b );
TVec3 operator / ( const TVec3 & a , const double b );
TVec3 operator += ( TVec3 & a , const TVec3 & b );
TVec3 operator -= ( TVec3 & a , const TVec3 & b );
TVec3 operator *= ( TVec3 & a , const TVec3 & b );
TVec3 operator /= ( TVec3 & a , const TVec3 & b );
TVec3 operator *= ( TVec3 & a , const double b );
TVec3 operator /= ( TVec3 & a , const double b );

TVec2 Normalize ( const TVec2& a );
TVec3 Normalize ( const TVec3& a );

double Magnitude ( const TVec2& a );
double Magnitude ( const TVec3& a );


double Dot ( const TVec2& a , const TVec2& b );
double Dot ( const TVec3& a , const TVec3& b );

TVec2 Rotate( const TVec2& v, const double a);