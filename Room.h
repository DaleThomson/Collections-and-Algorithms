#pragma once
#include <iostream>

class Room
{
	std::string roomNum, suite, vacancy; // Declarations of all needed strings.
	int price, occupancyLimit, rating; // Declarations of all needed intergers.

public:
	Room(std::string roomNum, std::string suite, std::string vacancy,
		int price, int occupancyLimit, int rating) : suite(suite), vacancy(vacancy),
		price(price), occupancyLimit(occupancyLimit), rating(rating) {} // Constructor

	std::string getRoomNum()
	{
		return roomNum;
	}

	std::string getSuite()
	{
		return suite;
	}

	std::string getVacancy()
	{
		return vacancy;
	}

	int getPrice()
	{
		return price;
	}

	int getOccupancyLimit()
	{
		return occupancyLimit;
	}

	int getRating()
	{
		return rating;
	}

	void setRoomNum(std::string newRoomNum)
	{
		roomNum = newRoomNum;
	}

	void setSuite(std::string newSuite)
	{
		suite = newSuite;
	}

	void setVacancy(std::string newVacancy)
	{
		vacancy = newVacancy;
	}

	void setPrice(int newPrice)
	{
		price = newPrice;
	}

	void setOccupancyLimit(int newOccupancyLimit)
	{
		occupancyLimit = newOccupancyLimit;
	}

	void setRating(int newRating)
	{
		rating = newRating;
	}

};