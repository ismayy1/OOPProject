#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class TicketManager {
private:
    int maxSeats;
    int numRows;
    int numZones;
    int seatsPerRow;

    string eventName;
    string eventDate;
    string eventTime;

    static int uniqueIdCounter; // Static member to maintain a unique ID counter
    int ticketId; // Member variable for the ticket ID
};

int TicketManager::uniqueIdCounter = 1; // Initialize static member variable

int main() {
	cout << endl << "Hello World, updated .cpp file!";
}