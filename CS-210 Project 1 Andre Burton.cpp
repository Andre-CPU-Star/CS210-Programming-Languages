// Andre Burton
// CS-210
// Clock Project
// 29 January 2023

#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
// DC=Sets up the clock display and changes with user input, DM=Sets menu up to show input options to user.
// IH=Increases hours to clock, IM=Increases minutes to clock, IS=Increases seconds to clock, UC=Inputs the users choice into the clock.
int DC(int, int, int);
void DM();

// Below sets up diffrent user options and what each option does when a number is inputted and then tells the user what they did.
int main()
{
    int IH = 1;
    int IM = 1;
    int IS = 1;

    DC(1, 0, 0);

    DM();

    int uC = 0;

    cin >> uC;

    while (uC != 4)
    {
        if (uC == 1)
        {
            DC(IH, 0, 0);
            cout << "Added One Hour" << endl;
        }
        else if (uC == 2)
        {
            DC(0, IM, 0);
            cout << "Added One Minute" << endl;
        }
        else if (uC == 3)
        {
            DC(0, 0, IS);
            cout << "Added One Second" << endl;
        }
        else
        {
            cout << "Error, input out of range for clock";
        }

        DM();

        cin >> uC;
    }
    cout << "Exiting Clock Application" << endl;
    return 0;
}
// nCH= 12-hour clocks hour, nCm=12-hour clock minute, nCs=12-hour clock seconds, eCh=24-hour clock hour, eCm= 24-hour clock minute, 
// eCs= 24-hour clock seconds, dOn= designates whether is morning or evening
// Below sets up how clock adds numbers user inputs together without going over normal clock hours specifically 59 for minutes and seconds and 12 or 24 for hours.
// Below also designates whether its am or pm as the time goes over 12 hours for both 12 and 24 hour clock.

int DC(int addHour, int addMinute, int addSecond)
{
    static int nCh = 0;
    static int nCm = 0;
    static int nCs = 0;

    string morning = "AM";
    string afternoon = "PM";

    static int eCh = 0;
    static int eCm = 0;
    static int eCs = 0;

    static string dOn = morning;

    nCh = nCh + addHour;
    nCm = nCm + addMinute;
    nCs = nCs + addSecond;

    eCh = eCh + addHour;
    eCm = eCm + addMinute;
    eCs = eCs + addSecond;

    if (nCh > 12)
    {
        if (dOn == morning)
            dOn = afternoon;
        else
            dOn = morning;
        nCh = 1;
    }

    if (nCm > 59)
    {
        nCm = 0;
        nCh++;
    }

    if (nCs > 59)
    {
        nCs = 0;
        nCm++;
    }

    if (eCh > 24)
    {
        eCh = 1;
    }

    if (eCm > 59)
    {
        eCm = 0;
        eCh++;
    }

    if (eCs > 59)
    {
        eCs = 0;
        eCm++;
    }
    // Below does the final print of the users input and shows both clocks and the optiosn to the user to input to change each clock.

    cout << "The current time is:" << endl;
    cout << "+-------------+" << " " << "+-------------+" << endl;
    cout << "|" << "12-hour Clock|" << " " << "|" << "24-hour Clock|" << endl;
    cout.fill('0');
    cout << "|" << setw(2) << nCh << ":" << setw(2) << nCm << ":" << setw(2) << nCs << " " << dOn << " " << " |"
        << " "
        << "|" << setw(2) << eCh << ":" << setw(2) << eCm << ":" << setw(2) << eCs << "     |" << endl;
    cout << "+-------------+" << " " << "+-------------+" << endl;
    cout << endl;

    return 0;
}

void DM()
{
    cout << "+------------------+" << endl;
    cout << "|1 - Add One Hour  |" << endl;
    cout << "|2 - Add One Mintue|" << endl;
    cout << "|3 - Add One Second|" << endl;
    cout << "|4 - Exit Program  |" << endl;
    cout << "+------------------+" << endl;
}

// Acroyms were used to make the coding easier to create and edit but each acronym can be changed to anythign as long as it stays consitant.
