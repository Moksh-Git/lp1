#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


void takeInput(vector<vector<float>> &items, int &n, float &weight)
{

    cout << "Enter number of items :- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float profit, weight, pw;
        cout << "Enter profit for " << i + 1 << " item : ";
        cin >> profit;
        cout << "Enter Weight for " << i + 1 << " item : ";
        cin >> weight;
        cout << endl;
        pw = profit / weight;

        vector<float> item;

        item.push_back(pw);
        item.push_back(profit);
        item.push_back(weight);

        items.push_back(item);
    }

    cout << "Enter maximum weigth allowed : ";
    cin >> weight;
    cout << endl;
    return;
}

int main()
{
    vector<vector<float>> items;
    int n;
    float weight;
    takeInput(items, n, weight);
    sort(items.begin(), items.end());
    vector<vector<float>> result = items;
    float profit = 0;

    for (int i = n - 1; i >= 0; i--)
    {

        if (items[i][2] <= weight)
        {
            weight -= items[i][2];
            profit += items[i][1];
            result[i][0] = 1;
        }
        else
        {
            profit += items[i][1] * (weight / items[i][2]);
            result[i][0] = (weight / items[i][2]);

            weight = 0;
        }
    }

    cout << "Final Profit : " << profit << endl;
}