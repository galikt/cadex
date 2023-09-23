#ifndef CX_SHAPE_FACTORY_H
#define CX_SHAPE_FACTORY_H

#include <memory>
#include "CX_ShapeBase.h"
#include "CX_Export.h"

using CX_ShapePtr = std::shared_ptr<CX_ShapeBase>;

CORE_EXPORT class CX_ShapeFactory
{
public:
  CX_ShapeFactory() = delete;
  ~CX_ShapeFactory() = delete;

  static CORE_EXPORT CX_ShapePtr CreateRandomShape();
};

#endif // !CX_SHAPE_FACTORY_H
