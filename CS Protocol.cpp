#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;
struct Book {
string UserName;
string Password;
int Specialnumber1;
int Specialnumber2;
int Specialnumber3;
int equationchoice;
Book* next;
};
typedef Book* book;

void SignUp(book&, book&);
void SignIn(book);
void delete_acc(book&, book&);
void equation(int choice,int SN1,int SN2,int SN3);
int specialnumber(int choice,int SN1,int SN2,int SN3);
int main() {
// This is the Time finder part of the code
  time_t current_time;
  struct tm  local_time;

  time ( &current_time );
  localtime_s(&local_time, &current_time);

  int Year   = local_time.tm_year + 1900;
  int Month  = local_time.tm_mon + 1;
  int Day    = local_time.tm_mday;

  int Hour   = local_time.tm_hour;
  int Min    = local_time.tm_min;
  int Sec    = local_time.tm_sec;
  if (Hour > 12){
    Hour -= 12;
  }
  cout<< Hour<<endl;
  cout<< Min<<endl;
  // End of time finder 

book head = NULL;
book final = NULL;
char C;
while(C != 'Q'){
cout<<"\nSelect an option."<<endl
    <<"Press [U] to Sign Up"<<endl
    <<"Press [I] to Sign In"<<endl
    <<"Press [D] to delete account"<<endl
    <<"Press [Q] to quit"<< endl;
    cin>> C;
    C = toupper(C);
    switch (C) {
        case 'U':
            SignUp(head,final);
            break;
        case 'I':
            SignIn(head);
            break;
        case 'D':
            delete_acc(head,final);
            break;
        case 'Q':
        break;
        default:
                cout<<"invaild Entery\n";

    }

}}

void SignUp(book& head, book& final) {
    bool PasswordNotMatch = true;
    string tp;
    if (head == NULL){
        book temp = new Book;
        cout<<"Enter User Name\n";
        cin>> temp-> UserName;
        while (PasswordNotMatch){
        cout<<"Enter Password\n";
        cin>> temp-> Password;
        cout<<"Renter Password\n";
        cin>> tp;
        if (temp->Password == tp){
            PasswordNotMatch = false;
        }else{
            cout << "Passwords don't match, Renter both Passwords"<<endl;
        }}
        // Start of equation maker
        srand(time(0));
        temp -> Specialnumber1 = rand()% 5 + 1;
        temp -> Specialnumber2 = rand()% 790+1;
        temp-> Specialnumber3 = rand()% 790+1;
        temp-> equationchoice= rand()% 3 +1;
        equation(temp-> equationchoice ,temp -> Specialnumber1,temp -> Specialnumber2,temp-> Specialnumber3);
        //int x = specialnumber(temp-> equationchoice ,temp -> Specialnumber1,temp -> Specialnumber2,temp-> Specialnumber3);
        temp -> next = NULL;
        head = temp;
        final = temp;
    }else{
        book temp1 = new Book;
        cout<<"Enter book title\n";
        cin>> temp1-> UserName;
         while (PasswordNotMatch){
        cout<<"Enter Password\n";
        cin>> temp1-> Password;
        cout<<"Renter Password\n";
        cin>> tp;
        if (temp1->Password == tp){
            PasswordNotMatch = false;
        }else{
            cout << "Passwords don't match, Renter both Passwords"<<endl;
        }}
        srand(time(0));
        temp1 -> Specialnumber1 = rand()% 5;
        temp1 -> Specialnumber2 = rand()% 790;
        temp1-> Specialnumber3 = rand()% 790;
        temp1-> equationchoice= rand()% 3 +1;
        equation(temp1-> equationchoice ,temp1 -> Specialnumber1,temp1 -> Specialnumber2,temp1-> Specialnumber3);
        temp1 -> next = NULL;
        final -> next = temp1;
        final = temp1;
    }
    cout<< "Account successfuly created"<<endl; 
}
void SignIn(book head){
    book NP;
    bool access = true;
    NP = head;
    string UN;
    string pw;
    int SC;
    int count = 0;
    cout << "Enter User Name"<<endl;
    cin >> UN;
    if (NP == NULL){
        cout<<"List is empty"<<endl;
    }else{
    while(NP!= NULL && access){
        if (UN == NP -> UserName){
            cout<< "Enter Password"<<endl;
            cin >> pw;
            if (NP -> Password == pw && count < 3){
                cout << "Use your special equation and enter the six digit number"<<endl;
                cin >> SC;
                int x = specialnumber(NP-> equationchoice ,NP -> Specialnumber1,NP -> Specialnumber2,NP-> Specialnumber3);
                if (x==SC){
                    cout<<"Welcome Back"<<endl;
                    break;
                }else{
                    cout << "Wrong Number"<<endl;
                    break;
                }
            }else if (count < 2){
                cout<< "Invalid Password"<<endl;
                count += 1;
            }else {
                cout<< "access denied"<<endl;
                access = false;
            }
            } else if (NP ->next == NULL) {
                cout<< "Account not found"<<endl;
                break;
            } else if(NP!= NULL){
                NP = NP->next;
            }

           
    }}
}

void delete_acc(book& head, book& final)
{if (head == NULL)
	{
	cout << "List is empty" << endl;
	}else if (head == final) {
        delete head;
        cout<< "Shit";
        head = NULL;
        final = NULL;
    }
	else{
    book temp = head;
    temp = final;
    final = head;
    while(final -> next != temp){
        final = final -> next;
    }
    final -> next = NULL;
    delete temp;

}}

void equation(int choice,int SN1,int SN2,int SN3){
if (choice == 1 ){
    cout<< "This is Your Special equation, make sure to keep it safe"<<endl;
    cout<< "(Local time( 12Hr Format ) + " << SN1 << ") * " << SN2<< " - " << SN3 <<endl;
}else if (choice == 2){
    cout<< "This is Your Special equation, make sure to keep it safe"<<endl;
    cout<< " (Local time( 12Hr Format ) / " << SN1 << ") * " << SN2<< " - " << SN3 <<endl;
} else if (choice == 3){
    cout<< "This is Your Special equation, make sure to keep it safe"<<endl;
    cout<< "(Local time( 12Hr Format ) * " << SN2 << ") / " << SN1<< "  +  " << SN3 <<endl;
}
}

int specialnumber(int choice,int SN1,int SN2,int SN3){
    int SC;
    time_t current_time;
  struct tm  local_time;

  time ( &current_time );
  localtime_s(&local_time, &current_time);
  int Hour1   = local_time.tm_hour;
  int Min1    = local_time.tm_min;
  if (Hour1 > 12){
    Hour1 -= 12;
  }
  int ct;
  ct = Hour1*100 + Min1;
if (choice == 1 ){
    SC = (ct +  SN1) * SN2 - SN3 ;
}else if (choice == 2){
    SC = (ct /  SN1) * SN2 - SN3 ;
} else if (choice == 3){
    SC = (ct *  SN2) / SN1 + SN3 ;
}
//cout<< SC<<endl;
return SC;
}
