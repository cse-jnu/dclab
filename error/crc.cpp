#include <bits/stdc++.h>
using namespace std;

string XOR(string a, string b)
{
    string result = "";
    int i = 0;
    for (i; i < b.length(); i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    for (i; i < a.length(); i++)
        result += a[i];
    return result;
}
string removePreZeros(string s)
{
    int i = 0;
    while (s[i] == '0')
        i++;
    return s.substr(i);
}
string CalculateCRC(string m, string d)
{
    string curr = m;
    for (int i = 0; i < d.length() - 1; i++)
        curr += "0";
    int ml = m.length();
    int dl = d.length();
    while (curr.length() > dl - 1)
    {
        string temp = XOR(curr, d);
        curr = removePreZeros(temp);
    }
    if (curr.length() < dl - 1)
    {
        int diff = dl - 1 - curr.length();
        for (int i = 0; i < diff; i++)
            curr = "0" + curr;
    }
    return curr;
}

int main()
{
    string m, d;
    cout << "Enter message  : ";
    cin >> m;
    cout << "Enter divisor  : ";
    cin >> d;
    string crc = CalculateCRC(m, d);
    cout << "CRC: " << crc << endl;
    cout << "Message with CRC: " << m + crc << endl;
    cout << "Enter received message: ";
    string rm;
    cin >> rm;
    string r_crc = CalculateCRC(rm, d);
    bool isError = false;
    for (int i = 0; i < r_crc.length(); i++)
    {
        if (r_crc[i] == '1')
        {
            isError = true;
            break;
        }
    }
    if (isError)
        cout << "Error detected in received message" << endl;
    else
        cout << "No error detected in received message" << endl;

    return 0;
}