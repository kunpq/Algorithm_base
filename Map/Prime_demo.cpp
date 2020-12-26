#include "./lib/EntryTable.h"
#include <iostream>
using namespace std;
int main(void) {
  Table T;
  Adjlist_map map;
  InitTable(0, map.map, T);
  Prime(T);
  Display(T);
  return 0;
}