#include <string>
#include <iostream>
#include "ReservationManager.hpp"

ReservationManager::ReservationManager()
{

}

ReservationManager::~ReservationManager()
{
    std::cout << "ReservationManager object deleted" << std::endl;
}

ReservationManager::ReservationManager(Date date, int capacity, int stations)
{
    this->reservation_table_ = { 0 };
    this->reservation_requests_ = { nullptr };
    this->passengers_ = { nullptr };
    this->date_ = date;
    this->capacity_ = capacity;
    this->stations_ = stations;
}

void ReservationManager::SetDate(Date date)
{
    this->date_ = date;
}

Date ReservationManager::GetDate()
{
    return this->date_;
}

void ReservationManager::SetCapacity(int capacity)
{
    this->capacity_ = capacity;
}

int ReservationManager::GetCapacity()
{
    return this-> capacity_;
}

void ReservationManager::SetStations(int stations)
{
    this->stations_ = stations;
}

int ReservationManager::GetStations()
{
    return this->stations_;
}

void ReservationManager::ProcessReservationRequest(ReservationRequest& reservation_request)
{
    int seats_requested = reservation_request.GetSeats();
    int start_id = DestinationNameToID(reservation_request.GetStart());
    int destination_id = DestinationNameToID(reservation_request.GetDest());
    int increment = destination_id - start_id;
    if (increment < 1)
    {
        std::cout << "invalid trip";
        exit(1);
        //throw "invalid trip";
    }
    for (int i = 0; i < increment; i++)
    {
        int seats_available = 0;
        for (int j = 0; j < this->reservation_table_[start_id + i].size(); j++)
        {
            if(this->reservation_table_[start_id + i][j] == 0)
            {
                seats_available++;
            }
        }
        if (seats_available < seats_requested){
            std::cout << "Not enough seats available!";
            exit(1);
            //throw "Not enough seats available!";
        }
    }
    for (int i = 0; i < increment; i++)
    {
        int counter = 0;
        for (int j = 0; j < this->reservation_table_[start_id + i].size() && counter < seats_requested; j++)
        {
            if(this->reservation_table_[start_id + i][j] == 0)
            {
                this->reservation_table_[start_id + i][j] = reservation_request.GetNumber();
                counter++;
            }
        }
    }
    
    bool pers_exists = false;
    for (int i = 0; i < this->passengers_.size(); i++)
    {
        if (this->passengers_[i] != nullptr && this->passengers_[i]->GetPerson() == reservation_request.GetPerson())
        {
            pers_exists = true;
            this->passengers_[i]->AddTrip(reservation_request.GetNumber());
            break;
        }
    }
    if(!pers_exists)
    {
        bool pers_assigned = false;
        for (int i = 0; i < this->passengers_.size(); i++)
        {
            std::cout << i << ": " << passengers_[i] << std::endl;
            if (this->passengers_[i] == nullptr)
            {
                this->passengers_[i] = new Passenger(reservation_request.GetPerson());
                pers_assigned = true;
                break;
            }
        }
        if (!pers_assigned)
        {
            std::cout << "not enough space for people";
            exit(1);
            //throw "not enough space for people";
        }
    }
    for (int i = 0; i < this->reservation_requests_.size(); i++)
    {
        if (this->reservation_requests_[i] == nullptr)
        {
            std::cout << "saved reservation request id " << reservation_request.GetNumber() << std::endl;
            this->reservation_requests_[i] = &reservation_request;
            return;
        }
    }
    std::cout << "too many reservation requests";
    exit(1);
    //throw "too many reservation requests";
}

void ReservationManager::PrintReservationRequestDetails(ReservationRequest& reservation_request)
{
    std::cout << "Reservation request id: " << reservation_request.GetNumber() << std::endl;
    std::cout << "Reservation request date: " << reservation_request.GetDate().GetDay() << "/" << reservation_request.GetDate().GetMonth() << "/" << reservation_request.GetDate().GetYear() << std::endl;
    std::cout << "Reservation request start: " << reservation_request.GetStart() << std::endl;
    std::cout << "Reservation request end: " << reservation_request.GetDest() << std::endl;
    std::cout << "Reservation request person: " << reservation_request.GetPerson().GetName() << ", born on " << reservation_request.GetPerson().GetDateOfBirth().GetDay() << "/" << reservation_request.GetPerson().GetDateOfBirth().GetMonth() << "/" << reservation_request.GetPerson().GetDateOfBirth().GetYear() << std::endl;
    std::cout << "Reservation request number of seats requested: " << reservation_request.GetSeats() << std::endl;
}

void ReservationManager::DeleteAllReservationRequestsOnDate(Date date)
{
    for (ReservationRequest* req : this->reservation_requests_)
    {
        if (req != nullptr && req->GetDate() == date)
        {
            delete req;
            req = nullptr;
        }
    }
}

void ReservationManager::CancelReservationRequestByNumber(int id)
{
    for (ReservationRequest* req : this->reservation_requests_)
    {
        if (req != nullptr && req->GetNumber() == id)
        {
            std::cout << "deleting reservation request number " << req->GetNumber() << std::endl;
            delete req;
            req = nullptr;
        }
    }
}

void ReservationManager::DeleteAllReservationRequestsFromPassengerOnDate(Passenger& passenger, Date date)
{
    for (ReservationRequest* req : this->reservation_requests_)
    {
        if (req != nullptr)
        {
            std::cout << req->GetPerson().GetName() << std::endl;
        }
        if (req != nullptr && req->GetDate() == date && req->GetPerson() == passenger.GetPerson())
        {
            std::cout << "deleting reservation request number " << req->GetNumber() << std::endl;
            delete req;
            req = nullptr;
        }
    }
    delete &passenger;
}

int ReservationManager::DestinationNameToID(std::string dest) const
{
    if (dest == "Montreal")
    {
        return 0;
    }
    else if (dest == "Dorval")
    {
        return 1;
    }
    else if (dest == "Brockville")
    {
        return 2;
    }
    else if (dest == "Kingston")
    {
        return 3;
    }
    else if (dest == "Belleville")
    {
        return 4;
    }
    else if (dest == "Toronto")
    {
        return 5;
    }
    return -1;
}

enum Destination
{
    Montreal = 0,
    Dorval = 1,
    Brockville = 2,
    Kingston = 3,
    Belleville = 4,
    Toronto = 5
};

int main(int argc, char *argv[])
{
    Person* p1 = new Person("mom", Date(1,1,1970));
    Person* p2 = new Person("mom1", Date(1,2,1970));
    Person* p3 = new Person("mom2", Date(1,3,1970));
    Person* p4 = new Person("mom3", Date(1,4,1970));
    Person* p5 = new Person("mom4", Date(1,5,1970));
    ReservationRequest* r1 = new ReservationRequest(*p1, Date(2,2,2020), "Montreal", "Toronto", 2);
    ReservationRequest* r2 = new ReservationRequest(*p2, Date(2,2,2020), "Brockville", "Kingston", 1);
    ReservationRequest* r3 = new ReservationRequest(*p3, Date(2,2,2020), "Belleville", "Toronto", 2);
    ReservationRequest* r4 = new ReservationRequest(*p4, Date(2,2,2020), "Dorval", "Kingston", 4);
    ReservationRequest* r5 = new ReservationRequest(*p5, Date(2,2,2020), "Montreal", "Dorval", 3);
    ReservationManager* rm = new ReservationManager();
    rm->ProcessReservationRequest(*r1);
    rm->ProcessReservationRequest(*r2);
    rm->ProcessReservationRequest(*r3);
    rm->ProcessReservationRequest(*r4);
    rm->ProcessReservationRequest(*r5);
    rm->PrintReservationRequestDetails(*r5);
    rm->DeleteAllReservationRequestsFromPassengerOnDate(*(new Passenger(*p1)), Date(2,2,2020));
    Person* p6 = new Person("mom5", Date(1,5,1970));
    Person* p7 = new Person("mom6", Date(1,6,1970));
    Person* p8 = new Person("mom7", Date(1,7,1970));
    Person* p9 = new Person("mom8", Date(1,8,1970));
    Person* p10 = new Person("mom9", Date(1,9,1970));
    ReservationRequest* r6 = new ReservationRequest(*p6, Date(2,2,2020), "Montreal", "Toronto", 2);
    ReservationRequest* r7 = new ReservationRequest(*p7, Date(2,2,2020), "Brockville", "Kingston", 1);
    ReservationRequest* r8 = new ReservationRequest(*p8, Date(2,2,2020), "Belleville", "Toronto", 2);
    ReservationRequest* r9 = new ReservationRequest(*p9, Date(2,2,2020), "Dorval", "Kingston", 4);
    ReservationRequest* r10 = new ReservationRequest(*p10, Date(2,2,2020), "Montreal", "Dorval", 3);
    rm->ProcessReservationRequest(*r6);
    rm->ProcessReservationRequest(*r7);
    rm->ProcessReservationRequest(*r8);
    rm->ProcessReservationRequest(*r9);
    rm->ProcessReservationRequest(*r10);
    rm->CancelReservationRequestByNumber(7);
    rm->CancelReservationRequestByNumber(8);
    rm->CancelReservationRequestByNumber(9);
    rm->DeleteAllReservationRequestsOnDate(Date(2,2,2020));
    //std::cout << (r1 == nullptr) << std::endl;
    return 0;
}