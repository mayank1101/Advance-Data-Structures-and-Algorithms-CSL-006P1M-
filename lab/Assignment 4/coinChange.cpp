#include<iostream>
#include<cstring>
using namespace std;

int minCoins(int coinsArr[], int amount, int numCoins)
{
  int table[amount+1];
  table[0] = 0; //for 0 amount we can make change with 0 coins
  for(int i=1;i<=amount;i++){ //initialize Minimum number of coins for each amount to be (amount+1)
    table[i] = amount+1;
  }
  for(int currAmount=1;currAmount<=amount;currAmount++) //loop through each amount
  {
    for(int currCoin=0;currCoin<numCoins;currCoin++){ //loop through coin with each denomination
      if(coinsArr[currCoin] <= currAmount){ //if current coin denomination is less than amount
        table[currAmount] = min(table[currAmount], table[currAmount-coinsArr[currCoin]]+1); //either include the coin or don't include it
      }
    }
  }
  return (table[amount]>amount)?-1:table[amount]; //if can not make change for the amount then return -1
}

int main()
{
  int amount,n;
  cout << "Enter the amount for which change need to be computed : ";
  cin>>amount;
  cout << "Enter the number of coins (assume each denomination has infinite supply) : ";
  cin>>n;
  int coinsArr[n];
  for(int i=0;i<n;i++){
    cout << "Enter the denomination of "<< i+1 << " coin : ";
    cin>>coinsArr[i];
  }
  cout << "Minimum number of coins : " << minCoins(coinsArr, amount, n) << "\n";
  return 0;
}
