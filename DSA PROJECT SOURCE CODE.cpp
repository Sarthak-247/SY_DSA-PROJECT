#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
struct Pharmacy{
    char id[50];
    string name ;
    int quantity;
    int price;
};
    Pharmacy phar;
    vector<Pharmacy> medics; 
 void add(){
        int c;
        do{
        cout<<"Id :";cin>>phar.id;
        cout<<"Name:";
        cin>>phar.name;
        cout<<"Quantity:";cin>>phar.quantity;
        cout<<"Price :";cin>>phar.price;
        medics.push_back(phar);
        cout<<"Save Successfully"<<endl;
        cout<<"Enter 0 To Exit Or 1 To Continue :";cin>>c;
        }
        while(c!=0&& c==1);
    }
void search()
{
    string n;
    cout<<"Enter Name For Search:"; cin>>n;
    for(int i=0;i<medics.size();i++)
    {
        if(n==medics[i].name)
            cout<<i+1<<" Id :"<<medics[i].id <<endl;
            cout<<i+1<<" Name:"<<medics[i].name <<endl;
            cout<<i+1<<" Quantity:"<<medics[i].quantity <<endl;
            cout<<i+1<<" Price :"<<medics[i].price <<endl;
    }
}
void del(){
     string n;
    cout<<"Enter Name To Delete:"; cin>>n;
    for(int i=0;i<medics.size();i++)
    {
        if(n==medics[i].name)
            medics.erase(medics.begin()+i);
            cout<<"Deleted :"<<medics[i].name<<endl<<endl;
    }
    
}
void showall(){
    for(int i=0;i<medics.size();i++)
    {
        cout<<i+1<<" Id :"<<medics[i].id <<endl;
        cout<<i+1<<" Name:"<<medics[i].name <<endl;
        cout<<i+1<<" Quantity:"<<medics[i].quantity <<endl;
        cout<<i+1<<" Price :"<<medics[i].price <<endl<<endl;
    }
}
void save_file(const vector<Pharmacy>& medics , const string& Medical ){
    ofstream out("D:/Sarthak/Medical.txt" );
    if(!out)
        cout<<" File Not Found: "<<Medical <<endl;
    
    for(int i=0;i<medics.size();i++)
    {
        out<<i+1<<"Id: "<<medics[i].id<<endl<<"Name :"<<medics[i].name<<endl
        <<"Quantity :"<<medics[i].quantity<<endl<<"Price :"<<medics[i].price<<endl;
    }
    out.close();
    cout<<"Medicines Saved To File "<<Medical<<endl;
}
int main()
{
    while(true){
        int value;
        cout<<"1 For  Add Medicine "<<endl;
        cout<<"2 For  Search Medicine "<<endl;
        cout<<"3 For  Delete Medicine "<<endl;
        cout<<"4 For  Show All Medicine "<<endl;
        cout<<"5 For  Save Medicine "<<endl;
        cout<<"6 For  Exit From Program "<<endl;
        cout<<"Enter The Choice :";
        cin>>value;
        switch(value){
            case 1:
                add();
            break;
            case 2 :
                search();
            break;
            case 3:
                del();
            break;
            case 4:
                showall();
            break; 
            case 5:
                save_file(medics,"D:/Sarthak/Medical.txt");
            break; 
            case 6:
                exit(0);
        }
    }
}
