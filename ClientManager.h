#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Person.h"
#include "FilesHelper.h"

using namespace std;
class ClientManager
{
private:
    inline static vector<Client> clients;


  
    static void saveAllClients()
    {
        ofstream output("Client.txt", ios::trunc);

        for (Client& client : clients)
        {
            output << client.getid() << "/"
                << client.getname() << "/"
                << client.getpassword() << "/"
                << client.GetBalance()
                << endl;
        }

        output.close();
    }

    /////////////////////////////////////////////////////////////////////////
public:
    // PrintClientMenu
    static void printClientMenu()
    {
        cout << "========== ClientMenu ==========\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Check Balance\n";
        cout << "5. Update Password\n";
        cout << "6. Logout\n";
        cout << "=================================\n";
    }
    //////////////////////////////////////////////////////////////////////////////
    // Update Password
  
    static void updatePassword(Person* person)
    {
        string newPassword;

        cout << "Enter New Password: ";
        cin >> newPassword;

        person->setpassword(newPassword);

        cout << "Password Updated Successfully!\n";

        saveAllClients();
    }

   
    ////////////////////////////////////////////////////////////////////////////////

       // Login
   
    static Client* login(int id, string password)
    {
        
        clients = FilesHelper::GetClients();

   
        for (Client& client : clients)
        {
            if (client.getid() == id &&
                client.getpassword() == password)
            {
                cout << "\nLogin Successful!\n";
                cout << "Welcome " << client.getname() << "!\n";

                return &client;
            }
        }

        cout << "\nInvalid ID or Password!\n";

        return nullptr;
    }
    //////////////////////////////////////////////////////////////////////////////////
    // Client Options

    static bool clientOptions(Client* client)
    {
        int choice;

        while (true)
        {
            printClientMenu();

            cout << "Choose: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                double amount;

                cout << "Enter amount to deposit: ";
                cin >> amount;

                if (amount > 0)
                {
                    client->Deposit(amount);
                    saveAllClients();
                }
                else
                {
                    cout << "Invalid Amount!\n";
                }

                break;
            }


          
            case 2:
            {
                double amount;

                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (amount > 0)
                {
                    client->Withdraw(amount);
                    saveAllClients();
                }
                else
                {
                    cout << "Invalid Amount!\n";
                }

                break;
            }


            case 3:
            {
                int recipientId;
                double amount;

                cout << "Enter Recipient ID: ";
                cin >> recipientId;

                cout << "Enter Amount: ";
                cin >> amount;

                Client* recipient = nullptr;

      
                for (Client& c : clients)
                {
                    if (c.getid() == recipientId)
                    {
                        recipient = &c;
                        break;
                    }
                }

                if (recipient == nullptr)
                {
                    cout << "Recipient Not Found!\n";
                }
                else if (recipient == client)
                {
                    cout << "You Cannot Transfer Money To Yourself!\n";
                }
                else if (amount <= 0)
                {
                    cout << "Invalid Amount!\n";
                }
                else
                {
                    client->TransferTo(amount, *recipient);
                    saveAllClients();
                }

                break;
            }


            
            case 4:
            {
                client->CheckBalance();
                cout << endl;

                break;
            }


            case 5:
            {
                updatePassword(client);

                break;
            }


          
            case 6:
            {
                cout << "\nLogging Out...\n";

                return false;
            }


          
            default:
            {
                cout << "Invalid Choice!\n";
                break;
            }
            }
        }
    }

};

