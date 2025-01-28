#include <iostream>  //for cin and cout
//#include <windows.h>  //for sleep
#include <time.h>    // for clock
#include <string.h> //strcpy
#include <stdlib.h> //for the random function
#include <unistd.h>

/*----------------------DECLARATION OF THE FUNCTION PROTOTYPES------------------------*/

void insert(char array[10][100]);
void fill(char array[10][100],int i);
void display(char array[10][100]);
void enqueue(char array[10][100] ,int index,char name[20]);
void dequeue(char array[10][100] );

/*-------------------THE MAIN FUNCTION------------------*/
int main(){
    int i=0;
    int j=0;
    int random;
    char a[20];
    int index_name=0;
    int index_f=0;
    int index_b=0;
    char store_client[10][100];
    //  \033[1;31  \033[0m
    char array[100][10]={"larry","larson","jenny","lisa","miranda","megane","alicia","fred","sebastian","marie","lorel","laeticia","marcus","robert","simon","pierre","nicolas","nadine","shella","baptiste","logan","zayne","jake","zack","milene","maurice","orlane","otis","lyana","alphonse","bobby","nalla","nolwen","diam's","adele","melissa","samantha","carla","karl","maelys","ebony","thomas","julie","axel","julien","lenie","helena","franck","ulysse","\0"};// array[a][b]  a is for num of character and b is for num of word
    std::cout<<" === ==== QUEUE SIMULATION ==== === \n";
    std::cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
    fill(store_client,index_b);
    display(store_client);
    srand(time(NULL));
    while(true){
        random=rand()%10;//generate a number between 0 and 9
        if((random%2)==0){ // if the remainder when divided by 2 is equal to 0, execute    
        
        if(index_b==9)
        {
            std::cout<<"queue is full\n";
        }

        else {
            enqueue(store_client,index_b,array[index_name]);//a==name
        std::cout<<"The client- "<<store_client[index_b]<<" has arrived\n";
        sleep(1);
        display(store_client);
        index_b++;
        index_name++;
        std::cout<<"\n";
        }

        }
        else
        {

            if(index_b>0){// j is for if there are already 3 people in the line,index_b there is still space in the line
                std::cout<<"The client- "<<store_client[index_f]<<" has been served\n";
                sleep(1);// delay 
                dequeue(store_client);
                display(store_client);
                index_b--;
                j=0;
                std::cout<<"\n";
            }
            else if(index_b==0)
            {
                std::cout<<"queue is empty\n";
            }
        }
        j++;
    sleep(2);
    fill(store_client,index_b);


    if(index_name==30){
        break;
    }


    }
    
    
    
    /*
    
    while(true){
        a=clock(); 
        int store_client[10];
        fill(store_client);
        if(a==2)
         {
        

         }
        display(store_client);

        system("cls");

        std::cout<<"\n";
    }*/
}
/*------------------IMPLEMENTATION OF THE FUNCTION PROTOYPES--------------------*/

/* The fill function used to fill the remaining cells with a character 
    to indicate that there is still space for other clients
*/
void fill(char array[10][100],int j){

    int i;
    char a[10]={'-'};
    for(i=j;i<10;i++){
        if(strcmp(array[i],a)==!0)
        {
            {
                strcpy(array[i],a);

        }
        }
    }
}
// Implementation of the Dequeue function used to remove the first name of the queue and replace with the second

void dequeue(char array[10][100]){
    for(int i=0;i<10;i++){
            strcpy(array[i],array[i+1]);
    }
}

// Implementation of the Enqueue function used to add names of clients behind the last element in the list
void enqueue(char array[10][100] ,int index,char name[20])
{
    if(index==10){
        std::cout<<"full"; //If the space dedicated for the names is full, the message is displayed
    }
    else{
        strcpy(array[index],name); // if the space is not full, we add names untill it is full
    }
    std::cout<<"\n";

} 

// The display function used to display the state of the list when the clients have arrived and left
void display(char store_client[10][100]){
    std::cout<<"**State: ";
    for(int i=0;i<10;i++){
        std::cout<<" Client-"<< store_client[i];
    }
    std::cout<<"\n";
}