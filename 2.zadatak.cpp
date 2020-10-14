#include <iostream>
#include <cmath>
using namespace std;

class razlomci 
{
	public:
	int nazivnik;
	int brojnik;
	  
};
void izbornik(){
	cout<<"ODABERITE KOJU RACUNSKU RADNJU ZELITE "<<endl;
	cout<<"1.ZBRAJANJE "<<endl;
	cout<<"--------------------"<<endl;
	cout<<"2.ODUZIMANJE "<<endl;
	cout<<"--------------------"<<endl;
	cout<<"3. MNOZENJE "<<endl;
	cout<<"--------------------"<<endl;
	cout<<"4. DIJELJENJE "<<endl;
	cout<<"--------------------"<<endl;
}
void oduzimanje(razlomci prvi, razlomci drugi){
	cout<<prvi.brojnik<<"/"<<prvi.nazivnik<<" - "<<drugi.brojnik<<"/"<<drugi.nazivnik<<" = "<< ((prvi.brojnik*drugi.nazivnik) - (prvi.nazivnik*drugi.brojnik))<<"/"<<prvi.nazivnik*drugi.nazivnik;
}
void dijeljenje(razlomci prvi, razlomci drugi){
	cout<<prvi.brojnik<<"/"<<prvi.nazivnik<<" % "<<drugi.brojnik<<"/"<<drugi.nazivnik<<" = "<< prvi.brojnik * drugi.nazivnik<<"/"<<drugi.brojnik*prvi.nazivnik;
}

void mnozenje(razlomci prvi, razlomci drugi)
{
cout<<prvi.brojnik<<"/"<<prvi.nazivnik<<" * "<<drugi.brojnik<<"/"<<drugi.nazivnik<<" = "<< prvi.brojnik*drugi.brojnik<<"/"<< prvi.nazivnik*drugi.nazivnik;
}

void zbrajanje(razlomci prvi, razlomci drugi){
cout<<prvi.brojnik<<"/"<<prvi.nazivnik<<" + "<<drugi.brojnik<<"/"<<drugi.nazivnik<<" = "<< prvi.brojnik*drugi.nazivnik +prvi.nazivnik*drugi.brojnik<<"/"<<prvi.nazivnik*drugi.nazivnik;
}

int main(){
	int odabir;
	razlomci prvi,drugi;
	
	cout<<"UPISI PRVI RAZLOMAK;"<<endl;
	cout<<"BROJNIK -  ";
	cin>>prvi.brojnik;
	do{
	cout<<"NAZIVNIK - ";
	cin>>prvi.nazivnik;
	if(prvi.nazivnik==0){
		cout<<"POGRESAN UNOS POKUSAJ PONOVNO";
	}
}
while(prvi.nazivnik == 0);

	cout<<"UPISI DRUGI RAZLOMAK"<<endl;
	
	cout<<"BROJNIK -  ";
	cin>>drugi.brojnik;
	do{
	cout<<"NAZIVNIK - ";
	cin>>drugi.nazivnik;
	if(drugi.nazivnik==0){
		cout<<"POGRESAN UNOS POKUSAJ PONOVNO";
	}
}
while( drugi.nazivnik == 0);
izbornik();
label: cout<<"UNESITE ZELJENU VRIJEDNOST  ";
cin>>odabir;
switch(odabir){
	case 1: cout<<"Rezultat; ";  
	        zbrajanje(prvi,drugi);
	        cout<<endl;
	        goto label;
	        
	case 2: cout<<"REZULTAT ODUZIMANJA JE ";
	        oduzimanje(prvi,drugi);
	        cout<<endl;
	        goto label;
	case 3: cout<<"REZULTAT MNOZENJA JE ";
	        mnozenje(prvi,drugi);	
			cout<<endl;
	        goto label;        
	case 4: cout<<"REZULTAT DIJELJENJA JE ";
	        dijeljenje(prvi,drugi);        
	        cout<<endl;
	        goto label;
	case 5: cout<<"KRAJ"<<endl;
	        break;
   default: 
           cout<<"UNESENI BROJ NE ODGOVARA IZBORNIKU"<<endl; 
	        goto label;       
}


return 0;

}
