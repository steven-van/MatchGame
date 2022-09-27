// @brief Fill the array with nbMatches matches
// @param tabMatches, nbMatches
extern void createMatches(int tabMatches[], int nbMatches);

// @brief Check if the match at the index position can be removed
// @param tabMatches, index, length
// @return 1 if true and 0 if false
extern int canRemoveMatch(int tabMatches[], int index, int length);

// @brief Count the remaining removable matches
// @param tabMatches, length
// @return the remaining removable matches
extern int getRemainingMatches(int tabMatches[], int length);

// @brief Ask the player choose the number of matches to remove
// between [1;maxToRemove] and [1;maxRemovable] if maxRemovable < maxToRemove
// @param maxToRemove, maxRemovable
// @return the number of matches the player wants to remove
extern int playerChoice(int maxToRemove, int maxRemovable);

// @brief : Remove the match at the <index> position
// @param : tabMatches, index
extern void removeMatch(int tabMatches[], int index);

// @brief Check if the current player has won
// (i.e the number of remaining matches is equal to 1)
// @param tabMatches, length
// @return 1 if true and 0 if false
extern int isWinGame(int tabMatches[], int length);

// @brief : Check if the current player has lost
// (i.e the number of remaining matches is equal to 0)
// @param tabMatches, length
// @return 1 if true and 0 if false
extern int isLoseGame(int tabMatches[], int length);

// Check if the game is finished
// (i.e the number of remaining matches is equal to 0 or 1)
// @param tabMatches, length
// @return 1 if true and 0 if false
extern int isEndGame(int tabMatches[], int length);

// @brief Get the computer choice of matches to remove
// @param max, remaining
// @return the number of matches the computer wants to remove
extern int aiChoice(int max, int remaining);

// @brief Print the array of matches
// @param tabMatches, length
extern void displayMatches(int tabMatches[], int length);

// @brief Generate a random number between [min;max[
// @param min, max
// @return number between [min;max[
extern int randomRange(int min, int max);

// @brief Game against a naïve computer
extern void onePlayerNaive();

// @brief Game against two smart computers
extern void computerGame();

// @brief Game between two players
extern void twoPlayersGame();

// @brief Game against a smart computer
extern void onePlayerSmart();
