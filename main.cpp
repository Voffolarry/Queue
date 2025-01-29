#include <iostream>  //for cin and cout
//#include <windows.h>  //for sleep
#include <time.h>    // for clock
#include <string.h> //strcpy
#include <stdlib.h> //for the random function
#include <unistd.h>// for sleep function
// declaration of a structure node to store name (in data ) and store address (next)
struct node{
    char data[20];
    node* next;
};




/*----------------------DECLARATION OF THE FUNCTION PROTOTYPES------------------------*/
void display(node* names);
void enqueue(node*& names,node*& names_b ,char name[20]);
void dequeue(node*& names_f);


/*-------------------THE MAIN FUNCTION------------------*/
int main(){
    node* names_f=nullptr;// the front of the queue/head
    node* names_b=nullptr;//the rear of the queue/tail
    int i=0;
    int j=0;
    int random;//to store the random number 
    char a[20];
    int index_name=0;//to knew which name will d]be taken in the array
    int index_b=0;//to limit the number of clients
    int index_f=0;//index of the first client
    char store_client[10][100];
    //  \033[1;31  \033[0m
    //to simulate the arrival of clients of differents names 
    char array[100][10]={"larry","larson","jenny","lisa","miranda","megane","alicia","fred","sebastian","marie","lorel","laeticia","marcus","robert","simon","pierre","nicolas","nadine","shella","baptiste","logan","zayne","jake","zack","milene","maurice","orlane","otis","lyana","alphonse","bobby","nalla","nolwen","diam's","adele","melissa","samantha","carla","karl","maelys","ebony","thomas","julie","axel","julien","lenie","helena","franck","ulysse","\0"};// array[a][b]  a is for num of character and b is for num of word
    //message for users 
    std::cout<<" === ==== QUEUE SIMULATION ==== === \n";
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
    //informing the user about the diffrents probabilities
    std::cout<<"Probability of a client arriving 0.44 \n";
    std::cout<<"Probability of a client to be serve 0.66 \n";//we served the client is dequeue (remove from the queue)
    // display of empty queue
    display(names_f);
    srand(time(NULL));//randomize so as to respect stochastic properties
    while(true)
    {
        random=rand()%9+1;//generate a number between 1 and 9
        //determining if it will be a dequeue or an enqueue operation    
        if((random%2)==0){ //if even then we enqueue
        if(index_b==9)//to limit maximun 10 personne in the queue
        {//messsage for user about the queue
            std::cout<<"queue is full\n";
        }
        else {
            //function call
        enqueue(names_f,names_b,array[index_name]);
        //information about the arrival of clents 
        std::cout<<"The client- "<<array[index_name]<<" has arrived\n";
        sleep(1);// to delay the display
        //function call
        display(names_f);
        index_b++;//incrementation of index_b to know if the maximum number of users has arrived the queue/since we want 10 people
        index_name++;// incrementing to go to the next name of array
        std::cout<<"\n";// to go to the next line 
        }

        }
        else// if its an odd number then we do  a dequeue operation
        {

            if(index_b>0){// to be sure there are clients in the queue 
                std::cout<<"The client- "<<array[index_f]<<" has been served\n";
                sleep(1);// delay 
                index_f++;
                dequeue(names_f);
                display(names_f);
                index_b--;//if we dequeue then we should reduce the index_b since a client left
                std::cout<<"\n";// moving to the next line
            }
            /*else if(index_b==0)//message for the user
            {
                std::cout<<"queue is empty\n";
            }*/
        }
           sleep(2);//to delay the printing

        if(index_name==10){// to stop the execution, after a certain number of names from array have been use
        break;
         }
    }
    
   delete names_f;//free the memory
   delete names_b;//
}


/*------------------IMPLEMENTATION OF THE FUNCTION PROTOYPES--------------------*/


// Implementation of the Dequeue function used to remove the first name of the queue and replace with the second

// Dequeue function to remove the front client from the queue
void dequeue(node*& names_f){//passing of parameter by reference to maintain the correct sate of queue
    if (names_f != nullptr) {
        node* temp = names_f;
        names_f = names_f->next;  // Move the head pointer to the next node
        delete temp;  // Free the memory of the old head node
    }
}

// Implementation of the Enqueue function used to add names of clients behind the last element in the list
void enqueue(node*& names_f,node*& names_b ,char name[20])//passing of parameter by reference to maintain the correct sate of queue
{
    //creation of new node to store the name 
    node* new_node=new node ;
    strcpy(new_node->data,name);//copy the content of name and storing in the (new_node->data)
    new_node->next=nullptr;//make new node to point to null as there is no other element at the end of the list

    if(names_b==nullptr){//to verify if queue is empty
        names_f=names_b=new_node;//when the queue is empty the front = back
    }
    else{
        names_b->next =new_node; // linking names_b to the address of new_node 
        names_b=new_node; // making new_node to be consider as the rear point
    }

    delete new_node;//deallocating the memory
} 

// The display function used to display the state of the list when the clients have arrived and left
void display(node* names_f){//passing of parameter by reference to maintain the correct sate of queue
    
    std::cout<<"**State: ";
    int i=0;
    if(names_f != nullptr){// that's it contain clients
        node* current =names_f;//creation of current for printing so as to avoid a removal/change of clients
        while(current!=nullptr){//repeat the loop till we found  null 
            std::cout<<" Client-" <<current->data;//print the data content at current->data
            current=current->next;//assigning current to the next list 
        }
        delete current;//deallocating the memory
    }
    else{
        std::cout<<" queue is empty\n";
    }
    std::cout<<"\n";//goes to next line 
}