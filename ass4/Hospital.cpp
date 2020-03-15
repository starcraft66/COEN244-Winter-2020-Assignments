#include "Hospital.hpp"
#include "InPatient.hpp"
#include "Bed.hpp"
#include <iostream>

Hospital::Hospital()
{
    this->inpatients_ = {nullptr};
    this->beds_ = {nullptr};
    this->doctors_ = {nullptr};
}

std::array<InPatient*, 500>& Hospital::GetInPatients()
{
    return this->inpatients_;
}

std::array<Doctor*, 100>& Hospital::GetDoctors()
{
    return this->doctors_;
}

std::array<Bed*, 500>& Hospital::GetBeds()
{
    return this->beds_;
}

void Hospital::AddInPatient(InPatient*& inpatient)
{
    bool found = false;
    for (Bed*& ptr : this->beds_)
    {
        if (ptr != nullptr && !ptr->GetOccupied())
        {
            ptr->SetOccupied(true);
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Invalid Bed";
        exit(1);
    }
    bool inserted = false;
    for (InPatient*& ptr : this->inpatients_)
    {
        if (ptr != nullptr && ptr->GetId() == inpatient->GetId())
        {
            std::cout << "Duplicate InPAtient!";
            exit(1);
        }
        if (ptr == nullptr)
        {
            if (!inserted)
            {
                ptr = inpatient;
                inserted = true;
            }
        }
    }
    if (!inserted)
    {
        std::cout << "InPatient Limit Reached";
        exit(1);
    }
}

void Hospital::DeleteInPatient(int id)
{
    bool deleted = false;
    for (InPatient*& ptr : this->inpatients_)
    {
        if (ptr != nullptr && ptr->GetId() == id)
        {
            for (Bed*& ptr2 : this->beds_)
            {
                if (ptr2 != nullptr && ptr2->GetId() == ptr->GetBedNumber())
                {
                    ptr2 = nullptr;
                }
            }
            ptr = nullptr;
            deleted = true;
        }
    }
    if (!deleted)
    {
        std::cout << "InPatient Not Found";
        exit(1);
    }
}

void Hospital::AddDoctor(Doctor*& doctor)
{
    bool inserted = false;
    for (Doctor*& ptr : this->doctors_)
    {
        if (ptr != nullptr && ptr->GetId() == doctor->GetId())
        {
            std::cout << "Duplicate Doctor!";
            exit(1);
        }
        if (ptr == nullptr)
        {
            if (!inserted)
            {
                ptr = doctor;
                inserted = true;
            }
        }
    }
    if (!inserted)
    {
        std::cout << "Doctor Limit Reached";
        exit(1);
    }
}

void Hospital::DeleteDoctor(int id)
{
    bool deleted = false;
    for (Doctor*& ptr : this->doctors_)
    {
        if (ptr != nullptr && ptr->GetId() == id)
        {
            ptr = nullptr;
            deleted = true;
        }
    }
    if (!deleted)
    {
        std::cout << "Doctor Not Found";
        exit(1);
    }
}

void Hospital::AddBed(Bed*& bed)
{
    bool inserted = false;
    for (Bed*& ptr : this->beds_)
    {
        if (ptr != nullptr && ptr->GetId() == bed->GetId())
        {
            std::cout << "Duplicate Bed!";
            exit(1);
        }
        if (ptr == nullptr)
        {
            if (!inserted)
            {
                ptr = bed;
                inserted = true;
            }
        }
    }
    if (!inserted)
    {
        std::cout << "Bed Limit Reached";
        exit(1);
    }
}

void Hospital::DeleteBed(int id)
{
    bool deleted = false;
    for (Bed*& ptr : this->beds_)
    {
        if (ptr != nullptr && ptr->GetId() == id)
        {
            ptr = nullptr;
            deleted = true;
        }
    }
    if (!deleted)
    {
        std::cout << "Doctor Not Found";
        exit(1);
    }
}

void Hospital::Print()
{
    std::cout << "Hospital{inpatients=[";
    for (int i = 0; i < this->inpatients_.size(); i++)
    {
        bool flag = false;
        if (this->inpatients_[i] != nullptr)
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                std::cout << ",";
            }
            this->inpatients_[i]->Print();
        }
    }
    std::cout << "],beds=[";
    for (int i = 0; i < this->inpatients_.size(); i++)
    {
        bool flag = false;
        if (this->beds_[i] != nullptr)
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                std::cout << ",";
            }
            this->beds_[i]->Print();
        }
    }
    std::cout << "],doctors=[";
    for (int i = 0; i < this->doctors_.size(); i++)
    {
        bool flag = false;
        if (this->doctors_[i] != nullptr)
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                std::cout << ",";
            }
            this->doctors_[i]->Print();
        }
    }
    std::cout << "]}";
}