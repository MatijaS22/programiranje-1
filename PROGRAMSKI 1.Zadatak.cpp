#include<iostream>
#include <string>
using namespace std;

struct student{
	double index;
	string ime;
	string prezime;
	float vjezbe;
	float predavanja;
	float ukupnobod;
};

void ispis(student st[],int i){
		
	for(int j = 0; j < i; j++){
	
		cout<<"indeks "<< st[j].index<<endl;
		cout<<"ime "<<st[j].ime<<endl;
		cout<<"prezime "<<st[j].prezime<<endl;
		cout<<"vjezbe "<<st[j].vjezbe<<endl;
		cout<<"pred "<<st[j].predavanja<<endl;
		
	}
}
void iznadprosjecni(student st[], int broj, float prosjek){
	for(int j = 0; j < broj; j++){
		if(st[j].ukupnobod >= prosjek ){
			cout<<"indeks "<< st[j].index<<endl;
			cout<<"ime "<<st[j].ime<<endl;
			cout<<"prezime "<<st[j].prezime<<endl;
			cout<<"vjezbe "<<st[j].vjezbe<<endl;
			cout<<"pred "<<st[j].predavanja<<endl;
		}
	
		
	}
}
void prezimena(student st[],int broj, float maks){
	for(int j = 0; j < broj; j++){
		if(st[j].predavanja == maks ){
			
			cout<<"prezime "<<st[j].prezime<<endl;
			
		}
	
		
	}
}
void prolazv(student st[], int broj){
	for(int j = 0; j < broj; j++){
		if(st[j].vjezbe > 25 ){
			cout<<"indeks "<< st[j].index<<endl;
			cout<<"ime "<<st[j].ime<<endl;
			cout<<"prezime "<<st[j].prezime<<endl;
			cout<<"vjezbe "<<st[j].vjezbe<<endl;
			cout<<"pred "<<st[j].predavanja<<endl;
		}
	
		
	}
}
void trazi(student st[], string ime, string prezime,int broj){
		for(int j = 0; j < broj; j++){
		if(st[j].ime.compare(ime) == 0 ){
			if(st[j].prezime.compare(prezime) == 0 ){
				if(st[j].ukupnobod >= 50 &&st[j].ukupnobod <60 ){
					cout << "ocjena je 2";
				}else if(st[j].ukupnobod >= 60 &&st[j].ukupnobod <70 ){
					cout << "ocjena je 3";
				}else if(st[j].ukupnobod >= 70 &&st[j].ukupnobod <80 ){
					cout << "ocjena je 4";
				}
				else if(st[j].ukupnobod >= 80 &&st[j].ukupnobod <100 ){
					cout << "ocjena je 5";
				}else{
					cout <<"ocjena je 1";
				}
			}
		}
	
		
	}
}
int main(){
	int brojstu;
	float bodv,bodp,ukupno = 0,prosjek,makspr = 0;
	string ime,prezime;
	do{
		cout<<"unesi broj studenata";
		cin>>brojstu;
	}while(brojstu<0 && brojstu > 70);
	student studenti[brojstu];
	
	for(int i = 0; i < brojstu; i++){
		cout<<"unesi broj indeksa "<< i + 1<< " studenta: ";
		cin>>studenti[i].index;
		cout<<"unesi ime "<< i + 1<< " studenta: ";
		cin>>studenti[i].ime;
		cout<<"unesi prezime "<< i + 1<< " studenta: ";
		cin>>studenti[i].prezime;
		do{
			cout<<"unesi broj bodova sa vjezbi "<< i + 1<< " studenta: ";
			cin>> bodv;
		}while(bodv > 50);
		
		studenti[i].vjezbe = bodv;
		do{
			cout<<"unesi broj bodova sa predavanj "<< i + 1<< " studenta: ";
			cin>> bodp;
		}while(bodp > 50);
		ukupno = bodp + bodv;
		studenti[i].predavanja = bodp;
		studenti[i].ukupnobod = bodp + bodv;
		if(makspr < bodp) makspr = bodp;
	}
	prosjek = ukupno / brojstu;
	int odabir;
	while(1){
	cout << string(150, '\n');
		cout<< "odaberi 1-SVI PODACI\n 2-iznadprosjecni\n 3-prezimenajbolji \n 4-prolaz \n 5-ocjena za ime i prez \n 6-izlaz";
	cin>>odabir;
	switch(odabir) {
      case 1:
         ispis(studenti, brojstu);
         break;
      case 2:
      	iznadprosjecni(studenti,brojstu,prosjek);
      	 break;
      case 3:
         prezimena(studenti, brojstu, makspr);
         break;
      case 4:
         prolazv(studenti, brojstu);
         break;
      case 5:
         cout<<"unesi ime: ";
         cin>>ime;
         cout<<"\nunesi prezime: ";
         cin>>prezime;
         cout<<"zelis trazit prezime "<< prezime;
         trazi(studenti, ime, prezime,brojstu);
         break;
      case 6:
         cout << "Izlaz" << endl;
         break;
   }
   if(odabir == 6) break;
   cout<< "POVRATAK";
   cin>>odabir;
	}
	
	return 0;
}
