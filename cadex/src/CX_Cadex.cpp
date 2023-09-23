#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <format>
#include <filesystem>
#include <omp.h>
#include "CX_Core.h"

const size_t SHAPE_AMOUNT{500};

int main()
{
  std::srand(time(nullptr));

  std::vector<CX_ShapePtr> list_one;
  std::vector<CX_ShapePtr> list_two;

  for (int i = 0; i < SHAPE_AMOUNT; ++i)
  {
    list_one.push_back(std::move(CX_ShapeFactory::CreateRandomShape()));
  }

  std::cout << "list one. Angle = PI/4" << std::endl;
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
  std::sort(list_two.begin(), list_two.end(), comparator);

  std::cout << "Sorted list two" << std::endl;
  for (auto& shape : list_two)
  {
    std::cout << shape->GetDescription() << std::endl;
  }

  float sum{0};
#pragma omp parallel for reduction(+ : sum)
  for (auto& shape : list_two)
  {
    auto circle = dynamic_cast<CX_Circle*>(shape.get());
    sum += circle->GetRadius();
    // std::cout << "Thread " << omp_get_thread_num() << std::endl;
  }
  std::cout << "Sum = " << sum << std::endl;

  std::filesystem::create_directory("Models");
  constexpr float step = PI_2 * 0.05f;
  constexpr float max_spiral = (PI_2 * 2) + step;
  constexpr float max_circle = PI_2 + step;
#pragma omp parallel for
  for (auto& shape : list_one)
  {
    CX_Obj obj(shape->GetDescription());

    float max = shape->GetType() == CX_ShapeType::SPIRAL ? max_spiral : max_circle;
    for (float angle = 0.0f; angle <= max; angle += step)
    {
      auto v = shape->GetPoint(angle);
      auto d = shape->GetDerivative(angle);
      obj.AddData(v, v + d);
      // std::cout << "Thread " << omp_get_thread_num() << std::endl;
    }
  }

  std::cout << "Press Enter to continue" << std::endl;
  std::cin.get();

  return 0;
}
