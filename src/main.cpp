#include "simulation.h"

int main() {
  Simulation sim( { 800, 450, { 55, 55, 55 }, "" } );
  sim.AddObject( ( Object ){
    "obj1",
    { 4.0f, 0.0f },
    { 0.0f, 0.0f },
    RED,
    1.0f,
    1.0f
  } );
  sim.AddObject( ( Object ){
    "obj1",
    { -4.0f, 0.0f },
    { 0.0f, 0.0f },
    BLUE,
    1.0f,
    1.0f
  } );

  while ( sim.IsRunning() ) {
    sim.Tick();
    sim.PrintObjects();
  }
}
