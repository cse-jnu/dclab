#include <bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    string sum;
    int carry = 0;
    for (int i = 7; i >= 0; i--)
    {
        if (carry == 0)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                sum.push_back('0'), carry = 1;
            }
            else if (a[i] == '1' || b[i] == '1')
            {
                sum.push_back('1');
            }
            else
            {
                sum.push_back('0');
            }
        }
        else
        {
            if (a[i] == '1' and b[i] == '1')
            {
                sum.push_back('1');
            }
            else if (a[i] == '1' or b[i] == '1')
            {
                sum.push_back('0');
            }
            else
            {
                sum.push_back('1'), carry = 0;
            }
        }
    }
    reverse(sum.begin(), sum.end());
    if (carry)
        return add(sum, "00000001");

    return sum;
}
string complement(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            s[i] = '0';
        }
        else
        {
            s[i] = '1';
        }
    }
    return s;
}

int main()
{
    string a, b;
    cout << "Enter 8 bit code for a and b : ";
    cin >> a >> b;
    string checksum = complement(add(a, b));
    cout << a << " " << b << " " << checksum << endl;

    string x, y, z;
    cout << "Enter receiver receive: ";
    cin >> x >> y >> z;
    string res = add(add(x, y), z);
    int error = 0;
    for (auto c : res)
    {
        if (c == '0')
            error = 1;
    }
    if (error)
        cout << "NOT CORRECT";
    else
        cout << "CORRECT";
}
