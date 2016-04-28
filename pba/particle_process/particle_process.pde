PVector init_pos,init_vel;
float dt = 0.1;
float GRAVITY = 9.8;
int radius = 20;

Particle p1,p2;

void setup() {
  init_pos = new PVector(200,200);
  init_vel = new PVector(0,0);
  p1 = new Particle(init_pos,init_vel,true);
  init_pos = new PVector(400,200);
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
    if ( pos.y < 200)
      System.out.println("DIVERGENT!");
    pos.add(PVector.mult(vel,dt));
    force_collision_detection();
    update_velocity();
  }

  void update_velocity() {
    vel.add(PVector.mult(force,dt/mass));
  }
  
  // Verlet
  void v_update_position() {
    PVector acc = PVector.mult(force,dt*dt*(1/mass));
    PVector tmp = pos;
    PVector diff = PVector.sub(pos,prev_pos);
    pos = PVector.add(PVector.add(pos,diff),acc);
    prev_pos = tmp;

  }

  void force_collision_detection(){
    if (pos.y+radius > 500 && vel.y > 0) {
      vel.y = -vel.y;
      pos.y = 500-radius;
      //force_collision_response(false,true);
    }
  }

  void force_collision_response(boolean x, boolean y){
    if (x)
      vel.x = -vel.x;
    if (y) {
      vel.y = -vel.y;
      //pos.y = 500-radius;
    }
    e_update_position();
  }

  void position_collision_detection(){
  }

}


void draw() {
  background(0);
  line(20,500,580,500);
  stroke(255);
  p1.update();
  p2.update();
  ellipse(int(p1.pos.x),int(p1.pos.y),2*radius,2*radius);
  ellipse(int(p2.pos.x),int(p2.pos.y),2*radius,2*radius);
}