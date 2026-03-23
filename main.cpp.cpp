// Cinema seat booking project

//showing no of seats available
//allows booking and cancelling multiple seats via menu
//tackles over-booking and over-cancellation
// shows Housefull message
// display seat matrix after each booking, also shows booked and available seats 

#include <iostream>
using namespace std;

const int m = 5, n = 5;
int seat[m][n] = {0};

    void showSeats()
    {
    int available = 0; int booked = 0;   
    cout<<"--Seat Layout--"<<endl;
    for(int i = 0; i<m; i++)
    {
        cout<<"Row "<<i+1<<": ";
        for(int j = 0; j<n; j++)
        {
            if (seat[i][j] == 0)
            {
            cout<<"O ";
            available++;
            }
            else
            { 
            cout<<"X ";
            booked++;
            }    
        }
        cout<<endl;
    } 
    cout <<"Booked: "<<booked<<" , Available: "<<available<<endl; 
    if(available==0){cout<<"Show is Housefull"<<endl;}
    }
  
    bool housefull()
    {
        for(int i = 0; i<m; i++)
        {    
            for(int j=0; j<n; j++)
            {
                if(seat[i][j]==0)
                    return false;
            }
        }
        return true;
    }

    void bookSeat()
    {
        if(housefull())
        {
            cout<<"Housefull, No seats available"<<endl;
            return;
        }

        int Row, SeatNo, count;
        int availableSeats = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(seat[i][j]==0)
                availableSeats++;
            }
        }

        cout<<"How many seats do you need?"<<endl;
        cin>>count;
        if(count>availableSeats)
        {
            cout<<"Sorry, Only "<<availableSeats<<" seats are available\n";
            return;
        }

        for(int i = 1; i<=count; i++)
        {

        cout<<"--Enter seat choice--\n in (Row: 1-5) with (SeatNo: 1-5)"<<endl;
        cout<<"Enter row"<<endl;
        cin>>Row;
        cout<<"Enter Seat No."<<endl;
        cin>>SeatNo;

        if(Row>0 && Row<=5 && SeatNo>0 && SeatNo<=5)
        {
            if(seat[Row-1][SeatNo-1]==0)
            {
                seat[Row-1][SeatNo-1]=1;
                cout<<"Row: "<<Row<<" SeatNo: "<<SeatNo<<": Booking Successful"<<endl;
            }
            else
            {   
                cout<<"Seat Already Booked"<<endl;
                i--;
            }    
        }
        else
        {    
            cout<<"Invalid Choice!!! Try again" <<endl;
            i--;
        }    
    }       
    }


    void cancelSeats()
    {
        int Row, SeatNo, count;
        int bookings = 0;


        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(seat[i][j]==1)
                bookings++;
            }
        }

        cout<<"How many bookings you want to cancel?"<<endl;
        cin>>count;
        if(count>bookings)
        {
            cout<<"Sorry, Only "<<bookings<<" bookings found\n";
            return;
        }

        for(int i = 1; i<=count; i++)
        {

        cout<<"--Enter seat choice--\n in (Row: 1-5) with (SeatNo: 1-5)"<<endl;
        cout<<"Enter row"<<endl;
        cin>>Row;
        cout<<"Enter Seat No."<<endl;
        cin>>SeatNo;

        if(Row>0 && Row<=5 && SeatNo>0 && SeatNo<=5)
        {
            if(seat[Row-1][SeatNo-1]==1)
            {
                seat[Row-1][SeatNo-1]=0;
                cout<<"Row: "<<Row<<" SeatNo: "<<SeatNo<<": Cancellation Successful"<<endl;
            }
            else
            {   
                cout<<"No booking found"<<endl;
                i--;
            }    
        }
        else
        {    
            cout<<"Invalid Choice!!! Try again" <<endl;
            i--;
        }    
    }       
    }

int main()
{
   
    int choice;
    while(1){
    cout<<"\nEnter your Choice: "<<endl
        <<"1- Show Seats"<<endl
        <<"2- Book Seat"<<endl
        <<"3- Cancel Seat"<<endl
        <<"4- Exit"<<endl;
    cout<<"Your choice is: ";
    cin>>choice;
    
    switch(choice)
    {
        case 1: showSeats();
                break;
        case 2: bookSeat();
                showSeats();
                break;
        case 3: cancelSeats();
                showSeats();
                break;        
        case 4: cout<<"Exiting"<<endl;
                return 0;        
        default: cout<<"Invalid Input\n Try again!";
                break;        
    }
    }
    return 0;
}