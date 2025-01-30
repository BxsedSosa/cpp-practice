class Casino {
private:
  int maxRange;
  int randomNumber;

public:
  void setMaxRange(int maxRange) { this->maxRange = maxRange; }
  int getRandomNumber() { return randomNumber; }
  int givePlayerChips() { return 100; }
};
