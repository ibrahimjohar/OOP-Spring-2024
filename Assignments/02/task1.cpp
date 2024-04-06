/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 1
*/

#include <iostream>
#include <string>
using namespace std;

const int MAXPORTS = 10;
const int MAXPROTOCOLS = 10;
const string STUDENTID = "23K-0074";

class SecurityTool
{
    protected:
        string securityLevel;
        double cost;
        int nDevices;
    public:
        SecurityTool(string secLevel, double c, int nD) : 
            securityLevel(secLevel), cost(c), nDevices(nD)
        {
            if (c <= 0.0)
            {
                cout << "Cost cannot be 0 or less than 0. Cost not assigned\n";
            }

            if (secLevel != "High" && secLevel != "Medium" && secLevel != "Low")
            {
                cout << "Incorrect secuirity level input, security level not assigned.\n";
            }
        }

        virtual void performScan()
        {
            if (securityLevel == "High" || securityLevel == "Medium" || securityLevel == "Low")
            {
                cout << "A secuirity scan has been performed.\n";;
            }
            else
            {
                cout << "Invalid security level. Please set security level to High, Medium, or Low.\n";
            }
        }
};

class FirewallTool : public SecurityTool
{
    private:
        int ports[23];
        string protocols[6] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
        
    public:
        FirewallTool(string s, double c, int nD) :
            SecurityTool(s, c, nD) {}

        void generateList()
        {
            char digit = '0';
            for (char c : STUDENTID)
            {
                if(c != '0')
                {
                    digit = c;
                    break;
                }
            }

            if (digit == '0')
            {
                cout << "No non-zero digit found.\n";
                return;
            }

            int startPort = digit - '0';
            for (int i = 0; i < 23; i++)
            {
                ports[i] = startPort + i;
            }
        }

        void performScan()
        {
            generateList();
            int portIndex;
            if(securityLevel == "High")
            {
                cout << "Allowed Protocols:\n";
                for (string p : protocols)
                {
                    cout << p << "\n";
                }

                cout << "\nAllowed Ports:\n";
                for (int p: ports)
                {
                    cout << p << "\n";
                }
            }

            if(securityLevel == "Medium")
            {
                cout << "Allowed Protocols:\n";
                for (string p : protocols)
                {
                    cout << p << "\n";
                }

                cout << "\nAllowed Ports:\n";
                for (int p : ports)
                {
                    cout << p << "\n";
                    portIndex = p;
                }
                cout << portIndex + 1 << "\n";
                cout << portIndex + 2 << "\n";
            }

            if(securityLevel == "Low")
            {
                cout << "Allowed Protocols:\n";
                for (string p : protocols)
                {
                    cout << p << "\n";
                }
                cout << "TCP\n";
                cout << "DNS\n";

                cout << "\nAllowed Ports:\n";
                for (int p : ports)
                {
                    cout << p << "\n";
                    portIndex = p;
                }

                cout << portIndex + 1 << "\n";
                cout << portIndex + 2 << "\n";
                cout << portIndex + 3 << "\n";
                cout << portIndex + 4 << "\n";
                cout << portIndex + 5 << "\n";
            }
        }

};

int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 1\n\n";

    double cost;
    int nDevices;
    string securitylevel;

    cout << "Enter security tool cost: ";
    cin >> cost;

    cout << "Enter number of devices the tool can run on (simultaneously): ";
    cin >> nDevices;

    cout << "Enter security level ('High', 'Medium', 'Low'): ";
    cin.ignore();
    getline(cin, securitylevel);

    //output based on security level
    if (securitylevel == "High")
    {
        if(cost > 0.0 && nDevices > 0 && nDevices <= 10 )
        {
            FirewallTool firewall1(securitylevel, cost, nDevices);  
            firewall1.performScan();
        }
        else
        {
            cout<<"Incorrect input, not according to limitations.\n";
        }
    }

    if (securitylevel == "Medium")
    {
        if(cost > 0.0 && nDevices > 0 && nDevices <= 10 )
        {
            FirewallTool firewall1(securitylevel, cost, nDevices);  
            firewall1.performScan();
        }
        else
        {
            cout<<"Incorrect input, not according to limitations.\n";
        }
    }

    if (securitylevel == "Low")
    {
        if(cost > 0.0 && nDevices > 0 && nDevices <= 10 )
        {
            FirewallTool firewall1(securitylevel, cost, nDevices);  
            firewall1.performScan();
        }
        else
        {
            cout<<"Incorrect input, not according to limitations.\n";
        }
    }


    return 0;
}
