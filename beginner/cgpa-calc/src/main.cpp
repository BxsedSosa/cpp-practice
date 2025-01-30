#include <iostream>
#include <vector>

std::vector<int> getTenthPlace(std::vector<int> grades) {
  for (int i = 0; i < grades.size(); i++) {
    grades[i] = grades[i] / 10;
  }

  return grades;
}

std::vector<int> getGrade(int classes) {
  std::vector<int> grades;

  for (int i = 0; i < classes; i++) {
    int grade;
    std::cout << "Enter in grade for class #" << i + 1 << ":\n>>> ";
    std::cin >> grade;
    grades.push_back(grade);
  }

  return grades;
}

float getGradeSum(std::vector<int> grades) {
  float sum = 0;

  for (int num : grades) {
    sum += num;
  }

  return sum;
}

float calculcateCGPAPercentage(float cgpa) { return cgpa * 9.5; }

float calculcateCGPA(std::vector<int> grades) {
  float sum = getGradeSum(getTenthPlace(grades));

  return sum / grades.size();
}

int main() {
  int classes;

  std::cout << "How many classes have you taken?:\n>>> ";
  std::cin >> classes;

  std::vector<int> grades = getGrade(classes);
  float cgpa = calculcateCGPA(grades);
  float percent = calculcateCGPAPercentage(cgpa);

  std::cout << "CGPA = " << cgpa << ", Percentage = " << percent << '\n';

  return 0;
}
