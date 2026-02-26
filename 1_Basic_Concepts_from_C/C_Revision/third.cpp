#include <iostream>
#include <string>
using namespace std;
double BTC_EUR(double);
double EUR_BTC(double);

int main(void) {
  std::cout << "SELECT CURRENCY(B for btc, E for euro)" << endl;
  string currency;
  std::cin >> currency;
  double coins = 0;
  std::cout << "ENTER COINS" << endl;
  std::cin >> coins;
  if (currency == "B") {
    std::cout << "BTC TO EUR " << BTC_EUR(coins) << endl;
  }
  else if(currency == "E")
    std::cout << "EUR TO BTC " << EUR_BTC(coins) << endl;
  else
    cout << "Whatever" << endl;
}
double BTC_EUR(double euro) { return 57000.0f * euro; }
double EUR_BTC(double btc) { return btc / 57000.0f; }
