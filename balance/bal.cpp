#include <iostream>
#include <sstream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void typewriterEffect(const string& text, int delay) {
  for (char c : text) {
    cout << c << flush;
    this_thread::sleep_for(chrono::milliseconds(delay));
  }
}


main() {

  cout << endl;

  int cardOptions;
  string userAnswer;

  string message;
  message = "Welcome to Quantum, what kind of card will you be using today? \n";
  int delay = 45;

  typewriterEffect(message, delay);
  cout << endl;
  cout << "- Bank Of America (1)\n- Mastercard (2) \n- Chase Bank (3) \n- Wells Fargo (4) \n- Citibank (5) \n";
  cout << endl;

  cout << "Enter an option 1-5: ";
  cin >> cardOptions;
  cout << endl;

  switch(cardOptions) {
    case 1:
      cout << "You've picked Bank Of America, is this correct (yes/no): ";
      break;

    case 2:
      cout << "You've picked Mastercard, is this correct (yes/no): ";
      break;

    case 3:
      cout << "You've picked Chase Bank, is this correct (yes/no): ";
      break;

    case 4: 
      cout << "You've picked Wells Fargo, is this correct (yes/no): ";
      break;

    case 5:
      cout << "You've picked Citibank, is this correct (yes/no): ";
      break;
    default:
      cout << "The option you've picked is invalid, please pick a valid option!";
      return 1;
  }

  cin >> userAnswer;
  transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

  int pin;
  ifstream inputFile("pin.txt");

  cout << endl;

  if(inputFile) {
    inputFile >> pin;
    inputFile.close();
    cout << "Your pin has been loaded successfully. ";
  } else {
    cout << "You have no previous pins created. Please create a new pin! \n";
    cout << "Create a pin using FOUR digits: ";
    cin >> pin;
    ofstream outputFile("pin.txt");
    outputFile << pin;
    outputFile.close();
    cout << "Your pin has been saved successfully! \n ";
  }

  int inputedDigits;
  cout << "Please enter your four digit pin number to access your account: ";
  cin >> inputedDigits;

  cout << endl;

  if(inputedDigits == pin) {
    cout << "You have successfully accessed your account \n";
  } else {
    cout << "Error: You've entered the incorrect digits. Your account will remain locked";
    return 1;
  }

  cout << endl;

  if (cardOptions == 1) {
        message = "Your starting balance with Bank Of America is: 350";
    } else if (cardOptions == 2) {
        message = "Your starting balance with Mastercard is: 350";
    } else if (cardOptions == 3) {
        message = "Your starting balance with Chase Bank is: 350";
    } else if (cardOptions == 4) {
        message = "Your starting balance with Wells Fargo is: 350";
    } else if (cardOptions == 5) {
        message = "Your starting balance with Citibank is: 350";
    } else {
        std::cout << "Invalid choice, please try again";
        return 1;
    }

    for( char c : message) {
      cout << c << flush;
      this_thread::sleep_for(chrono::milliseconds(delay));
    }

  cout << endl;

  cout << endl;
  if(userAnswer == "yes") {
    cout << "Would you like to deposit or withdraw funds from Quantum (Deposit/Withdraw): ";
    cin >> userAnswer;
    transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
  } else if (userAnswer == "no") {
    cout << "Let's restart so you can pick a new card!" << endl;
    return 1;
  } else {
    cout << "Invalid choice please respond with 'yes' or 'no'" << endl;
    return 1;
  }

  cout << endl;

  float deposit = 0.00;
  float withdraw = 0.00;
  float userDeposit;
  float userWithdraw;
  float defaultValue = 350.00;
  float failedTransaction = 0.00;

  if (userAnswer == "deposit") {
    cout << "How much money would you like to deposit to Quantum: ";
    cin >> userDeposit;
    deposit += userDeposit + defaultValue;
    cout << "Your new balance after depositing into Quantum is: " << fixed << setprecision(2) << deposit << endl;
  } else if (userAnswer == "withdraw") {
    cout << "How much money would you like to withdraw from Quantum: ";
    cin >> userWithdraw;
    withdraw -= userWithdraw - defaultValue;
    cout << "Your new balance after withdrawing from Quantum is: " << fixed << setprecision(2) << withdraw << endl;
  } else {
    cout << "Invalid choice, please choose 'deposit' or 'withdraw'" << endl;
    return 1;
  }

  cout << endl;
 
  cout << "Thank you for using Quantum, hope to see you again!";
  cout << endl;

  cout << endl;
  return 0;



}