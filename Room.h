#pragma once
#include <iostream>

class Room
{
	std::string roomNum, suite, vacancy; // Declarations of all needed strings.
	int price, occupancyLimit, rating; // Declarations of all needed intergers.

public:
	Room(); // Constructor
	Room(std::string Num, std::string suiteType, std::string vacancyStatus,
		int cost, int max_occupancy, int reviewScore); // Constructor with variables


	//Getters and setters
	std::string getRoomNum();
	std::string getSuite();
	std::string getVacancy();
	int getPrice();
	int getOccupancyLimit();
	int getRating();
	void setRoomNum(std::string newRoomNum);
	void setSuite(std::string newSuite);
	void setVacancy(std::string newVacancy);
	void setPrice(int newPrice);
	void setOccupancyLimit(int newOccupancyLimit);
	void setRating(int newRating);
};