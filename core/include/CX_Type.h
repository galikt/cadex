#ifndef CX_TYPE_H
#define CX_TYPE_H

#include <iostream>
#include <math.h>
#include <format>
#include "CX_Export.h"

static constexpr float PI_2 = static_cast<float>(M_PI * 2.0);

enum class CX_ShapeType
{
  CIRCLE = 0,
  ELLIPSE,
  SPIRAL,
  AMOUNT,
  NONE,
};

class CORE_EXPORT CX_Vector3f
{
public:
  float X{0.0f};
  float Y{0.0f};
  float Z{0.0f};

  CX_Vector3f() = default;
  CX_Vector3f(const float& x, const float& y, const float& z);

  CX_Vector3f operator+(const CX_Vector3f& v) const;
  friend std::ostream& operator<<(std::ostream& stream, const CX_Vector3f& value);

  std::string GetString() const;
};

#endif // !CX_TYPE_H
