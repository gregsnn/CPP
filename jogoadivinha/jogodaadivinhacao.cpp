#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  cout << "*********************************" << endl;
  cout << "* Welcome to the guessing game! *" << endl;
  cout << "*********************************" << endl;

  cout << "Choose your difficulty level:" << endl;
  cout << "Easy (E), Medium (M) or Hard (H)" << endl;

  char difficulty;
  cin >> difficulty;
  difficulty = toupper(difficulty);

  int number_of_tries;

  if (difficulty == 'E')
  {
    number_of_tries = 15;
  }
  else if (difficulty == 'M')
  {
    number_of_tries = 10;
  }
  else if (difficulty == 'H')
  {
    number_of_tries = 5;
  }
  else
  {
    cout << "Invalid difficulty level" << endl;
    cout << "The game will be played in the ultra hard level" << endl;
    number_of_tries = 3;
  }

  srand(time(NULL));
  const int SECRET_NUMBER = rand() % 100;
  int guess;
  int tries = 0;
  double points = 1000.0;

  bool not_hited = true;

  for (tries = 1; tries <= number_of_tries; tries++)
  {
    cout << "Try number: " << tries << endl;
    cout << "What is the secret number? ";
    cin >> guess;
    cout << "Your guess was: " << guess << endl;

    bool invalid_input = cin.fail() || guess < 0 || guess > 99;
    if (invalid_input)
    {
      cout << "You can only enter numbers between 0 and 99" << endl;
      cout << "********************************************" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      tries--;
      continue;
    }

    double lost_points = abs(guess - SECRET_NUMBER) / 2.0;
    points -= lost_points;

    const bool HIT = guess == SECRET_NUMBER;
    const bool BIGGER = guess > SECRET_NUMBER;

    if (HIT)
    {
      cout << "Congrats! You got it right!" << endl;
      not_hited = false;
      break;
    }
    else if (BIGGER)
    {
      cout << "Your guess was higher than the secret number" << endl;
      cout << "********************************************" << endl;
    }
    else
    {
      cout << "Your guess was lower than the secret number" << endl;
      cout << "*******************************************" << endl;
    }
  }

  cout << "End of the game!" << endl;

  if (not_hited)
  {
    cout << "You lost!, The secret number was: " << SECRET_NUMBER << ",  Try again!" << endl;
  }
  else
  {
    cout << "You got it right in " << tries << " tries" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Your score was: " << points << endl;
  }
}