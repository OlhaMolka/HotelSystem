#pragma once
#include <vector>
#include <string>
#include "Room.hpp"
#include "Reservation.hpp"
#include <unordered_map>

class Hotel {
    std::string name;
    std::string address;
    unsigned int roomCount;
    std::vector<Room> rooms;
    std::string contactInfo;
    std::unordered_map<std::string, unsigned int> clientBalance;
    unsigned int reservationCounter;

public:
    Hotel(const std::string& hotelName, const std::string& hotelAddress, unsigned int numRooms, const std::string& contact);

    void updateHotelInfo(const std::string& newName, const std::string& newAddress, unsigned int newRoomCount, const std::string& newContact);

    void addRoom(const Room& room);

    ReservationResult bookaRoom(Reservation reservation);

    void createPayment(const std::string& clientID, unsigned int amount);
};
