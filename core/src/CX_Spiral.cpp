#include "CX_Spiral.h"
#include <math.h>
#include <format>
#include "CX_Type.h"

CX_Spiral::CX_Spiral(const float& radius, const float& step)
{
  Type = CX_ShapeType::SPIRAL;

  Radius = radius >= 0.0f ? radius : 0.1f;
  Step = step >= 0.0f ? step : 0.1f;
  StepFactor = Step / PI_2;
}

CX_Vector3f CX_Spiral::GetPoint(const float& value) const
{
  CX_Vector3f result;
  result.X = Radius * std::cosf(value);
  result.Y = Radius * std::sinf(value);
  result.Z = StepFactor * value;

  return result;
}

CX_Vector3f CX_Spiral::GetDerivative(const float& value) const
{
  CX_Vector3f result;
  result.X = Radius * -std::sinf(value);
  result.Y = Radius * std::cosf(value);
  result.Z = StepFactor;

  return result;
}

std::string CX_Spiral::GetDescription() const
{
  return std::format("Spiral Radius={:f} Step={:f}", Radius, Step);
}
