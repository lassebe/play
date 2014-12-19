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
void printAssignment();
void printRoles();
void printConflict();
void printSolution();
void verifySolution();
bool contains(vector<int> & , int);
bool assign_divas(int);


// List of actors each actor can play
// index in outer list = actor
vector<vector<int>> actors;

// List of actors that appear in the same scene as role [i]
// index in outer list = role i
vector<vector<int>> conflictRoles;

//index in outer vector is actor
// inner vector contains which actors actor plays
vector<vector<int>> assignment;

// #actors, scenes, actors
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
  
  //For testing
  //verifySolution();
 // printConflict();
  printSolution();
}


//Assign the divas, then give each actor as many actors as possible
void greedyStuff(){

  //Which actors have been assigned
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
  //Try to assign each actor as many actors as possible
  for(int actor=2; actor < k; ++actor){
    //actors[i] = this actor can play these actors
    for(auto possibleRole = actors[actor].begin(); possibleRole != actors[actor].end(); ++possibleRole){
      if(!assigned[*possibleRole] ){
        for(auto it = conflictRoles[*possibleRole].begin(); it != conflictRoles[*possibleRole].end(); ++it){
            if(contains(assignment[actor],*it)){
              possible = false;
            }
        }
      }else{
        possible = false;
      }

      if(possible){
        assigned[*possibleRole] = true;
        assignment[actor].push_back(*possibleRole);
      }
      possible = true;
    }
  }

  int superactor = k;
  for(int role=0; role < n; ++role){
    if(!assigned[role]){
      assignment[superactor].push_back(role);
      assigned[role] = true;
      ++superactor;
    }
  }
  
}

bool assign_divas(int i){
  int j=0;
  while(i <  actors[0].size() && j < actors[1].size()){
    if(actors[0][i] != actors[1][j]){
      if(!contains(conflictRoles[0],actors[1][j])){
        assignment[0].push_back(actors[0][i]);
        assignment[1].push_back(actors[1][j]);
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


void printSolution(){
  int usedActors = 0;
  for(auto it=assignment.begin(); it!=assignment.end(); ++it ){
    if(it->size() > 0){
      ++usedActors;
    }
  }

  cout << usedActors << "\n";
  int actorNumber=0;
  for(auto it=assignment.begin(); it!=assignment.end(); ++it ){
    if(it->size() > 0){
      cout << actorNumber+1 << " ";
      cout << it->size() << " ";
      for(auto it2 = it->begin(); it2 != it->end(); ++it2){
        cout << *it2+1 << " ";
      }
      cout << "\n";
    }
    ++actorNumber;
  }  
}


void verifySolution(){
  //the divas have been casted (linear)

  assert(assignment[0].size() > 0);
  assert(assignment[1].size() > 0);
  //Check that the divas don't meet (constant)
  for(auto it = assignment[0].begin(); it != assignment[0].end(); ++it){
    for(auto it2 = assignment[1].begin(); it2 != assignment[1].end(); ++it2){
      assert(!contains(conflictRoles[*it],*it2));
    }
  }
  //Check that no actor has conflict between actors (quadratic)
  for(int i=0; i < k+n; ++i){
    for(auto it = assignment[i].begin(); it != assignment[i].end(); ++it){
      for(auto it2 = assignment[i].begin(); it2 != assignment[i].end(); ++it2){
        if(*it != *it2){
          assert(!contains(conflictRoles[*it],*it2));
        }
      }
    }
  }
}


void readInput(){
  cin >> n >> s >> k;

  actors = vector<vector<int>>(k,vector<int>(0));
  conflictRoles = vector<vector<int>>(n,vector<int>(0));
  assignment = vector<vector<int>>(k+n,vector<int>(0));
  //read actors for each role
  for(int i=0; i < n; ++i){      
    int numActorsForRole=0;
    cin >> numActorsForRole;
    
    int actor;
    for(int j=0; j < numActorsForRole; ++j){
      cin >> actor;
      //OFFSET BECAUSE VIGGO ÄR GALEN
      actors[actor-1].push_back(i);
      
    }
  }

  //Read actors for each scene
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
    //add all other actors in the scene to conflict list
    for(int j=0; j < numRolesInScene; ++j){
      for(int k=0; k < numRolesInScene; ++k){
        if(k!=j && !contains(conflictRoles[temp[j]],temp[k]))
          conflictRoles[temp[j]].push_back(temp[k]);
      }
    }
  }


}

void printAssignment(){
  cout << "________________\n";
  cout << "PRINTING ASSIGNMENT\n";
  int i=0;
  for(auto it=assignment.begin(); it != assignment.end();++it){
    cout << i << "=";
    for(auto it2=it->begin(); it2 != it->end(); ++it2){
        cout << *it2 << " ";
    }
    ++i;
    cout <<"\n";
  }
  cout << "FINISHED PRINTING ASSIGNMENT\n";
  cout << "________________\n";
}

void printRoles(){
  cout << "________________\n";
  cout << "PRINTING ROLES\n";
  int i=0;
  for(auto it=actors.begin(); it != actors.end();++it){
    cout <<"actor "<< i << "=";
    for(auto it2=it->begin(); it2 != it->end(); ++it2){
        cout << *it2 << " ";
    }
    ++i;
    cout <<"\n";
  }
  cout << "FINISHED PRINTING ROLES\n";
  cout << "________________\n";
}


void printConflict(){
  cout << "________________\n";
  cout << "PRINTING CONFLICT\n";
  int offset=0;
  for(auto it=conflictRoles.begin(); it != conflictRoles.end(); ++it){
    cout << "roll=" << offset << " conf with: ";
    for(auto wat= it->begin(); wat != it->end(); ++wat){
      cout << *wat << " ";
    }
    cout << "\n";
    ++offset;
  }
  cout << "FINISHED PRINTING CONFLICT\n";
  cout << "________________\n";
}