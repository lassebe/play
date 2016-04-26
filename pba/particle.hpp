#include <vector>
using namespace std;



class Particle {
public:
  Particle() {

  }
  ~Particle();

private:
  vector<double> position;
  vector<double> velocity;
  vector<double> force;
  vector<double> previous_position;
  double mass;
  double duration;

};