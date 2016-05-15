PVector init_pos,init_vel;
float dt = 0.02;
float GRAVITY = 1000;
int LEFT_EDGE = 200, RIGHT_EDGE = 400;
int radius = 20;
PVector wire;

Particle p;

void setup() {
  init_pos = new PVector(300,300);
  init_vel = new PVector(200,0);
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
    mass = 1;
    prev_pos = PVector.sub(pos,PVector.mult(vel,dt));
  }

  void update() {
    v_update_position();
  } 

  
  // Verlet
  void v_update_position() {
    //PVector acc = PVector.mult(force,dt*dt*(1/mass));
    PVector tmp = pos;
    //PVector diff = PVector.sub(pos,prev_pos);
    PVector next = PVector.add(PVector.add(pos,PVector.sub(pos,prev_pos)),PVector.mult(force,dt*dt*(1/mass)));
    prev_pos = tmp;
    pos = next;//PVector.add(PVector.add(pos,PVector.sub(pos,prev_pos)),PVector.mult(force,dt*dt*(1/mass)));

    position_collision_response();

    wire = new PVector(pos.x,300);

    float projection = PVector.dot(pos,PVector.mult(wire,1/wire.mag()));
    //PVector.mult(wire,PVector.dot(pos,wire)/PVector.dot(wire,wire));
    //wire.x = projection;
    pos.lerp(wire,1.0);
  }

  void position_collision_response(){
    float dist = pos.x - prev_pos.x;
      //System.out.println(dist);
    if ( pos.x > RIGHT_EDGE - radius ) {
      prev_pos.x = (RIGHT_EDGE-radius) + dist;
      pos.x = RIGHT_EDGE - radius;
    }

    if (pos.x < LEFT_EDGE + radius ){
      prev_pos.x = (LEFT_EDGE + radius) + dist;
      pos.x = LEFT_EDGE + radius;
    }
    //System.out.println(dist);
    /*pos.x = 500-radius;
    prev_pos.x = dist;
    prev_pos.x += pos.x;*/
  }

}


void draw() {
  background(0);
  stroke(255);
  line(LEFT_EDGE,300,RIGHT_EDGE,300);
  stroke(200);


  fill(255,50);
  ellipse(int(p.pos.x),int(p.pos.y),2*radius,2*radius);

  fill(16711680);
  ellipse(int(p.pos.x),int(p.pos.y),4,4);
  //line(p.pos.x,p.pos.y+50,p.prev_pos.x,p.prev_pos.y+50);

  p.update();
}