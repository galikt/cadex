#ifndef CX_CIRCLE_H
#define CX_CIRCLE_H

#include <iostream>
#include "CX_Export.h"
#include "CX_ShapeBase.h"

class CORE_EXPORT CX_Circle : public CX_ShapeBase
{
protected:
  float Radius{0.0f};

public:
  CX_Circle(const float& radius);
  virtual ~CX_Circle() = default;

  inline friend bool operator<(const CX_Circle& v1, const CX_Circle& v2);

  float GetRadius();
  virtual CX_Vector3f GetPoint(const float& value) const override;
  virtual CX_Vector3f GetDerivative(const float& value) const override;
  virtual std::string GetDescription() const override;
};

bool operator<(const CX_Circle& v1, const CX_Circle& v2)
{
  return v1.Radius < v2.Radius;
}

#endif