#include "object.h"

Object::Object( std::string name )
  : name( std::move( name ) ),
    position( { 0.0f, 0.0f } ),
    velocity( { 0.0f, 0.0f } ),
    color( { 255, 255, 255 } ),
    mass( 1.0f ),
    radius( 1.0f ) {}

Object::Object( const std::string& name, const Vector2 position,
                const Vector2 velocity,  const Color color,
                const float radius,      const float mass )
  : position( position ),
    velocity( velocity ),
    color( color ),
    mass( mass ),
    radius( radius ) {}

void Object::Move( const Vector2 displacement ) {
  position.x += displacement.x;
  position.y += displacement.y;
}

void Object::AddVelocity( const Vector2 velocityDelta ) {
  velocity.x += velocityDelta.x;
  velocity.y += velocityDelta.y;
}

void Object::ApplyForce( const Vector2 force ) {
  velocity.x += force.x / mass;
  velocity.y += force.y / mass;
}
