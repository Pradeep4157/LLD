#include <bits/stdc++.h>
using namespace std;

/*
Classes :

City
- id
- name

Theater
- id
- city_id
- name
- address

Screen
- id
- name
- theater_id
- total_seat

Movie
- id
- name
- genre
- duration
- language

Seat
- id
- screen_id
- row_num
- seat_num

ShowSeat
- id
- show_id
- seat_id
- status

Booking
- id
- show_id
- amount
- status

User
*/

class BookMyShowService
{
public:
    auto searchMovies() {}
    auto listShowForMovie() {}
    auto getSeatLayout() {}
    auto createBooking() {}
    auto cancelBooking() {}
};

signed main()
{
}