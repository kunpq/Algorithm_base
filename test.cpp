#include <fstream>
#include <iostream>
using namespace std;
void readd();
int main(void) {
  int a = 100;
  if (a > 237) {
    printf("%d", a);
  } else {
    putchar('d');
    putchar('\n');
  }
  readd();
  return 0;
}
void readd() {
  int a;
  int s;
  ifstream file("data.txt");

  while (!file.eof()) {
    file >> s;
    if (file.fail()) {
      cout << "Mismatch" << endl;
      //   file.clear();
      file >> s;
      //   file.clear()
      if (!file.eof()) {
        cout << s << endl;
      }
    } else {
      cout << s << " ";
    }
  }
  cout << endl;
  cout << "唐赢坤" << endl;
  file.close();
}