/*

*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

struct Node
{
   int data = -1;
   Node * next = nullptr;
};

void displayList(Node * baseNode);
Node * addNodeToEnd(Node * baseNode, int num);
Node * insertAfter(Node * currNode, int num);

int main()
{
   Node * n = new Node;   //main?
   Node * t;   //temp
   Node * h;   //head
   ifstream inputFile;
   int val = 0;

   inputFile.open("Perm 50.txt");

   n->data = -1;
   t = n;   //point to the same node as n this will connect the nodes
   h = n;   //stays in place

   if (inputFile)
   {
      while (inputFile >> val)
         n = addNodeToEnd(n, val);

      inputFile.close();
   }
   else
      cout << "Unable to open file" << endl;

   displayList(h);


   system("pause");

   return 0;
}

void displayList(Node * baseNode)
{
   Node * currNode = baseNode->next;
   int i = 0;

   while (currNode != nullptr)
   {
      if (i % 10 == 0 && i != 0)
         cout << endl;

      cout << setw(5) << currNode->data; 
      currNode = currNode->next;
      i++;
   }
}

Node * addNodeToEnd(Node * baseNode, int num)
{
   Node * temp = baseNode;
   insertAfter(baseNode, num);

   baseNode = new Node;

   baseNode->data = num;
   temp->next = baseNode;
   temp = baseNode;
   baseNode->next = nullptr;

   return baseNode;
}

Node * insertAfter(Node * currNode, int num)
{
   Node * temp = currNode;
   currNode = new Node;

   currNode->data = num;
   temp->next = currNode;

   return currNode;
}
