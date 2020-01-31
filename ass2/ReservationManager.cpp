#include <string>
#include "ReservationManager.hpp"

ReservationManager::ReservationManager()
{

}

ReservationManager::ReservationManager(Date, int, int)
{

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

void ProcessReservationRequest(ReservationRequest reservation_request)
{

}

void PrintReservationRequestDetails(ReservationRequest reservation_request)
{

}

void DeleteAllReservationRequestsOnDate(Date date)
{

}

void CancelReservationRequestByNumber(int id)
{

}

void DeleteAllReservationRequestsFromPassengerOnDate(Passenger passenger, ReservationRequest reservation_request)
{

}

int main(int argc, char *argv[])
{
    return 0;
}