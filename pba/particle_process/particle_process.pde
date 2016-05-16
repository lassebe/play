PVector init_pos,init_vel;
final float dt = 0.1;
final float GRAVITY = 0;
final int LEFT_EDGE = 50, RIGHT_EDGE = 550;
int ID_COUNTER = 0;
float radius = 20.0;


ArrayList<Particle> particles;

Particle p,p2;

void setup() {
  particles = new ArrayList<Particle>();
  init_pos = new PVector(300,300);
  init_vel = new PVector(0,50);
  p = new Particle(init_pos,init_vel);
  init_pos = new PVector(300,400);
  init_vel = new PVector(0,-50);
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

  }

}


void particle_collision() {
  for ( int i = 0; i < particles.size(); i++ ) {
    Particle p_1 = particles.get(i);
    for( int j = i+1; j < particles.size(); j++ ) {
      Particle p_2 = particles.get(j);

      PVector overlap = PVector.sub(p_1.pos,p_2.pos);
      float distance = overlap.mag();
      float target = radius + radius;
      if ( distance  < target ) {
        // Calculate previous "velocities"
        PVector prev_vel_1 = PVector.sub(p_1.pos,p_1.prev_pos);
        PVector prev_vel_2 = PVector.sub(p_2.pos,p_2.prev_pos);

        // Resolve overlap by moving both particles halfway
        float penetration = (distance - target) / distance ;
        p_1.pos.sub(PVector.mult(overlap,penetration/2));
        p_2.pos.add(PVector.mult(overlap,penetration/2));

        // Calculate the projected component factors
        float f1 = PVector.dot(overlap, prev_vel_1) / (distance*distance);
        float f2 = PVector.dot(overlap, prev_vel_2) / (distance*distance);

        // Swap projected components
        prev_vel_1.add(PVector.sub(PVector.mult(overlap,f2),PVector.mult(overlap,f1)));
        prev_vel_2.add(PVector.sub(PVector.mult(overlap,f1),PVector.mult(overlap,f2)));

        // Update the previous position to it's 
        // correct physical place
        p_1.prev_pos = PVector.sub(p_1.pos,prev_vel_1);
        p_2.prev_pos = PVector.sub(p_2.pos,prev_vel_2);

      }
    }
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

    particle_collision();
  }

}