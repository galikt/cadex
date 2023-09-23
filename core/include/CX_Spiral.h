#ifndef CX_SPIRAL_H
#define CX_SPIRAL_H

#include <iostream>
#include "CX_Export.h"
#include "CX_ShapeBase.h"

class CORE_EXPORT CX_Spiral : public CX_ShapeBase
{
protected:
  float Radius{0.0f};
  float Step{0.0f};
  float StepFactor{0.0f};

public:
  CX_Spiral(const float& radius, const float& step);
  virtual ~CX_Spiral() = default;

  inline friend std::ostream& operator<<(std::ostream& stream, const CX_Spiral& spiral);

  virtual CX_Vector3f GetPoint(const float& value) const override;
  virtual CX_Vector3f GetDerivative(const float& value) const override;
  virtual std::string GetDescription() const override;
};

#endif