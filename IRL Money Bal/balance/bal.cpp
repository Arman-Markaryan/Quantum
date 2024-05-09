#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>

using namespace std;

void typewriterEffect(const std::string& text, int delay) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}



main() {

  cout << endl;

  int cardOptions;
  string userAnswer;

  string message = "Welcome to Quantum, what kind of card will you be using today? \n";
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


  double BankOfAmericaBalance = 0.00;
  double MastercardBalance = 0.00;
  double ChaseBankBalance = 0.00;
  double WellsFargoBalance = 0.00;
  double CitibankBalance = 0.00;

  cout << endl;

  string baseValue = "$350";

  if (cardOptions == 1) {
        cout << "Your starting balance with Bank Of America is: " << baseValue << endl;
    } else if (cardOptions == 2) {
        cout << "Your starting balance with Mastercard is: " << baseValue << endl;
    } else if (cardOptions == 3) {
        cout << "Your starting balance with Chase Bank is: " << baseValue << endl;
    } else if (cardOptions == 4) {
        cout << "Your starting balance with Wells Fargo is: " << baseValue << endl;
    } else {
        cout << "Your starting balance with Citibank is: " << baseValue << endl;
    }

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
  

  double deposit = 0.00;
  double withdraw = 0.00;
  int userDeposit;
  int userWithdraw;
  double defaultValue = 350.00;
  double failedTransaction = 0.00;

  cout << endl;


  if(userAnswer == "deposit") {
    cout << "How much money would you like to deposit to Quantum: ";
    cin >> userDeposit;
    deposit += userDeposit + defaultValue;
    cout << "Your new balance after depositing into Quantum is: " << deposit << endl;
  } else if (userAnswer == "withdraw") {
    cout << "How much money would you like to withdraw from Quantum: ";
    cin >> userWithdraw;
    withdraw -= userWithdraw - defaultValue;
    cout << "Your new balance after withdrawing from Quantum is: " << withdraw << endl;
  }

  cout << "Thank you for using Quantum, hope to see you again!";
  system("pause");
  cout << endl;

  return 0;
}