#pragma once
#include <string>
#include "Room.hpp"

struct Reservation {
    unsigned int begin;
    unsigned int end;
    std::string clientID;
    Category Cat;
};

struct ReservationResult {
    bool Succeed;
    unsigned int RoomNumber;
    std::string reservationID;
    std::string message;
};
