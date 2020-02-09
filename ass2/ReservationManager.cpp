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

ReservationManager::ReservationManager(Date date, int, int)
{
    this->date_ = date;
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

void ReservationManager::ProcessReservationRequest(ReservationRequest reservation_request)
{
    int seats_requested = reservation_request.GetSeats();
    int start_id = DestinationNameToID(reservation_request.GetStart());
    int destination_id = DestinationNameToID(reservation_request.GetDest());
    int increment = destination_id - start_id;
    if (increment < 1)
    {
        throw "invalid trip";
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
            throw "Not enough seats available!";
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
    for (int i; i < this->passengers_.size(); i++)
    {
        if (this->passengers_[i]->GetPerson() == reservation_request.GetPerson())
        {
            pers_exists = true;
            this->passengers_[i]->AddTrip(reservation_request.GetNumber());
            break;
        }
    }
    if(!pers_exists)
    {
        bool pers_assigned = false;
        for (int i; i < this->passengers_.size(); i++)
        {
            if (this->passengers_[i] == nullptr)
            {
                this->passengers_[i] = new Passenger(reservation_request.GetPerson());
                pers_assigned = true;
                break;
            }
        }
        if (!pers_assigned)
        {
            throw "not enough space for people";
        }
    }
    for (int i = 0; i < this->reservation_requests_.size(); i++)
    {
        if (this->reservation_requests_[i] == nullptr)
        {
            this->reservation_requests_[i] = &reservation_request;
            return;
        }
    }
    throw "too many reservation requests";
}

void ReservationManager::PrintReservationRequestDetails(ReservationRequest reservation_request)
{

}

void ReservationManager::DeleteAllReservationRequestsOnDate(Date date)
{
    for (ReservationRequest* req : this->reservation_requests_)
    {
        if (req->GetDate() == date)
        {
            for (Passenger* p : this->passengers_)
            {
                if (p->GetPerson() == req->GetPerson())
                {
                    delete p;
                    p = nullptr;
                }
            }
            delete req;
            req = nullptr;
        }
    }
}

void ReservationManager::CancelReservationRequestByNumber(int id)
{
    for (ReservationRequest* req : this->reservation_requests_)
    {
        if (req->GetNumber() == id)
        {
            for (Passenger* p : this->passengers_)
            {
                if (p->GetPerson() == req->GetPerson())
                {
                    delete p;
                    p = nullptr;
                }
            }
            delete req;
            req = nullptr;
        }
    }
}

void ReservationManager::DeleteAllReservationRequestsFromPassengerOnDate(Passenger passenger, Date date)
{
    for (ReservationRequest* req : this->reservation_requests_)
    {
        if (req->GetDate() == date && req->GetPerson() == passenger.GetPerson())
        {
            delete req;
            req = nullptr;
        }
    }
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
    Person* p1 = new Person("your mom", Date(1,1,1));
    ReservationRequest* r1 = new ReservationRequest(*p1, Date(2,2,2), "Montreal", "Toronto", 2);
    return 0;
}