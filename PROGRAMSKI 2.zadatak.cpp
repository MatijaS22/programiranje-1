#include<iostream>
using namespace std;
int n,m,matrica[10][10];

void unos(){
	do{
		cout<<"unesi n: ";
		cin>>n;
	}while(n>10  && n < 0);

	do{
		cout<<"unesi m: ";
		cin>>m;
	}while(m>10  && m < 0);	
	matrica[n][m];

	int i=0, j=0,unos;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			cout<<"unesi " << i+1 << "red i " << j+1<< "stupac" ;
			
			cin>>unos;	
			matrica[i][j] = unos;
		}
	}	
	
}
void ispis(){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			cout<< matrica[i][j];
		}
		cout<<endl;
	}
}
int* zbroj(){
	int i, j;
	int	*polje = new int[m];
	for(j = 0; j < m; j++){
		for(i = 0; i < n; i++){
		polje[j] += matrica[i][j];
		}
	}
	return polje;
}
int main(){
	unos();
	
	ispis();
	int* rez = zbroj();
	for(int i = 0; i < m; i++){
		cout << rez[i];
	}	
	return 0;
	
}
