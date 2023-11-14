#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


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



    ~TicketManager() {

    }

};

int TicketManager::uniqueIdCounter = 1; // Initialize static member variable

int main() {
	cout << endl << "Hello World, updated .cpp file!";
}