#include <iostream>
//#include <algorithms>
#include <vector>
#include <assert.h>
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void readInput();

void stupidStuff();
void greedyStuff();
void trySwitch(int);
void localSearch();

void printAssignment();
void printRoles();
void printSolution();

void verifySolution();

bool assign_divas(int);
int countUsedActors(vector<vector<int>> &);
bool checkForConflict(int possibleRole, int actor);
bool checkForDivaConflict(int possibleRole, int actor);



// List of roles each actor can play
// index in outer list = actor
vector<vector<int>> roles;

vector<vector<int>> roles_in_scene;
vector<vector<int>> scenes_for_role;

//index in outer vector is actor
// inner vector contains which roles actor plays
vector<vector<int>> assignment;

vector<int> assigned;

// #roles, scenes, actors
// minimum 1, 1, 2
int n, s, k;
// We can use n-1 "superactors" who can play any role, but only ONE role at a time
// They have numbers k+1, k+2, ... k+n




int main(){
  srand(time(NULL));
  //rand() % n - random number between 0 and n 

  readInput();

  stupidStuff();

  //local search with
  //Simulated annealing
  greedyStuff();

  //For testing
  //verifySolution();
  for(int i = 0; i < k; ++i)
    trySwitch(i);
  printSolution();
}


void trySwitch(int prevActor){
  int newActor = -1;
  int switchRole = assignment[prevActor].back();
  assignment[prevActor].pop_back();

  for(int i=k; i < k+n; ++i){
    if(assignment[i].size() == 0){
      assignment[i].push_back(switchRole);
      assigned[switchRole] = i;
      newActor = i;
      break;
    }
  }
  bool conflict = false;
  
  for(int actor = 0; actor < k; ++actor){
    if(actor == prevActor)
      continue;
    for(auto role = roles[actor].begin(); role != roles[actor].end(); ++role){
      int possibleRole = *role;
      if(possibleRole != switchRole)
        continue;

      //cout  << "possibleRole = " << possibleRole << "\n actor = " << actor << "\n";
      conflict = checkForConflict(possibleRole,actor);
      
      if(!conflict){
        assignment[newActor].pop_back();

        assignment[actor].push_back(possibleRole);
        assigned[possibleRole] = actor;

        //If the old solution was better, revert
        /*if(usedActors < countUsedActors(assignment)){
          assignment[assigned[possibleRole]].pop_back();
          assignment[prevActor].push_back(possibleRole);
          assigned[possibleRole] = prevActor;
        }*/

        //to break the loop
        greedyStuff();
        return;
      }
      conflict = false;
    }
  }
}


void greedyStuff(){

  //int usedActors = countUsedActors(assignment);
  bool conflict = false;


  for(int actor = 0; actor < k; ++actor){
    for(auto role = roles[actor].begin(); role != roles[actor].end(); ++role){
      int possibleRole = *role;
      int prevActor = assigned[possibleRole];

      if(prevActor == 0 || prevActor == 1)
        continue;


      conflict = checkForConflict(possibleRole,actor);
      
      if(!conflict){
        for(auto it = assignment[prevActor].begin(); it != assignment[prevActor].end(); ++it){
         if(*it == possibleRole){
            assignment[prevActor].erase(it);
            break;
          }
        }
        assignment[actor].push_back(possibleRole);
        assigned[possibleRole] = actor;

        //If the old solution was better, revert
        /*if(usedActors < countUsedActors(assignment)){
          assignment[assigned[possibleRole]].pop_back();
          assignment[prevActor].push_back(possibleRole);
          assigned[possibleRole] = prevActor;
        }*/
      }
      conflict = false;
    }
 }
    

}

bool checkForConflict(int possibleRole, int actor){
  if(actor == 0 || actor == 1)
    return checkForDivaConflict(possibleRole, actor);

  for(auto otherRole = assignment[actor].begin(); otherRole != assignment[actor].end(); ++otherRole){
    for(auto scene=scenes_for_role[*otherRole].begin(); scene != scenes_for_role[*otherRole].end(); ++scene ){
      for(auto scene_role = roles_in_scene[*scene].begin(); scene_role != roles_in_scene[*scene].end();  ++scene_role){
        if(*scene_role == possibleRole){
          return true;
        }
      }
    }
  }
  return false;
}

void stupidStuff(){
  
  //Assign the divas
  int i=0;
  while(!assign_divas(i)){
    ++i;
  }
  assigned[assignment[0][0]] = 0;
  assigned[assignment[1][0]] = 1;

  int superactor = k;
  for(int role=0; role < n; ++role){
    if(assigned[role] == -1){
      assignment[superactor].push_back(role);
      assigned[role] = superactor;
      ++superactor;
    }
  }
}


bool assign_divas(int i){
  int j=0;
  bool conflict = false;
  while(i <  roles[0].size() && j < roles[1].size()){
    if(roles[0][i] != roles[1][j]){
      for(auto it = scenes_for_role[roles[0][i]].begin(); it != scenes_for_role[roles[0][i]].end(); ++it){
        for(auto it2 = roles_in_scene[*it].begin(); it2 != roles_in_scene[*it].end(); ++it2){
          if(*it2 == roles[1][j]){
            conflict = true;
          }
        } 
      }
     
      if(!conflict){
        assignment[0].push_back(roles[0][i]);
        assignment[1].push_back(roles[1][j]);
        return true;
      }
      conflict = false;
    }
    ++j;
  }

  return false;
}


void printSolution(){
  int usedActors = countUsedActors(assignment);

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



void readInput(){
  cin >> n >> s >> k;

  roles = vector<vector<int>>(k,vector<int>(0));
  roles_in_scene = vector<vector<int>>(s,vector<int>(0));
  scenes_for_role = vector<vector<int>>(n,vector<int>(0));
  assignment = vector<vector<int>>(k+n,vector<int>(0));

  assigned = vector<int>(n);
  for(auto it=assigned.begin(); it != assigned.end(); ++it){
    *it = -1;
  }

  //read actors for each role
  for(int i=0; i < n; ++i){      
    int numActorsForRole=0;
    cin >> numActorsForRole;
    
    int actor;
    for(int j=0; j < numActorsForRole; ++j){
      cin >> actor;
      //OFFSET BECAUSE VIGGO ÄR GALEN
      roles[actor-1].push_back(i);
      
    }
  }

  //Read actors for each scene
  for(int i=0; i < s; ++i){
    int numRolesInScene=0;
    cin >> numRolesInScene;
    int role;
    for(int j=0; j < numRolesInScene; ++j){
      cin >> role;

      //OFFSET BECAUSE VIGGO ÄR GALEN
      roles_in_scene[i].push_back(role-1);
      scenes_for_role[role-1].push_back(i);
    }
  }


}


int countUsedActors(vector<vector<int>> & vec){
  int usedActors = 0;
  for(auto it=vec.begin(); it!=vec.end(); ++it ){
    if(it->size() > 0){
      ++usedActors;
    }
  }
  return usedActors;
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
  for(auto it=roles.begin(); it != roles.end();++it){
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


bool checkForDivaConflict(int possibleRole, int actor){
  int other_diva = 0;

  if(actor == 0){
    other_diva = 1;
  }else if(actor == 1){
    other_diva = 0;
  }

  for(auto otherRole = assignment[actor].begin(); otherRole != assignment[actor].end(); ++otherRole){
    for(auto scene=scenes_for_role[*otherRole].begin(); scene != scenes_for_role[*otherRole].end(); ++scene ){
      for(auto scene_role = roles_in_scene[*scene].begin(); scene_role != roles_in_scene[*scene].end();  ++scene_role){
        if(*scene_role == possibleRole || assigned[*scene_role] == other_diva){
          return true;
        }
      }
    }
  }

  for(auto scene=scenes_for_role[possibleRole].begin(); scene != scenes_for_role[possibleRole].end(); ++scene ){
    for(auto scene_role = roles_in_scene[*scene].begin(); scene_role != roles_in_scene[*scene].end();  ++scene_role){
      if(assigned[*scene_role] == other_diva){
        return true;
      }
    }
  }

  return false;
}

