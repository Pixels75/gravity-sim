#include "space_transform.h"

float SpaceTransform::world_to_screen_multiplier = 50.0f;

Vector2 SpaceTransform::ScreenToWorld( Vector2 point ) {
  const Vector2 centerPoint = { static_cast<float>( GetScreenWidth()  ) / 2.0f,
                                static_cast<float>( GetScreenHeight() ) / 2.0f };
  point.x -= centerPoint.x;
  point.y =  centerPoint.y - point.y;

  point.x /= world_to_screen_multiplier;
  point.y /= world_to_screen_multiplier;

  return point;
}

Vector2 SpaceTransform::WorldToScreen( Vector2 point ) {
  point.x *= world_to_screen_multiplier;
  point.y *= world_to_screen_multiplier;

  const Vector2 centerPoint = { static_cast<float>( GetScreenWidth()  ) / 2.0f,
                                static_cast<float>( GetScreenHeight() ) / 2.0f };
  point.x += centerPoint.x;
  point.y += centerPoint.y;

  return point;
}