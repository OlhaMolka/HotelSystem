#include "Room.hpp"
#include <cassert>

Room::Room(unsigned int num, Category cat) : number(num), Cat(cat), Status(14, true) {}

void Room::changeStatus(unsigned int begin, unsigned int end, bool availability) {
    assert(begin < end && "Begin date must be less than end date");
    assert(begin >= 1 && end <= 14 && "Dates must be within the range 1 to 14");
    for (unsigned int i = begin - 1; i < end; i++) {
        Status[i] = availability;
    }
}

std::string Room::getRoomInfo() const {
    std::string categoryStr = (Cat == Standard) ? "Standard" : "Comfort";
    return "Room Number: " + std::to_string(number) + "\nCategory: " + categoryStr;
}

bool Room::isAvailable(unsigned int begin, unsigned int end) const {
    assert(begin < end && "Begin date must be less than end date");
    assert(begin >= 1 && end <= 14 && "Dates must be within the range 1 to 14");
    for (unsigned int i = begin - 1; i < end; i++) {
        if (!Status[i]) {
            return false;
        }
    }
    return true;
}

Category Room::getCategory() const {
    return Cat;
}

unsigned int Room::getNumber() const {
    return number;
}
