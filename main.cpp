//Project3.cpp
  
  #include "HashingTable.h"

int main()   /* A sample main program */
{  
  HashingTable<char*>* myHashTable; 
  char* Names[25] = {"Andy B", "Amy Dean", "Antonio G", "Andy Roberts", "Brian W", "Bob Macy", "Brent James", "Buck Muck", "Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis", "David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith",  "Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma", "Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen"}; 
  int i;   
  myHashTable = new HashingTable<char*>(25); 
  
  //Inserting the input into the Hash table
  for (i=0; i < 25; i++)          
   (*myHashTable).insert(Names[i]); 
  if ((*myHashTable).find("Zandi Rich"))  
    cout << "Zandi Rich is in the list" << endl; 
  else   
    cout << "Zandi Rich is not in the list" << endl;

  cout << "Printing the hash table after inserting...." << endl; // To check whether all the names are entered

  cout << (*myHashTable) << endl;   
    
  if ((*myHashTable).find("Zandi Rich"))  
    cout << "Zandi Rich is in the list" << endl; 
  else   
    cout << "Zandi Rich is not in the list" << endl;  
  (*myHashTable).remove("Zea John");                   // To remove the string 
  
   //To find out whether the string has been removed
  
  if ((*myHashTable).find("Zea John"))   
    cout << "Zea John is in the list" << endl;  
  else   
    cout << "Zea John is not in the list" << endl;

    //Split function

  for (i=0; i < 26; i++) 
    (*myHashTable).split(i,2);   
    
  cout << "Printing the hash table after splitting...." << endl; 
  cout << (*myHashTable) << endl;   
 
  if ((*myHashTable).find("Ziert Paul"))  
    cout << "Ziert Paul is in the list" << endl; 
  else   
    cout << "Ziert Paul is not in the list" << endl;   
  (*myHashTable).insert("Zea John"); 
  if ((*myHashTable).find("Zea John"))   
    cout << "Zea John is in the list" << endl; 
  else  
    cout << "Zea John is not in the list" << endl;  

  delete myHashTable;    //Deleting the Hash table

  return 0;
} 