//Oct.19, 2020
//By: Ishpreet Nagi

#include <iostream> //adding all my libraries
#include <bits/stdc++.h>
using namespace std;

void title() //this function is to just display the title screen to greet the user to the program
{
    cout << "\t\t\t\t\t\t       Welcome to the" << endl; //messages for the user
    cout << "\t\t\t\t\t\tAll Creatures Big and Small...\n" << endl;
    cout << "\t\t\t\t\t    ___                  _   _             " << endl; //some art to make my code look a bit more appealing
    cout << "\t\t\t\t\t   /   \\___  _ __   __ _| |_(_) ___  _ __  " << endl;
    cout << "\t\t\t\t\t  / /\\ / _ \\| '_ \\ / _` | __| |/ _ \\| '_ \\ " << endl;
    cout << "\t\t\t\t\t / /_// (_) | | | | (_| | |_| | (_) | | | |" << endl;
    cout << "\t\t\t\t\t/___,' \\___/|_| |_|\\__,_|\\__|_|\\___/|_| |_|" << endl;
    cout << "\t\t\t\t       ___                _           _            " << endl;
    cout << "\t\t\t\t      / __\\   _ _ __   __| |_ __ __ _(_)___  ___ _ __ " << endl;
    cout << "\t\t\t\t     / _\\| | | | '_ \\ / _` | '__/ _` | / __|/ _ \\ '__|" << endl;
    cout << "\t\t\t\t    / /  | |_| | | | | (_| | | | (_| | \\__ \\  __/ |   " << endl;
    cout << "\t\t\t\t   \\/    \\__,_|_| |_|\\__,_|_|  \\__,_|_|___/\\___|_|   \n" << endl;
}

void time() //this function contains the the code that gets the time from the computer and displays along with some messages for the user
{
    time_t currentTime = time(0); //this code will read and collect the time and date from the computer on which it is being run
    char * dateTime = ctime(&currentTime);
    cout << "\t\t\t\t\t       " << dateTime << endl; //displays the time and date which had been collected before
    cout << "\t\t\t ***THANK YOU FOR TAKING THE TIME TO COME OUT TO THIS EVENT TONIGHT***" << endl; //message for the user
    cout << "\t\t\t\t     ***WE ALL GREATLY APPRECIATE YOUR SUPPORT***" << endl;
}

struct DONATIONS_TYPE //creates the structure that will be used throughout this code
{
    string name, number; //declares the variables within the structure
    double amount;
};

string confirm() //a function to give the user the choice to change their donation amount right before they submit the money
{
    string answer; //declares the variable
    do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
        cout << "Would you like to confirm this donation amount (Y/N): "; cin >> answer; //tells the user what they need to enter and then stores that input in the variable
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower); //takes whatever string value the user enters and makes it lowercase
        if(answer != "y" && answer != "n" && answer != "yes" && answer != "no")
            {
                cout << "\n***CHOOSE BETWEEN Y or N***\n" << endl; //error message
            }
    } while(answer != "y" && answer != "n" && answer != "yes" && answer != "no"); //the requirement that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input

    return(answer); //returns the answer of the user back to the main
}

void sorting(vector<DONATIONS_TYPE> &donor) //the function for sorting the structure array from highest to smallest donation amount
{
    DONATIONS_TYPE temp; //creates a temporary array that could be used to sort the original array
    for(int i=1;i<donor.size();i++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is the size of the structure array
    {
        for(int j=0;j<donor.size();j++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is the size of the structure array
        {
            if (donor[i].amount > donor[j].amount) //sees if the donation amount value in the first structure array is bigger than the next structure array and keeps going down the array comparing the donation amount values in the structures with each other
            {
                temp = donor[j]; //stores the contents of the original structure array spot into the temporary structure array
                donor[j] = donor[i]; //makes the first structure array variables all the same as the contents of the structure array variable in the next spot
                donor[i] = temp; //makes the structure array variables all equal to the contents of the variables in the temp structure array
            }
        }
    }
    return; //returns back to the main
}

void printdonors(vector<DONATIONS_TYPE> &donor) //the function to print and display the details of all the people that donated
{
    cout << " ---------------------------------" << endl; //message for the user
    cout << "| LIST OF ALL PEOPLE THAT DONATED |" << endl;
    cout << " ---------------------------------\n" << endl;
    cout << "(NAME | PHONE# | DONATION)\n" << endl;

    for(int x=0;x<donor.size();x++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is the size of the structure array
    {
        cout << donor[x].name << "   |   " << donor[x].number << "   |   $" << donor[x].amount << endl; //this where the inputs stores in the variables within the structure array are actually pulled and displayed on the screen
        cout << endl; //creates a space between the texts
    }
    return; //returns to the main
}

void printhighest(vector<DONATIONS_TYPE> &donor) //this functions displays the names of the people that donated the highest amounts of money
{
    cout << "\n --------------------" << endl; //message for the user
    cout << "| HIGHEST DONATOR(s) |" << endl;
    cout << " --------------------\n" << endl;

    if(donor[0].amount == donor[1].amount && donor[0].amount == donor[2].amount)
    {
        for(int p=0;p<3;p++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is 3
        {
            cout << donor[p].name << "     $" << donor[p].amount << endl; //pulls the names of the people and the money they donated from the structure array and displays it
            cout << endl; //creates a space between the texts
        }
    }
    else if(donor[0].amount == donor[1].amount)
    {
        for(int q=0;q<2;q++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is 2
        {
            cout << donor[q].name << "     $" << donor[q].amount << endl; //pulls the names of the people and the money they donated from the structure array and displays it
            cout << endl; //creates a space between the texts
        }
    }
    else
    {
        cout << donor[0].name << "     $" << donor[0].amount << endl; //pulls the names of the people and the money they donated from the structure array and displays it
    }
    return; //returns to the main
}

void average(vector<DONATIONS_TYPE> &donor) //this functions does the math to calculate the total amount of money donated and the average money that was donated
{
    double total = 0; //declares a variable and makes it equal zero

    cout << "\n ---------------------" << endl; //message for the user
    cout << "| DONATION COLLECTION |" << endl;
    cout << " ---------------------\n" << endl;

    for(int w=0;w<donor.size();w++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is the size of the structure array
    {
        total += donor[w].amount; //pulls the amount of money each person donated from the structure array and adds it to the total variable
    }

    cout << "TOTAL: $" << total << endl; //displays the total to the user

    total = total/donor.size(); //divides the total variable by the size of the structure array and makes it equal the total variable

    cout << "AVERAGE: $" << total << endl; //displays the average to the user

    return; //returns to the main
}

int main()
{
    system("color F1"); //changes the color of the background and the text
    int people; //declares a variable
    cout << fixed << setprecision(2); //makes it so only two decimal places of double values can be displayed on screen

    title(); //calls the title function
    system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
    system("CLS"); //clears the screen and allows for the new content to be displayed cleanly
    time(); //calls the time function

    do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
        cout << "\nNumber of people donating today: "; cin >> people;//tells the user what they need to enter and then stores that input in the variable
        cin.ignore();
        if(people <= 0)
        {
            cout << "\n***NUMBER OF PEOPLE CANNOT BE LESS THAN OR EQUAL TO 0***" << endl; //error message
        }
    } while(people <= 0); //the requirement that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input

    vector<DONATIONS_TYPE>donor(people); //creates the structure array and specifies how many of there should be depending on how many the user entered they wanted

    for (int i=0;i<people;i++) //keeps looping the things within itself as long as the integer is less than the parameter specified, which in this case is the size of the structure array
    {
        cout << " \n -----------" << endl; //message for the user
        cout << "| DONOR " << i+1 << "   |" << endl;
        cout << " -----------\n" << endl;

        cout << "Name: "; //message for the user
        getline(cin,donor[i].name); //stores the input of the user into the variable along with any extra characters the user enters
        cout << "Phone Number: "; //message for the user
        getline(cin,donor[i].number); //stores the input of the user into the variable along with any extra characters the user enters

        while(true)
        {
            do{ //begins the do-while loop that would allow for the user to enter the option again if they enter an illegal input
                cout << "Donation Amount: $"; cin >> donor[i].amount; //tells the user what they need to enter and then stores that input in the variable
                if(donor[i].amount < 0)
                {
                    cout << "***DONATION AMOUNT CANNOT BE LESS THAN 0!***" << endl; //error message
                }
            } while(donor[i].amount < 0); //the requirement that once met, will cause the do-while loop to repeat, thus not letting them exit the loop until they have entered the correct input

            cout << endl; //creates a space between texts

            string ans = confirm(); //calls the confirm functions and stores what it returns in the variable

            if(ans == "y" || ans == "yes")
            {
                break; //breaks out of the while true loop
            }
            else
            {
                cout << endl; //creates a space between texts
                continue; //starts the while true loop again
            }
        }
        cin.ignore();
    }
    sorting(donor); //calls the sorting function and sends the variable it will need

    cout << endl; //creates a space between texts
    system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
    system("CLS"); //clears the screen and allows for the new content to be displayed cleanly
    printdonors(donor); //calls the printdonors function and sends the variable it will need to it

    cout << "****************************************************************" << endl;
    cout << "****************************************************************" << endl;
    printhighest(donor); //calls the printhighest function and sends the variable it will need to it

    cout << "\n****************************************************************" << endl;
    cout << "****************************************************************" << endl;
    average(donor); //calls the average function and sends the variable it will need with it

    cout << endl; //creates a space between texts
    system("pause"); //pauses the screen so the user gets a chance to properly look at everything before they can press a button to keep moving
    system("CLS"); //clears the screen and allows for the new content to be displayed cleanly

    cout << "\t\t\t\t Thank you to everyone that came out today and donated!" << endl; //message for the user
    cout << "\t\t\tWe will make sure this money goes toward helping stray animals find a home!" << endl;
    cout << "\t\t\t\t\t\tHave a wonderful day!" << endl;
    exit(0); //ends the entire code
}
