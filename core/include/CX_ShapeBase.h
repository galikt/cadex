#ifndef CX_SHAPE_BASE_H
#define CX_SHAPE_BASE_H

#include <string>
#include "CX_Export.h"
#include "CX_Type.h"

class CORE_EXPORT CX_ShapeBase
{
protected:
  CX_ShapeType Type{CX_ShapeType::NONE};

public:
  CX_ShapeBase() = default;
  virtual ~CX_ShapeBase() = default;

  virtual std::string GetDescription() const = 0;
  virtual CX_Vector3f GetPoint(const float& value) const = 0;
  virtual CX_Vector3f GetDerivative(const float& value) const = 0;
  inline CX_ShapeType GetType() const;
};

CX_ShapeType CX_ShapeBase::GetType() const
{
  return Type;
}

#endif
