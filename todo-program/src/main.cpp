#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

string mainMenu(void) {
  string userAnswer;
  cout << "Welcome to To-Do Manager" << '\n';
  cout << '\n' << "1. Create new 'to-do' project" << '\n';
  cout << "2. Edit 'to-do' project" << '\n';
  cout << "3. Delete 'to-do' project" << '\n' << ">> ";
  cin >> userAnswer;

  return userAnswer;
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

string getFile(void) {
  string name;

  cout << "Edit a 'to-do' project" << '\n';
  cout << '\n' << "Please enter name of project" << '\n' << ">> ";
  cin >> name;

  stringstream fileName;
  fileName << name << ".md";

  return fileName.str();
}

string getDocumentDirectoryPath() {
  fs::path currentPath = fs::current_path();

  stringstream path(currentPath);
  vector<std::string> brokenPaths;
  std::string brokenPath;

  while (getline(path, brokenPath, '/')) {
    brokenPaths.push_back(brokenPath);
  }

  string home = brokenPaths[1];
  string user = brokenPaths[2];
  string documentPath = "/" + home + "/" + user + "/" + "Documents/todos/";

  return documentPath;
}

string getProjectName(void) {
  string projectName;
  cout << "Creating a new 'to-do' project" << '\n';
  cout << '\n' << "Please enter name of project:" << '\n' << ">> ";
  cin >> projectName;

  return projectName;
}

void createTodoFolder() {
  string documentPath = getDocumentDirectoryPath();

  if (!filesystem::exists(documentPath)) {
    filesystem::create_directory(documentPath);
  }
}

void createNewProject(string projectName) {
  createTodoFolder();
  string filePath = getDocumentDirectoryPath();
  stringstream fileName;
  fileName << filePath << projectName << ".md";

  ofstream outputfile(fileName.str());
  outputfile << "# " + projectName << '\n';
  outputfile.close();
}

int main(void) {
  string userAnswer = mainMenu();

  if (userAnswer == "1") {
    string projectName = getProjectName();
    createNewProject(projectName);
  }

  if (userAnswer == "2") {
    string fileName = getFile();
    readFile(fileName);
  }

  if (userAnswer == "3") {
  }

  return 0;
}
