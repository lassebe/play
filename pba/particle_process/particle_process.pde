PVector pos,vel;
float dt = 0.1;


int radius = 4;

class Particle {
  PVector pos;
  PVector vel;
  
  Particle(PVector pos_, PVector vel_) {
    pos = pos_;
    vel = vel_;
  }
}

Particle p;

void setup() {
  pos = new PVector(5,5);
  vel = new PVector(1,10);
  p = new Particle(pos,vel);
  background(4);
  size(600, 600);
}

void draw() {
  background(0);
  p.pos.add(PVector.mult(vel,dt));
  if ((p.pos.x > 1.0) || (p.pos.x < 0.0)) p.vel.x = -p.vel.x;
  if ((p.pos.y > 1.0) || (p.pos.y < 0.0)) p.vel.y = -p.vel.y;
  ellipse(int(pos.x*radius),int(pos.y*radius),8,8);
}