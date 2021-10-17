#include "train.h"

void ticket::READING(local_time *local_time_arr, ticket *array, ifstream &file, int N){
  for(int i = 0; i < N; i++){
      file >> array[i].train;
      file.ignore();
      getline(file, array[i].station1);
      getline(file, array[i].station2);
      getline(file, local_time_arr[i].ticket_date);
      getline(file, local_time_arr[i].ticket_time);
      file >> array[i].coach;
      file >> array[i].seat;
      file >> array[i].price;
      //file.ignore();
  }
}

void ticket::OUTPUTIN(local_time *local_time_arr, ticket *array, int N){
  for(int i = 0; i < N; i++){
      cout << array[i].train << " ";
      cout << array[i].station1 << " ";
      cout << array[i].station2 << " ";
      cout << local_time_arr[i].ticket_date << " ";
      cout << local_time_arr[i].ticket_time << " ";
      cout << array[i].coach << " ";
      cout << array[i].seat << " ";
      cout << array[i].price << " " << endl;
  }
}

void ticket::MOST_EXPENSIVE(local_time *local_time_arr, ticket *array, int N) {
  int max_price = -1;
  int max_i = 0;
  for (int i = 0; i < N; i++) {
    if (array[i].price > max_price) 
    {
      max_price = array[i].price;
      max_i = i;
    }
  }
  cout << "most expensive ticket's cost is " << max_price << endl;
  cout << "all info about the ticket: " << endl;
  cout << array[max_i].train << " ";
  cout << array[max_i].station1 << " ";
  cout << array[max_i].station2 << " ";
  cout << local_time_arr[max_i].ticket_date << " ";
  cout << local_time_arr[max_i].ticket_time << " ";
  cout << array[max_i].coach << " ";
  cout << array[max_i].seat << " " << endl;
}

void ticket::VACANT_SEATS(local_time *local_time_arr, ticket *array, int N) {
  struct tm;
  string s_temp;
  int doubleS_temp;
  int i, temp;
  int k = 5;
  cout << "Input train's number: ";
  cin >> temp;
  while((temp >= 1000)||(temp <= 0)) {
    cout << "Enter correct train's number" << endl;
    cin >> temp;
  }
  cout << "Input date of departure: ";
  cin >> s_temp;
  while(!checkTime(s_temp)) {
    cout << "Enter correct date" << endl;
    cin >> s_temp;
  }
  cout << "Input coach: ";
  cin >> doubleS_temp;
  while((doubleS_temp >= 10)||(temp <= 0)) {
    cout << "Enter correct coach's number" << endl;
    cin >> doubleS_temp;
  }
  for (i = 0; i < N; i++)
  {
    if((temp == array[i].train)&&(s_temp == local_time_arr[i].ticket_date)&&(doubleS_temp == array[i].coach)) {
      k--;
    }
  }
  if (k == 5) {
     cout << "There are no such trains" << endl;
  }
  else {
     cout << "Number of vacant seats for such criteria = " << k << endl;
  }
}
   bool checkTime(string const& input) {
    regex validTime("^([0]?[1-9]|[1|2][0-9]|[3][0|1])[./-]([0]?[1-9]|[1][0-2])[./-]([0-9]{4}|[0-9]{2})$");
    return regex_match(input, validTime);
}
