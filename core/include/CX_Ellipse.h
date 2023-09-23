#ifndef CX_ELLIPSE_H
#define CX_ELLIPSE_H

#include <iostream>
#include "CX_Export.h"
#include "CX_ShapeBase.h"

class CORE_EXPORT CX_Ellipse : public CX_ShapeBase
{
protected:
  float RadiusX{0.0f};
  float RadiusY{0.0f};

public:
  CX_Ellipse(const float& radius_x, const float& radius_y);
  virtual ~CX_Ellipse() = default;

  inline friend std::ostream& operator<<(std::ostream& stream, const CX_Ellipse& ellipse);

  virtual CX_Vector3f GetPoint(const float& value) const override;
  virtual CX_Vector3f GetDerivative(const float& value) const override;
  virtual std::string GetDescription() const override;
};

#endif