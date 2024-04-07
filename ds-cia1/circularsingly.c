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
struct node
{
	int data;
	struct node* next;
};
typedef struct node Node;
Node *head = NULL;
Node *last;

void reverse(){
    last = head;
    Node *prev,*curr;
    prev =head;
    head = curr = head->next;
    while(head!=last){
             head = head->next;
             curr->next = prev;
             prev = curr;
             curr= head;
    }
    curr->next = prev;
    head = prev;

    
}
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
        printf("8 Reverse \n");
	    printf("9. ** To exit **");

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
			case 8: reverse();break;
            case 9:exit(0);
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
    else{
              last->next = new  ;
              last = new;
    }
    new->next = head;
}

void display(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
    Node * temp = head;
    printf("Linked List elements : ");

    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}


int getlength(){
    Node * temp = head;
    int i = 0;
    if (temp == NULL) return i;
    do{
        i++;
        temp = temp->next;

    }while(temp!=head);
    return i;
}


void insert_begin(){
        Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;
    if(head == NULL) {head = last = new; head->next = head; return;}
    new->next = head;
    last->next = new;
    head = new;
    

}







void insert_end(){
       Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;
    if(head == NULL) head = last = new;
    else{
              last->next = new  ;
              last = new;
    }
    new->next = head;
}

void insert_pos(){
      int pos;
     printf("Enter pos : ");
     scanf("%d",&pos);
      Node *temp = head;
      if( pos == 0) {insert_begin(); return;}
      if(pos == getlength()) {insert_end();return;}
    Node *new = (Node*)malloc(sizeof(Node));
    printf("Enter data \n");
    scanf("%d",&new->data);
   new->next = NULL;

    if(pos<0 || pos>getlength()){
        printf("Cannot insert\n");
    }

    int i = 1;
    while(i<pos){
        temp = temp->next;
        i++;
    }
    new->next = temp->next;
    temp->next = new;
}


void delete_begin(){
    if(head == NULL){
        printf("Cannot delete\n");
    }
    else if(head->next == head){
        head = last = NULL;
    }
    else{
        last->next = head->next;
        head = head->next;
    }
}
void delete_end(){
    if(head == NULL){
        printf("Cannot delete\n");return;

    }
    if(head->next == head){
        head = last = NULL;
        return;
    }
    else{
        Node *prev;
        Node* temp = head;
        while(temp->next !=head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        last = prev;

    }

}
void delete_pos(){
     int pos;
     printf("Enter pos : ");
     scanf("%d",&pos);
      Node *temp = head;
      if(pos<0 || pos>=getlength()){
        printf("Cannot delete \n");
        return;
      }
      if( pos == 0) {delete_begin(); return;}
      if(pos == getlength()-1) {delete_end();return;}
      else{
        Node *temp =head;
        Node * prev;
        for(int i=0;i<pos;i++){
              prev = temp;
              temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
      }

}

