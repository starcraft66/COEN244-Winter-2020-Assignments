#ifndef RESERVATION_MANAGER_H_
#define RESERVATION_MANAGER_H_
#include <array>
#include "ReservationRequest.hpp"
#include "Passenger.hpp"
class ReservationManager
{
    Date date_;
    int capacity_;
    int stations_;
    std::array<std::array<int, 0>, 0> reservation_table_;
    std::array<ReservationRequest*, 0>  reservation_requests_;
    std::array<Passenger*, 0>  passengers_;
public:
    ReservationManager();
    ReservationManager(Date, int, int);
    void SetDate(Date);
    Date GetDate();
    void SetCapacity(int);
    int GetCapacity();
    void SetStations(int);
    int GetStations();
    void ProcessReservationRequest(ReservationRequest);
    void PrintReservationRequestDetails(ReservationRequest);
    void DeleteAllReservationRequestsOnDate(Date);
    void CancelReservationRequestByNumber(int);
    void DeleteAllReservationRequestsFromPassengerOnDate(Passenger, ReservationRequest);
};
#endif