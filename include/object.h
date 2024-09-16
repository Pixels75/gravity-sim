#pragma once

#include "raylib.h"

class Object {
public:
  const char* name;
  Vector2 position;
  Vector2 velocity;
  Color color;
  float mass;
  float radius;

  explicit Object( const char* name );

  Object( const char* name, Vector2 position,
          Vector2 velocity,        Color color,
          float radius,            float mass );

  void Move( Vector2 displacement );

  void AddVelocity( Vector2 velocityDelta );

  void ApplyForce( Vector2 force );

  void Render() const;
};
