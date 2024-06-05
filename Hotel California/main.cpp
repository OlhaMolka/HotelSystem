#include <iostream>
#include <algorithm> 
#include "Hotel.hpp"
#include "Room.hpp"
#include "Reservation.hpp"

Category inputCategory() {
    int category;
    std::cout << "Enter room category (0 for Standard, 1 for Comfort): ";
    std::cin >> category;
    return static_cast<Category>(category);
}

unsigned int inputDays() {
    unsigned int days;
    std::cout << "Enter the number of days (1-14): ";
    std::cin >> days;
    return days;
}

std::string inputClientID() {
    std::string clientID;
    bool validID = false;

    while (!validID) {
        std::cout << "Enter client ID (numeric only): ";
        std::cin >> clientID;

        if (std::all_of(clientID.begin(), clientID.end(), ::isdigit)) {
            validID = true;
        }
        else {
            std::cout << "Invalid client ID. Please enter a numeric client ID." << std::endl;
        }
    }

    return clientID;
}

int main() {
    std::cout << "Welcome to Hotel Reservation System" << std::endl;

    Hotel One("M", "street", 10, "phone");

    One.addRoom(Room(1, Standard));
    One.addRoom(Room(2, Comfort));
    One.addRoom(Room(3, Standard));
    One.addRoom(Room(4, Comfort));
    One.addRoom(Room(5, Standard));
    One.addRoom(Room(6, Comfort));
    One.addRoom(Room(7, Standard));
    One.addRoom(Room(8, Comfort));
    One.addRoom(Room(9, Standard));
    One.addRoom(Room(10, Comfort));

    const std::vector<std::string> clientIDs = {
        "1", "2", "3", "4", "5",
        "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15",
        "16", "17", "18", "19", "20"
    };

    for (const std::string& clientID : clientIDs) {
        One.createPayment(clientID, 5000); 
    }

    while (true) {
        int categoryInt = inputCategory();
        Category category = static_cast<Category>(categoryInt);

        unsigned int days = inputDays();
        std::string clientID = inputClientID();

        std::cout << "Enter start day (1-14): ";
        unsigned int startDay;
        std::cin >> startDay;

        std::cout << "Enter end day (1-14): ";
        unsigned int endDay;
        std::cin >> endDay;

        unsigned int pricePerNight = (category == Standard) ? 1000 : 1500;
        unsigned int totalPrice = pricePerNight * (endDay - startDay + 1);

        std::cout << "Client ID: " << clientID << "\nCategory: "
            << (category == Standard ? "Standard" : "Comfort")
            << "\nDays: " << endDay - startDay + 1
            << "\nTotal Price: " << totalPrice
            << "\nConfirm booking? (y/n): ";
        char confirm;
        std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
           
            if (std::find(clientIDs.begin(), clientIDs.end(), clientID) != clientIDs.end()) {
                Reservation reservation{ startDay, endDay, clientID, category };
                ReservationResult result = One.bookaRoom(reservation);

                std::cout << "Reservation success: " << result.Succeed
                    << "\nRoom number: " << result.RoomNumber
                    << "\nReservation ID: " << result.reservationID
                    << "\nMessage: " << result.message << std::endl;
            }
            else {
                std::cout << "Client ID does not exist in the system." << std::endl;
            }
        }
        else {
            std::cout << "Reservation canceled." << std::endl;
        }

        std::cout << "Do you want to make another reservation? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}

