#include "CX_Type.h"

CX_Vector3f::CX_Vector3f(const float& x, const float& y, const float& z)
    : X(x), Y(y), Z(z)
{
}

CX_Vector3f CX_Vector3f::operator+(const CX_Vector3f& v) const
{
  return CX_Vector3f(X + v.X, Y + v.Y, Z + v.Z);
}

std::ostream& operator<<(std::ostream& stream, const CX_Vector3f& value)
{
  stream << std::format("({:f}, {:f}, {:f})", value.X, value.Y, value.Z);
  return stream;
}

std::string CX_Vector3f::GetString() const
{
  return std::format("{:f} {:f} {:f}", X, Y, Z);
}
