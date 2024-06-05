#include "Hotel.hpp"
#include <iostream>

std::unordered_map<Category, unsigned int> PriceList = {
    {Standard, 1000},
    {Comfort, 1500}
};

Hotel::Hotel(const std::string& hotelName, const std::string& hotelAddress, unsigned int numRooms, const std::string& contact)
    : name(hotelName), address(hotelAddress), roomCount(numRooms), contactInfo(contact) {}

void Hotel::updateHotelInfo(const std::string& newName, const std::string& newAddress, unsigned int newRoomCount, const std::string& newContact) {
    name = newName;
    address = newAddress;
    roomCount = newRoomCount;
    contactInfo = newContact;
}

void Hotel::addRoom(const Room& room) {
    rooms.push_back(room);
}

ReservationResult Hotel::bookaRoom(Reservation reservation) {
    unsigned int totalPrice = PriceList[reservation.Cat] * (reservation.end - reservation.begin + 1);
    std::cout << "Total Price: " << totalPrice << std::endl;

    for (Room& room : rooms) {
        if (room.getCategory() == reservation.Cat && room.isAvailable(reservation.begin, reservation.end)) {
            std::cout << "Client Balance for " << reservation.clientID << ": " << clientBalance[reservation.clientID] << std::endl;
            if (clientBalance[reservation.clientID] >= totalPrice) {
                room.changeStatus(reservation.begin, reservation.end, false);
                clientBalance[reservation.clientID] -= totalPrice;
                return { true, room.getNumber(), "Reservation successful." };
            }
            else {
                room.changeStatus(reservation.begin, reservation.end, false);
                return { false, room.getNumber(), "", "Insufficient funds" };
            }
        }
    }
    return { false, 0, "", "No available rooms in the selected category." };
}

void Hotel::createPayment(const std::string& clientID, unsigned int amount) {
    clientBalance[clientID] += amount;
}
