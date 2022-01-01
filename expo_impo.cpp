

//Cars impo and expo
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
struct date
{ int d;
  int m;
  int y;
};
class carsimpo
{
  char model[50];
  char place[50];
  long prc;
  char colour[50];
  int num;
  date dt;
  public:
  void display();
  void input();
  void output();
  int bussines(char[],int);
  void Delete();
};
class carsexpo
{ char model[50];
  char place[50];
  long prc;
  char colour[50];
  int num;
  date dt;
  public:
  void input();
  void output();
  void Delete();
};
int carsimpo::bussines(char mod[50],int n)
{ int flag=0;
   char pl[50];
  if(strcmpi(mod,model)==0)
  { flag=1;
    if(n<num)
    {  num-=n;
       cout<<"\n Yes the car is available for export";
       cout<<"\n Enter the place of delivery= ";
       gets(pl);
       cout<<"\n Cost you need to pay= "<<prc*n;
       cout<<"\n Your delivery will be done by 3 days at "<<pl;
    }
    else cout<<"\n Sorry....We have only "<<num<<" "<<mod;
    getch();
  }
 return flag;
}
void carsimpo::input()
{ clrscr();
  cout<<"\n Enter the model= ";
  gets(model);
  cout<<"\n Enter the place from where it is imported =";
  gets(place);
  cout<<"\n Enter the price of the car= ";
  cin>>prc;
  cout<<"\n  Enter the colour of the car= ";
  gets(colour);
  cout<<"\n Enter the number of "<<model<<" imported= ";
  cin>>num;
  cout<<"\n Enter the date(dd mm yy)= ";
  cin>>dt.d>>dt.m>>dt.y;
}
void carsexpo::input()
{ clrscr();
  cout<<"\nEnter the model= ";
  gets(model);
  cout<<"\nEnter the place to where it is exported= ";
  gets(place);
  cout<<"\nEnter the price of the car= ";
  cin>>prc;
  cout<<"\nEnter the colour of the car= ";
  gets(colour);
  cout<<"\nEnter number of "<<model<<" exported= ";
  cin>>num;
  cout<<"\nEnter the date of export(dd mm yy)= ";
  cin>>dt.d>>dt.m>>dt.y;
}
void carsimpo::output()
{ clrscr();
  cout<<"\n Model is= "<<model;
   cout<<"\n Price is= "<<prc;
   cout<<"\n Colour is= "<<colour;
   cout<<"\n Place from where it is imported= "<<place;
   cout<<"\n"<<num<<" "<<model<<" were imported on "<<dt.d<<"-"<<dt.m<<"-"<<dt.y;
}
void carsexpo::output()
{  clrscr();
   cout<<"\n Model is= "<<model;
   cout<<"\n Price is= "<<prc;
   cout<<"\n Colour is= "<<colour;
   cout<<"\n Place to where it is exported= "<<place;
   cout<<"\n"<<num<<" "<<model<<" were exported on "<<dt.d<<"-"<<dt.m<<"-"<<dt.y;
}

void carsimpo::display()
{ cout<<setw(10)<<"\n Model:-"<<model<<setw(10)<<"Price:-"<<prc<<setw(10)<<"Colour:-"<<colour;
}
void carsimpo::Delete()
{ ifstream ifile("impo.dat",ios::binary);
  ofstream ofile("temp.dat",ios::binary);
  char ch; carsimpo ci;
  int size=sizeof(ci);
  while(ifile.read((char*)&ci,size))
  { cout<<"\nModel of the car= "<<model;
    cout<<"\nDo you want to delete this model(y/n)= ";
    cin>>ch;
    if(ch=='n'||ch=='N')
    ofile.write((char*)&ci,size);
    else
    cout<<"\nRecord is deleted...";
  }
  ifile.close();
  ofile.close();
  remove("impo.dat");
  rename("temp.dat","impo.dat");
  getch();
}
void carsexpo::Delete()
{ ifstream ifile("expo.dat",ios::binary);
  ofstream ofile("temp.dat",ios::binary);
  char ch;
  carsexpo ci;
  int size=sizeof(ci);
  while(ifile.read((char*)&ci,size))
  { cout<<"\n Model of the car = "<<model;
  cout<<"\n Do you want to delete this model (y/n) = ";
  cin>>ch;
  if(ch=='n'||ch=='N')
  ofile.write((char*)&ci,size);
  else
  cout<<"\n Record is deleted ....";
  }
  ifile.close();
  ofile.close();
  remove("expo.dat");
  rename("temp.dat","expo.dat");
  getch();
}
void main()
{
  clrscr();
  carsimpo CI;
  carsexpo CE;
  ofstream ofile;
  ofstream sfile;
  ifstream ifile;
  int ch,sizei,sizee;
  sizei=sizeof(CI);
  sizee=sizeof(CE);
  char ans;
  do
  { clrscr();
   textcolor(6);
    cprintf("\n             MAIN MENU          ");cout<<endl;
    textcolor(4);
    cprintf("\n 1. To add the details of imported cars");cout<<endl;
    cprintf("\n 2. To add the details of exported cars");cout<<endl;
    cprintf("\n 3. To export cars.");cout<<endl;
    cprintf("\n 4. To show the details of all imported cars");cout<<endl;
    cprintf("\n 5. To show the details of all exported cars");cout<<endl;
    cprintf("\n 6. To delete the details of an imported car");cout<<endl;
    cprintf("\n 7. To delete the details of an exported car");cout<<endl;
    cprintf("\n 8. Exit");cout<<endl;
    cout<<"\n    Enter your choice (1-8) = ";
  cin>>ch;
  switch(ch)
      {
	case 1:clrscr();
	       char ans='y';
		sfile.open("showcars",ios::binary|ios::app);
		ofile.open("impo.dat",ios::binary|ios::app);
	       while(ans=='y'||ans=='Y')
	       { CI.input();
		 ofile.write((char*)&CI,sizei);
		 sfile.write((char*)&CI,sizei);
		 cout<<"\nDo you want to enter more(y/n)= ";
		 cin>>ans;
	       } ofile.close();
	       break;
	case 2:clrscr();
		ans='y';
		ofile.open("expo.dat",ios::binary|ios::app);
	       while(ans=='y'||ans=='Y')
	       { CE.input();
		 ofile.write((char*)&CE,sizee);
		 cout<<"\nDo you want to enter more(y/n)= ";
		 cin>>ans;
	       } ofile.close();
	       break;
	case 3: clrscr();
		char mod[50];
		int n;
		ifile.open("showcars",ios::binary);
		ofile.open("temp.dat",ios::binary);
		if(!ifile)
		cout<<"\nNo data is found....";
		else
	      { cout<<setw(30)<<"\n Cars available are....";
		while(ifile.read((char*)&CI,sizei))
	       { CI.display();   }
	       cout<<"\nEnter the model of the car to be exported= ";
	       gets(mod);
	       cout<<"\nHow many "<<mod<<" do you want to export= ";
	       cin>>n;
	       int flag;
	       while(ifile.read((char*)&CI,sizei))
	       { flag=CI.bussines(mod,n);
		 ofile.write((char*)&CI,sizei);
	       }
	       if(flag==0)
	       cout<<mod<<" is not available for export"
		    <<"\nImport "<<n<<" "<<mod;
	       else
	       { ofile.close();
		 ifile.close();
		 remove("showcars");
		 rename("temp.dat","showcars");
	      }
	     }
	       break;

	case 4:clrscr();
		ifile.open("impo.dat",ios::binary);
		if(!ifile)
		cout<<"\nNo data is found...";
		else
	      { cout<<"\nDetails of all imported cars...";
		while(ifile.read((char*)&CI,sizei))
		{ CI.output();
		  getch(); clrscr();
		}

	      }	ifile.close();

		break;
	case 5: clrscr();
		cout<<"\nDetails of all exported cars are.....";
		ifile.open("expo.dat",ios::binary);
		if(!ifile)
		cout<<"\nNo data is found...";
		else
	      {	while(ifile.read((char*)&CE,sizee))
		{ CE.output();
		  getch(); clrscr();
		}
	      }	ifile.close();
		break;
	case 6: CI.Delete();
		break;
	case 7: CE.Delete();
		break;
	case 8: textcolor(3);      //from conio
		 cprintf("\nTHANK YOU"); //from conio
		 break;
	default: cout<<"\nWrong choice";
      } getch();
    }while(ch!=8);
  getch();
  closegraph();
}








































EXPOIMPO.CPP
Displaying EXPOIMPO.CPP.