// ReSharper disable CppMemberFunctionMayBeStatic
#include <iostream>

#include "raylib.h"
#include "simulation.h"


SimulationWindow::SimulationWindow( const size_t width,
                                    const size_t height,
                                    const Color bg_color,
                                    const char *title )
  : width( width ), height( height ), bg_color( bg_color ), title( title ) {}

Simulation::Simulation( const SimulationWindow &window )
  : m_window( window ) {
  InitWindow( static_cast<int>( m_window.width ),
              static_cast<int>( m_window.height ),
              m_window.title );
}

Simulation::~Simulation() { CloseWindow(); }

bool Simulation::IsRunning() const { return !WindowShouldClose(); };

void Simulation::Tick() {
  Update();
  Render();
}


void Simulation::Update() {}

void Simulation::Render() {
  BeginDrawing();
  ClearBackground( m_window.bg_color );
  for ( auto& obj : m_objects ) {
    obj.Render();
  }
  EndDrawing();
}

void Simulation::AddObject( const Object &&object ) { m_objects.push_back( object ); }

void Simulation::PrintObjects() {
  for ( auto &m_object : m_objects ) { std::cout << m_object.name << '\n'; }
  std::cout << "----------------\n";
}
