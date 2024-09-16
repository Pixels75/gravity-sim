#pragma once
#include "raylib.h"

class SpaceTransform {
public:
  static float world_to_screen_multiplier;
  static Vector2 ScreenToWorld( Vector2 point );
  static Vector2 WorldToScreen( Vector2 point );
};
