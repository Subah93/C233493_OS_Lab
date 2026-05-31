#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int at[n], bt[n], rt[n], wt[n], tat[n];

    int time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    cout << "\nEnter Arrival Time and Burst Time:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "\nGantt Chart:\n";

    while(completed != n)
    {
        int shortest = -1;
        int min = 9999;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            cout << "| Idle ";
            time++;
            continue;
        }


        cout << "| P" << shortest + 1 << " ";
        rt[shortest]--;

        if(rt[shortest] == 0)
        {
            completed++;
            int finish = time + 1;

            tat[shortest] = finish - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            total_wt += wt[shortest];
            total_tat += tat[shortest];
        }

        time++;
    }

    cout << "|\n";

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << total_wt / n;
    cout << "\nAverage Turnaround Time = " << total_tat / n << endl;

    return 0;
}
