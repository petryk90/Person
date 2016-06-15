#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 64

typedef struct Node {
  char *name;
  char *surname;
  char *phone;
  char *mail;
  Node *next;
} Node;

Node *createList(char *name, char *surname, char *phone, char *mail);
Node *addNode(Node *head, char *name,  char *surname, char *phone, char *mail);
void deleteNode(Node *head, char *name);
Node *insertNode(Node *head, char *name, char *surname, char *phone, char *mail, int position);
void printList(Node *head);

int main(void)
{
  Node *head;

  head = createList("Anna", "Kuts", "0977114229", "akuts@gmail.com");

  addNode(head, "Petro", "Datsyshyn", "0503157145", "petryk1990@gmail.com");
  printList(head);

  addNode(head, "Vitaliy", "Dutka", "0634334561", "vdutka@gmail.com");
  printList(head);

  insertNode(head, "Taras", "Didyk", "0666587498","tdidyk@gmail.com", 2);
  printList(head);

  deleteNode(head, "Anna");
  printList(head);

  return 0;
}

Node *createList(char *name, char *surname, char *phone, char *mail)
{
  Node *head = (Node *) malloc (sizeof(Node));

  head->name = (char *) malloc (MAXLEN);
  head->surname = (char *) malloc (MAXLEN);
  head->phone = (char *) malloc (MAXLEN);
  head->mail = (char *) malloc (MAXLEN);
  head->next = NULL;

  strcpy(head->name, name);
  strcpy(head->surname, surname);
  strcpy(head->phone, phone);
  strcpy(head->mail, mail);

  return head;
}

Node *addNode(Node *head, char *name, char *surname, char *phone, char *mail)
{
  Node *node = (Node *) malloc (sizeof(Node));

  node->name = (char *) malloc (MAXLEN);
  node->surname = (char *) malloc (MAXLEN);
  node->phone = (char *) malloc (MAXLEN);
  node->mail = (char *) malloc (MAXLEN);
  node->next = NULL;

  strcpy(node->name, name);
  strcpy(node->surname, surname);
  strcpy(node->phone, phone);
  strcpy(node->mail, mail);

  while(head->next) {
    head = head->next;
  }

  head->next = node;

  return node;
}

void deleteNode(Node *head, char *name)
{
	Node *node = (Node *) malloc (sizeof(Node));
	Node *node1 = (Node *) malloc (sizeof(Node));


	  node->name = (char *) malloc (MAXLEN);
	  node->surname = (char *) malloc (MAXLEN);
	  node->phone = (char *) malloc (MAXLEN);
	  node->mail = (char *) malloc (MAXLEN);
	  node->next = NULL;
	  strcpy(node1->name, name);

	  node=head;

	  while(node->next) {
	    if (node->name == node1->name)
	    {
	    	head=node->next;
	    	delete node;
	    }
	  }

	  return;
}

Node *insertNode(Node *head, char *name, char *surname, char *phone, char *mail, int position)
{

    Node *node = (Node *) malloc (sizeof(Node));

      node->name = (char *) malloc (MAXLEN);
      node->surname = (char *) malloc (MAXLEN);
      node->phone = (char *) malloc (MAXLEN);
      node->mail = (char *) malloc (MAXLEN);
      node->next = NULL;

      strcpy(node->name, name);
      strcpy(node->surname, surname);
      strcpy(node->phone, phone);
      strcpy(node->mail, mail);
      int pos=1;

      while (head)

      {
    	  if (pos==position)
    	  {
    		  node->next=head->next;
    		  head->next=node;
    		  pos++;
    	  }
    	  head = head->next;
    	  pos++;
      }
	return head;
}

void printList(Node *head)
{
  int pos = 0;

  while (head) {
    printf("%d: %s %s - %s, %s\n", pos, head->name, head->surname, head->phone, head->mail);
    pos++;

    head = head->next;
  }
}
