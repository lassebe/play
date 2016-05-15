PVector init_pos,init_vel;
final float dt = 0.1;
final float GRAVITY = 0;
final int LEFT_EDGE = 50, RIGHT_EDGE = 550;
int ID_COUNTER = 0;
int radius = 20;


ArrayList<Particle> particles;

Particle p,p2;

void setup() {
  particles = new ArrayList<Particle>();
  init_pos = new PVector(300,300);
  init_vel = new PVector(50,0);
  p = new Particle(init_pos,init_vel);
  init_pos = new PVector(400,300);
  init_vel = new PVector(-50,0);
  p2 = new Particle(init_pos,init_vel);

  particles.add(p);
  particles.add(p2);
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
  int id;
  
  Particle(PVector pos_, PVector vel_) {
    pos = pos_;
    prev_pos = pos;
    vel = vel_;
    force = new PVector(0,GRAVITY);
    mass = 1;
    prev_pos = PVector.sub(pos,PVector.mult(vel,dt));
    id = ID_COUNTER++;
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
    pos = next;

    position_collision_response();


  }

  void particle_collision() {
    for ( Particle par : particles ) {
      if ( par.id == this.id )
        continue;

      float distance = PVector.sub(par.pos,pos).mag();
      if ( distance < radius + radius ) {
        float penetration = (distance - (radius + radius)) / distance ;
        pos.sub(PVector.mult(PVector.sub(pos,par.pos),penetration/2));
      }
    }
  }

  void position_collision_response() {
    float x_dist = pos.x - prev_pos.x;
    float y_dist = pos.y - prev_pos.y;
      //System.out.println(dist);
    if ( pos.x > RIGHT_EDGE - radius ) {
      prev_pos.x = (RIGHT_EDGE-radius) + x_dist;
      pos.x = RIGHT_EDGE - radius;
    }

    if (pos.x < LEFT_EDGE + radius ){
      prev_pos.x = (LEFT_EDGE + radius) + x_dist;
      pos.x = LEFT_EDGE + radius;
    }

    if (pos.y > RIGHT_EDGE - radius ) {
      prev_pos.y = (RIGHT_EDGE-radius) + y_dist;
      pos.y = RIGHT_EDGE - radius;
    }


    if (pos.y < LEFT_EDGE + radius ) {
      prev_pos.y = (LEFT_EDGE + radius) + y_dist;
      pos.y = LEFT_EDGE + radius;
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
  // draw_box
  line(LEFT_EDGE,LEFT_EDGE,LEFT_EDGE,RIGHT_EDGE);
  line(LEFT_EDGE,RIGHT_EDGE,RIGHT_EDGE,RIGHT_EDGE);
  line(LEFT_EDGE,LEFT_EDGE,RIGHT_EDGE,LEFT_EDGE);
  line(RIGHT_EDGE,LEFT_EDGE,RIGHT_EDGE,RIGHT_EDGE);
  stroke(200);

  for(Particle par : particles ) {
    fill(255,50);
    ellipse(int(par.pos.x),int(par.pos.y),2*radius,2*radius);
    fill(16711680);
    ellipse(int(par.pos.x),int(par.pos.y),4,4);
    par.update();

    par.particle_collision();
  }

}