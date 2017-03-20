#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  char buf[5];
  if (!(cin >> buf)) {
    cout << "Error\n";
    return EXIT_FAILURE;
  }
  //cin >> buf;
  //cout << cin;
  cout << buf << endl;
}
