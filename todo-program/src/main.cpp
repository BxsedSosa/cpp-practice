#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string mainMenu(void) {
  string userAnswer;
  cout << "Welcome to To-Do Manager" << '\n';
  cout << '\n' << "1. Create new 'to-do' project" << '\n';
  cout << "2. Edit 'to-do' project" << '\n';
  cout << "3. Delete 'to-do' project" << '\n' << ">> ";
  cin >> userAnswer;

  return userAnswer;
}

string getFile(void) {
  string name;

  cout << "Edit a 'to-do' project" << '\n';
  cout << '\n' << "Please enter name of project" << '\n' << ">> ";
  cin >> name;

  stringstream fileName;
  fileName << name << ".md";

  return fileName.str();
}

string getProjectName(void) {
  string projectName;
  cout << "Creating a new 'to-do' project" << '\n';
  cout << '\n' << "Please enter name of project:" << '\n' << ">> ";
  cin >> projectName;

  return projectName;
}

void createFile(string projectName) {
  stringstream fileName;
  fileName << projectName << ".md";

  ofstream outputfile(fileName.str());
  outputfile << "# " + projectName << '\n';
  outputfile.close();
}

void readFile(string fileName) {
  ifstream file(fileName);
  string line;

  if (file.is_open()) {
    while (getline(file, line)) {
      cout << line << '\n';
    }
    file.close();
  } else {
    cerr << "Unable to open file";
  }
}

int main(void) {
  string userAnswer = mainMenu();

  if (userAnswer == "1") {
    string projectName = getProjectName();
    createFile(projectName);
  }

  if (userAnswer == "2") {
    string fileName = getFile();
    readFile(fileName);
  }

  if (userAnswer == "3") {
  }

  return 0;
}
