#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
int getlength();
struct node
{
	int data;
	struct node* next;
};
typedef struct node Node;
Node *head = NULL;
Node *last;
int main()
{
	int choice;
	while(1)
	{
	    printf("\n*\n");
	    printf("0. Create\n");
	    printf("1. display\n");
	    printf("2. Insert Node at beginning\n");
	    printf("3. Insert Node in specific position\n");
	    printf("4. Insert Node at end of LinkedList\n");
	    printf("5. Delete Node at beginning\n");
	    printf("6. Delete Node at end\n");
	    printf("7. Delete Node at position\n");
	    printf("8. ** To exit **");

		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: create();
					break;
			case 1: display();
					break;
			case 2: insert_begin();
					break;
			case 3: insert_pos();
					break;
			case 4: insert_end();
					break;
			case 5: delete_begin();
					break;
			case 6: delete_end();
					break;
			case 7: delete_pos();
					break;
			case 8: exit(0);
			default:printf("\n Wrong Choice");
                    break;
		}
	}
}

void create(){
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;
    if(head == NULL) head = last = new;
    else {
         last->next = new;
         last = new;
    }

}


void display(){
    if(head == NULL){
        printf("Linked list is empty \n");
        return ;
    }
    else{
        printf("LInkedList Content : ");
        Node *temp = head;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void insert_begin(){
        Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;
    if(head == NULL) head = last = new;
    else{
               new->next = head;
               head = new;        
    }

}
void insert_pos(){
      int pos;
     printf("Enter pos : ");
     scanf("%d",&pos);
      Node *temp = head;
      if( pos == 0) {insert_begin(); return;}
      if(pos == getlength()){ insert_end();
      return;
      }
      if(pos<0 || pos>getlength()){
        printf("Cannot insert");
        return;
      }
              Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;

     for(int i = 1;i<pos;i++){

            temp = temp -> next;
     }
     new->next = temp->next;
     temp->next = new;

   
}

void insert_end(){
        Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;
    if(head == NULL) head = last = new;
     else{
        last->next = new;
        last = new;
     }
}

void delete_begin(){
           if(head == NULL){
            printf("Cannot delete \n");
            return;
           }
           Node *temp = head;
            head = head->next;
        free(temp);
}

int getlength(){
    int i = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        i++;
    }
    return i;
}

void delete_end(){
    if(head == NULL){
        printf("Cannot delete \n");
        return;
    }
    if(head->next == NULL){
       last =  head = NULL;
       return;
    }
    Node *prev;
    Node *temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
     prev->next = NULL;
    last = prev;
    
} 

void delete_pos(){
          int pos;
     printf("Enter pos : ");
     scanf("%d",&pos);
      Node *temp = head;
      if( pos == 0) {delete_begin(); return;}
      if(pos == getlength()-1){
        delete_end();
        return;
      }
      if(pos <0 || pos>=getlength()){
        printf("Cannot delete\n");
        return;
      }
      Node *prev = NULL;
      for(int i = 0;i<pos;i++){
        
           prev = temp;
           temp = temp->next;
      }
         prev->next = temp->next;
 
     free(temp);
}


