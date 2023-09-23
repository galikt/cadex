#include "CX_Circle.h"
#include <math.h>
#include <format>

CX_Circle::CX_Circle(const float& radius)
{
  Type = CX_ShapeType::CIRCLE;

  Radius = radius >= 0.0f ? radius : 0.1f;
}

CX_Vector3f CX_Circle::GetPoint(const float& value) const
{
  CX_Vector3f result;
  result.X = Radius * std::cosf(value);
  result.Y = Radius * std::sinf(value);
  result.Z = 0.0f;

  return result;
}

CX_Vector3f CX_Circle::GetDerivative(const float& value) const
{
  CX_Vector3f result;
  result.X = Radius * -std::sinf(value);
  result.Y = Radius * std::cosf(value);
  result.Z = 0.0f;

  return result;
}

std::string CX_Circle::GetDescription() const
{
  return std::format("Circle Radius={:f}", Radius);
}

float CX_Circle::GetRadius()
{
  return Radius;
}
