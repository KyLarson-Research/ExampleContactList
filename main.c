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
   printf("Name:%s\n", node->contactName);
   printf("Phone number:%s\n", node->contactPhoneNumber);
}
void PrintContactNodes(ContactNode * head);
ContactNode * GetLastContactNode(ContactNode * head);
void FreeContactList(ContactNode * head);
void remove_newline(char * s);
int main(void) {
   /* Type your code here. */
   ContactNode *new, *headObj = (ContactNode *)malloc(sizeof(ContactNode));
   char nameBuf[50], numBuf[50];
   int args;
   InitializeContactNode(headObj, "first", "9288530033");
   fflush(stdin);
   fgets(nameBuf, sizeof(nameBuf), stdin);
   remove_newline(nameBuf);
   while(strlen(nameBuf)!=0){
      fflush(stdin);
      fgets(numBuf, sizeof(numBuf), stdin);
      remove_newline(numBuf);
      
      new = (ContactNode *)malloc(sizeof(ContactNode));
      InitializeContactNode(new, nameBuf, numBuf);
      InsertAfter(GetLastContactNode(headObj), new);
       
      fflush(stdin);
      fgets(nameBuf, sizeof(nameBuf), stdin);
      remove_newline(nameBuf);
   
   }
   PrintContactNodes(headObj);
   FreeContactList(headObj);
   PrintContactNodes(headObj);
   return 0;
} 
void PrintContactNodes(ContactNode * head){
   ContactNode *current;
   current = head;
   printf("CONTACT LIST\n");
   while(current!=NULL){
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
/*
 * typedef struct IntNode_struct {
 *    int dataVal;
 *       struct IntNode_struct* nextNodePtr;
 *       } IntNode;
 *
 / Constructor
void IntNode_Create
(IntNode* thisNode, int dataInit, IntNode* nextLoc) {
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = nextLoc;
}
 Insert newNode after node.
 *  Before: thisNode -- next
 *   After:  thisNode -- newNode -- next
 *    
void IntNode_InsertAfter
(IntNode* thisNode, IntNode* newNode) {
   IntNode* tmpNext = NULL;
   
   tmpNext = thisNode->nextNodePtr; // Remember next
   thisNode->nextNodePtr = newNode; // this -- new -- ?
   newNode->nextNodePtr = tmpNext;  // this -- new -- next
}*/

// Print dataVal
// void IntNode_PrintNodeData(IntNode* thisNode) {
//    printf("%d\n", thisNode->dataVal);
//    }
//
//    // Grab location pointed by nextNodePtr
//    IntNode* IntNode_GetNext(IntNode* thisNode) {
//       return thisNode->nextNodePtr;
//       }
//
//       int main(void) {
//          IntNode* headObj  = NULL; // Create IntNode objects
//             IntNode* nodeObj1 = NULL;
//                IntNode* nodeObj2 = NULL;
//                   IntNode* nodeObj3 = NULL;
//                      IntNode* currObj  = NULL;
//                         
//                            // Front of nodes list
//                               headObj = (IntNode*)malloc(sizeof(IntNode));
//                                  IntNode_Create(headObj, -1, NULL);
//                                     
//                                        // Insert nodes
//                                           nodeObj1 = (IntNode*)malloc(sizeof(IntNode));
//                                              IntNode_Create(nodeObj1, 555, NULL);
//                                                 IntNode_InsertAfter(headObj, nodeObj1);
//                                                    
//                                                       nodeObj2 = (IntNode*)malloc(sizeof(IntNode));
//                                                          IntNode_Create(nodeObj2, 999, NULL);
//                                                             IntNode_InsertAfter(nodeObj1, nodeObj2);
//                                                                
//                                                                   nodeObj3 = (IntNode*)malloc(sizeof(IntNode));
//                                                                      IntNode_Create(nodeObj3, 777, NULL);
//                                                                         IntNode_InsertAfter(nodeObj1, nodeObj3);
//                                                                            
//                                                                               // Print linked list
//                                                                                  currObj = headObj;
//                                                                                     while (currObj != NULL) {
//                                                                                           IntNode_PrintNodeData(currObj);
//                                                                                                 currObj = IntNode_GetNext(currObj);
//                                                                                                    }
//                                                                                                       
//                                                                                                          return 0;
//                                                                                                          }*/

