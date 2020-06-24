#include "Room.h"

Room::Room()
{

}

Room::Room(std::string num, std::string suiteType, std::string vacancyStatus,
	int cost, int max_occupancy, int reviewScore)
{
	roomNum = num;
	suite = suiteType;
	vacancy = vacancyStatus;
	price = cost;
	occupancyLimit = max_occupancy;
	rating = reviewScore;
}

std::string Room::getRoomNum()
{
	return roomNum;
}

std::string Room::getSuite()
{
	return suite;
}

std::string Room::getVacancy()
{
	return vacancy;
}

int Room::getPrice()
{
	return price;
}

int Room::getOccupancyLimit()
{
	return occupancyLimit;
}

int Room::getRating()
{
	return rating;
}

void Room::setRoomNum(std::string newRoomNum)
{
	roomNum = newRoomNum;
}

void Room::setSuite(std::string newSuite)
{
	suite = newSuite;
}

void Room::setVacancy(std::string newVacancy)
{
	vacancy = newVacancy;
}

void Room::setPrice(int newPrice)
{
	price = newPrice;
}

void Room::setOccupancyLimit(int newOccupancyLimit)
{
	occupancyLimit = newOccupancyLimit;
}

void Room::setRating(int newRating)
{
	rating = newRating;
}