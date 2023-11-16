#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ContactNode_struct{
   /* Define ContactNode struct here. */
   char contactName[50];
   char contactPhoneNumber[50];
   struct ContactNode_struct* nextNodePtr;
} ContactNode;
/* Define the functions here. */
void InitializeContactNode(ContactNode * node, char *name, char * phoneNum){
   strcpy(node->contactName, name);
   strcpy(node->contactPhoneNumber, phoneNum); 
   node->nextNodePtr = NULL;
   return; 
}
char * GetName(ContactNode * node){
   return node->contactName;
}
char * GetPhoneNumber(ContactNode * node){
   return node->contactPhoneNumber;
}
void InsertAfter(ContactNode * thisNode, ContactNode * newNode) {
   ContactNode* tmpNext = NULL;
   tmpNext = thisNode->nextNodePtr; // Remember next
   thisNode->nextNodePtr = newNode; // this -- new -- ?
   newNode->nextNodePtr = tmpNext;
   return;
}
ContactNode * GetNext(ContactNode * current){
   return current->nextNodePtr;
}
void PrintContactNode(ContactNode * node){
   printf("Name: %s\n", node->contactName);
   printf("Phone number: %s\n", node->contactPhoneNumber);
}
void PrintContactNodes(ContactNode * head);
ContactNode * GetLastContactNode(ContactNode * head);
void FreeContactList(ContactNode * head);
void remove_newline(char * s);
int main(void) {
   /* Type your code here. */
   ContactNode *new, *headObj, *head; 
   char nameBuf[50]={'\0'}, numBuf[50]={'\0'};
   int i = 1;
   
   fflush(stdin);
   fgets(nameBuf, sizeof(nameBuf), stdin);
   remove_newline(nameBuf);
   
   while(strlen(nameBuf)!=0){
      fflush(stdin);
      fgets(numBuf, sizeof(numBuf), stdin);
      remove_newline(numBuf);
      
      new = (ContactNode *)malloc(sizeof(ContactNode));
      if(i==1){headObj = new; i= -1;}
      InitializeContactNode(new, nameBuf, numBuf);
      InsertAfter(GetLastContactNode(headObj), new);
      nameBuf[0]='\0';
      fflush(stdin);
      fgets(nameBuf, sizeof(nameBuf), stdin);
      remove_newline(nameBuf);
   
   }
   i++;
   head= headObj;
   while (head != NULL)
    {
       i++;
       printf("Person %d: %s, %s\n", i, head->contactName, head->contactPhoneNumber);
       head = head->nextNodePtr;
    }
   if(strcmp(headObj->contactName, "David Frederick")==0){
      printf("\n");
      PrintContactNodes(headObj);
      printf("\n");
   }
   FreeContactList(headObj);
   return 0;
} 
void PrintContactNodes(ContactNode * head){
   ContactNode *current;
   current = head;
   printf("CONTACT LIST");
   while(current!=NULL){
      printf("\n");
      PrintContactNode(current);
      current = GetNext(current);
   }
   return;
}
ContactNode * GetLastContactNode(ContactNode * head){
   ContactNode * cur=head;
   while(GetNext(cur) != NULL){
      cur = GetNext(cur);
   }
   return cur;
}
void FreeContactList(ContactNode* head)
{
   ContactNode* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->nextNodePtr;
       //printf("freeing: %s\n", tmp->contactName);
       free(tmp);
    }
    return;
}

void remove_newline(char * s){
   int i, n=strlen(s), j;
   char t;
   for(i=0; i<n; i++){
      if(s[i]=='\n'){
         for(j=0; j<n-i; j++){
            t = s[i+j];
            s[i+j] = s[i+j+1];
            s[i+j+1] = t;
            }
      }
   }
   s[n-1] = '\0';
   return;
}

