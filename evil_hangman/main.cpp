#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cctype>
#include <assert.h>
using namespace std;



set<string> used_families;

bool in_alphabet(char c);
map<string,vector<string>> * get_word_families(char guess, string family, vector<string> & words);
bool letter_used(char c, vector<char>& used_letters);

int main(int argc, char const *argv[]) {

  used_families = set<string>();
  int guesses = 24;
  cout << "How many letters?\n";
  int length;
  cin >> length;

  vector<string> words;
  vector<char> used_letters;
  ifstream in_file("dictionary.txt");
  string word;
  while(in_file.good()){
    in_file >> word;
    if(word.length() == length)
      words.push_back(word);
  }

  if(words.empty()){
    cout << "There are no words with that length!\n";
    return 0;
  }

  char guess;
  string family = "";
  for(int i=0;i<length;++i){
    family.push_back('-');
  }

  while(guesses!=0){
    cout << family << "\n";
    cout << "Remaining guesses: " << guesses << "\n";
    cout << "Remaining words: " << words.size() << "\n";
    cout << "Used letters: ";
    for(auto it=used_letters.begin();it!=used_letters.end();++it){
      cout << char(toupper(*it)) << ", ";
    }
    cout << "\nEnter a letter: \n";
    cin >> guess;


    if(!in_alphabet(guess)){
      cout << "Non-alphabetic character!\n";
      continue;
    }

    if(letter_used(guess,used_letters)){
      cout << "You've already used that letter!\n";
      continue;
    }
    used_letters.push_back(guess);

    map<string,vector<string>> * word_families = get_word_families(guess,family,words);
    
    vector<string> new_words = (*word_families)[family];
    int family_size = new_words.size();
    
    for(auto fam_it=used_families.begin();fam_it!=used_families.end();++fam_it){
      vector<string> fam_words = (*word_families)[*fam_it];
      if(fam_words.size() > family_size){
        family = *fam_it;
        new_words = fam_words;
        family_size = new_words.size();
      }
    }

    used_families = set<string>();

    delete word_families;
    words = new_words;
    --guesses;
  }

  return 0;
}

bool in_alphabet(char c){
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  for(int i=0;i<alphabet.length();++i){
    if(alphabet[i] == c)
      return true;
  }

  return false;
}

bool letter_used(char c, vector<char>& used_letters){
  for(auto it=used_letters.begin(); it!=used_letters.end();++it){
    if(*it == c)
      return true;
  }
  return false;

}

map<string,vector<string>> * get_word_families(char guess, string family, vector<string> & words){
  map<string,vector<string>> * word_families = new map<string,vector<string>>();
  stringstream ss;
  for(auto it = words.begin(); it!=words.end();++it){
    string word = *it;
    for(int i=0;i<word.length();++i){
      if(family[i] == '-'){
        if(word[i] == guess){
          ss << guess;
        }else{
          ss << "-";
        }
      }else{
        ss << family[i];
      }
    }
    string temp_family = ss.str();
    ss.str("");
    used_families.insert(temp_family);
    (*word_families)[temp_family].push_back(word);
    temp_family = "";
  }

  for(auto it=used_families.begin();it!=used_families.end();++it){
    vector<string> vec = (*word_families)[*it];
    cout << "Family: " << *it << "\n";
    for(auto iter=vec.begin();iter!=vec.end();++iter){
      cout << *iter << ", ";
    }
    cout <<"\n";
  }
  return word_families;
}