PVector init_pos,init_vel;
float dt = 0.1;
float GRAVITY = 9.8;
int radius = 20;
int line_x_1=20,line_y_1=500,line_x_2=580,line_y_2=500;

Particle p1,p2;

void setup() {
  init_pos = new PVector(100,200);
  init_vel = new PVector(40,-20);
  p1 = new Particle(init_pos,init_vel,true);
  init_pos = new PVector(400,200);
  init_vel = new PVector(-40,-20);
  p2 = new Particle(init_pos,init_vel,false);
  background(0);
  size(600, 600);
}

class Particle {
  PVector pos;
  PVector vel;
  PVector force;
  PVector prev_pos;
  float mass;
  boolean e;
  
  Particle(PVector pos_, PVector vel_, boolean euler) {
    e = euler;
    pos = pos_;
    vel = vel_;
    force = new PVector(0,GRAVITY);
      
    mass = 1;
      
    prev_pos = PVector.sub(pos,PVector.mult(force,dt/mass));
  }

  void update() {
    if (e)
      e_update_position();
    else
      v_update_position();
  } 

  // Euler
  void e_update_position() {
    pos.add(PVector.mult(vel,dt));
    vel.add(PVector.mult(force,dt/mass));
  }

  
  // Verlet
  void v_update_position() {
    PVector tmp = pos;
    pos = PVector.add(PVector.add(pos,PVector.sub(pos,prev_pos)),PVector.mult(force,dt*dt*(1/mass)));
    prev_pos = tmp;
  }

}


void draw() {
  background(0);
  p1.update();
  p2.update();
  ellipse(int(p1.pos.x),int(p1.pos.y),radius,radius);
  ellipse(int(p2.pos.x),int(p2.pos.y),radius,radius);
}