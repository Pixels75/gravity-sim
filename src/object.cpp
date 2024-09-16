#include "raylib.h"
#include "object.h"
#include "space_transform.h"

Object::Object( const char *name )
  : name( name ),
    position(),
    velocity(),
    color( WHITE ),
    mass( 1.0f ),
    radius( 1.0f ) {}

Object::Object( const char *name, const Vector2 position,
                const Vector2 velocity, const Color color,
                const float radius, const float mass )
  : name( name ),
    position( position ),
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

void Object::Render() const {
  DrawCircleV( SpaceTransform::WorldToScreen( position ),
                     radius * SpaceTransform::world_to_screen_multiplier / 2.0f,
                     color );
}
