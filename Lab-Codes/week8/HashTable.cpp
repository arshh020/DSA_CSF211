#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> dnsRecords;

    cout << "Implementation of DNS records" << endl;
    int choice;
    do {
        cout << "1.Insert hostname" << endl;
        cout << "2.Search hostname" << endl;
        cout << "3.Display the pairs" << endl;
        cout << "4.Exiting" << endl;

        cin >> choice;

        switch (choice) {
            case 1: {
                string hostname, ipAddress;
                cout << "Enter the hostname: ";
                cin >> hostname;
                cout << "Enter the IP address: ";
                cin >> ipAddress;
                dnsRecords[hostname] = ipAddress;
                cout << "Record (key, value) pair has been inserted successfully" << endl;
                cout << endl;
                break;
            }
            case 2: {
                string hostname;
                cout << "Enter the hostname to be searched: ";
                cin >> hostname;
                auto it = dnsRecords.find(hostname);
                if (it != dnsRecords.end()) {
                    cout << "The IP address of the hostname is: " << it->second << endl;
                    cout << endl;
                } else {
                    cout << "The hostname doesn't exist" << endl;
                    cout << endl;
                }
                break;
            }
            case 3: {
                cout << "Displaying all the hostnames:" << endl;
                for (const auto& entry : dnsRecords) {
                    cout << entry.first << " " << entry.second << endl;
                }
                cout << endl;
                break;
            }
            case 4:
                cout << "Exiting...." << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                cout << endl;
        }
    } while (choice < 4);

    return 0;
}
