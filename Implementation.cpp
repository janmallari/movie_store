#include <iostream>
#include <string>
#include "Data.h"
using namespace std;
using namespace ns;

MovieList::MovieList()
{
  head = NULL;
}

MovieList::~MovieList()
{
  Movie *nodePtr, *nextNode;

  nodePtr = head;
  while (nodePtr != NULL)
  {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
  cout << "Linked List has been destroyed!" << endl;
}

void MovieList::appendMovie(string code, string title, string genre, int year)
{
  Movie *newNode, *nodePtr;
  // Allocate a new node & store num
  newNode = new Movie;
  newNode->code = code;
  newNode->title = title;
  newNode->genre = genre;
  newNode->year = year;
  newNode->next = NULL;
  // If there are no nodes in the list
  // make newNode the first node
  if (!head)
    head = newNode;
  else // Otherwise, insert newNode at end
  {
    // Initialize nodePtr to head of list
    nodePtr = head;
    // Find the last node in the list
    while (nodePtr->next)
      nodePtr = nodePtr->next;
    // Insert newNode as the last node
    nodePtr->next = newNode;
  }
}

void MovieList::displayList()
{
  Movie *nodePtr;
  if (head == NULL)
    cout << "The list is empty!" << endl;
  else
  {
    cout << "<< Available Movies >>" << endl;
    cout << "=============================================" << endl;
    nodePtr = head;
    while (nodePtr)
    {
      cout << "Code: " << nodePtr->code << endl;
      cout << "Title: " << nodePtr->title << endl;
      cout << "Genre: " << nodePtr->genre << endl;
      cout << "Year Released: " << nodePtr->year << endl;
      cout << "=============================================" << endl;
      nodePtr = nodePtr->next;
    }
  }
}

void MovieList::insertMovie(string code, string title, string genre, int year)
{
  Movie *newNode, *nodePtr, *previousNode;

  // Allocate a new node & store Num
  newNode = new Movie;
  newNode->code = code;
  newNode->title = title;
  newNode->genre = genre;
  newNode->year = year;

  // If there are no nodes in the list
  // make newNode the first node
  if (!head)
  {
    head = newNode;
    newNode->next = NULL;
  }
  else // Otherwise, insert newNode.
  {
    // Initialize nodePtr to head of list
    nodePtr = head;
    previousNode = NULL;

    // Skip all nodes whose code is same
    while (nodePtr != NULL && nodePtr->code == code)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    // If the new mode is to be the 1st in the list,
    // insert it before all other nodes.
    if (previousNode == NULL)
    {
      head = newNode;
      newNode->next = nodePtr;
    }
    else
    {
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }
  cout << endl
       << "Input has been successfully Inserted!" << endl;
}

void MovieList::deleteMovie(string code)
{
  Movie *nodePtr, *previousNode;
  int found = 0;

  // If the list is empty, do nothing.
  if (!head)
  {
    cout << "List is empty!" << endl;
    return;
  }

  // Determine if the first node is the one.
  if (head->code == code)
  {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
    cout << "Movie has been succesfully checked-out!" << endl;
    found = 1;
  }
  else
  {
    // Initialize nodePtr to head of list
    nodePtr = head;
    previousNode = NULL;

    // Skip all nodes whose value member is
    // not equal to num.
    while (nodePtr != NULL && nodePtr->code != code)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    // Link the previous node to the node after
    // nodePtr, then delete nodePtr.
    if (nodePtr != NULL)
    {
      previousNode->next = nodePtr->next;
      delete nodePtr;
      cout << "Movie has been succesfully checked-out!" << endl;
      found = 1;
    }
  }
  if (found == 0)
    cout << "Input is not found in the list!" << endl;
}

void MovieList::showDetails(string code)
{
  Movie *nodePtr, *previousNode;
  int found = 0;

  // If the list is empty, do nothing.
  if (!head)
  {
    cout << "List is empty!" << endl;
    return;
  }
  else
  {

    nodePtr = head;
    while (nodePtr)
    {
      if (nodePtr->code == code)
      {

        cout << "<< Movie Details >>" << endl;
        cout << "=============================================" << endl;
        cout << "Code: " << nodePtr->code << endl;
        cout << "Title: " << nodePtr->title << endl;
        cout << "Genre: " << nodePtr->genre << endl;
        cout << "Year Released: " << nodePtr->year << endl;
        cout << "=============================================" << endl;
      }
      nodePtr = nodePtr->next;
    }
  }
}