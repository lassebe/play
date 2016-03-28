#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

map<char, pair<int,int>> key_map;


struct word_distance {
public:
  word_distance(string s, int d){
    word = s;
    distance = d;
  }
  bool operator <(const word_distance& y) {
    if(this->distance == y.distance)
      return this->word < y.word;
    return this->distance < y.distance;
  }

  string word;
  int distance;
};

bool my_cmp(const word_distance& x, const word_distance& y){
    if(x.distance == y.distance)
      return x.word < y.word;
    return x.distance < y.distance;
}


int calc_distance(string w1, string w2){
  int dist = 0;

  for(int i=0;i<w1.size();++i){
    int xdist, ydist; 
    xdist = abs(key_map[w1[i]].first - key_map[w2[i]].first);
    ydist = abs(key_map[w1[i]].second - key_map[w2[i]].second);
    

    dist += xdist + ydist;
  }
  return dist;
}

int main(int argc, char const *argv[]) {
  string keyboard[] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
  for(int i=0;i<3;++i){
    for(int j=0;j<keyboard[i].size();++j){
      key_map[keyboard[i].at(j)] = make_pair(i,j);
    }
  }
  int t;
  cin >> t;
  while(t--){
    string word;
    int dict_size;
    cin >> word >> dict_size;
    vector<string> dict = vector<string>(dict_size);
    vector<word_distance> dists;

    for(int i=0;i<dict_size;++i) {
      cin >> dict[i];
    }

    for(int i=0;i<dict_size;++i){
      dists.push_back( word_distance(dict[i],calc_distance(word,dict[i])));
    }


    sort(dists.begin(),dists.end(),my_cmp);
    for(auto it= dists.begin();it!=dists.end();++it){
      cout << it->word << " " << it->distance << endl;
    }
  }  
  return 0;
}