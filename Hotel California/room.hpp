#pragma once
#include <vector>
#include <string>

enum Category {
    Standard,
    Comfort
};

class Room {
    unsigned int number;
    Category Cat;
    std::vector<bool> Status;

public:
    Room(unsigned int num, Category cat);

    void changeStatus(unsigned int begin, unsigned int end, bool availability);

    std::string getRoomInfo() const;

    bool isAvailable(unsigned int begin, unsigned int end) const;

    Category getCategory() const;

    unsigned int getNumber() const;
};
