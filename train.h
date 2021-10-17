#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <regex>

using namespace std;

bool checkTime(string const& input);

        struct local_time {
        string ticket_time;
        string ticket_date;
};

class ticket {
    private:
    unsigned int train;
    string station1;
    string station2;
    unsigned int coach, seat, price;

    public:
    void READING(local_time *local_time_arr, ticket *array, ifstream &file, int N);
    void OUTPUTIN(local_time *local_time_arr, ticket *array, int N);
    void MOST_EXPENSIVE(local_time *local_time_arr, ticket *array, int N);
    void VACANT_SEATS(local_time *local_time_arr, ticket *array, int N);
};



/* struct ticket {
   int train; 
   string station1, station2;
   int coach, seat, price;
}; */



/*
void READING(local_time *local_time_arr, ticket *array, ifstream &file, int N);
void OUTPUTIN(local_time *local_time_arr, ticket *array, int N);
void MOST_EXPENSIVE(local_time *local_time_arr, ticket *array, int N);
void VACANT_SEATS(local_time *local_time_arr, ticket *array, int N);

*/

#endif