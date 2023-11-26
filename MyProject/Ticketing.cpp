#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class MovieType { DOCUMENTARY = 10, ROMANCE = 20, ACTION = 30, DRAMA = 40, COMEDY = 50 };

class Ticket {
private:
    const int id;
    int roomNum = 0;
    int rowNum = 0;
    int seatNum = 0;
    string time = "";
    char* movieNames = nullptr;
    int noMovies = 0;

public:
    //getters
    int getRoomNum() {
        return this->roomNum;
    }
    int getRowNum() {
        return this->rowNum;
    }
    int getSeatNum() {
        return this->seatNum;
    }
    string getTime() {
        return this->time;
    }
    char* getMovieNames() {
        char* copyMovieNames = new char[this->noMovies];
        for (int i = 0; i < this->noMovies; i++) {
            copyMovieNames[i] = this->movieNames[i];
        }
        return copyMovieNames;
        //return this->movieNames;
    }
    int getNoMovies() {
        return this->noMovies;
    }
    //setters
    int setRoomNum(int newNum) {
        this->roomNum = newNum;
    }
    int setRowNum(int newRowNum) {
        this->rowNum = newRowNum;
    }
    int setSeatNum(int newSeatNum) {
        this->seatNum = newSeatNum;
    }
    string setTime(const string& newTime) {
        this->time = newTime;
    }
    char* setMovieNames(const char* newMovieNames, int newNoMovies) {
        delete[] this->movieNames;
        this->movieNames = new char[newNoMovies];
        //strcpy(this->movieNames, newMovieNames);
        for (int i = 0; i < newNoMovies; i++) {
            this->movieNames[i] = newMovieNames[i];
        }
        this->noMovies = newNoMovies;
    }
    
    //constructors
    Ticket():id(0){}
    Ticket(int id, int noRoom, int noRow, int noSeat): id(id) {
        this->setRoomNum(noRoom);
    }
    Ticket(int id, int noRoom, int noRow, int noSeat, string time, char* movieNames, int noMovieNames) : id(id) {
        this->setRoomNum(noRoom);
        this->setRowNum(noRow);
        this->setSeatNum(noSeat);
        this->setTime(time);
        this->setMovieNames(movieNames, noMovieNames);
        this->noMovies = noMovieNames;
    }
    //copy constructor
    Ticket(Ticket& ticket): id(0) {
        this->setRoomNum(ticket.roomNum);
        this->setRowNum(ticket.rowNum);
        this->setSeatNum(ticket.seatNum);
        this->setTime(ticket.time);
        this->setMovieNames(ticket.movieNames, ticket.noMovies);
    }
    //overloaded operator
    
    //destructor
    ~Ticket() {

    }
};

class Theatre {
private:
    int noSeats = 0;
    int noRows = 0;
    int noMovies = 0;
    char* movies = nullptr;
    char* theatreName = nullptr;

    static int freeSeatsPerRoom;
public:
    //getters
    int getMaxSeats() {
        return this->noSeats;
    }
    int getNumRows() {
        return this->noRows;
    }
    int getNoMovies() {
        return this->noMovies;
    }
    char* getMovies() {
        //return this->movies;
        char* copy = new char[strlen(this->movies) + 1];
        for (int i = 0; i < strlen(this->movies); i++) {
            copy[i] = this->movies[i];
        }
        return copy;
    }
    char* getTheatreName() {
        return this->theatreName;
    }
    //setters
    void setMaxSeats(int newNoSeat) {
        this->noSeats = newNoSeat;
    }
    void setNumRows(int newNoRows) {
        this->noRows = newNoRows;
    }
    void setMovies(const char* newMovies, int newNoMovies) {
        delete[] this->movies;
        this->movies = new char[newNoMovies];
        for (int i = 0; i < newNoMovies; i++) {
            this->movies[i] = newMovies[i];
        }
        this->noMovies = newNoMovies;
    }
    void setTheatreName(const char* newTheatreName) {
        delete[] this->theatreName;
        this->theatreName = new char[strlen(newTheatreName) + 1];
        strcpy(this->theatreName, newTheatreName);
    }
    //constructor
    Theatre() {}
    Theatre(const char* movies, int noMovies, const char* theatreName) {
        this->setMovies(movies, noMovies);
        this->noMovies = noMovies;
        this->setTheatreName(theatreName);
    }
    Theatre(int noSeats, int noRows, int noMovies, const char* movies, const char* theatreName) {
        this->setMaxSeats(noSeats);
        this->setNumRows(noRows);
        this->noMovies = noMovies;
        this->setMovies(movies, noMovies);
        this->setTheatreName(theatreName);
    }
    //copy constructor
    Theatre(Theatre& theatre) {
        this->setMaxSeats(theatre.noSeats);
        this->setNumRows(theatre.noRows);
        this->noMovies = theatre.noMovies;
        this->setMovies(theatre.movies, theatre.noMovies);
        this->setTheatreName(theatre.theatreName);
    }
    //destructor
    ~Theatre() {

    }
};
int Theatre::freeSeatsPerRoom = 150;

class Movie {
private:
    int roomNum = 0;
    bool hasFreePlace = true;
    char* movieName = nullptr;
    string time = "";
    MovieType type = MovieType::DOCUMENTARY;
public:
    //getters
    int getRoomNum() {
        return this->roomNum;
    }
    bool getHasFreePlace() {
        return this->hasFreePlace;
    }
    char* getMovieName() {
        char* newMovieName = new char[strlen(this->movieName) + 1];
        strcpy(newMovieName, this->movieName);
        return newMovieName;
        //return this->movieName;
    }
    string getTime() {
        return this->time;
    }
    MovieType getMovieType() {
        return this->type;
    }
    //setters
    void setRooNum(int newRoomNum) {
        this->roomNum = newRoomNum;
    }
    void setHasFreePlace(bool doesHaveFreePlace) {
        this->hasFreePlace = doesHaveFreePlace;
    }
    void setMovieName(const char* newMovieName) {
        delete[] this->movieName;
        this->movieName = new char[strlen(this->movieName) + 1];
        strcpy(this->movieName, newMovieName);
    }
    void setTime(const string& newTime) {
        this->time = newTime;
    }
    void setMovieType(MovieType t) {
        this->type = t;
    }
    //constructor
    Movie() {}
    Movie(bool hasFreePlace, const char* movieName, MovieType type) {
        this->setHasFreePlace(hasFreePlace);
        this->setMovieName(movieName);
        this->setMovieType(type);
    }
    Movie(int roomNum, bool hasFeePlace, const char* movieName, const string& time, MovieType type) {
        this->setRooNum(roomNum);
        this->setHasFreePlace(hasFeePlace);
        this->setMovieName(movieName);
        this->setTime(time);
        this->setMovieType(type);
    }
    //copy constructor
    Movie(Movie& movie) {
        this->setRooNum(movie.roomNum);
        this->setHasFreePlace(movie.hasFreePlace);
        this->setMovieName(movie.movieName);
        this->setTime(movie.time);
        this->setMovieType(movie.type);
    }
    //destructor
    ~Movie() {

    }
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