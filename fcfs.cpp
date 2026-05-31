#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n],wt[n], tat[n];

    cout << "\nEnter Burst Time for each process:\n";
    for (int i = 0;i < n;i++)
    {
        cout<<"P"<<i + 1<< ": ";
        cin>>bt[i];
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++)
    {
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    float avgWT = totalWT / n;
    float avgTAT = totalTAT / n;

    cout << "\nFCFS Scheduling Result\n";
    cout << "-----------------------------------------------------\n";
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    cout << "-----------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "-----------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Average Waiting Time    = " << avgWT << endl;
    cout << "Average Turnaround Time = " << avgTAT << endl;

    cout << "\nGantt Chart:\n|";
    for (int i = 0; i < n; i++)
    {
        cout << " P" << i + 1 << " |";
    }

    cout << "\n0";
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += bt[i];
        cout << "\t" << time;
    }

    cout << endl;

    return 0;
}
