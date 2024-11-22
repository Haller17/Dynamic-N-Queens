#include <cmath>
#include <iostream>
using namespace std;
bool ok(int arr[], int b) {
  for (int i = 0; i < b; i++) {
    if (arr[i] == arr[b] || ((b - i) == (abs(arr[i] - arr[b]))))
      return false;
  }
  return true;
}
int nqueens(int n) {
  int *q = new int[n];
  int c = 0, solutions = 0;
  q[0] = 0;

  while (c >= 0) {
    if (c == n - 1) {
      solutions++;
      c--;
    } else {
      c++;
      q[c] = -1;
    }

    while (c >= 0) {
      q[c]++;
      if (q[c] == n) {
        c--;
      } else if (ok(q, c)) {
        break;
      }
    }
  }
  delete[] q;

  return solutions;
}
int main() {
  int a;
  
cout<<"Enter the amount of queens: "<<endl;
cin>>a;
  
  cout << "There are " << nqueens(a) << " solutions to the " << a
       << " queens problem." << endl;
  }
  return 0;
}