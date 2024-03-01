#ifndef INVENTORYMANAGEMENTSYSTEM_HISTORY_H
#define INVENTORYMANAGEMENTSYSTEM_HISTORY_H

#include "DataStructures/Stack.h"
stack <string> ManagingUserInteractions;
bool used = false;
void addsparePart(int partNumber)
{
    string interactionsMessage = " User entered data for Spare Part number " + to_string(partNumber);
    ManagingUserInteractions.push(interactionsMessage);
    used = true;
}

void addSupplier(int partNumber)
{
    string interactionsMessage = " User entered data for Supplier number " + to_string(partNumber);
    ManagingUserInteractions.push(interactionsMessage);
    used = true;
}
void ModifySparePart(int partNumber)
{
    string InteractionModifyMessage = " User Modified Data for spare part number " + to_string(partNumber);
    ManagingUserInteractions.push(InteractionModifyMessage);
}
void ModifySupplier(int partNumber)
{
    string InteractionModifyMessage = " User Modified Data for supplier number " + to_string(partNumber);
    ManagingUserInteractions.push(InteractionModifyMessage);
}
void DeleteSparepart( int partNumber)
{
    string InteractionDeleteMessage = " User Deleted Data for spare part number " + to_string(partNumber);
    ManagingUserInteractions.push(InteractionDeleteMessage);
}
void deleteSupplier(int partNumber)
{
    string InteractionDeleteMessage = " User Deleted Data for supplier number " + to_string(partNumber);
    ManagingUserInteractions.push(InteractionDeleteMessage);
}

void InteractionHistory()
{
    if (used) {
        cout << "Interaction History:" << endl;
        cout << "___________________________" << endl;
        ManagingUserInteractions.display();
        cout << "___________________________" << endl;
    }
    if (!used)
    {
        cout << "There is No Interaction History " << endl;
    }
}

#endif //INVENTORYMANAGEMENTSYSTEM_HISTORY_H
