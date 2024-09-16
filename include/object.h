#pragma once

#include <string>

#include "raylib.h"

class Object {
public:
  std::string name;
  Vector2 position;
  Vector2 velocity;
  Color color;
  float mass;
  float radius;

  explicit Object( std::string name );

  Object( const std::string& name, Vector2 position,
          Vector2 velocity,        Color color,
          float radius,            float mass );

  void Move( Vector2 displacement );

  void AddVelocity( Vector2 velocityDelta );

  void ApplyForce( Vector2 force );
};
