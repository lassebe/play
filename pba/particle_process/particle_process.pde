PVector init_pos,init_vel;
float dt = 0.1;
float GRAVITY = 9.8;
int radius = 20;
int line_x_1=20,line_y_1=500,line_x_2=580,line_y_2=500;

Particle p;

void setup() {
  init_pos = new PVector(40,400);
  init_vel = new PVector(100,-50);
  p = new Particle(init_pos,init_vel);
  background(0);
  size(600, 600);
}

class Particle {
  PVector pos;
  PVector vel;
  PVector force;
  PVector prev_pos;
  float mass;
  
  Particle(PVector pos_, PVector vel_) {
    pos = pos_;
    vel = vel_;
    force = new PVector(0,GRAVITY);
    mass = 1;
    prev_pos = pos;
    prev_pos = prev_pos.sub(vel);

  }

  void update() {
    e_update_position();
    e_update_velocity();
  }

  // Euler
  void e_update_position() {
    pos.add(PVector.mult(vel,dt));
  }

  void e_update_velocity() {
    vel.add(PVector.mult(force,dt*(1/mass)));
  }
  
  // Verlet
  void v_update_position() {
    System.out.println(pos);
    PVector tmp = PVector.add(PVector.add(pos,PVector.sub(pos,prev_pos)),PVector.mult(force,dt*dt*(1/mass)));
    prev_pos = pos;
    pos.add(tmp);

    System.out.println(prev_pos);
  }


}


void draw() {
  background(0);
  p.update();
  if (p.pos.y + radius > 600 ) return;
  ellipse(int(p.pos.x),int(p.pos.y),radius,radius);
}