#pragma once
#include <iostream>

class Room
{
	std::string floor, type, rating, vacancy; // Declarations of all needed strings.
	int roomNumber, price, occupancyLimit; // Declarations of all needed intergers.

public:
	Room(std::string floor, std::string type, std::string rating, std::string vacancy,
		int roomNumber, int price, int occupancyLimit) : floor(floor), type(type), rating(rating), vacancy(vacancy),
		roomNumber(roomNumber), price(price), occupancyLimit(occupancyLimit) {} // Constructor


}; 