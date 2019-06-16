
#include "Vector.h"

TVec2 Vec2 ( double X , double Y )
{
	TVec2 ans;
	ans.X = X;
	ans.Y = Y;
	return ans;
}

TVec2 Vec2 ( double a )
{
	TVec2 ans;
	ans.X = a;
	ans.Y = a;
	return ans;
}

TVec3 Vec3 ( double X , double Y , double Z )
{
	TVec3 ans;
	ans.X = X;
	ans.Y = Y;
	ans.Z = Z;
	return ans;
}

TVec3 Vec3 ( double a )
{
	TVec3 ans;
	ans.X = a;
	ans.Y = a;
	ans.Z = a;
	return ans;
}

TVec2 operator + ( const TVec2 & a , const TVec2 & b )
{
	return Vec2 ( a.X + b.X , a.Y + b.Y );
}

TVec2 operator - ( const TVec2 & a , const TVec2 & b )
{
	return Vec2 ( a.X - b.X , a.Y - b.Y );
}

TVec2 operator * ( const TVec2 & a , const TVec2 & b )
{
	return Vec2 ( a.X * b.X , a.Y * b.Y );
}

TVec2 operator / ( const TVec2 & a , const TVec2 & b )
{
	return Vec2 ( a.X / b.X , a.Y / b.Y );
}

TVec2 operator * ( const TVec2 & a , const double b )
{
	return Vec2 ( a.X * b , a.Y * b );
}

TVec2 operator / ( const TVec2 & a , const double b )
{
	return Vec2 ( a.X / b , a.Y / b );
}

TVec2 operator += ( TVec2 & a , const TVec2 & b )
{
	a.X += b.X;
	a.Y += b.Y;

	return a;
}

TVec2 operator -= ( TVec2 & a , const TVec2 & b )
{
	a.X -= b.X;
	a.Y -= b.Y;

	return a;
}

TVec2 operator *= ( TVec2 & a , const TVec2 & b )
{
	a.X *= b.X;
	a.Y *= b.Y;

	return a;
}

TVec2 operator /= ( TVec2 & a , const TVec2 & b )
{
	a.X /= b.X;
	a.Y /= b.Y;

	return a;
}

TVec2 operator *= ( TVec2 & a , const double b )
{
	a.X *= b;
	a.Y *= b;
	
	return a;
}

TVec2 operator /= ( TVec2 & a , const double b )
{
	a.X /= b;
	a.Y /= b;
	
	return a;
}

TVec3 operator + ( const TVec3 & a , const TVec3 & b )
{
	return Vec3 ( a.X + b.X , a.Y + b.Y , a.Z + b.Z );
}

TVec3 operator - ( const TVec3 & a , const TVec3 & b )
{
	return Vec3 ( a.X - b.X , a.Y - b.Y , a.Z - b.Z );
}

TVec3 operator * ( const TVec3 & a , const TVec3 & b )
{
	return Vec3 ( a.X * b.X , a.Y * b.Y , a.Z * b.Z );
}

TVec3 operator / ( const TVec3 & a , const TVec3 & b )
{
	return Vec3 ( a.X / b.X , a.Y / b.Y , a.Z / b.Z );
}

TVec3 operator * ( const TVec3 & a , const double b )
{
	return Vec3 ( a.X * b , a.Y * b , a.Z * b );
}

TVec3 operator / ( const TVec3 & a , const double b )
{
	return Vec3 ( a.X / b , a.Y / b , a.Z / b );
}


TVec3 operator += ( TVec3 & a , const TVec3 & b )
{
	a.X += b.X;
	a.Y += b.Y;
	a.Z += b.Z;

	return a;
}

TVec3 operator -= ( TVec3 & a , const TVec3 & b )
{
	a.X -= b.X;
	a.Y -= b.Y;
	a.Z -= b.Z;

	return a;
}

TVec3 operator *= ( TVec3 & a , const TVec3 & b )
{
	a.X *= b.X;
	a.Y *= b.Y;
	a.Z *= b.Z;

	return a;
}

TVec3 operator /= ( TVec3 & a , const TVec3 & b )
{
	a.X /= b.X;
	a.Y /= b.Y;
	a.Z /= b.Z;

	return a;
}

TVec3 operator *= ( TVec3 & a , const double b )
{
	a.X *= b;
	a.Y *= b;
	a.Z *= b;
	
	return a;
}

TVec3 operator /= ( TVec3 & a , const double b )
{
	a.X /= b;
	a.Y /= b;
	a.Z /= b;
	
	return a;
}

TVec2 Normalize ( const TVec2& a )
{
	if (Magnitude(a)==0) {
		return Vec2(0, 0);
	}
	return a/Magnitude(a);
}

TVec3 Normalize ( const TVec3& a )
{
	if (Magnitude(a)==0) {
		return Vec3(0, 0, 0);
	}
	return a/Magnitude(a);
}

double Magnitude ( const TVec2& a )
{
	return sqrt(a.X*a.X+a.Y*a.Y);
}

double Magnitude ( const TVec3& a )
{
	return sqrt(a.X*a.X+a.Y*a.Y+a.Z*a.Z);
}

double Dot ( const TVec2& a , const TVec2& b )
{
    return a.X*b.X + a.Y*b.Y;
}

double Dot ( const TVec3& a , const TVec3& b )
{
    return a.X*b.X + a.Y*b.Y + a.Z*b.Z;
}

TVec2 Rotate( const TVec2& v, const double deg)
{
	TVec2 q;
	double s, c;

	s = sinDeg(deg);
	c = cosDeg(deg);

	q.X = c * v.X + -s * v.Y;
	q.Y = s * v.X + c * v.Y;

	return (q);
}

TVec2::TVec2(VecPosition _pos) {
    this->X = _pos.getX();
    this->Y = _pos.getY();
}

TVec2::operator VecPosition() {
    return VecPosition(this->X,this->Y);
}
