#include <iostream>
//#include <algorithms>
#include <vector>
#include <assert.h>
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void readInput();
void greedyStuff();
void verifySolution();
bool contains(vector<int> & , int);
bool assign_divas(int);


// List of roles each actor can play
// index in outer list = actor
vector<vector<int>> roles;

// List of roles that appear in the same scene as role [i]
// index in outer list = role i
vector<vector<int>> conflictRoles;

//index in outer vector is actor
// inner vector contains which roles actor plays
vector<vector<int>> assignment;

// #roles, scenes, actors
// minimum 1, 1, 2
int n, s, k;
// We can use n-1 "superactors" who can play any role, but only ONE role at a time
// They have numbers k+1, k+2, ... k+n




int main(){
  srand(time(NULL));
  //rand() % n - random number between 0 and n 

  readInput();

  greedyStuff();
  //Simulated annealing
  verifySolution();
}


//Assign the divas, then give each actor as many roles as possible
void greedyStuff(){

  //Which roles have been assigned
  bool assigned[n];
  for(int i=0;i<n;++i){
    assigned[i]=false;
  }
  
  //Assign the divas
  int i_temp=0;
  while(!assign_divas(i_temp)){
    ++i_temp;
  }
  assigned[assignment[0][0]] = true;
  assigned[assignment[1][0]] = true;

  bool possible = true;
  //Try to assign each actor as many roles as possible
  for(int i=2; i < k; ++i){
    //roles[i] = this actor can play these roles
    for(auto possibleRole = roles[i].begin(); possibleRole != roles[i].end(); ++possibleRole){
      if(!assigned[*possibleRole] ){
        for(auto it = assignment[i].begin(); it != assignment[i].end(); ++it){
            if(contains(conflictRoles[*it],*possibleRole)){
              possible = false;
            }
        }
      }else{
        possible = false;
      }

      if(possible){
        assigned[*possibleRole] = true;
        assignment[i].push_back(*possibleRole);
      }
      possible = true;
    }
  }

  int superactor = k;
  for(int i=0; i < n; ++i){
    if(!assigned[i]){
      assignment[i].push_back(superactor);
      assigned[i] = true;
      ++superactor;
    }
  }
  
}

bool assign_divas(int i){
  int diva1roles = roles[0].size();
  int diva2roles = roles[1].size();
  int j=0;
  while(i < diva1roles && j < diva2roles){
    if(roles[0][i] != roles[1][j]){
      if(!contains(conflictRoles[0],roles[1][j])){
        assignment[0].push_back(roles[0][i]);
        assignment[1].push_back(roles[1][j]);
        return true;
      }
    }
    ++j;
  }
  return false;
}

bool contains(vector<int> & vec, int role){
  for(auto it=vec.begin(); it != vec.end(); ++it){
    if(*it == role)
      return true;
     
  }
  return false;
}








void verifySolution(){
  //the divas have been casted (linear)
  assert(assignment[0].size() > 0);
  assert(assignment[1].size() > 0);
  //Check that the divas don't meet (constant)
  for(auto it = assignment[0].begin(); it != assignment[0].end(); ++it){
    for(auto it2 = assignment[1].begin(); it2 != assignment[1].end(); ++it2){
      for(auto wat=conflictRoles[*it].begin(); wat != conflictRoles[*it].end(); ++wat){
        cout << *wat << " ";
      }
      cout << "\n";
      assert(!contains(conflictRoles[*it],*it2));
    }
  }
  //Check that no actor has conflict between roles (quadratic)
  for(int i=0; i < n+k; ++i){
    for(auto it = assignment[i].begin(); it != assignment[i].end(); ++it){
      for(auto it2 = assignment[i].begin(); it2 != assignment[i].end(); ++it2){
        if(*it != *it2){
          cout  << "skådespelare= " << i << " r1=" << *it << " OCH r2=" << *it2 << "\n";
          
          assert(!contains(conflictRoles[*it],*it2));
        }
      }
    }
  }
}


void readInput(){
  cin >> n >> s >> k;

  roles = vector<vector<int>>(n,vector<int>(0));
  conflictRoles = vector<vector<int>>(n,vector<int>(0));
  assignment = vector<vector<int>>(k+n,vector<int>(0));
  //read actors for each role
  for(int i=0; i < n; ++i){      
    int numRolesForActor=0;
    cin >> numRolesForActor;
    
    int actor;
    for(int j=0; j < numRolesForActor; ++j){
      cin >> actor;
      //OFFSET BECAUSE VIGGO ÄR GALEN
      roles[i].push_back(actor-1);
    }
  }
  /* PRINT
  for(int i=0; i < n; ++i){
    for(auto it=roles[i].begin(); it != roles[i].end(); ++it){
      cout << *it << " ";
    }
    cout << "\n";
  }*/

  //Read roles for each scene
  for(int i=0; i < s; ++i){
    int numRolesInScene=0;
    cin >> numRolesInScene;
    int temp[numRolesInScene];
    int role;
    for(int j=0; j < numRolesInScene; ++j){
      cin >> role;
      //OFFSET BECAUSE VIGGO ÄR GALEN
      temp[j] = role-1;
    }


    //For each role that appears in the scene,
    //add all other roles in the scene to conflict list
    for(int j=0; j < numRolesInScene; ++j){
      for(int k=0; k < numRolesInScene; ++k){
        if(k!=j && !contains(conflictRoles[temp[j]],temp[k]))
          conflictRoles[temp[j]].push_back(temp[k]);
      }
    }
  }


  cout << "MOAR DEBUG ____________________\n";
  int offset=0;
  for(auto it=conflictRoles.begin(); it != conflictRoles.end(); ++it){
    cout << "roll=" << offset << " krockar med: ";
    for(auto wat= it->begin(); wat != it->end(); ++wat){
      cout << *wat << " ";
    }
    cout << "\n";
    ++offset;
  }
}