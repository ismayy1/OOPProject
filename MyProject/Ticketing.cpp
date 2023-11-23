#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class MovieType { DOCUMENTARY = 10, ROMANCE = 20, ACTION = 30, DRAMA = 40, COMEDY = 50 };

class Ticket {
    int roomNum = 0;
    int rowNum = 0;
    int seatNum = 0;
    string time = "";
    char* movieName = nullptr;
};

class Theatre {
    int maxSeats = 0;
    int numRows = 0;
    char* movies = nullptr;
    char* theatreName = nullptr;
};

class Movie {
    int roomNum = 0;
    char* movieName = nullptr;
    string time = "";
    MovieType type = MovieType::DOCUMENTARY;
};


class TicketManager {
private:
    int maxSeats = 0;
    int numRows = 0;
    int numZones = 0;
    int seatsPerRow = 0;

    char* eventName = nullptr;
    string eventDate = "";
    string eventTime = "";

    static int uniqueIdCounter; // Static member to maintain a unique ID counter
    const int ticketId; // Member variable for the ticket ID

public:
    TicketManager() :ticketId(0) {}

    TicketManager(int ticketId, int maxSeats, int numRows, int numZones, int seatsPerRow, char* eventName, string eventDate, string eventTime)
        :ticketId(ticketId) {

    }

    void setMaxSeats(int newMaxSeats) {
        this->maxSeats = newMaxSeats;
    }
    void setNumRows(int newNumRows) {
        this->numRows = newNumRows;
    }
    void setNumZones(int newNumZones) {
        this->numZones = newNumZones;
    }
    void setSeatsPerRow(int newSeatsPerRow) {
        this->seatsPerRow = newSeatsPerRow;
    }
    void setEventName(const char* newEventName) {
        delete[] this->eventName; //prevent memory leak
        this->eventName = new char[strlen(newEventName) + 1];
        strcpy(this->eventName, newEventName);
    }
    void setEventDate(const string& newEventDate) {
        this->eventDate = newEventDate;
    }
    void setEventTime(const string& newEventTime) {
        this->eventTime = newEventTime;
    }

    ~TicketManager() {

    }

};

int TicketManager::uniqueIdCounter = 1; // Initialize static member variable

int main() {
	cout << endl << "Hello World, updated .cpp file!";
}