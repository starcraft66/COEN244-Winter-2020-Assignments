#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include "InPatient.hpp"
#include "Doctor.hpp"
#include "Bed.hpp"
#include <array>

class Hospital
{
    std::array<InPatient*, 500> inpatients_;
    std::array<Doctor*, 100> doctors_;
    std::array<Bed*, 500> beds_;
public:
    Hospital();
    void AddInPatient(InPatient*&);
    void DeleteInPatient(int);
    void AddDoctor(Doctor*&);
    void DeleteDoctor(int);
    void AddBed(Bed*&);
    void DeleteBed(int);
    void Print();
    std::array<InPatient*, 500>& GetInPatients();
    std::array<Doctor*, 100>& GetDoctors();
    std::array<Bed*, 500>& GetBeds();
};
#endif