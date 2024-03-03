#include <iostream>
#include <cstdlib>
#include <string>

//Group 54
//EG_2021_4434

using namespace std;

class vehicleRecord
{
public:
    string name;
    string vehicletype;
    int pickmonth;
    int pickdate;
    int dropmonth;
    int dropdate;
    int daysforrent;
    string vehicleid;
    vehicleRecord* next;
};

class Vehicle
{
public:
    vehicleRecord* head = NULL;
    void insert();

    void update();
    void search();
    void del();
    void sorttype();

    void show();
    void income();
    void searchandprice();
    void sorthighestDate();
    void sortpickupdate();


};


void Vehicle::insert()     //create a record
{
    string vid, vname, vtype;
    int  vpdate, vpmonth, vddate, vdmonth;
    cout << "\n\t_____Vehicle Rental Management System______";
    // Node* new_Node = new Node;
    cout << "\nEnter Vehicle ID (AA-0000) : ";
    cin >> vid;
    cout << "\nEnter Customer Name : ";
    cin >> vname;
    cout << "\nEnter Pickup Month Number (1-12) : ";
    cin >> vpmonth;
    while (vpmonth > 12 || vpmonth <= 0)
    {
        cout << "Invalid month number please renter valid month number : ";
        cin >> vpmonth;
    }
    cout << "\nEnter Pickup Date : ";
    cin >> vpdate;
    while (vpdate > 30 || vpdate <= 0)
    {
        cout << "Invalid date please renter valid date : ";
        cin >> vpdate;
    }
    cout << "\nEnter Drop off Month number (1-12) : ";
    cin >> vdmonth;
    while (vdmonth > 12 || vdmonth <= 0)
    {
        cout << "Invalid month number please renter valid month number : ";
        cin >> vdmonth;
    }
    cout << "\nEnter Drop off Date : ";
    cin >> vddate;
    while (vpdate > 30 || vpdate <= 0)
    {
        cout << "Invalid date please renter valid date : ";
        cin >> vddate;
    }

    cout << "\nEnter Vehicle Type (Bike/Car/Van/Cab/Bus) : ";
    cin >> vtype;

    vehicleRecord* new_Node = new vehicleRecord;           //creating new node
    new_Node->vehicleid = vid;
    new_Node->name = vname;
    new_Node->pickmonth = vpmonth;
    new_Node->pickdate = vpdate;
    new_Node->dropmonth = vdmonth;
    new_Node->dropdate = vddate;
    new_Node->vehicletype = vtype;

    if (new_Node->dropmonth - new_Node->pickmonth == 0)     //rent days calculate
    {
        new_Node->daysforrent = (new_Node->dropdate - new_Node->pickdate) + 1;
    }
    else if (new_Node->dropdate == new_Node->pickdate)
    {
        new_Node->daysforrent = 1;
    }
    else if ((new_Node->dropdate - new_Node->pickdate) < 0)
    {
        new_Node->daysforrent = (30 - new_Node->pickdate) + new_Node->dropdate + 1;
    }
    else
    {
        int month = new_Node->dropmonth - new_Node->pickmonth;
        new_Node->daysforrent = (month * 30) + (new_Node->dropdate - new_Node->pickdate) + 1;
    }


    if (head == NULL)
    {
        head = new_Node;
    }
    else
    {
        vehicleRecord* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_Node;
    }
    cout << "\n\n\t\tVehicle Record Successfully Inserted!" << endl;

}

void Vehicle::search()          //search and print
{
    cout << "\n\t_____Vehicle Rental Management System______";
    string searchvehid;
    if (head == NULL)
    {
        cout << "\nVehicle Records are Empty!";

    }
    else
    {
        cout << "\n\nEnter Vehicle ID : ";
        cin >> searchvehid;
        vehicleRecord* current = head;
        int found = 0;
        while (current != NULL)
        {
            if (searchvehid == current->vehicleid)        //search records
            {
                found = 1;

                cout << "\n\Vehicle ID : " << current->vehicleid;
                cout << "\n\nCustomer Name : " << current->name;
                cout << "\n\nVehicle Pick up Date : " << current->pickmonth << "/" << current->pickdate;
                cout << "\n\nVehicle Drop off Date : " << current->dropmonth << "/" << current->dropdate;
                cout << "\n\nVehicle Type : " << current->vehicletype;

            }
            current = current->next;
        }

        if (found == 0)
        {
            cout << "There is no recording for " << searchvehid;
        }
    }

}



//update the record

void Vehicle::update()
{
    cout << "\n\t_____Vehicle Rental Management System______";
    string updatervehd;
    cout << "\n\nEnter vehicle ID of the vehicle ID : ";
    cin >> updatervehd;
    if (head == NULL)
    {
        cout << "\nVehicle Records are empty";
    }
    else
    {
        vehicleRecord* current = head;
        int found = 0;
        while (current != NULL)
        {

            if (current->vehicleid == updatervehd)
            {
                found = 1;
                cout << "Vehicle ID : " << updatervehd << endl;        //entering new values
                cout << "\nEnter Vehicle ID (AA-0000) : ";
                cin >> current->vehicleid;
                cout << "\nEnter Customer Name : ";
                cin >> current->name;
                cout << "\nEnter Pickup Month Number (1-12) : ";
                cin >> current->pickmonth;
                while (current->pickmonth > 12 || current->pickmonth <= 0)
                {
                    cout << "Invalid month number please renter valid month number : ";
                    cin >> current->pickmonth;
                }
                cout << "\nEnter Pickup Date : ";
                cin >> current->pickdate;
                while (current->pickdate > 30 || current->pickdate <= 0)
                {
                    cout << "Invalid date please renter valid date : ";
                    cin >> current->pickdate;
                }
                cout << "\nEnter Drop off Month number (1-12) : ";
                cin >> current->dropmonth;
                while (current->dropmonth > 12 || current->dropmonth <= 0)
                {
                    cout << "Invalid month number please renter valid month number : ";
                    cin >> current->dropmonth;
                }
                cout << "\nEnter Drop off Date : ";
                cin >> current->dropdate;
                while (current->dropdate > 30 || current->dropdate <= 0)
                {
                    cout << "Invalid date please renter valid date : ";
                    cin >> current->dropdate;
                }
                cout << "\nEnter Vehicle Type (Bike/Car/Van/Cab) : ";
                cin >> current->vehicletype;
            }
            current = current->next;
        }
        if (found == 1)
        {
            cout << "Vehicle record updated Successfully" << endl;
        }
        else
        {
            cout << "There is no recording for " << updatervehd;
        }


    }



}


//delete a vehicle record

void Vehicle::del()
{
    cout << "\n\t_____Vehicle Rental Management System______";
    string delvehid;


    if (head == NULL)
    {
        cout << "\nVehicle Records are empty";
    }
    else
    {
        cout << "\n\nVehicle ID want to Delete : ";
        cin >> delvehid;

        if (delvehid == head->vehicleid)
        {
            vehicleRecord* temp = head;
            head = head->next;
            delete temp;
            cout << "\n\n\t\tDelete Vehicle Record Successfully!";
        }
        else
        {
            vehicleRecord* temp = head;
            vehicleRecord* pre = head;
            while (temp != NULL)
            {
                if (delvehid == temp->vehicleid)
                {
                    pre->next = temp->next;
                    delete temp;                                      //deleteing record
                    cout << "\n\n\t\tDelete Vehicle Record Successfully!";
                    break;
                }
                pre = temp;
                temp = temp->next;
            }
            cout << "\n\n\t\tDelete Vehicle Record Successfully!";
        }
    }
}

void Vehicle::show()          //show all records one by one
{
    cout << "\n\t_____Vehicle Rental Management System______";

    if (head == NULL)
    {
        cout << "\n\n\t\tNo Vehicle Records!";
    }
    else
    {
        vehicleRecord* temp = head;
        while (temp != NULL)
        {
            cout << "\n\nVehicle ID : " << temp->vehicleid;
            cout << "\nCustomer Name : " << temp->name;
            cout << "\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
            cout << "\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
            cout << "\nVehicle Type : " << temp->vehicletype;
            cout << "\n-----------------------------------------------";
            temp = temp->next;
        }
    }

}

//sort all records by its vehicle category

void Vehicle::sorttype()
{
    if (head == NULL)
    {
        cout << "\n\n\t\tNo Vehicle Records!";
    }
    else
    {
        vehicleRecord* temp = head;                       //print bikes
        cout << "\t\t\n\n____________________ Bike ____________________";
        while (temp != NULL)
        {
            if (temp->vehicletype == "Bike")
            {

                cout << "\n\nVehicle ID : " << temp->vehicleid;
                cout << "\nCustomer Name : " << temp->name;
                cout << "\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
                cout << "\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
                cout << "\nVehicle Type : " << temp->vehicletype;
                cout << "\n-----------------------------------------------";

            }
            temp = temp->next;

        }
        cout << "\t\t\n\n____________________ Car ____________________";
        vehicleRecord* temp1 = head;
        while (temp1 != NULL)                   //print cars
        {
            if (temp1->vehicletype == "Car")
            {

                cout << "\n\nVehicle ID : " << temp1->vehicleid;
                cout << "\nCustomer Name : " << temp1->name;
                cout << "\nVehicle Pick up Date (MM/DD) : " << temp1->pickmonth << "/" << temp1->pickdate;
                cout << "\nVehicle Drop off Date (MM/DD) : " << temp1->dropmonth << "/" << temp1->dropdate;
                cout << "\nVehicle Type : " << temp1->vehicletype;
                cout << "\n-----------------------------------------------";

            }
            temp1 = temp1->next;

        }
        cout << "\t\t\n\n____________________ Van ____________________";
        vehicleRecord* temp3 = head;
        while (temp3 != NULL)
        {
            if (temp3->vehicletype == "Van")
            {
                //prints van
                cout << "\n\nVehicle ID : " << temp3->vehicleid;
                cout << "\nCustomer Name : " << temp3->name;
                cout << "\nVehicle Pick up Date (MM/DD) : " << temp3->pickmonth << "/" << temp3->pickdate;
                cout << "\nVehicle Drop off Date (MM/DD) : " << temp3->dropmonth << "/" << temp3->dropdate;
                cout << "\nVehicle Type : " << temp3->vehicletype;
                cout << "\n-----------------------------------------------";

            }
            temp3 = temp3->next;
        }
        cout << "\t\t\n\n____________________ Cab ____________________";
        vehicleRecord* temp4 = head;
        while (temp4 != NULL)
        {
            if (temp4->vehicletype == "Cab")
            {
                //print cab

                cout << "\n\nVehicle ID : " << temp4->vehicleid;
                cout << "\nCustomer Name : " << temp4->name;
                cout << "\nVehicle Pick up Date (MM/DD) : " << temp4->pickmonth << "/" << temp4->pickdate;
                cout << "\nVehicle Drop off Date (MM/DD) : " << temp4->dropmonth << "/" << temp4->dropdate;
                cout << "\nVehicle Type : " << temp4->vehicletype;
                cout << "\n-----------------------------------------------";

            }
            temp4 = temp4->next;
        }

        cout << "\t\t\n\n____________________ Bus ____________________";
        vehicleRecord* temp5 = head;
        while (temp5 != NULL)             //print bus
        {
            if (temp5->vehicletype == "Bus")
            {

                cout << "\n\nVehicle ID : " << temp5->vehicleid;
                cout << "\nCustomer Name : " << temp5->name;
                cout << "\nVehicle Pick up Date (MM/DD) : " << temp5->pickmonth << "/" << temp5->pickdate;
                cout << "\nVehicle Drop off Date (MM/DD) : " << temp5->dropmonth << "/" << temp5->dropdate;
                cout << "\nVehicle Type : " << temp5->vehicletype;
                cout << "\n-----------------------------------------------";


            }
            temp5 = temp5->next;
        }
    }
}


//sort by the days of rent and fee that has to come

void Vehicle::sorthighestDate()
{
    if (head == nullptr || head->next == nullptr) {
        return; // NO VEHICLE RECORD OR HEAD ONLY
    }

    bool swapped;
    vehicleRecord* current;
    vehicleRecord* current2;

    do
    {
        swapped = false;
        current = head;

        while (current->next != nullptr)
        {
            current2 = current->next;

            if (current->daysforrent < current2->daysforrent)
            {
                //SWAP VALUES
                swap(current->daysforrent, current2->daysforrent);
                swap(current->vehicleid, current2->vehicleid);
                swap(current->name, current2->name);
                swap(current->pickdate, current2->pickdate);
                swap(current->pickmonth, current2->pickmonth);
                swap(current->dropdate, current2->dropdate);
                swap(current->dropmonth, current2->dropmonth);
                swapped = true;
            }

            current = current->next;
        }
    } while (swapped);

}

void Vehicle::sortpickupdate()
{
    //sort by the pickup date

     //check linked list empty or not

    if (head == NULL)
    {
        cout << "\n\n\t\tNo Vehicle Records!";
    }
    else
    {
        int count = 0, tpickmonth, tpickdate, tdropmonth, tdropdate, tdaysforrent;
        string tvehid, tvehtype, tname;
        vehicleRecord* temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        vehicleRecord* temp7 = head;
        if (temp7->next == NULL)
        {
            cout << "\n\nVehicle ID : " << temp7->vehicleid;
            cout << "\nCustomer Name : " << temp7->name;
            cout << "\nVehicle Pick up Date (MM/DD) : " << temp7->pickmonth << "/" << temp7->pickdate;
            cout << "\nVehicle Drop off Date (MM/DD) : " << temp7->dropmonth << "/" << temp7->dropdate;
            cout << "\nVehicle Type : " << temp7->vehicletype;
            cout << "\n-----------------------------------------------";
        }
        else
        {
            //dates from the begining of the year

            int datesfromstart1 = 0;
            int datesfromstart2 = 0;



            vehicleRecord* current = head;
            vehicleRecord* min = head;
            for (int i = 0;i < count - 1; i++)
            {
                //find the minimum value

                datesfromstart1 = (current->pickmonth - 1) * 30 + current->pickdate;
                datesfromstart2 = ((current->next)->pickmonth - 1) * 30 + (current->next)->pickdate;
                if ((datesfromstart1) > (datesfromstart2))
                {
                    min = current->next;

                }
                current = current->next;
            }


            datesfromstart1 = (head->pickmonth - 1) * 30 + head->pickdate;
            datesfromstart2 = (min->pickmonth - 1) * 30 + min->pickdate;
            if (datesfromstart2 < datesfromstart1)
            {

                //tempery store data 

                tvehid = min->vehicleid;
                tname = min->name;
                tpickmonth = min->pickmonth;
                tpickdate = min->pickdate;
                tdropdate = min->dropdate;
                tdropmonth = min->dropmonth;
                tvehtype = min->vehicletype;
                tdaysforrent = min->daysforrent;


                //assign nest data to current

                min->vehicleid = head->vehicleid;
                min->name = head->name;
                min->pickmonth = head->pickmonth;
                min->pickdate = head->pickdate;
                min->dropdate = head->dropdate;
                min->dropmonth = head->dropmonth;
                min->vehicletype = head->vehicletype;
                min->daysforrent = head->daysforrent;


                //get data from temporary store

                head->vehicleid = tvehid;
                head->name = tname;
                head->pickmonth = tpickmonth;
                head->pickdate = tpickmonth;
                head->dropdate = tdropdate;
                head->dropmonth = tdropmonth;
                head->vehicletype = tvehtype;
                head->daysforrent = tdaysforrent;
            }


            current = head->next;

            for (int i = 0;i < count - 2;i++)
            {
                for (int j = 0;j < count - i - 2;j++)
                {
                    datesfromstart1 = (current->pickmonth - 1) * 30 + current->pickdate;
                    datesfromstart2 = ((current->next)->pickmonth - 1) * 30 + (current->next)->pickdate;


                    if (datesfromstart1 > datesfromstart2)
                    {

                        //tempery store data 

                        tvehid = current->vehicleid;
                        tname = current->name;
                        tpickmonth = current->pickmonth;
                        tpickdate = current->pickdate;
                        tdropdate = current->dropdate;
                        tdropmonth = current->dropmonth;
                        tvehtype = current->vehicletype;
                        tdaysforrent = current->daysforrent;


                        //assign nest data to current

                        current->vehicleid = (current->next)->vehicleid;
                        current->name = (current->next)->name;
                        current->pickmonth = (current->next)->pickmonth;
                        current->pickdate = (current->next)->pickdate;
                        current->dropdate = (current->next)->dropdate;
                        current->dropmonth = (current->next)->dropmonth;
                        current->vehicletype = (current->next)->vehicletype;
                        current->daysforrent = (current->next)->daysforrent;



                        //get data from temporary store

                        (current->next)->vehicleid = tvehid;
                        (current->next)->name = tname;
                        (current->next)->pickmonth = tpickmonth;
                        (current->next)->pickdate = tpickmonth;
                        (current->next)->dropdate = tdropdate;
                        (current->next)->dropmonth = tdropmonth;
                        (current->next)->vehicletype = tvehtype;
                        (current->next)->daysforrent = tdaysforrent;
                    }



                    current = current->next;


                }
            }

            vehicleRecord* temps = head;
            while (temps != NULL)
            {
                //print after sort

                cout << "\n\nVehicle ID : " << temps->vehicleid;
                cout << "\nCustomer Name : " << temps->name;
                cout << "\nVehicle Pick up Date (MM/DD) : " << temps->pickmonth << "/" << temps->pickdate;
                cout << "\nVehicle Drop off Date (MM/DD) : " << temps->dropmonth << "/" << temps->dropdate;
                cout << "\nVehicle Type : " << temps->vehicletype;
                cout << "\n-----------------------------------------------";
                temps = temps->next;
            }



        }

    }
}



void Vehicle::income()
{
    //business income analysing part

    cout << "\n\t_____Vehicle Rental Management System______";

    //income record analysis

    string delvehid;
    if (head == NULL)
    {
        cout << "\nVehicle Records are empty";
    }
    else
    {
        int price = 0;
        int payfull = 0;
        int paybike = 0;
        int paycar = 0;
        int paycab = 0;
        int payvan = 0;
        int paybus = 0;

        vehicleRecord* temp = head;
        while (temp != NULL)
        {
            if (temp->vehicletype == "Bike")
            {
                int payb = 0;
                payb = 2000 * temp->daysforrent;            //bike
                paybike = payb + paybike;


            }
            else if (temp->vehicletype == "Car")
            {

                int payc = 0;
                payc = 4000 * temp->daysforrent;              //car
                paycar = payc + paycar;
            }
            else if (temp->vehicletype == "Van")
            {

                int payv = 0;
                payv = 8000 * temp->daysforrent;
                payvan = payv + payvan;                        //van
            }

            else if (temp->vehicletype == "Cab")
            {

                int payca = 0;
                payca = 6000 * temp->daysforrent;
                paycab = payca + paycab;
            }                                                         //cab
            else
            {
                int paybb = 0;
                paybb = 10000 * temp->daysforrent;                          //bus
                paybus = paybb + paybus;
            }



            temp = temp->next;
        }
        cout << "\n\nIncome from Bike : " << paybike;
        cout << "\n-----------------------------------------------";
        cout << "\n\nIncome from Car : " << paycar;
        cout << "\n-----------------------------------------------";
        cout << "\n\nIncome from Van : " << payvan;
        cout << "\n-----------------------------------------------";
        cout << "\n\nIncome from Cab : " << paycab;                                 //analyzer
        cout << "\n-----------------------------------------------";
        cout << "\n\nIncome from Bus : " << paybus;
        cout << "\n-----------------------------------------------";
        payfull = paybike + paycar + payvan + paycab + paybus;
        cout << "\n\nIncome from All Vehicles : " << payfull;
        cout << "\n-----------------------------------------------";
    }
}

void Vehicle::searchandprice()
{

    //quick find price

    cout << "\n\t_____Vehicle Rental Management System______";
    string searchvehid;
    if (head == NULL)                                                      //search and print the output
    {
        cout << "\nVehicle Records are Empty!";

    }
    else
    {
        cout << "\n\nEnter Vehicle ID : ";
        cin >> searchvehid;
        vehicleRecord* temp = head;
        while (temp != NULL)
        {
            if (temp->vehicleid == searchvehid)
            {
                if (temp->vehicletype == "Bike")
                {                                                                          //bike
                    int payb = 0;
                    payb = 2000 * temp->daysforrent;
                    cout << "\n\nIncome from Customer : " << payb;
                    cout << "\n\Vehicle ID : " << temp->vehicleid;
                    cout << "\n\nCustomer Name : " << temp->name;
                    cout << "\n\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
                    cout << "\n\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
                    cout << "\n\nVehicle Type : " << temp->vehicletype;


                }
                else if (temp->vehicletype == "Car")
                {
                    //car
                    int payc = 0;
                    payc = 4000 * temp->daysforrent;
                    cout << "\n\nIncome from Customer : " << payc;
                    cout << "\n\nVehicle ID : " << temp->vehicleid;
                    cout << "\n\nCustomer Name : " << temp->name;
                    cout << "\n\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
                    cout << "\n\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
                    cout << "\n\nVehicle Type : " << temp->vehicletype;
                }
                else if (temp->vehicletype == "Van")
                {
                    //van
                    int payv = 0;
                    payv = 8000 * temp->daysforrent;
                    cout << "\n\nIncome from Customer : " << payv;
                    cout << "\n\nVehicle ID : " << temp->vehicleid;
                    cout << "\n\nCustomer Name : " << temp->name;
                    cout << "\n\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
                    cout << "\n\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
                    cout << "\n\nVehicle Type : " << temp->vehicletype;
                }

                else if (temp->vehicletype == "Cab")
                {
                    //Cab
                    int payca = 0;
                    payca = 6000 * temp->daysforrent;
                    cout << "\n\nIncome from Customer : " << payca;
                    cout << "\n\nVehicle ID : " << temp->vehicleid;
                    cout << "\n\nCustomer Name : " << temp->name;
                    cout << "\n\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
                    cout << "\n\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
                    cout << "\n\nVehicle Type : " << temp->vehicletype;
                }
                else
                {
                    int paybb = 0;                                                                //bus
                    paybb = 10000 * temp->daysforrent;
                    cout << "\n\nIncome from Customer : " << paybb;
                    cout << "\n\nVehicle ID : " << temp->vehicleid;
                    cout << "\n\nCustomer Name : " << temp->name;
                    cout << "\n\nVehicle Pick up Date (MM/DD) : " << temp->pickmonth << "/" << temp->pickdate;
                    cout << "\n\nVehicle Drop off Date (MM/DD) : " << temp->dropmonth << "/" << temp->dropdate;
                    cout << "\n\nVehicle Type : " << temp->vehicletype;
                }

            }
            temp = temp->next;
        }
    }

}






int main()
{
    Vehicle h;
    int choice;
    do {

        cout << "\n\tWelcome to Vehicle Rental Management System" << endl;
        cout << "\n\t_________Vehicle Rental Management System_________";
        cout << "\n\nS.No    Functions                                       Description" << endl;
        cout << "\n[1]\tAllocate Vehicle\t\t\t\tInsert new Vehicle";
        cout << "\n[2]\tSearch Vehicle\t\t\t\t\tSearch Vehicle using Vehicle Id";
        cout << "\n[3]\tUpdate Vehicle Record\t\t\t\tUpdate Vehicle Records";
        cout << "\n[4]\tDelete Vehicle Record\t\t\t\tDelete Vehicle Record";
        cout << "\n[5]\tShow all Vehicle Records\t\t\tShow Vehicle Records that (We Added)";
        cout << "\n[6]\tShow all Vehicle Income Records\t\t\tShow the Income according to Vehicle Type and Full Income";
        cout << "\n[7]\tSearch and Find the Fee for Rental\t\tShow the Payment that Customer has to Pay";
        cout << "\n[8]\tSort the Vehicle Rental Records\t\t\tSort by Vehicle Type";
        cout << "\n[9]\tSort the Vehicle Rental Records\t\t\tSort from Highest Rental Days to Lowest";
        cout << "\n[10]\tSort the Vehicle Pick up Date\t\t\tSort from nearest Pickup Date of the Vehicle";
        cout << "\n[11]\tExit" << endl;
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        //OPERATING PART

        switch (choice)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.search();
            break;
        case 3:
            h.update();
            break;
        case 4:
            h.del();
            break;
        case 5:
            h.show();
            break;
        case 6:
            h.income();
            break;
        case 7:
            h.searchandprice();
            break;
        case 8:
            h.sorttype();
            break;
        case 9:
            h.sorthighestDate();
            h.show();
            break;
        case 10:
            h.sortpickupdate();
            h.show();
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "\n\nInvalid Choice!";
            break;
        }
        cin.get();

    } while (true);

    return 0;
}



