#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct job{
  job(int we, int le) : w(we), l(le) {
  }
  int w;
  int l;
};

bool compare_job( const job & e1, const job & e2) {
  double p1,p2;
  p1 = (double)e1.w /  (double)e1.l;
  p2 = (double)e2.w /  (double)e2.l;
  if(p1 == p2){
    if( e1.w > e2.w){
      return true;
    }
    return false;
  }
  return (p1 > p2);
}

int main(){
  vector<job> jobs;
  int n, t, tmp;

  cin >> n;
  for(int i=0; i < n; ++i){
    cin >> t >> tmp;
    jobs.push_back(job(t,tmp));
  }

  sort(jobs.begin(), jobs.end(), compare_job);

  int timer = 0;
  long sum = 0;
  for(auto it = jobs.begin(); it != jobs.end(); ++it){
    cout << it-> w << " " << it->l <<  " " << (double)it->w / (double)it->l <<"\n";
    timer += it->l;
    sum += timer*it->w; 
  }
  cout << sum << "\n";
  return 0;
}