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
void enqueue(node* names,char name[20]);
void dequeue(char array[10][100] );


/*-------------------THE MAIN FUNCTION------------------*/
int main(){
    node* names_f=nullptr;// the head of the queue
    node* names_b=nullptr;//the tail of the queue
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
    //informing the user about the diffrents probability
    std::cout<<"Probability of a client arriving 0.44 \n";
    std::cout<<"Probability of a client to be serve 0.66 \n";
    // display of empty queue
    display(names_f);
    srand(time(NULL));//randomize so as to repest stochastic properties
    while(true)
    {
        random=rand()%10+1;//generate a number between 0 and 9
        //determining if it will be a dequeue or an enqueue operation    
        if((random%2)==0){ //if even then we enqueue
        //if even the i enqueue else i dequeue 
        if(index_b==9)//to limit maximun 10 personne in the queue
        {//messsage for user about the queue
            std::cout<<"queue is full\n";
        }
        else {
            //function call
        enqueue(names_f,array[index_name]);//a==name
        //information about the arrival of clents 
        std::cout<<"The client- "<<store_client[index_b]<<" has arrived\n";
        sleep(1);// to delay the display
        //function call
        display(names_f);
        index_b++;//incrementation of index_b to know if the maximum number of users have arrive 
        index_name++;// incrementing to go to the next name of array
        std::cout<<"\n";// to go to the next line 
        }

        }
        else// if its an odd number the we do the a dequeue opertaion
        {

            if(index_b>0){// j is for if there are already 3 people in the line,index_b there is still space in the line
                std::cout<<"The client- "<<store_client[index_f]<<" has been served\n";
                sleep(1);// delay 
                dequeue(store_client);
                display(names_f);
                index_b--;//if the dequeue the we should reduce the index_d since a client left
                std::cout<<"\n";// moving to the next line
            }
            else if(index_b==0)//message for the user
            {
                std::cout<<"queue is empty\n";
            }
        }
           sleep(2);//to delay the printing

        if(index_name==30){// to stop the execution after a certain number of names from array have been us
        break;
         }
    }
    
   free(names_f);//free the memory
   free(names_b);//
}


/*------------------IMPLEMENTATION OF THE FUNCTION PROTOYPES--------------------*/


// Implementation of the Dequeue function used to remove the first name of the queue and replace with the second

void dequeue(char array[10][100]){
    for(int i=0;i<10;i++){
            strcpy(array[i],array[i+1]);
    }
}

// Implementation of the Enqueue function used to add names of clients behind the last element in the list
void enqueue(node* names ,char name[20])
{
    //creation of new node to store the name 
    node* new_node=new node ;
    strcpy(new_node->data,name);//copy the content of name and storing in the new name(new_node->data)
    new_node->next=nullptr;//make new node to point to null as there is no other element at the end of the list
    names->next=new_node;//makes the names to point to  new to the new_node
    names=new_node;
    free(new_node);//deallocating the memory
} 

// The display function used to display the state of the list when the clients have arrived and left
void display(node* names_f){
    
    std::cout<<"**State: ";
    int i=0;
    if(names_f != nullptr){// that's it contain clients
        node* current =names_f;//creation of current for printing so as to avoid a removal/change of clients
        while(current!=nullptr){//repeat the loop till we found  null 
            std::cout<<" Client-" <<current->data;//print the data content at current->data
            current=current->next;//assigning current to the next list 
        }
        free(current);//deallocating the memory
    }
    else{
        std::cout<<" Client-";
    }
    std::cout<<"\n";//goes to next line 
}