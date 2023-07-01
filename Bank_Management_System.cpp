#include<iostream>
using namespace std;

struct node{
    int data;
    long account_number[800000];  // 9 digits
    long account_id[80000];    // 4 digits
    long balance;
    string Gender;
    string acc_num;
    string acc_id;
    double branch_id[2000];
    string bran_id;
    string account_type;
    node* head;
    node* root;
    node* parent;
    node* current;
    node* left;
    node* right;
    node* new_node;
};
 

void insert(struct node* &head,string acc_num, string acc_id, string bran_id, long balance, string Gender, string account_type){
    
    struct node* current;
    struct node* parent;
    struct node* new_node;
    
    new_node = (struct node*) malloc(sizeof(struct node));

    new_node->acc_num = acc_num;
    new_node->acc_id = acc_id;
    new_node->bran_id = bran_id;
    new_node->balance = balance;
    new_node->Gender = Gender;
    new_node->account_type = account_type;

    new_node->left = NULL;
    new_node->right = NULL;

    if(head==NULL){
        head=new_node;
    }

    else{
        current = head;
        parent = NULL;

        while(current!=NULL){
            parent = current;
            if(acc_num < parent->acc_num){
                current=current->left;
                if(current==NULL){
                    parent->left = new_node;
                     
                }
            }  
            else{
                current=current->right;
                if(current==NULL){
                    parent->right=new_node;
                  
                }
            }
        }
    } 
}

void search(struct node* temp, string number){

    int count=0;
      
    if(temp==NULL){
        cout<<"NO DATA is present"<<endl;
    }
    if(temp->acc_num==number){
        cout<<temp->acc_num<<" has been found and it's details are !"<<endl;
        cout<<"Your current Balance is = "<<temp->balance<<endl;
        cout<<"Your Account Number is = "<<temp->acc_num<<endl;
        cout<<"Your Account ID is = "<<temp->acc_id<<endl;
        cout<<"Your Branch ID is = "<<temp->bran_id<<endl;
        cout<<"Your Gender is = "<<temp->Gender<<endl;
    }
    else{

        while(temp!=NULL){
            if(temp->acc_num==number){
                count++;
                cout<<temp->acc_num<<" has been found and it's details are !"<<endl;
                cout<<"Your current Balance is = "<<temp->balance<<endl;
                cout<<"Your Account Number is = "<<temp->acc_num<<endl;
                cout<<"Your Account ID is = "<<temp->acc_id<<endl;
                cout<<"Your Branch ID is = "<<temp->bran_id<<endl;
                cout<<"Your Gender is = "<<temp->Gender<<endl;
                break; 
            }
            else if(temp->acc_num > number){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        
        
        if(count==0){
        cout<<"OOPS ! "<<temp->acc_num<<" account not found in our system."<<endl;
        }
        
        
        // if(temp->data > number){
        //     while(temp!=NULL){
        //         temp=temp->left;
        //         if(temp->data==number){
        //             count++;
        //             cout<<temp->data<<" has been found !"<<endl;
        //             break;
        //         }
        //     }
        //     if(count==0){
        //         cout<<"OOPS ! Not Found...."<<endl;
        //     }
        // }

        // if(temp->data < number){
        //     while(temp!=NULL){
        //         temp=temp->right;
        //         if(temp->data==number){
        //             count++;
        //             cout<<temp->data<<" has been found !"<<endl;
        //             break;
        //         }
        //     }
        //     if(count==0){
        //         cout<<"OOPS ! Not found...."<<endl;
        //     }
        // }

         
    }
}

 

void deposit(struct node* temp){
    double money;
    string account_num;
    int count=0;

    cout<<"Enter the account number = ";
    cin>>account_num;
    cout<<endl;

    if(temp==NULL){
        cout<<"NO DATA is present"<<endl;
    }
    
    if(temp->acc_num==account_num){
        cout<<"Account Number = "<<temp->acc_num<<" has been found and it's details are !"<<endl;
        cout<<"Your current Balance is = "<<temp->balance<<endl;
        cout<<"Now Please enter the amount you want to deposit = ";
        cin>>money;
        double money_1=temp->balance + money;
        temp->balance=money_1;
        cout<<"Now your new Balance is = "<<temp->balance;
        cout<<endl;
    }
    
    else{

        while(temp!=NULL){
            if(temp->acc_num==account_num){
                count++;
                cout<<"Account Number = "<<temp->acc_num<<" has been found and it's details are !"<<endl;
                cout<<"Your current Balance is = "<<temp->balance<<endl;
                cout<<"Now Please enter the amount you want to deposit = ";
                cin>>money;
                double money_1=temp->balance + money;
                temp->balance=money_1;
                cout<<"Now your new Balance is = "<<temp->balance; 
                cout<<endl;               
                break; 
            }
            else if(temp->acc_num > account_num){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        
        
        if(count==0){
        cout<<"OOPS ! Account number "<<temp->acc_num<<" not found in our system."<<endl;
        }
    } 
}


void fund_transfer(struct node* temp){
    struct node* temp2;
    temp2=temp;
    string account_num1;  
    string account_num2;
    double money1, money2; 
    int count=0;
    cout<<"Enter your complete (9-Digits) account number = ";
    cin>>account_num1;
    cout<<endl;
    
    if(temp2==NULL){
        cout<<"NO DATA is present"<<endl;
    }

    if(temp2->acc_num==account_num1){
        cout<<"Account Number = "<<temp2->acc_num<<" has been found and it's details are !"<<endl;
        cout<<"Your current Balance is = "<<temp2->balance<<endl;
        cout<<"Now please enter the amount you want to tranfer = ";
        cin>>money1;
        cout<<endl;
        while(money1>temp2->balance){
            cout<<"INVALID amount. You don't have this amount "<<money1<<" in your account !"<<endl; 
            cout<<"Please enter within range = ";
            cin>>money1;
        }    
         
        cout<<"Enter other's complete (9-Digits) account number = ";
        cin>>account_num2;
        
        if(temp->acc_num==account_num2){
            cout<<"Account Number = "<<temp->acc_num<<" has been found "<<endl;
            temp->balance=temp->balance + money1;
            cout<<"Money has been tranfer to "<<temp->acc_num<<endl; 
            temp2->balance=temp2->balance - money1;
            cout<<"Your new balance is = "<<temp2->balance<<endl;             

        }
        else{

            while(temp!=NULL){
                if(temp->acc_num==account_num2){
                    count++;
                    cout<<"Account Number = "<<temp->acc_num<<" has been found "<<endl;
                    temp->balance=temp->balance + money1;
                    cout<<"Money has been tranfer to "<<temp->acc_num<<endl; 
                    temp2->balance=temp2->balance - money1;
                    cout<<"Your new balance is = "<<temp2->balance<<endl; 
                    break; 
                }
                else if(temp->acc_num > account_num2){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
        }    
        
        if(count==0){
            cout<<"OOPS ! Account number is not found in our system."<<endl;
        }
    
    
    }
         
      
    else{
        while(temp2!=NULL){
            if(temp2->acc_num==account_num1){
                count++;
                cout<<"Account Number = "<<temp2->acc_num<<" has been found and it's details are !"<<endl;
                cout<<"Your current Balance is = "<<temp2->balance<<endl;
                cout<<"Now please enter the amount you want to tranfer = ";
                cin>>money1;
                cout<<endl;
                while(money1>temp2->balance){
                   cout<<"INVALID amount. You don't have this amount "<<money1<<" in your account !"<<endl; 
                   cout<<"Please enter within range = ";
                   cin>>money1;
                }
         
                cout<<"Enter other's complete (9-Digits) account number = ";
                cin>>account_num2;
        
                if(temp->acc_num==account_num2){
                    cout<<"Account Number = "<<temp->acc_num<<" has been found "<<endl;
                    cout<<"Account Number = "<<temp->acc_num<<" has been found "<<endl;
                    temp->balance=temp->balance + money1;
                    cout<<"Money has been tranfer to "<<temp->acc_num<<endl; 
                    temp2->balance=temp2->balance - money1;
                    cout<<"Your new balance is = "<<temp2->balance<<endl;                    
                }
                
                else{

                    while(temp!=NULL){
                        if(temp->acc_num==account_num2){
                            count++;
                            cout<<"Account Number = "<<temp->acc_num<<" has been found "<<endl;
                            cout<<"Account Number = "<<temp->acc_num<<" has been found "<<endl;
                            temp->balance=temp->balance + money1;
                            cout<<"Money has been tranfer to "<<temp->acc_num<<endl; 
                            temp2->balance=temp2->balance - money1;
                            cout<<"Your new balance is = "<<temp2->balance<<endl;    
                            break; 
                        }
                        else if(temp->acc_num > account_num2){
                            temp=temp->left;
                        }
                        else{
                            temp=temp->right;
                        }
                    }
                }    
        
                if(count==0){
                cout<<"OOPS ! Account number is not found in our system."<<endl;
                }
                          
                break; 
            }
            else if(temp2->acc_num > account_num1){
                temp2=temp2->left;
            }
            else{
                temp2=temp2->right;
            }
        }
        
        if(count==0){
        cout<<"OOPS ! Account number is not found in our system."<<endl;
        }   
    }
     
 
}


void withdraw(struct node* temp){
    double money;
    string account_num;
    int count=0;

    cout<<"Enter the account number = ";
    cin>>account_num;
    cout<<endl;

    if(temp==NULL){
        cout<<"NO DATA is present"<<endl;
    }
    
    if(temp->acc_num==account_num){
        cout<<"Account Number = "<<temp->acc_num<<" has been found and it's details are !"<<endl;
        cout<<"Your current Balance is = "<<temp->balance<<endl;
        cout<<"Now Please enter the amount you want to withdraw = ";
        cin>>money;

        while(money>temp->balance){ 
            cout<<"ERROR ! Please enter valid amount"<<endl;
            cin>>money;
        }    
        double money_1=temp->balance - money;
        temp->balance=money_1;
        cout<<"Now your new Balance is = "<<temp->balance;
        cout<<endl;
    }
    
    else{

        while(temp!=NULL){
            if(temp->acc_num==account_num){
                count++;
                cout<<"Account Number = "<<temp->acc_num<<" has been found and it's details are !"<<endl;
                cout<<"Your current Balance is = "<<temp->balance<<endl;
                cout<<"Now Please enter the amount you want to withdraw = ";
                cin>>money;
                while(money>temp->balance){ 
                    cout<<"ERROR ! Please enter valid amount"<<endl;
                    cin>>money;
                }    
                double money_1=temp->balance - money;
                temp->balance=money_1;
                cout<<"Now your new Balance is = "<<temp->balance;
                cout<<endl;
                break; 
            }
           
            else if(temp->acc_num > account_num){
                temp=temp->left;
            }
           
            else{
                temp=temp->right;
            }
        }
        
        
        if(count==0){
        cout<<"OOPS ! Account number -> "<<temp->acc_num<<" not found in our system."<<endl;
        }
    } 
}
   
void in_order(struct node* temp){
     
    if(temp!=NULL){
        in_order(temp->left);
        cout<<temp->acc_num<<" ";
        cout<<temp->acc_id<<" ";
        cout<<temp->Gender<<" ";
        cout<<temp->balance<<" ";
        cout<<temp->account_type<<" "<<endl; 

        in_order(temp->right);
    }
} 


void pre_order(struct node* temp){
     
    if(temp!=NULL){
        cout<<temp->acc_num<<" ";
        cout<<temp->acc_id<<" ";
        cout<<temp->Gender<<" ";
        cout<<temp->balance<<" ";
        cout<<temp->account_type<<" "<<endl; 

        pre_order(temp->left);
        pre_order(temp->right);
    }
} 



void post_order(struct node* temp){
     
    if(temp!=NULL){
        post_order(temp->left);
        post_order(temp->right);
        cout<<temp->acc_num<<" ";
        cout<<temp->acc_id<<" ";
        cout<<temp->Gender<<" ";
        cout<<temp->balance<<" ";
        cout<<temp->account_type<<" "<<endl; 
    }
} 


void Random(){
    struct node* new_node;
         
    for (int i= 0; i<1000; i++){
        struct node* new_node;
        new_node = (struct node*) malloc(sizeof(struct node));    
    
        for(int j=0;j<9;j++){
            new_node->account_number[i]=rand();

            if(new_node->account_number[4]>4){
                new_node->Gender='F';
            }
     
            if(new_node->account_number[4]<4){  
                new_node->Gender='M';
            }

            if(new_node->account_number[4]==0){   
                new_node->account_type="Current";
            }

            if(new_node->account_number[4]==1){   
                new_node->account_type="Saving";
            }

            if(new_node->account_number[4]==2){   
                new_node->account_type="Salary";
            }

            if(new_node->account_number[4]==3){   
                new_node->account_type="Education";
            }

            if(new_node->account_number[4]==4){   
                new_node->account_type="IT";
            }

            if(new_node->account_number[4]==5){   
                new_node->account_type="Government";
            }

            if(new_node->account_number[4]==6){   
                new_node->account_type="Bonds";
            }
               
            if(new_node->account_number[4]==7){   
                new_node->account_type="Foreign";
            }
            
            if(new_node->account_number[4]==8){   
                new_node->account_type="Ariculture";
            }
            
            if(new_node->account_number[4]==9){   
                new_node->account_type="Ehsas";
            }
 
        }
       
        for(int k=0; k<4; k++){
            new_node->account_id[k] = rand();
        }
        
        for(int l=0; l<3; l++){
            new_node->branch_id[l]= rand();
        }
        
        new_node->balance = (double)rand() / RAND_MAX * 1000; 
    }

    //insert(new_node,new_node->account_number[5000000000],new_node->account_id[100000],new_node->branch_id[100000],new_node->balance,new_node->Gender,new_node->account_type);
}
   
 
  

int main(){
    int option;
    string acc_num, acc_id;
    double balance; 
    string Gender;
    string bran_id;
    string account_type;
    struct node* temp=NULL;
    //Random();
     
    do{
       cout<<"     *****   Welcome to TBL (Talha's bank Limited)    *****   "<<endl;
       cout<<"                  (Developed by Talha Khalid)     "<<endl<<endl; 
       cout<<"1. Add a new account "<<endl; 
       cout<<"2. Delete an account "<<endl; 
       cout<<"3. Funds Transfer "<<endl; 
       cout<<"4. Deposit "<<endl; 
       cout<<"5. Withdraw "<<endl; 
       cout<<"6. History "<<endl; 
       cout<<"7. Searching "<<endl; 
       cout<<"8. Query Handling "<<endl;
       cout<<"\n";
       cout<<"Enter the Option/Number you want to use (PRESS '0' TO EXIT) = ";
       cin>>option;
       switch (option){
            case 1:
            cout<<"Add details one by one"<<endl;
          
            cout<<"Enter the account number (9 digits) = ";
            cin>>acc_num;
            cout<<endl;
          
            cout<<"Enter the account ID (LAST 4 digits) = ";
            cin>>acc_id;
            cout<<endl;
         
            cout<<"Enter the branch ID (FIRST 3 digits) = ";
            cin>>bran_id;
            cout<<endl;
         
            cout<<"Enter the Gender  = ";
            cin>>Gender;
            cout<<endl;
         
            cout<<"Enter the account Type (0-Current, 1-Saving, 2-Salary, 3-Education, 4-IT, 5-Government, 6-Bonds, 7-Foreign, 8-Agriculture, 9-Ehsas) = ";
            cin>>account_type;
            cout<<endl;
         
            cout<<"Enter the balance = ";
            cin>>balance;
            cout<<endl;

            insert(temp,acc_num,acc_id,bran_id,balance,Gender,account_type);
         
            break;

            case 3:
            fund_transfer(temp);
            break;

            case 4:
            deposit(temp);
            break;

            case 5:
            withdraw(temp);
            break;
            
            case 7:
            cout<<"Entert the complete account number you want to search =";
            cin>>acc_num;

            search(temp,acc_num);
            
            break;

            default:
            cout<<"OOPS invalid ! Respected user please enter valid option"<<endl;
        
       } 
    }
    while(option!=0);   
    cout<<"Thank you so much for using my Banking Software"<<endl; 
    cout<<"          Developed by TALHA KHALID"<<endl; 
}
 