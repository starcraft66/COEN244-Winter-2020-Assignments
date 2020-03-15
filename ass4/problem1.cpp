#include "InPatient.hpp"
#include "OutPatient.hpp"
#include "Doctor.hpp"
#include "Bed.hpp"
#include "Hospital.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Bed *bed1 = new Bed(0, false);
    Bed *bed2 = new Bed(1, false);
    Bed *bed3 = new Bed(2, false);
    Bed *bed4 = new Bed(3, false);
    Bed *bed5 = new Bed(4, false);
    Doctor *d1 = new Doctor(0, "69", "Dr. Evil", "Lazer Beams");
    Doctor *d2 = new Doctor(1, "420", "Dr. Lion", "Medical Marijuana");
    InPatient *ip1 = new InPatient(0, "mommy", Date(2,2,2020), Date(2,3,2020), d1, 0, 9999.99);
    InPatient *ip2 = new InPatient(1, "mommy", Date(2,2,2020), Date(2,3,2020), d2, 1, 9999.99);
    InPatient *ip3 = new InPatient(2, "mommy", Date(2,2,2020), Date(2,3,2020), d1, 2, 9999.99);
    InPatient *ip4 = new InPatient(3, "mommy", Date(2,2,2020), Date(2,3,2020), d2, 3, 9999.99);
    OutPatient *op1 = new OutPatient(0, "mommy", Date(2,2,2020), Time(12, 0, 0), 9999.99, d1);
    OutPatient *op2 = new OutPatient(1, "mommy", Date(2,2,2020), Time(12, 0, 0), 9999.99, d2);
    OutPatient *op3 = new OutPatient(2, "mommy", Date(2,2,2020), Time(12, 0, 0), 9999.99, d1);
    OutPatient *op4 = new OutPatient(3, "mommy", Date(2,2,2020), Time(12, 0, 0), 9999.99, d2);
    Hospital *h = new Hospital();
    h->AddDoctor(d1);
    h->AddDoctor(d2);
    h->AddBed(bed1);
    h->AddBed(bed2);
    h->AddBed(bed3);
    h->AddBed(bed4);
    h->AddBed(bed5);
    h->AddInPatient(ip1);
    h->AddInPatient(ip2);
    h->AddInPatient(ip3);
    h->AddInPatient(ip4);
    for (Bed*& bed : h->GetBeds())
    {
        if (bed != nullptr)
        {
            bed->Print();
            std::cout << std::endl;
        }
    }
    for (InPatient*& ip : h->GetInPatients())
    {
        if (ip != nullptr)
        {
            ip->Print();
            std::cout << std::endl;
        }
    }
    for (Doctor*& doc : h->GetDoctors())
    {
        if (doc != nullptr)
        {
            doc->Print();
            std::cout << std::endl;
        }
    }
    h->Print();
    return 0;
}