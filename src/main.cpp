#include "simulation.h"

int main() {
  Simulation sim( { 800, 450, { 55, 55, 55 }, "" } );
  sim.AddObject( ( Object ){ "obj1" } );
  sim.AddObject( ( Object ){ "obj2" } );

  while ( sim.IsRunning() ) {
    sim.Tick();
    sim.PrintObjects();
  }
}
