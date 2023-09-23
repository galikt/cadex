#include "CX_Ellipse.h"
#include <math.h>
#include <format>

CX_Ellipse::CX_Ellipse(const float& radius_x, const float& radius_y)
{
  Type = CX_ShapeType::ELLIPSE;

  RadiusX = radius_x > 0.0f ? radius_x : 0.1f;
  RadiusY = radius_y > 0.0f ? radius_y : 0.1f;
}

CX_Vector3f CX_Ellipse::GetPoint(const float& value) const
{
  CX_Vector3f result;
  result.X = RadiusX * std::cos(value);
  result.Y = RadiusY * std::sin(value);
  result.Z = 0.0f;

  return result;
}

CX_Vector3f CX_Ellipse::GetDerivative(const float& value) const
{
  CX_Vector3f result;
  result.X = RadiusX * -std::sin(value);
  result.Y = RadiusY * std::cos(value);
  result.Z = 0.0f;

  return result;
}

std::string CX_Ellipse::GetDescription() const
{
  return std::format("Ellipse RadiusX={:f} RadiusY={:f}", RadiusX, RadiusY);
}
