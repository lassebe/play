#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

struct item{  
  public:
    item(int a, int b){
      v=a;
      w=b;
    }
  int v,w;
};

bool compare_item( const item & e1, const item & e2) {
  double p1,p2;
  p1 = (double) e1.v / (double) e1.w;
  p2 = (double) e2.v / (double) e2.w;
  return (p1 < p2);
}

int n, cap;
int value; // init -1
vector<int> taken;
vector<item> items;

void branch(int dec, int val, int weight, int expectedValue, vector<int> prev);
int calculateMaxVal(vector<item> i2s);

int main(int argc, char const *argv[]){
  ifstream inRead;
  inRead.open(argv[1]);
  inRead >> n >> cap;
  items = vector<item>();

  int v,w;
  for(int i=0; i < n; ++i){
    inRead >> v >> w;
    items.push_back(item(v,w));
  }

  value = -1;
  taken = vector<int>(n,0);
  
  int maxVal = 0;//calculateMaxVal(items);
  for(auto it=items.begin(); it!=items.end();++it){
    maxVal += it->v;
  }

  branch(1, 0, 0, maxVal, vector<int>());
  branch(0, 0, 0, maxVal, vector<int>());

  cout << value << " 0\n";
  for(auto it=taken.begin(); it!=taken.end();++it){
    cout << *it << " ";
  }
  cout << "\n";

  inRead.close();
  return 0;
}

void branch(int dec, int val, int weight, int expectedValue, vector<int> prev){
  int index = prev.size();
  assert(index < n);
  assert(dec == 0 || dec == 1);
  //cout<< "\n\nbranch'd\n";
  //cout << "expected " << expectedValue <<"\n";
  //cout << "current item val " << items[index].v << "\n";
  if(expectedValue < value){
    //cout << "worse!\n";
    return;
  }


  prev.push_back(dec);
  if(dec == 0){
    //don't include item index
    //calculate max expected value
    expectedValue -= items[index].v;
    if(expectedValue < value){
    //cout << "worse!\n dec=" << dec << "\n";
    //cout << "expected " << expectedValue << " val " << value << " \n";
      return;
    }
  }else{
    //take the item
    weight += items[index].w;
    if(weight > cap){
      //cout << "too heavy!\n";
      return;
    }

    val += items[index].v;
  }


  if(index == n-1){
    //update value and taken
    if(expectedValue > value){
      //cout << "CHANGE VALUE FROM " << value << " TO " << val << "\n";
      taken = prev;
      value = val;
    }
    return;
  }

  //branch left and right
  branch(1,val,weight,expectedValue,prev);
  branch(0,val,weight,expectedValue,prev);
}

int calculateMaxVal(vector<item> i2s){
  sort(i2s.begin(), i2s.end(), compare_item);
  int maxVal = 0;
  int weight = 0;
  int iter = i2s.size()-1;
  while(weight < cap){
    weight += i2s[iter].w;
    if(weight > cap)
      break;
    maxVal += i2s[iter].v;
    --iter;
  }
  int rem = weight - cap;

  int remVal = rem * ( (double)i2s[iter].v / (double)i2s[iter].w);
  return maxVal + remVal;
}