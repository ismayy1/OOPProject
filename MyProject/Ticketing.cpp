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

    void printTicket() {
        cout << endl << "Room number: " << this->getRoomNum();
        cout << endl << "Row number: " << this->getRowNum();
        cout << endl << "Seat number: " << this->getSeatNum();
        cout << endl << "Time of the movie: " << this->getTime();
        cout << endl << "Names of the available movies: " << this->getMovieNames();
        cout << endl << "Number of the available movies:" << this->getNoMovies();
    }
    //copy constructor
    Ticket(const Ticket& ticket): id(0) {
        this->setRoomNum(ticket.roomNum);
        this->setRowNum(ticket.rowNum);
        this->setSeatNum(ticket.seatNum);
        this->setTime(ticket.time);
        this->setMovieNames(ticket.movieNames, ticket.noMovies);
    }
    //overloaded operators
    void operator=(const Ticket& ticket) {
        if (&ticket == this) {
            return;
        }
        delete[] this->movieNames;
        this->setMovieNames(ticket.movieNames, ticket.noMovies);
    }
    //destructor
    ~Ticket() {

    }
    //math operator
    Ticket operator+(int value) {
        Ticket t = *this;
        t.roomNum += value;
        return t;
    }
    bool operator!() {
        return this->noMovies > 0;
    }
    bool operator>(int value) {
        if (this->roomNum > value) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator==(int id) {
        if (this->id == id) {
            return true;
        }
        else {
            return false;
        }
    }
    //input stream operator
    friend ostream& operator<<(ostream& console, Ticket& t);

    void operator>>(istream& console) {
        cout << endl << "Room number is: ";
        console >> this->roomNum;
        cout << endl << "Row number: ";
        console >> this->rowNum;
        cout << endl << "Seat number: ";
        console >> this->seatNum;
    }
};

ostream& operator<<(ostream& console, Ticket& t) {
    console << endl << "Room number: " << t.getRoomNum();
    console << endl << "Row number: " << t.getRowNum();
    console << endl << "Seat Number: " << t.getSeatNum();
    console << endl << "Movie time: " << t.getTime();
    return console;
}

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

    void printTheatre() {
        cout << endl << "Number of seats: " << this->getMaxSeats();
        cout << endl << "Number of rows: " << this->getNumRows();
        cout << endl << "Number of movies: " << this->getNoMovies();
        cout << endl << "Available movie names: " << this->getMovies();
        cout << endl << "Theatre name: " << this->getTheatreName();
    }
    //copy constructor
    Theatre(Theatre& theatre) {
        this->setMaxSeats(theatre.noSeats);
        this->setNumRows(theatre.noRows);
        this->noMovies = theatre.noMovies;
        this->setMovies(theatre.movies, theatre.noMovies);
        this->setTheatreName(theatre.theatreName);
    }
    //math opeartors
    Theatre operator+(int value) {
        Theatre t = *this;
        t.noMovies += value;
        return t;
    }
    bool operator!() {
        return this->freeSeatsPerRoom >= 0;
    }
    bool operator>(int value) {
        if (this->noSeats > value) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator==(int value) {
        if (this->noSeats >= value) {
            return true;
        }
        else {
            return false;
        }
    }

    //destructor
    ~Theatre() {

    }
    //<< & >> operators
    friend void operator<<(ostream& console, Theatre& t);

    void operator>>(istream& console) {
        cout << endl << "Number of seats: ";
        console >> this->noSeats;
        cout << endl << "Number of Rows: ";
        console >> this->noRows;
        cout << endl << "Number of movies: ";
        console >> this->noMovies;
    }
};
int Theatre::freeSeatsPerRoom = 150;

void operator<<(ostream& console, Theatre& t) {
    console << endl << "Number of seats: " << t.getMaxSeats();
    console << endl << "Number of Rows: " << t.getNumRows();
    console << endl << "Number of movies: " << t.getNoMovies();
    console << endl << "Available Movies: " << t.getMovies();
    console << endl << "Theatre name: " << t.getTheatreName();
}

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
        this->movieName = new char[strlen(newMovieName) + 1];
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
    Movie(int roomNum, bool hasFreePlace, const char* movieName, const string& time, MovieType type) {
        this->setRooNum(roomNum);
        this->setHasFreePlace(hasFreePlace);
        this->setMovieName(movieName);
        this->setTime(time);
        this->setMovieType(type);
    }

    void printMovie() {
        cout << endl << "Room number: " << this->roomNum;
        cout << endl << "Free place is available: " << this->hasFreePlace;
        cout << endl << "Movie name: " << this->movieName;
        cout << endl << "Time of the movie: " << this->time;
        cout << endl << "Type of the movie: " << this->getTime();
    }
    //copy constructor
    Movie(Movie& movie) {
        this->setRooNum(movie.roomNum);
        this->setHasFreePlace(movie.hasFreePlace);
        this->setMovieName(movie.movieName);
        this->setTime(movie.time);
        this->setMovieType(movie.type);
    }
    //math operators
    void operator=(const Movie& value) {
        if (this == &value) {
            return;
        }
        this->setRooNum(value.roomNum);
        this->setTime(value.time);
        this->setMovieName(value.movieName);
    }
    Movie operator+(int val) {
        Movie res = *this;
        res.roomNum += val;
        return res;
    }
    bool operator!() {
        return this->hasFreePlace;
    }
    bool operator>(int val) {
        if (this->roomNum != val) {
            return false;
        }
        else {
            return true;
        }
    }
    bool operator==(Movie m) {
        if (this->roomNum == m.roomNum && this->movieName == m.movieName) {
            return true;
        }
        else {
            return false;
        }
    }

    //destructor
    ~Movie() {

    }

    //<< & >> operators
    friend void operator<<(ostream& console, Movie& m);

    void operator>>(istream& console) {
        cout << endl << "Room nr: ";
        console >> this->roomNum;
        cout << endl << "Movie name: ";
        console >> this->movieName;
    }
};

void operator<<(ostream& console, Movie& m) {
    console << endl << "Room nr: " << m.getRoomNum();
    console << endl << "Movie name: " << m.getMovieName();
    console << endl << "Time of the movie: " << m.getTime();
}


int main() {
	cout << endl << "Hello World, updated .cpp file!";
}