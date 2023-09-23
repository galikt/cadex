#include <iostream>
#include <time.h>
#include <math.h>
#include <list>
#include <format>
#include "CX_Core.h"
#include <filesystem>

int main()
{
  std::srand(time(nullptr));

  std::list<CX_ShapePtr> list_one;
  std::list<CX_ShapePtr> list_two;

  for (int i = 0; i < 100; ++i)
  {
    list_one.push_back(std::move(CX_ShapeFactory::CreateRandomShape()));
  }

  for (auto& shape : list_one)
  {
    auto description = shape->GetDescription();
    auto point = shape->GetPoint(M_PI_4);
    auto derivative = shape->GetDerivative(M_PI_4);
    auto str = std::format("Point({:f}, {:f}, {:f}) Derivative({:f}, {:f}, {:f})", point.X, point.Y, point.Z, derivative.X, derivative.Y, derivative.Z);
    std::cout << str << std::endl;

    if (shape->GetType() == CX_ShapeType::CIRCLE)
    {
      list_two.push_back(shape);
    }
  }

  auto comparator = [](const CX_ShapePtr& v1, const CX_ShapePtr& v2) -> bool {
    auto c1 = dynamic_cast<CX_Circle*>(v1.get());
    auto c2 = dynamic_cast<CX_Circle*>(v2.get());
    return *c1 < *c2;
  };
  list_two.sort(comparator);

  float sum{0};
  for (auto& shape : list_two)
  {
    auto circle = dynamic_cast<CX_Circle*>(shape.get());
    sum += circle->GetRadius();
  }

  std::filesystem::create_directory("Models");
  constexpr float step = PI_2 * 0.05f;
  constexpr float max_spiral = (PI_2 * 2) + step;
  constexpr float max_circle = PI_2 + step;
  for (auto& shape : list_one)
  {
    CX_Obj obj(shape->GetDescription());

    float max = shape->GetType() == CX_ShapeType::SPIRAL ? max_spiral : max_circle;
    for (float angle = 0.0f; angle <= max; angle += step)
    {
      auto v = shape->GetPoint(angle);
      auto d = shape->GetDerivative(angle);
      obj.AddData(v, v + d);
    }
  }

  system("pause");

  return 0;
}
