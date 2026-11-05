
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_DAYS = 30;

// Function to calculate minimum value
double findMin(double arr[], int n)
{
    double min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}


double findMax(double arr[], int n)
{
    double max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max= arr[i];
        }
    }

    return max;
}


double findAvg(double arr[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum / n;
}

// Main function
int main()
{
    // Arrays to store weather readings
    double temp[MAX_DAYS];
    double hum[MAX_DAYS];
    double rain[MAX_DAYS];

    int days;

   
    cout << "     WEATHER STATION CLIMATE ANALYZER\n";
    cout << "\nEnter number of days (1-30): ";
    cin >> days;

    if (cin.fail() || days < 1 || days > MAX_DAYS)
    {
        cout << "Invalid number of days!\n";
        return 1;
    }    // Input daily weather readings
    cout << "\nEnter Daily Weather Readings\n";
    for (int i = 0; i < days; i++)
    {
        cout << "\nDay " << i + 1 << ":\n";

        cout << "Temperature (Celsius): ";
        cin >> temp[i];

        cout << "Humidity (%): ";
        cin >> hum[i];
        if (cin.fail() || hum[i] < 0 || hum[i] > 100)
        {
            cout << "Invalid humidity value!\n";
            return 1;
        }

        cout << "Rain (mm): ";
        cin >> rain[i];

        // Validate rainfall
        if (cin.fail() || rain[i] < 0)
        {
            cout << "Invalid rainfall value!\n";
            return 1;
        }
    }
   
    cout << "           DAILY WEATHER DATA\n";
    cout << left << setw(10) << "Day"
         << setw(18) << "Temperature"
         << setw(15) << "Humidity"
         << setw(15) << "Rainfall" << endl;

    for (int i = 0; i < days; i++)
    {
        cout << left << setw(10) << i + 1
             << setw(18) << temp[i]
             << setw(15) << hum[i]
             << setw(15) << rain[i] << endl;
    }

  
    cout << "         \n WEATHER ANALYSIS REPORT\n";
    cout << fixed << setprecision(2);

    cout << "TEMPERATURE ANALYSIS\n";
    cout << "Minimum Temperature: "
         << findMin(temp, days) << " C\n";

    cout << "Maximum Temperature: "
         << findMax(temp, days) << " C\n";

    cout << "Average Temperature: "
         << findAvg(temp, days) << " C\n";

    cout << "\nHUMIDITY ANALYSIS\n";
    cout << "Minimum Humidity: "
         << findMin(hum, days) << " %\n";

    cout << "Maximum Humidity: "
         << findMax(hum, days) << " %\n";

    cout << "Average Humidity: "
         << findAvg(hum, days) << " %\n";

    cout << "\nRAINFALL ANALYSIS\n";
    cout << "Minimum Rainfall: "
         << findMin(rain, days) << " mm\n";

    cout << "Maximum Rainfall: "
         << findMax(rain, days) << " mm\n";

    cout << "Average Rainfall: "
         << findAvg(rain, days) << " mm\n";

   
    cout << "       WEATHER ANALYSIS COMPLETED\n";
   

    return 0;
}
