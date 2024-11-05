#include <bits/stdc++.h>
using namespace std;
string ASCIIValue(char s)
{
    string str = "";
    int n = s;
    while (n > 0)
    {
        str += (n % 2) + '0';
        n /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}
string RedundantBits(string s)
{
    string str = "";
    int n = s.length();
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            r++;
    }
    if (r % 2 == 0)
    {
        str = s + '0';
    }
    else
    {
        str = s + '1';
    }
    return str;
}
int main()
{
    int op;
    cout << "Enter 1 for Word and 2 for ASCII Sequence: ";
    cin >> op;
    if (op == 1)
    {
        string s;
        cout << "Enter Data Word: ";
        cin >> s;
        vector<string> v, vr;
        for (int i = 0; i < s.length(); i++)
        {
            v.push_back(ASCIIValue(s[i]));
        }
        cout << "ASCII Value of Data Word is: ";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
        cout << "Bit Sends: ";
        for (int i = 0; i < v.size(); i++)
        {
            vr.push_back(RedundantBits(v[i]));
            cout << RedundantBits(v[i]) << " ";
        }
        cout << endl;
        cout << "Received Data Word: ";
        string rs;
        cin >> rs;
        if (rs.length() > s.size())
        {
            cout << "Error: Received word is larger than sender's word." << endl;
            return 0;
        }
        vector<string> rv, rrv;
        for (int i = 0; i < rs.length(); i++)
        {
            rv.push_back(ASCIIValue(rs[i]));
        }
        bool flag = true;
        for (int i = 0; i < rs.length(); i++)
        {
            string cc = (RedundantBits(rv[i]));
            if (cc != vr[i])
            {
                cout << "Error: At Index: " << i << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "No Error" << endl;
    }
    else if (op == 2)
    {
        cout << "Enter Data Length: ";
        int n;
        cin >> n;
        vector<string> v, vr, vv, vvr;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
            vr.push_back(RedundantBits(s));
        }
        cout << "Bit sequence sent is: ";
        for (int i = 0; i < vr.size(); i++)
            cout << vr[i] << " ";
        cout << endl;
        cout << "Enter received sequence: ";
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            vv.push_back(s);
        }
        bool flag = true;
        for (int i = 0; i < vv.size(); i++)
        {
            if (vv[i] != vr[i])
            {
                cout << "Error: At Number: " << i << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "No Error" << endl;
    }
    else
    {
        cout << "Invalid Option" << endl;
        return 0;
    }

    return 0;
}