#include <iostream>  
#include <time.h>    // for clock
#include <string.h> //strcpy
#include <stdlib.h> //for the random function
#include <unistd.h>// for sleep function


// Declaration of a structure node to store name (in data ) and store address (next)
struct node{
    char data[20];
    node* next;
};



/*----------------------DECLARATION OF THE FUNCTION PROTOTYPES------------------------*/
void display(node* names);
void enqueue(node*& names,node*& names_b ,char name[20]);
void dequeue(node*& names_f, node*& names_b);


/*-------------------THE MAIN FUNCTION------------------*/
int main(){

    node* names_f=nullptr;// The front of the queue/head
    node* names_b=nullptr;//The rear of the queue/tail
    int random;//To store the random number
    int index_name=0;//To knew which name will d]be taken in the array
    int index_b=0;//To limit the number of clients
    int index_f=0;//Index of the first client

    //To simulate the arrival of clients of differents names 
    char array[100][10]={"larry","larson","jenny","lisa","miranda","megane","alicia","fred","sebastian",
                        "marie","lorel","laeticia","marcus","robert","simon","pierre","nicolas","nadine",
                        "shella","baptiste","logan","zayne","jake","zack","milene","maurice","orlane","otis",
                        "lyana","alphonse","bobby","nalla","nolwen","diam's","adele","melissa","samantha","carla",
                        "karl","maelys","ebony","thomas","julie","axel","julien","lenie","helena","franck","ulysse",
                        "\0"};

    //Display program start message 
    std::cout<<" === ==== QUEUE SIMULATION ==== === \n";
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
    //Informing the user about the diffrents probabilities
    std::cout<<"Probability of a client arriving 0.44 \n";
    std::cout<<"Probability of a client to be serve 0.66 \n";

   
    display(names_f);   // Display of empty queue
    srand(time(NULL));//Randomize so as to respect stochastic properties

    while(true)
    {
        random=rand()%9+1;//generate a number between 1 and 9

        //Determining if it will be a dequeue or an enqueue operation    
        if((random%2)==0){ //If even then we enqueue
            if(index_b==9)   //To limit maximun 10 people in the queue
            {
                std::cout<<"Queue is full\n";
            }
            else {
               //Function call
                enqueue(names_f,names_b,array[index_name]);

              //Information about the arrival of clents 
                std::cout<<"The client-- "<<array[index_name]<<" has arrived\n";
                sleep(1);// To delay the display
              //Function call
                display(names_f);
                index_b++;//Incrementation of index_b to know if the maximum number of clients we want has arrived the queue
                index_name++;// Incrementing to go to the next name of array
                std::cout<<"\n";// To go to the next line 
           }

        }
        else  // If its an odd number then we do  a dequeue operation
        {
            if(index_b>0){  // To be sure there are clients in the queue 
                std::cout<<"The client-- "<<array[index_f]<<" has been served\n";
                sleep(1);
                index_f++;
                dequeue(names_f, names_b);
                display(names_f);
                index_b--;   //If we dequeue then we should reduce the index_b since a client left
                std::cout<<"\n";
            }
            else if(index_b==0)
            {
                std::cout<<"Queue is empty\n";
            }
        }
           sleep(2);

        if(index_name==10){// To stop the execution, after a certain number of names from array have been use
        break;
         }
    }
    //free the memory
   delete names_f;
   delete names_b;

return 0;   
}


/*------------------IMPLEMENTATION OF THE FUNCTION PROTOYPES--------------------*/

// Dequeue function to remove the front client from the queue
void dequeue(node*& names_f, node*& names_b){  //Passing of parameter by reference to maintain the correct sate of queue
    if (names_f != nullptr) {
        node* temp = names_f;
        names_f = names_f->next;  // Move the head pointer to the next node
        if(names_f == nullptr){
            names_b = nullptr;   //If the queue becomes empty, we set the rear pointer to nullptr
        }
        delete temp;  // Free the memory of the old head node
    }
}



// Implementation of the Enqueue function used to add names of clients behind the last element in the list

void enqueue(node*& names_f,node*& names_b ,char name[20])//Passing of parameter by reference to maintain the correct sate of queue
{
    //Creation of new node to store the name 
    node* new_node = new node ;
    strcpy(new_node->data,name);   //Copy the content of name and storing in the (new_node->data)
    new_node->next = nullptr;   //Make new node to point to null as there is no other element at the end of the list

    if(names_b == nullptr){   //To verify if queue is empty
        names_f = names_b = new_node;   //When the queue is empty the front = back
    }
    else{
        names_b->next = new_node; // Linking names_b to the address of new_node 
        names_b = new_node; // Making new_node to be consider as the rear point
    }
} 



// The display function used to display the state of the list when the clients have arrived and left

void display(node* names_f){
    
    std::cout<<"**State: ";
    if(names_f != nullptr){  // If there are clients in the queue
        node* current =names_f;    //Creation of current for printing so as to avoid a removal/change of clients
        while(current!=nullptr){  //Repeat the loop till we found  null 
            std::cout<<" Client -- " <<current->data << " ";
            current=current->next;    //Assigning current to the next list 
        }
    }
    else{
        std::cout<<" Queue is empty\n";
    }
    std::cout<<"\n";//Goes to next line 
}