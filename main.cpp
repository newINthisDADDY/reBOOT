#include "train.h"

int main() {
  int N;
  ticket *nomenclature;
  local_time *local_time_arr;
  ifstream infile;
  infile.open("ooplab3_1.txt");
  infile >> N;
  cout << "Tickets number = " << N << endl;
  nomenclature = new ticket[N];
  local_time_arr = new local_time[N];
  nomenclature->READING(local_time_arr, nomenclature, infile, N);
  infile.close();
  nomenclature->OUTPUTIN(local_time_arr, nomenclature, N);
  nomenclature->MOST_EXPENSIVE(local_time_arr, nomenclature, N);
  nomenclature->VACANT_SEATS(local_time_arr, nomenclature, N);
  delete[] nomenclature;
  delete[] local_time_arr;
  return 0;
}
