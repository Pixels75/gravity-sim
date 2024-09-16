#pragma once

#include <cstddef>
#include <vector>

#include "object.h"
#include "raylib.h"

struct SimulationWindow {
  size_t width;
  size_t height;
  Color bg_color;
  const char *title;

  SimulationWindow( size_t width, size_t height, Color bg_color, const char *title );
};

class Simulation {
public:
  explicit Simulation( const SimulationWindow &window );

  ~Simulation();

  bool IsRunning() const;

  void Tick();

  void Update();

  void Render();

  void AddObject( const Object&& object );

  void PrintObjects();

private:
  SimulationWindow m_window;
  std::vector<Object> m_objects;
};
