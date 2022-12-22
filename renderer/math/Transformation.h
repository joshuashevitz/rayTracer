#pragma once

#include "math/tuples.h"
#include "math/Matrix.h"

namespace Math{
  template<typename T>
  class Transform{
  public:
    Math::Tuple3<T> translation;
    Math::Tuple3<T> rotation;
    Math::Tuple3<T> scale;

    Transform() = default;
    Transform(Math::Tuple3<T> translation, Math::Tuple3<T> rotation, Math::Tuple3<T> scale): 
      translation(translation), rotation(rotation), scale(scale){}

  };
}