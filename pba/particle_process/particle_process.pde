PVector init_pos,init_vel;
float dt = 0.1;
float GRAVITY = 9.82;
int radius = 20;

PVector wire;

Particle p;

void setup() {
  init_pos = new PVector(250,300);
  init_vel = new PVector(50,0);
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
  boolean e;
  
  Particle(PVector pos_, PVector vel_) {
    pos = pos_;
    prev_pos = pos;
    vel = vel_;
    force = new PVector(0,GRAVITY);  
    //force.add(vel);
    mass = 1;
    //prev_pos = PVector.sub(pos,PVector.mult(vel,dt));
  }

  void update() {
    v_update_position();
  } 

  
  // Verlet
  void v_update_position() {
    PVector acc = PVector.mult(force,dt*dt*(1/mass));
    PVector tmp = pos;
    PVector diff = PVector.sub(pos,prev_pos);
    PVector next = PVector.add(PVector.add(pos,PVector.sub(pos,prev_pos)),PVector.mult(force,dt*dt*(1/mass)));
    prev_pos = tmp;
    pos = next;
    if ( collision_detection(next.x) ) {
      position_collision_response();
    }

    wire = new PVector(pos.x,300);
    PVector projection = PVector.mult(wire,PVector.dot(pos,wire)/PVector.dot(wire,wire));
    pos = projection;
    //pos = PVector.add(wire,PVector.mult(delta, radius/delta.mag()));

    //System.out.println(pos);
  }

  boolean collision_detection(float position){
    return position  > 500-radius;
  }

  void position_collision_response(){
    float dist = pos.x - prev_pos.x;
    prev_pos.x = (500-radius) + dist;
    pos.x = 500 - radius;
    System.out.println(prev_pos.x);
    /*pos.x = 500-radius;
    prev_pos.x = dist;
    prev_pos.x += pos.x;*/
  }

}


void draw() {
  background(0);
  stroke(255);
  line(100,300,500,300);
  stroke(200);


  fill(255,50);
  ellipse(int(p.pos.x),int(p.pos.y),2*radius,2*radius);

  fill(16711680);
  ellipse(int(p.pos.x),int(p.pos.y),4,4);
  line(p.pos.x,p.pos.y+50,p.prev_pos.x,p.prev_pos.y+50);

  p.update();
}