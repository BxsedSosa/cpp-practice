class Player {
private:
  int chips;
  int bet;
  int guess;

public:
  void setChips(int chips) { this->chips = chips; }
  void setGuess();
  void setBet();

  int getChips() { return chips; }
  int getBet();
  int getGuess();
};
