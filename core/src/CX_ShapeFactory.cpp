#include "CX_ShapeFactory.h"
#include "cstdlib"
#include "CX_Circle.h"
#include "CX_Ellipse.h"
#include "CX_Spiral.h"

std::shared_ptr<CX_ShapeBase> CX_ShapeFactory::CreateRandomShape()
{
  CX_ShapePtr result;

  CX_ShapeType type = static_cast<CX_ShapeType>(std::rand() % static_cast<int>(CX_ShapeType::AMOUNT));
  switch (type)
  {
  case CX_ShapeType::CIRCLE: {
    float radius = static_cast<float>(std::rand() % 100) / 10.f;
    result = std::make_shared<CX_Circle>(radius);
    break;
  }
  case CX_ShapeType::ELLIPSE: {
    float radius_x = static_cast<float>(std::rand() % 100) / 10.f;
    float radius_y = static_cast<float>(std::rand() % 100) / 10.f;
    result = std::make_shared<CX_Ellipse>(radius_x, radius_y);
    break;
  }
  case CX_ShapeType::SPIRAL: {
    float radius = static_cast<float>(std::rand() % 100) / 10.f;
    float step = static_cast<float>(std::rand() % 100) / 10.f;
    result = std::make_shared<CX_Spiral>(radius, step);
    break;
  }
  }

  return result;
}