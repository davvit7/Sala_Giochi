//ZONA LIBRERIE
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
//Reload declaretion
	bool reload=false; //sistema di riavvio
	int contatore_reload=0;//sistema di riavvio
//ZONA FUNZIONI
//Master control (funzioni)
	char master_control_password[6]; //sistema master
	int cont_master_control=-1; //sistema master
	int master_control_interface, boost=0, jolly=0, berserk=0, backstage=0; //sistema master
	bool utilizzo_master_control=false, corrispondenza_master_utente=false;//sistema master
//Controllo password
	bool verifica_master_control_password(){
		do{
			cont_master_control=-1;
//Inserimento password
			cout<<"Inserisci password o premi \033[31m(0)\033[0m se l'hai dimenticata: ";
			cin>>master_control_password;
			do{
				cont_master_control++;
			}while(master_control_password[cont_master_control]!='\0');
//Confronto password inserita con password corretta
			switch(cont_master_control){
				case 1:
					if(master_control_password[0]=='0')
						utilizzo_master_control=true;
				break;
				case 3:
					if(master_control_password[0]=='o' && master_control_password[1]=='f' && master_control_password[2]=='f')
						utilizzo_master_control=true;
				break;
				case 4:
					if(master_control_password[0]=='v' && master_control_password[1]=='i' && master_control_password[2]=='e' && master_control_password[3]=='w')
						utilizzo_master_control=true;
				break;
				case 6:
					if(master_control_password[0]=='m' && master_control_password[1]=='a' && master_control_password[2]=='s' && master_control_password[3]=='t' && master_control_password[4]=='e' && master_control_password[5]=='r')
						utilizzo_master_control=true;
					else
						if(master_control_password[0]=='r' && master_control_password[1]=='e' && master_control_password[2]=='l' && master_control_password[3]=='o' && master_control_password[4]=='a' && master_control_password[5]=='d')
							utilizzo_master_control=true;
						
				break;
				default:
					utilizzo_master_control=false;
			}
		}while(!utilizzo_master_control==true);
		return true;
	}
	
//Master control mode
	void master_control_mode(){
//Confornto password in base al relativo lavoro
		switch(cont_master_control){
//Master control "0" (Salto inserimento password)
			case 1:
				if(utilizzo_master_control==true)
					cout<<endl;
			break;
//Master control off
			case 3:
				if(utilizzo_master_control==true){
					cout<<endl;
					cout<<"\033[35mMaster control disactivated\033[0m"<<endl;
					cout<<"\033[31mSecret area locked\033[0m"<<endl;
					boost=0;
					jolly=0;
					berserk=0;
					backstage=0;
				}
				cout<<endl;
			break;
			case 4:
//Master control view
				if(utilizzo_master_control==true){
					cout<<endl;
//View boost
					if(boost==1)
						cout<<"(1) boost \033[32mon\033[0m"<<endl;
					else
						cout<<"(1) boost \033[31moff\033[0m"<<endl;
//View jolly
					if(jolly==1)
						cout<<"(2) jolly \033[32mon\033[0m"<<endl;
					else
						cout<<"(2) jolly \033[31moff\033[0m"<<endl;
//View berserk
					if(berserk==1)
						cout<<"(3) berserk \033[32mon\033[0m"<<endl;
					else
						cout<<"(3) berserk \033[31moff\033[0m"<<endl;
//View backstage
					if(backstage==1)
						cout<<"(4) backstage \033[32mon\033[0m"<<endl;
					else
						cout<<"(4) backstage \033[31moff\033[0m"<<endl;
//View reload
					cout<<"(5) reload effettuati: \033[35m"<<contatore_reload<<"\033[0m"<<endl;
				}
				if(backstage==1)
					cout<<"\n\033[35m"<<boost<<" "<<jolly<<" "<<berserk<<" "<<backstage<<"\033[0m"<<endl;
				cout<<endl;
			break;
			case 6:
//Master control on
				if(utilizzo_master_control==true && master_control_password[0]=='m'){
					cout<<endl;
					cout<<"\033[32mSecret area unlocked\033[0m"<<endl;
					cout<<"\033[35mMaster control activated\033[0m\n"<<endl;
					boost=1;
					cout<<"(1) boost \033[32mon\033[0m"<<endl;
					jolly=1;
					cout<<"(2) jolly \033[32mon\033[0m"<<endl;
					berserk=1;
					cout<<"(3) berserk \033[32mon\033[0m"<<endl;
					backstage=1;
					cout<<"(4) backstage \033[32mon\033[0m"<<endl;
//Master control interface
					do{
						cout<<"\nPremere \033[32m(1)\033[0m per accedere all'interfaccia o \033[31m(2)\033[0m per andare avanti: ";
						cin>>master_control_interface;
					}while(master_control_interface!=1 && master_control_interface!=2);
					if(master_control_interface==1){
						cout<<endl;
						cout<<"\033[35mMaster control interface:\033[0m"<<endl;
						cout<<endl;
//boost
						do{
							cout<<"Premere \033[31m(0)\033[0m per disattivare il boost o \033[32m(1)\033[0m per tenerlo attivo: ";
							cin>>boost;
						}while(boost!=0 && boost!=1);
						if(boost==1)
							cout<<"(1) boost \033[32mon\033[0m"<<endl;
						else
							cout<<"(1) boost \033[31moff\033[0m"<<endl;
//jolly
						do{
							cout<<"Premere \033[31m(0)\033[0m per disattivare il jolly o \033[32m(1)\033[0m per tenerlo attivo: ";
							cin>>jolly;
						}while(jolly!=0 && jolly!=1);
						if(jolly==1)
							cout<<"(2) jolly \033[32mon\033[0m"<<endl;
						else
							cout<<"(2) jolly \033[31moff\033[0m"<<endl;
//berserk
						do{
							cout<<"Premere \033[31m(0)\033[0m per disattivare il berserk o \033[32m(1)\033[0m per tenerlo attivo: ";
							cin>>berserk;
						}while(berserk!=0 && berserk!=1);
						if(berserk==1)
							cout<<"(3) berserk \033[32mon\033[0m"<<endl;
						else
							cout<<"(3) berserk \033[31moff\033[0m"<<endl;
//backstage
						do{
							cout<<"Premere \033[31m(0)\033[0m per disattivare il backstage o \033[32m(1)\033[0m per tenerlo attivo: ";
							cin>>backstage;
						}while(backstage!=0 && backstage!=1);
						if(backstage==1)
							cout<<"(4) backstage \033[32mon\033[0m"<<endl;
						else
							cout<<"(4) backstage \033[31moff\033[0m"<<endl;
					}
				}
//visualizzazione zone attive
				if(backstage==1)
					cout<<"\n\033[35m"<<boost<<" "<<jolly<<" "<<berserk<<" "<<backstage<<"\033[0m"<<endl;
				cout<<endl;
//reload
				if(utilizzo_master_control==true && master_control_password[0]=='r'){
					contatore_reload++;
					if(backstage==1){
						cout<<"\033[35mReload System in :\033[0m"<<endl;
						cout<<endl;
//count down
						for(int f=3; f>0; f--){
							cout<<"\033[35m"<<f<<"\033[0m"<<endl;
							cout<<endl;
							Sleep(1000);
						}
					}
					reload=true;
				}
			break;
		}
	}
//Corrispondenza master utente		[Fa' parte di verifica utente]
	char utente[20], master_utente[8]; //inizio sistema
	int  scelta_colore, cont_lettere=0; //inizio sistema
	bool verifica_colore(){
		int identity=0, cont_inserimenti=0;
		if(scelta_colore!=4)
			do{
				cout<<"Confermare la propria identita' o premere \033[31m(0)\033[0m nel caso non lo si possa fare: ";
				cin>>identity;
				cont_inserimenti++;
			}while(identity!=0 && identity!=84868 && cont_inserimenti!=5);
		if(identity==84868 || scelta_colore==4){
			corrispondenza_master_utente=true;
			return true;
		}
		else
			return false;
	}
//Verifica utente (funzione)	[Fa' parte di Corrispondenza master utente]
	void verifica_utente(){
		master_utente[0]='e';
		master_utente[1]='l';
		master_utente[2]='e';
		master_utente[3]='t';
		master_utente[4]='t';
		master_utente[5]='r';
		master_utente[6]='o';
		master_utente[7]='\0';
		do{
			cont_lettere++;
		}while(utente[cont_lettere]!='\0');
		if(cont_lettere==7){
			cont_lettere=0;
			for(int f=0; f<=6; f++){
				if(utente[f]==master_utente[f])
					cont_lettere++;
			}
		}
		if(cont_lettere==7 && verifica_colore()==true)
			cout<<"\033[3"<<scelta_colore<<"mBen tornato "<<utente<<" a cosa vuoi giocare questa volta??\033[0m"<<endl;
		else
			cout<<"\033[3"<<scelta_colore<<"mBen arrivato "<<utente<<" a cosa vuoi giocare??\033[0m"<<endl;
	}
//Assegnazione int in comune (funzione) [Fa' parte di "Segna punti"]
	int cont_v=0, cont_s=0, cont_p=0, partite_giocate=0; //int in comune
	void stamp_assegnazioni(){
		cont_p=0;
		cont_v=0;
		cont_s=0;
		partite_giocate=0;
	}
//Segna punti (funzione) [Fa' parte di "Assegnazione int in comune"]
	void segna_punti(){
		partite_giocate=cont_v+cont_s;
		cout<<"Segna punti: "<<endl;
		cout<<"Partite giocate: " <<partite_giocate <<endl;
		cout<<"\033[32mVittorie:  "<<cont_v <<"\033[0m" <<endl;
		cout<<"\033[31mSconfitte: "<<cont_s <<"\033[0m" <<endl;
		cout<<"\033[34mPareggi:   "<<cont_p <<"\033[0m" <<endl;
	}
//Lista resoconto (Funzione)
	int resoconto_v=0, resoconto_s=0, resoconto_p=0, resoconto_partite=0; //int in comune
	void resoconto(){
		resoconto_partite=resoconto_partite+partite_giocate;
		resoconto_v=resoconto_v+cont_v;
		resoconto_s=resoconto_s+cont_s;
		resoconto_p=resoconto_p+cont_p;
	}
//Giocare ancora o tornare alla scelta iniziale (funzione)
	int restart; //int in comune
	void stamp_termina(){
		do{
			cout<<"Vuoi ricominciare la partita??"<<endl;
			cout<<"Premere \033[32m(1) per giocare ancora \033[0mo \033[31m(2) per tornare alla scelta iniziale\033[0m: ";
			cin>>restart;
			cout<<endl;
		}while(restart!=1 && restart!=2);
	}
//Spegimento (funzione)
	int riprovare; //inizio sistema
	void stamp_spegimento(){
		do{
			cout<<"Vuoi giocare ancora o vuoi spegnere il sistema??" <<endl;
			cout<<"Premere \033[32m(1) per giocare ancora \033[0mo \033[31m(2) per spegnere il sistema\033[0m: ";
			cin>>riprovare;
			cout<<endl;
		}while(riprovare!=1 && riprovare!=2);
	}

//5° GIOCO
//Creazione matrice del tris
	int const RIGHE_TRIS=3, COLONNE_TRIS=3;
	char matrice_tris[RIGHE_TRIS][COLONNE_TRIS];
	bool verifica_tris=false;
	void create_tris(){
		for(int r=0; r<RIGHE_TRIS; r++){
			for(int c=0; c<COLONNE_TRIS; c++){
				matrice_tris[r][c]=' ';
				cout<<" ";
				if(c<COLONNE_TRIS-1)
					cout<<"  \033[33m|\033[0m  ";
			}
			cout<<endl;
			if(r<RIGHE_TRIS-1)
				cout<<"\033[33m-------------\033[0m"<<endl;
		}
	}
//Controllo del tris
	void controllo_tris(){
//Controllo righe
		for(int r=0; r<RIGHE_TRIS; r++){
			char t;
			for(int c=0; c<COLONNE_TRIS; c++){
				if(c==0)
					t=matrice_tris[r][c];
				if(c==2)
					if(t!=' ' && matrice_tris[r][c]==t && matrice_tris[r][c-1]==t){
						cout<<"\033[32mVittoria!!\033[0m"<<endl;
						cout<<"\033[32mHa vinto la "<<t<<"\033[0m"<<endl;
						verifica_tris=true;
					}
			}
		}
//Controllo colonne
		for(int c=0; c<COLONNE_TRIS; c++){
			char t;
			for(int r=0; r<RIGHE_TRIS; r++){
				if(r==0)
					t=matrice_tris[r][c];
				if(r==2)
					if(t!=' ' && matrice_tris[r][c]==t && matrice_tris[r-1][c]==t){
						cout<<"\033[32mVittoria!!\033[0m"<<endl;
						cout<<"\033[32mHa vinto la "<<t<<"\033[0m"<<endl;
						verifica_tris=true;
					}
			}
		}
//Controllo diagonale principale
		for(int r=0; r<RIGHE_TRIS; r++){
			char t;
			for(int c=0; c<COLONNE_TRIS; c++){
				if(c==0 && c==r)
					t=matrice_tris[r][c];
				if(c==2 && c==r)
					if(t!=' ' && matrice_tris[r][c]==t && matrice_tris[r-1][c-1]==t){
						cout<<"\033[32mVittoria!!\033[0m"<<endl;
						cout<<"\033[32mHa vinto la "<<t<<"\033[0m"<<endl;
						verifica_tris=true;
					}
			}
		}
//Controllo diagonale secondaria
		for(int r=0; r<RIGHE_TRIS; r++){
			char t;
			for(int c=0; c<COLONNE_TRIS; c++){
				if(c==2 && r==0)
					t=matrice_tris[r][c];
				if(c==0 && r+c==RIGHE_TRIS-1)
					if(t!=' ' && matrice_tris[r][c]==t && matrice_tris[1][1]==t){
						cout<<"\033[32mVittoria!!\033[0m"<<endl;
						cout<<"\033[32mHa vinto la "<<t<<"\033[0m"<<endl;
						verifica_tris=true;
					}
			}
		}
	}
//Primo turno "X"
	void turno1_tris(){
		int riga=0, colonna=0;
//Inserimento "X"
		cout<<"Inserisci la 'X' in una delle caselle libere: "<<endl;
		do{
			cin>>riga>>colonna;
			if(riga<0 || colonna<0 || riga>2 || colonna>2)
				cout<<"La casella selezionata non \212 esistente"<<endl;
			else if(matrice_tris[riga][colonna]!=' ')
					cout<<"La casella \212 gia' occupata"<<endl;
		}while(matrice_tris[riga][colonna]!=' ');
//Assegnazione "X"	
		matrice_tris[riga][colonna]='X';
//Stampa della tabella
		for(int r=0; r<RIGHE_TRIS; r++){
			for(int c=0; c<COLONNE_TRIS; c++){
				if(matrice_tris[r][c]=='X')
					cout<<"\033[34m"<<matrice_tris[r][c]<<"\033[0m";
				else
					cout<<"\033[31m"<<matrice_tris[r][c]<<"\033[0m";
				if(c<COLONNE_TRIS-1)
					cout<<"  \033[33m|\033[0m  ";
			}
			cout<<endl;
			if(r<RIGHE_TRIS-1)
				cout<<"\033[33m-------------\033[0m"<<endl;
		}
//Vittoria??
		controllo_tris();
	}
//Secondo turno "O"
	void turno2_tris(){
		int riga=0, colonna=0;
		//Inserimento "O"
		cout<<"Inserisci la 'O' in una delle caselle libere: "<<endl;
		do{
			cin>>riga>>colonna;
			if(matrice_tris[riga][colonna]!=' ')
				cout<<"La casella \212 gia' occupata"<<endl;
		}while(matrice_tris[riga][colonna]!=' ');
//Assegnazione "O"
		matrice_tris[riga][colonna]='O';
//Stampa della tabella
		for(int r=0; r<RIGHE_TRIS; r++){
			for(int c=0; c<COLONNE_TRIS; c++){
				if(matrice_tris[r][c]=='O')
					cout<<"\033[31m"<<matrice_tris[r][c]<<"\033[0m";
				else
					cout<<"\033[34m"<<matrice_tris[r][c]<<"\033[0m";
				if(c<COLONNE_TRIS-1)
					cout<<"  \033[33m|\033[0m  ";
			}
			cout<<endl;
			if(r<RIGHE_TRIS-1)
				cout<<"\033[33m-------------\033[0m"<<endl;
		}
//Vittoria??
		controllo_tris();
	}
//Terzo turno, modalità multiplayer "O"
	void turno3_computer_tris(){
		int const TOMBOLA_DEL_TRIS=3;
		int riga=0, colonna=0;
		srand(time(NULL));
		//Inserimento "O"
		cout<<"Inserisci la 'O' in una delle caselle libere: "<<endl;
		do{
			riga=rand()%TOMBOLA_DEL_TRIS;
			colonna=rand()%TOMBOLA_DEL_TRIS;
		}while(matrice_tris[riga][colonna]!=' ');
			if(backstage==1) cout<<"\033[35mRiga:"<<riga<<"\033[0m"<<endl; //master control mode: "backstage"
			if(backstage==1) cout<<"\033[35mColonna:"<<colonna<<"\033[0m"<<endl; //master control mode: "backstage"
//Assegnazione "O"
		matrice_tris[riga][colonna]='O';
//Stampa della tabella
		for(int r=0; r<RIGHE_TRIS; r++){
			for(int c=0; c<COLONNE_TRIS; c++){
				if(matrice_tris[r][c]=='O')
					cout<<"\033[31m"<<matrice_tris[r][c]<<"\033[0m";
				else
					cout<<"\033[34m"<<matrice_tris[r][c]<<"\033[0m";
				if(c<COLONNE_TRIS-1)
					cout<<"  \033[33m|\033[0m  ";
			}
			cout<<endl;
			if(r<RIGHE_TRIS-1)
				cout<<"\033[33m-------------\033[0m"<<endl;
		}
//Vittoria??
		controllo_tris();
	}
//6° GIOCO
//Creazione matrice dama
	int const RIGHE_DAMA=8, COLONNE_DAMA=8, X_DAMA=8, Y_DAMA=8;
	int matrice_dama[RIGHE_DAMA][COLONNE_DAMA];
	int vet_x_dama[X_DAMA], vet_y_dama[Y_DAMA];
	int pedine_blu_dama=12, pedine_rosse_dama=12;
	void create_matrice_dama(){
		for(int r=0; r<RIGHE_DAMA; r++)
			for(int c=0; c<COLONNE_DAMA; c++){
				if(r==0 || r==1 || r==2){
					if(r%2==0 && c%2==0 && r!=3 && r!=4 )
						matrice_dama[r][c]=1;
					else
						if(r%2!=0 && c%2!=0 && r!=3 && r!=4)
							matrice_dama[r][c]=1;
					else
						matrice_dama[r][c]=0;
				} 
				else
					if(r==5 || r==6 || r==7){
						if(r%2==0 && c%2==0 && r!=3 && r!=4)
							matrice_dama[r][c]=2;
						else
							if(r%2!=0 && c%2!=0 && r!=3 && r!=4)
								matrice_dama[r][c]=2;
						else
							matrice_dama[r][c]=0;
					}
				else
					matrice_dama[r][c]=0;
			}
	}
//Stampa tabella dama
	void view_matrice_dama(){
		for(int f=0; f<Y_DAMA; f++){
			vet_y_dama[f]=f;
			cout<<"   "<<vet_y_dama[f]<<"  ";
		}
		cout<<endl;
		for(int r=0; r<RIGHE_DAMA; r++){
			vet_x_dama[r]=r;
			cout<<vet_x_dama[r]<<"  ";
			for(int c=0; c<COLONNE_DAMA; c++){
				switch(matrice_dama[r][c]){
					case 0:
						cout<<"\033[31m \033[0m";
					break;
					case 1:
						cout<<"\033[31mO\033[0m";
					break;
					case 2:
						cout<<"\033[34mO\033[0m";
					break;
					case 3:
						cout<<"\033[31m0\033[0m";
					break;
					case 4:
						cout<<"\033[34m0\033[0m";
					break;
				}
				if(c<COLONNE_DAMA-1)
					cout<<"  \033[33m|\033[0m  ";
			}
			if(r==0)
				cout<<"\t \033[31mDame: "<<pedine_rosse_dama<<"\033[0m";
			else
				if(r==RIGHE_DAMA-1)
					cout<<"\t \033[34mDame: "<<pedine_blu_dama<<"\033[0m";
			cout<<endl;
			if(r<RIGHE_DAMA-1)
				cout<<"\033[33m  ---------------------------------------------\033[0m"<<endl;
		}
	}
//1° Turno dama
	void turno_1_dama(){
		int riga=0, colonna=0, t=0;
		char dx_sx;
		bool mossa=true, pedina_selezionata=false, super_salto=false, coordinate=false, pedine_nemiche=false;
		do{
			cout<<"\033[34mTocca al BLU\033[0m"<<endl;
			cout<<"Inserisci le coordinate della pedina che vuoi muovere:"<<endl;
			do{
				cin>>riga>>colonna;
				coordinate=true;
				if(riga<0 || riga>RIGHE_DAMA-1 || colonna<0 || colonna>COLONNE_DAMA-1 || matrice_dama[riga][colonna]==0){
					cout<<"Le coordinate inserite non vanno bene"<<endl;
					coordinate=false;
				}
				if(matrice_dama[riga][colonna]!=2 && matrice_dama[riga][colonna]!=4 && coordinate==true){
					cout<<"Quella non \212 la tua pedina!"<<endl;
					pedina_selezionata=false;
				}
				else
					pedina_selezionata=true;
			}while(!(riga>=0 && riga<=RIGHE_DAMA-1 && colonna>=0 && colonna<=COLONNE_DAMA-1 && pedina_selezionata==true && coordinate==true));
//Comandi dama
			if(matrice_dama[riga][colonna]==2){
				cout<<"Usa le freccette per andare a sinistra \033[34m(<) o (>)\033[0m a destra: "<<endl;
				do{
					dx_sx=_getch();
				}while(dx_sx!=75 && dx_sx!=77);
				cout<<endl;
			}
//Comandi Damone
			else
				if(matrice_dama[riga][colonna]==4){
					cout<<"Guarda la disposizione qui sotto per decidere dove mandare la pedina:"<<endl;
					cout<<"\033[34m   (^)   \033[0m"<<endl;
					cout<<"\033[34m(<) o (>)\033[0m"<<endl;
					cout<<"\033[34m   (v)   \033[0m"<<endl;
					do{
						dx_sx=_getch();
					}while(dx_sx!=72 && dx_sx!=75 && dx_sx!=80 && dx_sx!=77);
				}
//Do-While per le frecce direzionali
			do{
//Mossa della pedina
				if(matrice_dama[riga][colonna]==4){
					super_salto=false;
					switch(dx_sx){
						case 72:
							for(int r=riga; r>=0; r--)
								for(int c=0; c<COLONNE_DAMA; c++)
									if(matrice_dama[r][c]==1 || matrice_dama[r][c]==3)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(colonna>=0 && colonna<=3 || mossa==true)
										for(int c=colonna; c>=0; c--)
											for(int r=riga; r>=0; r--){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c];
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int c=colonna; c<COLONNE_DAMA; c++)
											for(int r=riga; r>=0; r--){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
						case 75:
							for(int c=colonna; c>=0; c--)
								for(int r=0; r<RIGHE_DAMA; r++)
									if(matrice_dama[r][c]==1 || matrice_dama[r][c]==3)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(riga>=0 && riga<=3 || mossa==true)
										for(int r=riga; r>=0; r--)
											for(int c=colonna; c>=0; c--){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int r=riga; r<RIGHE_DAMA; r++)
											for(int c=colonna; c>=0; c--){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
						case 80:
							for(int r=riga; r<RIGHE_DAMA; r++)
								for(int c=0; c<COLONNE_DAMA; c++)
									if(matrice_dama[r][c]==1 || matrice_dama[r][c]==3)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(colonna>=0 && colonna<=3 || mossa==true)
										for(int c=colonna; c>=0; c--)
											for(int r=riga; r<RIGHE_DAMA; r++){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int c=colonna; c<COLONNE_DAMA; c++)
											for(int r=riga; r<RIGHE_DAMA; r++){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
						case 77:
							for(int c=colonna; c<COLONNE_DAMA; c++)
								for(int r=0; r<RIGHE_DAMA; r++)
									if(matrice_dama[r][c]==1 || matrice_dama[r][c]==3)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(riga>=0 && riga<=3 || mossa==true)
										for(int r=riga; r>=0; r--)
											for(int c=colonna; c<COLONNE_DAMA; c++){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int r=riga; r<RIGHE_DAMA; r++)
											for(int c=colonna; c<COLONNE_DAMA; c++){
												if((matrice_dama[r][c]==1 || matrice_dama[r][c]==3) && (super_salto==false)){
													matrice_dama[r][c]=4;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
					}
				}
//Pedina mangia sinistra
				else
					if(dx_sx==75 && matrice_dama[riga-2][colonna-2]==0 && (matrice_dama[riga-1][colonna-1]==1 || matrice_dama[riga-1][colonna-1]==3) && matrice_dama[riga][colonna]==2 && riga!=0 && colonna!=0 && riga-2>=0 && colonna-2>=0){
						if(riga-2==0)
							matrice_dama[riga-2][colonna-2]=4;
						else
							matrice_dama[riga-2][colonna-2]=2;
						matrice_dama[riga-1][colonna-1]=0;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina mangia a destra
				else
					if(dx_sx==77 && matrice_dama[riga-2][colonna+2]==0 && (matrice_dama[riga-1][colonna+1]==1 || matrice_dama[riga-1][colonna+1]==3) && matrice_dama[riga][colonna]==2 && riga!=0 && colonna!=7 && riga-2>=0 && colonna+2<=7){
						if(riga-2==0)
							matrice_dama[riga-2][colonna+2]=4;
						else
							matrice_dama[riga-2][colonna+2]=2;
						matrice_dama[riga-1][colonna+1]=0;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina muove a sinistra
				else
					if(dx_sx==75 && matrice_dama[riga-1][colonna-1]==0 && matrice_dama[riga][colonna]==2 && riga!=0 && colonna!=0){
						if(riga-1==0)
							matrice_dama[riga-1][colonna-1]=4;
						else
							matrice_dama[riga-1][colonna-1]=2;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina muove a destra
				else
					if(dx_sx==77 && matrice_dama[riga-1][colonna+1]==0 && matrice_dama[riga][colonna]==2 && riga!=0 && colonna!=7){
						if(riga-1==0)
							matrice_dama[riga-1][colonna+1]=4;
						else
							matrice_dama[riga-1][colonna+1]=2;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina non movibile
				else{
					cout<<"Quella pedina al momento non si puo' muovere"<<endl;
					mossa=true;
					dx_sx=27;
				}
			}while(dx_sx!=27);	
		}while(mossa==true);
	}
//2° Turno dama
	void turno_2_dama(){
		int riga=0, colonna=0, t=0;
		char dx_sx;
		bool mossa=true, pedina_selezionata=false, super_salto=false, coordinate=false, pedine_nemiche=false;
		do{
			cout<<"\033[31mTocca al ROSSO\033[0m"<<endl;
			cout<<"Inserisci le coordinate della pedina che vuoi muovere:"<<endl;
			do{
				cin>>riga>>colonna;
				coordinate=true;
				if(riga<0 || riga>RIGHE_DAMA-1 || colonna<0 || colonna>COLONNE_DAMA-1 || matrice_dama[riga][colonna]==0){
					cout<<"Le coordinate inserite non vanno bene"<<endl;
					coordinate=false;
				}
				if(matrice_dama[riga][colonna]!=1 && matrice_dama[riga][colonna]!=3 && coordinate==true){
					cout<<"Quella non \212 la tua pedina!"<<endl;
					pedina_selezionata=false;
				}
				else
					pedina_selezionata=true;
			}while(!(riga>=0 && riga<=RIGHE_DAMA-1 && colonna>=0 && colonna<=COLONNE_DAMA-1 && pedina_selezionata==true && coordinate==true));
//Comandi dama
			if(matrice_dama[riga][colonna]==1){
				cout<<"Usa le freccette per andare a sinistra \033[31m(<) o (>)\033[0m a destra: "<<endl;
				do{
					dx_sx=_getch();
				}while(dx_sx!=75 && dx_sx!=77);
				cout<<endl;
			}
//Comandi Damone
			else
				if(matrice_dama[riga][colonna]==3){
					cout<<"Guarda la disposizione qui sotto per decidere dove mandare la pedina:"<<endl;
					cout<<"\033[31m   (^)   \033[0m"<<endl;
					cout<<"\033[31m(<) o (>)\033[0m"<<endl;
					cout<<"\033[31m   (v)   \033[0m"<<endl;
					do{
						dx_sx=_getch();
					}while(dx_sx!=72 && dx_sx!=75 && dx_sx!=80 && dx_sx!=77);
				}
//Do-While per le frecce direzionali
			do{
//Mossa della pedina
				if(matrice_dama[riga][colonna]==3){
					super_salto=false;
					switch(dx_sx){
						case 72:
							for(int r=riga; r>=0; r--)
								for(int c=0; c<COLONNE_DAMA; c++)
									if(matrice_dama[r][c]==2 || matrice_dama[r][c]==4)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(colonna>=0 && colonna<=3 || mossa==true)
										for(int c=colonna; c>=0; c--)
											for(int r=riga; r>=0; r--){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int c=colonna; c<COLONNE_DAMA; c++)
											for(int r=riga; r>=0; r--){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
						case 75:
							for(int c=colonna; c>=0; c--)
								for(int r=0; r<RIGHE_DAMA; r++)
									if(matrice_dama[r][c]==2 || matrice_dama[r][c]==4)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(riga>=0 && riga<=3 || mossa==true)
										for(int r=riga; r>=0; r--)
											for(int c=colonna; c>=0; c--){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int r=riga; r<RIGHE_DAMA; r++)
											for(int c=colonna; c>=0; c--){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
						case 80:
							for(int r=riga; r<RIGHE_DAMA; r++)
								for(int c=0; c<COLONNE_DAMA; c++)
									if(matrice_dama[r][c]==2 || matrice_dama[r][c]==4)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(colonna>=0 && colonna<=3 || mossa==true)
										for(int c=colonna; c>=0; c--)
											for(int r=riga; r<RIGHE_DAMA; r++){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int c=colonna; c<COLONNE_DAMA; c++)
											for(int r=riga; r<RIGHE_DAMA; r++){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
						case 77:
							for(int c=colonna; c<COLONNE_DAMA; c++)
								for(int r=0; r<RIGHE_DAMA; r++)
									if(matrice_dama[r][c]==2 || matrice_dama[r][c]==4)
										pedine_nemiche=true;
							if(pedine_nemiche==true)
								do{
									if(riga>=0 && riga<=3 || mossa==true)
										for(int r=riga; r>=0; r--)
											for(int c=colonna; c<COLONNE_DAMA; c++){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
									if(riga>=4 && riga<=7 || mossa==true)
										for(int r=riga; r<RIGHE_DAMA; r++)
											for(int c=colonna; c<COLONNE_DAMA; c++){
												if((matrice_dama[r][c]==2 || matrice_dama[r][c]==4) && (super_salto==false)){
													matrice_dama[r][c]=3;
													matrice_dama[riga][colonna]=0;
													super_salto=true;
													mossa=false;
												}
											}
								}while(mossa==true);
							else{
								cout<<"Non ci sono pedine in quella zona"<<endl;
								mossa=true;
							}
							dx_sx=27;
						break;
					}
				}
//Pedina mangia sinistra
				else
					if(dx_sx==75 && matrice_dama[riga+2][colonna-2]==0 && (matrice_dama[riga+1][colonna-1]==2 || matrice_dama[riga+1][colonna-1]==4) && matrice_dama[riga][colonna]==1 && riga!=7 && colonna!=0 && riga+2<=7 && colonna-2>=0){
						if(riga+2==7)
							matrice_dama[riga+2][colonna-2]=3;
						else
							matrice_dama[riga+2][colonna-2]=1;
						matrice_dama[riga+1][colonna-1]=0;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina mangia a destra
				else
					if(dx_sx==77 && matrice_dama[riga+2][colonna+2]==0 && (matrice_dama[riga+1][colonna+1]==2 || matrice_dama[riga+1][colonna+1]==4) && matrice_dama[riga][colonna]==1 && riga!=7 && colonna!=7 && riga+2<=7 && colonna+2<=7){
						if(riga+2==7)
							matrice_dama[riga+2][colonna+2]=3;
						else
							matrice_dama[riga+2][colonna+2]=1;
						matrice_dama[riga+1][colonna+1]=0;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina muove a sinistra
				else
					if(dx_sx==75 && matrice_dama[riga+1][colonna-1]==0 && matrice_dama[riga][colonna]==1 && riga!=7 && colonna!=0){
						if(riga+1==7)
							matrice_dama[riga+1][colonna-1]=3;
						else
							matrice_dama[riga+1][colonna-1]=1;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina muove a destra
				else
					if(dx_sx==77 && matrice_dama[riga+1][colonna+1]==0 && matrice_dama[riga][colonna]==1 && riga!=7 && colonna!=7){
						if(riga+1==7)
							matrice_dama[riga+1][colonna+1]=3;
						else
							matrice_dama[riga+1][colonna+1]=1;
						matrice_dama[riga][colonna]=0;
						mossa=false;
						dx_sx=27;
					}
//Pedina non movibile
				else{
					cout<<"Quella pedina al momento non si puo' muovere"<<endl;
					mossa=true;
					dx_sx=27;
				}
			}while(dx_sx!=27);
		}while(mossa==true);
	}
//Verifica dama
	bool verifica_pedine_dama(){
		pedine_blu_dama=0;
		pedine_rosse_dama=0;
		for(int r=0; r<RIGHE_DAMA; r++)
			for(int c=0; c<COLONNE_DAMA; c++){
				if(matrice_dama[r][c]==2 || matrice_dama[r][c]==4)
					pedine_blu_dama++;
				else
					if(matrice_dama[r][c]==1 || matrice_dama[r][c]==3)
						pedine_rosse_dama++;
			}
		if(pedine_blu_dama==0 || pedine_rosse_dama==0){
			if(pedine_blu_dama==0)
				cout<<"\n"<<"\033[31mVittoria\033[0m"<<"\n"<<"Vincono le pedine rosse"<<endl;
			else
				cout<<"\n"<<"\033[34mVittoria\033[0m"<<"\n"<<"Vincono le pedine blu"<<endl;
			return false;
		}
		else
			return true;
	}
	
//RELOAD SYSTEM
void Reolad_System(){
	//Sistema di riavvio
	reload=false;
	//sistema master
	for(int f=0; f<6; f++)
		master_control_password[f]=' ';
	cont_master_control=-1;
	master_control_interface=0;
	boost=0;
	jolly=0;
	berserk=0;
	backstage=0;
	utilizzo_master_control=false;
	corrispondenza_master_utente=false;
	//inizio sistema
	for(int f=0; f<20; f++)
		utente[f]=' ';
	//inizio sistema
	scelta_colore=0;
	cont_lettere=0;
	//int in comune
	cont_v=0;
	cont_s=0;
	cont_p=0;
	partite_giocate=0;
	//int in comune
	resoconto_v=0;
	resoconto_s=0;
	resoconto_p=0;
	resoconto_partite=0;
	//int in comune
	restart;
	//inizio sistema
	riprovare;
	//5° Gioco
	verifica_tris=false;
	//6° Gioco
	pedine_blu_dama=12;
	pedine_rosse_dama=12;
}

//ZONA SISTEMA
int main ()
{
	do{
		Reolad_System();
		int scelta_gioco, scambio_colore_master_control; //inizio sistema
		int s1=100, s2=101, s3=102, c1, c2, c3, scommessa, vincitore, scelta_interna1;  //1° gioco
		int scelta_g, scelta_c, scelta_interna2; //2° gioco
		int attacco, difesa, cont_dif=0, fortuna, scelta_interna3;//3° gioco
		int lancio, dadi, vita_blu=100, vita_rossa=100, cannonata=15, doppia_cannonata=30, razzo=50, cont_round=0, cont_dinamico_dispari=0, cont_dinamico_pari=0, cont_dispari=0, cont_pari=0, scelta_interna4;//4° gioco
		int conta_turni_tris=0, scelta_multiplayer_tris=0, scelta_interna5; //5° gioco
		int scelta_interna6;//6° gioco
//Inizio del sistema
		cout<<"\033[35mXXXXXXXX    XXXXXXXX    X          XXXXXXXX           XXXXXXXXX    XX    XXXXXXXXXX   XXXXXXXXX   X       X   XX\033[0m"<<"               \033[31m(1)\033[0m per il colore \033[31mrosso\033[0m"  <<endl;
		cout<<"\033[35mX           X      X    X          X      X           X            XX    X        X   X           X       X   XX\033[0m"<<"               \033[32m(2)\033[0m per il colore \033[32mverde\033[0m"  <<endl;
		cout<<"\033[35mX           X      X    X          X      X           X            XX    X        X   X           X       X   XX\033[0m"<<"               \033[33m(3)\033[0m per il colore \033[33mgiallo\033[0m" <<endl;
		cout<<"\033[35mXXXXXXXX    XXXXXXXX    X          XXXXXXXX           X   XXXXX    XX    X        X   X           XXXXXXXXX   XX\033[0m"<<"               \033[34m(4)\033[0m per il colore \033[34mblu\033[0m"    <<endl;
		cout<<"\033[35m       X    X      X    X          X      X           X       X    XX    X        X   X           X       X   XX\033[0m"<<"               \033[35m(5)\033[0m per il colore \033[35mviola\033[0m"  <<endl;
		cout<<"\033[35m       X    X      X    X          X      X           X       X    XX    X        X   X           X       X   XX\033[0m"<<"               \033[36m(6)\033[0m per il colore \033[36mazzurro\033[0m"<<endl;
		cout<<"\033[35mXXXXXXXX    X      X    XXXXXXXX   X      X           XXXXXXXXX    XX    XXXXXXXXXX   XXXXXXXXX   X       X   XX\033[0m"<<"               \033[37m(7)\033[0m per il colore \033[37mbianco\033[0m" <<endl;
		cout<<endl;
		cout<<endl;
//Colore utente
		do{
			cout<<"Inserisci il numero del colore che vuoi: ";
			cin>>scelta_colore;
			scambio_colore_master_control=scelta_colore;
			cout<<endl;
		}while(scelta_colore!=1 && scelta_colore!=2 && scelta_colore!=3 && scelta_colore!=4 && scelta_colore!=5 && scelta_colore!=6 && scelta_colore!=7);
//Nome utente
		cout<<"Inserire il tuo nome utente: ";
		cin>>utente;
		cout<<endl;
//Stampa utente
		verifica_utente();
		do{
//Scelta del gioco
			do{
				cout<<"\n\033[32m(1)\033[0m Corsa dei cavalli        \033[32m(2)\033[0m Sasso carta forbice    \033[32m(3)\033[0m Assalto alla torre "<<endl;
				cout<<"\033[32m(4)\033[0m Raid into the Kingdom    \033[32m(5)\033[0m Tris                   \033[32m(6)\033[0m Dama"<<endl;
				cout<<endl;
				cout<<"Inserire \033[3"<<scelta_colore<<"m(10)\033[0m"<<" per andare in lobby"<<endl;
				cout<<"Inserire \033[31m(0)\033[0m per spegnere il sistema"<<endl;
				cout<<"\nScegli un gioco: ";
				cin>>scelta_gioco;
				cout<<endl;
			}while(scelta_gioco!=1 && scelta_gioco!=2 && scelta_gioco!=3 && scelta_gioco!=4 && scelta_gioco!=5 &&scelta_gioco!=6 && scelta_gioco!=7 && scelta_gioco!=8 && scelta_gioco!=9 && scelta_gioco!=10 && scelta_gioco!=0);
			switch(scelta_gioco){
//Scelta gioco (1)
				case 1:
//Game start (1)
				cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
				do{
					do{
						cout<<"Benvenuti nel minigame: Corsa dei cavalli."<<endl;
						cout<<"Mettiti in gioco, tenta la fortuna per vincere." <<endl;
						cout<<"\033[33mPremere (1) per leggere le regole e il funzionamento del gioco.\033[0m"<<endl;
						cout<<"\033[36mPremere (2) per iniziare a giocare.\033[0m"<<endl;
						cin>>scelta_interna1;
						cout<<endl;
					}while(scelta_interna1!=1 && scelta_interna1!=2);
					if(scelta_interna1==1){
						cout<<"\033[33mECCO IL REGOLAMENTO:\033[0m"<<endl;
						cout<<"\033[33m1) Corsa dei Cavalli, un gioco basato sul fatto che l'utente deve scommettere su uno dei 3 cavalli in gioco.\033[0m"<<endl;
						cout<<"\033[33m2) I 3 cavalli si muoveranno in modo completamente casuale e il primo che arrivera' al traguardo vincera'.\033[0m"<<endl;
						cout<<"\033[33m3) L'utente deve scegliere su quale cavallo scommettere e il sistema li fara' avanzare in modo autonomo.\033[0m"<<endl;
						cout<<"\033[33m4) In caso di vincita o sconfitta l'utente potra' comunque fare un'altra partita se vorra'.\033[0m"<<endl;
						cout<<"\033[33m5) In caso di pareggio invece il sistema fara' ricominciare la partita in modo autonomo senza vincitori e vinti.\033[0m"<<endl;
						cout<<endl;
					}
				}while(scelta_interna1!=2);
//Assegnazione int in comune
		stamp_assegnazioni();
			do{
				if(scelta_interna1==2){
					cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
					cout<<endl;
					cout<<"\033[36mSi comincia!!\033[0m"<<endl;
					cout<<endl;
//Inizio secondario
					do{
						if(s1==s2 || s2==s3 || s1==s3){
							cont_p++;
							cout<<"\033[34mSi e' verificato un pareggio, per corettezza la gara verra' rifatta.\033[0m"<<endl;
							cout<<endl;
						}
//Assegnazione 1° gioco
						s1=0;
						s2=0;
						s3=0;
						c1=0;
						c2=0;
						c3=0;
						scommessa=0;
//Inizio principale
						do{
							cout<<"Su quale cavallo scommetti??"<<endl;
							cout<<"Inserire (1) per il primo cavallo"<<endl;
							cout<<"Inserire (2) per il secondo cavallo"<<endl;
							cout<<"Inserire (3) per il terzo cavallo"<<endl;
							cin>>scommessa;
						}while(scommessa!=1 && scommessa!=2 && scommessa!=3);
						cout<<endl;
						cout<<"Che la corsa dei cavalli abbia inizio: " <<endl;
						srand(time(NULL));
						do{
//Cavallo 1
							if(boost==1 && scommessa==1) c1=rand()%13+1; //master control mode: "boost"
							else c1=rand()%10+1;
							s1=s1+c1;
//Cavallo 2
							if(boost==1 && scommessa==2) c2=rand()%13+1; //master control mode: "boost"
							else c2=rand()%10+1;
							s2=s2+c2;							
//Cavallo 3
							if(boost==1 && scommessa==3) c3=rand()%13+1; //master control mode: "boost"
							else c3=rand()%10+1;
							s3=s3+c3;
//Contatore 1
								if(backstage==1) cout<<"\033[35mc1: "<<c1<<" e "<<"s1: "<<s1<<"\033[0m"<<endl; //master control mode: "backstage"
							if(s1>=s2 && s1>=s3){
								cout<<"\033[32mCavallo 1: " <<s1 <<"%\033[0m ";
								for(int f=1; f<=s1; f++) cout<<"\033[32m-\033[0m";
								cout<<endl;
							}
							else{
								cout<<"Cavallo 1: " <<s1 <<"% ";
								for(int f=1; f<=s1; f++) cout<<"-";
								cout<<endl;
							}
//Contatore 2
								if(backstage==1) cout<<"\033[35mc2: "<<c2 <<" e "<<"s2: "<<s2<<"\033[0m"<<endl; //master control mode: "backstage"
							if(s2>=s1 && s2>=s3){
								cout<<"\033[32mCavallo 2: " <<s2 <<"%\033[0m ";
								for(int f=1; f<=s2; f++) cout<<"\033[32m-\033[0m";
								cout<<endl;
							}
							else{
								cout<<"Cavallo 2: " <<s2 <<"% ";
								for(int f=1; f<=s2; f++) cout<<"-";
								cout<<endl;
							}
//Contatore 3
								if(backstage==1) cout<<"\033[35mc3: "<<c3<<" e "<<"s3: "<<s3<<"\033[0m"<<endl; //master control mode: "backstage"
							if(s3>=s1 && s3>=s2){
								cout<<"\033[32mCavallo 3: " <<s3 <<"%\033[0m ";
								for(int f=1; f<=s3; f++) cout<<"\033[32m-\033[0m";
								cout<<endl;
							}
							else{
								cout<<"Cavallo 3: " <<s3 <<"% ";
								for(int f=1; f<=s3; f++) cout<<"-";
								cout<<endl;
							}
							cout<<endl;
							cout<<".................................................................................................................."<<endl;
							cout<<endl;
						}while(s1<=99 && s2<=99 && s3<=99);
						cout<<endl;
					}while(s1==s2 || s2==s3 || s1==s3);
//Arrivo
					cout<<"-Hai puntato sul cavallo numero: (" <<scommessa <<")" <<endl;
					if(s1>s2 && s1>s3){
						cout<<"-Ha vinto il cavallo numero 1."<<endl;
						vincitore=1;
					}
					else{
						if(s2>s1 && s2>s3){
							cout<<"-Ha vinto il cavallo numero 2."<<endl;
							vincitore=2;
						}
						else{
							if(s3>s1 && s3>s2){
								cout<<"-Ha vinto il cavallo numero 3."<<endl;
								vincitore=3;
							}
						}
					}
					if(scommessa==vincitore){
						cont_v++;
						cout<<"-Il cavallo su cui hai scomesso ha vinto."<<endl;
						cout<<"\033[32m-HAI VINTO LE SCOMMESSE!!\033[0m"<<endl;
					}
					else{
						cont_s++;
						cout<<"-Il cavallo su cui hai scomesso non ha vinto."<<endl;
						cout<<"\033[31m-Questa volta non hai vinto nulla, pero' puoi sempre riprovare.\033[0m"<<endl;
					}
//Classifica
					cout<<endl;
					cout<<"Ecco la classifica: "<<endl;
					if(s1<s2 && s1<s3 && s2<s3){
						cout<<"Primo posto: cavallo numero 3" <<endl;
						cout<<"Secondo posto: cavallo numero 2" <<endl;
						cout<<"Terzo posto: cavallo numero 1" <<endl;
					}
					else{
						if(s1>s2 && s1>s3 && s2>s3){
							cout<<"Primo posto: cavallo numero 1" <<endl;
							cout<<"Secondo posto: cavallo numero 2" <<endl;
							cout<<"Terzo posto: cavallo numero 3" <<endl;
						}
						else{
							if(s1>s2 && s1>s3 && s2<s3){
								cout<<"Primo posto: cavallo numero 1" <<endl;
								cout<<"Secondo posto: cavallo numero 3" <<endl;
								cout<<"Terzo posto: cavallo numero 2" <<endl;
							}
							else{
								if(s1<s2 && s1>s3 && s2>s3){
									cout<<"Primo posto: cavallo numero 2" <<endl;
									cout<<"Secondo posto: cavallo numero 1" <<endl;
									cout<<"Terzo posto: cavallo numero 3" <<endl;
								}
								else{
									if(s1<s2 && s1<s3 && s2>s3){
										cout<<"Primo posto: cavallo numero 2" <<endl;
										cout<<"Secondo posto: cavallo numero 3" <<endl;
										cout<<"Terzo posto: cavallo numero 1" <<endl;
									}
									if(s1>s2 && s1<s3 && s2<s3){
										cout<<"Primo posto: cavallo numero 3" <<endl;
										cout<<"Secondo posto: cavallo numero 1" <<endl;
										cout<<"Terzo posto: cavallo numero 2" <<endl;
									}
								}
							}
						}
					}
					cout<<endl;
//Segna punti
					segna_punti();
					cout<<endl;
				}
//Giocare ancora o tornare alla scelta iniziale
				stamp_termina();
			}while(restart!=2);
//Lista resoconto
			resoconto();
		break;
//Scelta gioco (2)
		case 2:
//Game start (2)
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
			do{
				do{
					cout<<"Benvenuti nel minigame: Sasso carta forbice."<<endl;
					cout<<"\033[33mPremere 1 per leggere le regole e il funzionamento del gioco.\033[0m"<<endl;
					cout<<"\033[36mPremere 2 per iniziare a giocare.\033[0m"<<endl;
					cin>>scelta_interna2;
					cout<<endl;
				}while(scelta_interna2!=1 && scelta_interna2!=2);
				if(scelta_interna2==1){
					cout<<"\033[33mECCO IL REGOLAMENTO:\033[0m"<<endl;
					cout<<"\033[33m1) Sasso carta forbice, e' un gioco basato sulla fortuna in cui il tuo obbiettivo sara' vincere contro il sistema.\033[0m"<<endl;
					cout<<"\033[33m2) In questo gioco l'utenete dovra' scegliere tra 1, 2 o 3 per i rispettivi simboli.\033[0m"<<endl;
					cout<<"\033[33m3) Il sistema scegliera' in modo completamente casuale quale simbolo scegliere.\033[0m"<<endl;
					cout<<"\033[33m4) In caso di vincita o sconfitta l'utente potra' comunque fare un'altra partita se vorra'.\033[0m"<<endl;
					cout<<"\033[33m5) In caso di pareggio invece il sistema fara' ricominciare la partita in modo autonomo senza vincitori e vinti.\033[0m"<<endl;
					cout<<endl;
				}
			}while(scelta_interna2!=2);
//Assegnazione int in comune
			stamp_assegnazioni();
//Inizio principale
			do{
				if(scelta_interna2==2){
					cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
					cout<<endl;
					cout<<"\033[36msi comincia!!\033[0m"<<endl;
					cout<<endl;
					srand(time(0));
		   			string choices[]={"sasso", "carta", "forbice"};
//Inizio secondario
		   			do{
		   				cout<< "Scegli tra carta sasso e forbice!\n\n";
		   				do{
		   					cout<< "Inserisci (1) per sasso, (2) per carta e (3) per forbice: ";
		   					cin>> scelta_g;
		   				}while(scelta_g!=1 && scelta_g!=2 && scelta_g!=3);
		   				cout<<"Hai scelto " <<choices[scelta_g-1] << ".\n";
		   				scelta_c=rand()%3+1;
		   				cout<<"Il computer ha scelto "<<choices[scelta_c-1]<<".\n";
						if(scelta_g == scelta_c){
							cout<<"\033[34mPareggio!\033[0m\n" <<endl;
							cont_p++;
						}
					}while(scelta_g == scelta_c);
					if((scelta_g == 1 && scelta_c == 3)||(scelta_g == 2 && scelta_c == 1)||(scelta_g == 3 && scelta_c == 2)){
		   				cout<<"\033[32mHai vinto!\033[0m\n";
						cont_v++;
		   			}
					else{
						cout<< "\033[31mIl computer ha vinto!\033[0m\n";
						cont_s++;
					}
				}
				cout<<endl;
//Segna punti
				segna_punti();
				cout<<endl;
//Giocare ancora o tornare alla scelta iniziale
				stamp_termina();
			}while(restart!=2);
//Lista resoconto
			resoconto();
		break;
//Scelta gioco (3)
		case 3:
//Game start (3)
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
			do{
				do{
					cout<<"Benvenuti nel minigame: assalto alla torre."<<endl;
					cout<<"\033[33mPremere 1 per leggere le regole e il funzionamento del gioco.\033[0m"<<endl;
					cout<<"\033[36mPremere 2 per iniziare a giocare.\033[0m"<<endl;
					cin>>scelta_interna3;
					cout<<endl;
				}while(scelta_interna3!=1 && scelta_interna3!=2);
				if(scelta_interna3==1){
					cout<<"\033[33mECCO IL REGOLAMENTO:\033[0m"<<endl;
					cout<<"\033[33m1)  Assalto alla torre e' un gioco basato sulla strategia.\033[0m"<<endl;
					cout<<"\033[33m2)  Il tuo obbiettivo e' quello di proteggere la torre dagli attacchi del cannone.\033[0m"<<endl;
					cout<<"\033[33m3)  Utilizza i pulssanti (1), (2) e (3) per proteggere le zone della torre che potrebbero essere attaccate.\033[0m"<<endl;
					cout<<"\033[33m4)  Il sistema scegliera' in modo completamente casuale quale zona attaccare.\033[0m"<<endl;
					cout<<"\033[33m5)  In caso di vincita o sconfitta l'utente potra' comunque fare un'altra partita se vorra'.\033[0m"<<endl;
					cout<<endl;
				}
			}while(scelta_interna3!=2);
//Assegnazione int in comune
			stamp_assegnazioni();
//Inizio principale
			do{
				if(scelta_interna3==2){
					cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
					cout<<endl;
					cout<<"\033[36msi comincia!!\033[0m"<<endl;
					cout<<endl;
//Grafica
					cout<<"\033[34mXX  XX  XX    XX  XX  XX\033[0m		\033[33mXXXX        XXXX    XXXXXXXXXXXXXXXX\033[0m 		\033[31m                           X \033[0m"<<endl;
					cout<<"\033[34mXXX XXX XXX  XXX XXX XXX\033[0m		\033[33mXXXX        XXXX    XXXXXXXXXXXXXXXX\033[0m   		\033[31mXXX       XXXXXXXXXXXXXX  X  \033[0m"<<endl;
					cout<<"\033[34mXXXXXXXXXXXXXXXXXXXXXXXX\033[0m		\033[33mXXXX        XXXX    XXXXX           \033[0m  		\033[31mXXXXXXXXXXXXXXXXXXXXXXXXXXX  \033[0m"<<endl;
					cout<<"\033[34m   XXXXXXXXXXXXXXXXXX   \033[0m		\033[33m XXXX      XXXX     XXXXX           \033[0m  		\033[31mXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\033[0m"<<endl;
					cout<<"\033[34m    XXXXXXXXXXXXXXXX    \033[0m		\033[33m XXXX      XXXX     XXXXX           \033[0m   		\033[31mXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\033[0m"<<endl;
					cout<<"\033[34m    XXXXXXXXXXXXXXXX    \033[0m		\033[33m XXXX      XXXX     XXXXXXXXXXXXXXXX\033[0m 		\033[31mXXXXXXXXXXXXXXXXXXXXXXXXXXX  \033[0m"<<endl;
					cout<<"\033[34m   XXXXXXXXXXXXXXXXXX   \033[0m		\033[33m  XXXX    XXXX      XXXXXXXXXXXXXXXX\033[0m 		\033[31mXXX       XXXXXXXXXXXXXX     \033[0m"<<endl;
					cout<<"\033[34m  XXXXXXXXXXXXXXXXXXXX  \033[0m		\033[33m  XXXX    XXXX                 XXXXX\033[0m 		\033[31m       XXXXXXXXXXXXXXXXXXXXX \033[0m"<<endl;
					cout<<"\033[34m XXXXXXXXXXXXXXXXXXXXXX \033[0m		\033[33m  XXXX    XXXX                 XXXXX\033[0m 		\033[31m        XXXX           XXXX  \033[0m"<<endl;
					cout<<"\033[34mXXXXXXXXXXX  XXXXXXXXXXX\033[0m		\033[33m   XXXX  XXXX                  XXXXX\033[0m 		\033[31m      XXXXXXXX       XXXXXXXX\033[0m"<<endl;
					cout<<"\033[34mXXXXXXXXXX    XXXXXXXXXX\033[0m		\033[33m   XXXXXXXXXX       XXXXXXXXXXXXXXXX\033[0m 		\033[31m      XXXXXXXX       XXXXXXXX\033[0m"<<endl;
					cout<<"\033[34mXXXXXXXXXX    XXXXXXXXXX\033[0m		\033[33m   XXXXXXXXXX       XXXXXXXXXXXXXXXX\033[0m 		\033[31m        XXXX           XXXX  \033[0m"<<endl;
					cout<<endl;
					srand(time(NULL));
					cout<<"Difendi la tua torre!!"<<endl;
					for(int f=0; f<=4; f++){
						attacco=rand()%3+1;
							if(jolly==1){ //master control mode: "jolly"
								fortuna=rand()%4+1;
								if(fortuna==4) attacco=0;
								if(backstage==1) cout<<"\033[35mFortuna: "<<fortuna<<"\033[0m"<<endl; //master control mode: "backstage"
							}
							if(backstage==1) cout<<"\033[35mattacco: "<<attacco<<"\033[0m"<<endl; //master control mode: "backstage"
//Azione del giocatore
						do{
							cout<<"Scegli che punto difendere inserendo (1), (2) o (3): ";
							cin>>difesa;
						}while(difesa!=1 && difesa!=2 && difesa!=3);
//Attacco
						if(attacco==0){
							cout<<"\033[32mChe fortuna ci hanno mancato!!\033[0m"<<endl;
							cont_dif++;
						}
//Difesa
						else{
							if(difesa==attacco){
								cout<<"\033[32mBravo sei riuscito a difenderti!!\033[0m"<<endl;
								cont_dif++;
							}
							else cout<<"\033[31mCavolo ci hanno colpiti!!\033[0m"<<endl;
						}
					}
					cout<<endl;
//Classifica
					if(cont_dif>=3){
						cout<<"\033[32mBravo!! La tua difesa ha vinto sull'attacco\033[0m"<<endl;
						cont_v++;
					}
					else{
						if(cont_dif==2){
							cout<<"\033[33mPeccato!! per poco non vincevi!!\033[0m"<<endl;
							cont_s++;
						}
						else{
							cout<<"\033[31mPeccato!! L'attacco ha sopraffatto la nostra difesa\033[0m"<<endl;
							cont_s++;
						}
					}
				}
				cout<<endl;
//Assegnazione 3° gioco
				cont_dif=0;
//Segna punti
				segna_punti();
				cout<<endl;
//Giocare ancora o tornare alla scelta iniziale
				stamp_termina();	
			}while(restart!=2);
//Lista resoconto
			resoconto();
		break;
//Scelta gioco (4)
		case 4:
//Game start (4)
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
			do{
				do{
					cout<<"Benvenuti nel minigame: Raid into the Kingdom."<<endl;
					cout<<"\033[33mPremere 1 per leggere le regole e il funzionamento del gioco.\033[0m"<<endl;
					cout<<"\033[36mPremere 2 per iniziare a giocare.\033[0m"<<endl;
					cin>>scelta_interna4;
					cout<<endl;
				}while(scelta_interna4!=1 && scelta_interna4!=2);
				if(scelta_interna4==1){
					cout<<"\033[33mECCO IL REGOLAMENTO:\033[0m"<<endl;
					cout<<"\033[33m1) Raid into the Kingdom e' un gioco basato sulla strategia.\033[0m"<<endl;
					cout<<"\033[33m2) In questo gioco il tuo obbiettivo sara' vincere contro il sistema.\033[0m"<<endl;
					cout<<"\033[33m3) In questo gioco l'utente dovra' scegliere se attaccare il nemico o curarsi.\033[0m"<<endl;
					cout<<"\033[33m4) Il sistema scegliera' in modo completamente casuale quale delle 2 opzioni scegliere.\033[0m"<<endl;
					cout<<"\033[33m5) In caso di vincita o sconfitta l'utente potra' comunque fare un'altra partita se vorra'.\033[0m"<<endl;
					cout<<endl;
				}
			}while(scelta_interna4!=2);
//Assegnazione int in comune
			stamp_assegnazioni();
//Inizio principale
			do{
				if(scelta_interna4==2){
					cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
					cout<<endl;
					cout<<"\033[36msi comincia!!\033[0m"<<endl;
					cout<<endl;
//Grafica
					cout<<"\033[34m               XX  XX  XX    XX  XX  XX               \033[0m	   \033[33mXXXX        XXXX    XXXXXXXXXXXXXXXX\033[0m      \033[31m               XX  XX  XX    XX  XX  XX               \033[0m"<<endl;
					cout<<"\033[34m               XXX XXX XXX  XXX XXX XXX               \033[0m	   \033[33mXXXX        XXXX    XXXXXXXXXXXXXXXX\033[0m      \033[31m               XXX XXX XXX  XXX XXX XXX               \033[0m"<<endl;
					cout<<"\033[34m               XXXXXXXXXXXXXXXXXXXXXXXX               \033[0m	   \033[33mXXXX        XXXX    XXXXX           \033[0m      \033[31m               XXXXXXXXXXXXXXXXXXXXXXXX               \033[0m"<<endl;
					cout<<"\033[34m                  XXXXXXXXXXXXXXXXXX                  \033[0m	   \033[33m XXXX      XXXX     XXXXX           \033[0m      \033[31m                  XXXXXXXXXXXXXXXXXX                  \033[0m"<<endl;
					cout<<"\033[34mX X X X X X X      XXXXXXXXXXXXXXXX      X X X X X X X\033[0m	   \033[33m XXXX      XXXX     XXXXX           \033[0m      \033[31mX X X X X X X      XXXXXXXXXXXXXXXX      X X X X X X X\033[0m"<<endl;
					cout<<"\033[34mXXXXXXXXXXXXX      XXXXXXXXXXXXXXXX      XXXXXXXXXXXXX\033[0m	   \033[33m XXXX      XXXX     XXXXXXXXXXXXXXXX\033[0m      \033[31mXXXXXXXXXXXXX      XXXXXXXXXXXXXXXX      XXXXXXXXXXXXX\033[0m"<<endl;
					cout<<"\033[34m  XXXXXXXXX       XXXXXXXXXXXXXXXXXX       XXXXXXXXX  \033[0m	   \033[33m  XXXX    XXXX      XXXXXXXXXXXXXXXX\033[0m      \033[31m  XXXXXXXXX       XXXXXXXXXXXXXXXXXX       XXXXXXXXX  \033[0m"<<endl;
					cout<<"\033[34m   XXXXXXX       XXXXXXXXXXXXXXXXXXXX       XXXXXXX   \033[0m	   \033[33m  XXXX    XXXX                 XXXXX\033[0m      \033[31m   XXXXXXX        XXXXXXXXXXXXXXXXXXX       XXXXXXX   \033[0m"<<endl;
					cout<<"\033[34m  XXXXXXXXX     XXXXXXXXXXXXXXXXXXXXXX     XXXXXXXXX  \033[0m	   \033[33m  XXXX    XXXX                 XXXXX\033[0m      \033[31m  XXXXXXXXX     XXXXXXXXXXXXXXXXXXXXXX     XXXXXXXXX  \033[0m"<<endl;
					cout<<"\033[34m XXXXX XXXXX   XXXXXXXXXXX  XXXXXXXXXXX   XXXXX XXXXX \033[0m	   \033[33m   XXXX  XXXX                  XXXXX\033[0m      \033[31m XXXXX XXXXX   XXXXXXXXXXX  XXXXXXXXXXX   XXXXX XXXXX \033[0m"<<endl;
					cout<<"\033[34mXXXXX   XXXXX  XXXXXXXXXX    XXXXXXXXXX  XXXXX   XXXXX\033[0m	   \033[33m   XXXXXXXXXX       XXXXXXXXXXXXXXXX\033[0m      \033[31mXXXXX   XXXXX  XXXXXXXXXX    XXXXXXXXXX  XXXXX   XXXXX\033[0m"<<endl;
					cout<<"\033[34mXXXXX   XXXXX  XXXXXXXXXX    XXXXXXXXXX  XXXXX   XXXXX\033[0m	   \033[33m   XXXXXXXXXX       XXXXXXXXXXXXXXXX\033[0m      \033[31mXXXXX   XXXXX  XXXXXXXXXX    XXXXXXXXXX  XXXXX   XXXXX\033[0m"<<endl;
					cout<<endl;
					do{
						cont_round++;
//Azione del giocatore
						if(cont_round%2!=0){
							if(berserk==1){	//master mode control: "berserk"
								do{
									cout<<endl;
									if(backstage==1)
										cout<<"Premi (1) per attaccare o (2) per riparare la torre o \033[35m(3) per usare l'abilita' 'berserk': \033[0m"; //master mode control: "backstage"
									else
										cout<<"Premi (1) per attaccare o (2) per riparare la torre: ";
									cin>>lancio;
								}while(lancio!=1 && lancio!=2 && lancio!=3);
							}
							else{
								do{
									cout<<"\nPremi (1) per attaccare o (2) per riparare la torre: ";
									cin>>lancio;
								}while(lancio!=1 && lancio!=2);
							}
							if(cont_dispari!=0){
								if(vita_blu<=135)
									vita_blu=vita_blu+15;
								else
									vita_blu=150;
								cout<<"\033[32mLa tua torre si sta riparando: "<<vita_blu<<"\033[0m"<<endl;
							}
						}
//Azione del computer
						else{
							cout<<"\nTOCCA AL ROSSO!!"<<endl;
							lancio=rand()%2+1;
							if(cont_pari!=0){
								if(vita_rossa<=135)
									vita_rossa=vita_rossa+15;
								else
									vita_rossa=150;
									if(backstage==1) cout<<"\033[35mCura dinamica attiva "<<cont_pari<<"\033[0m"<<endl; //master control mode: "backstage"
								cout<<"\033[32mLa torre nemica si sta riparando: "<<vita_rossa<<"\033[0m"<<endl;
							}
								if(backstage==1) cout<<"\033[35mLancio:"<<lancio<<"\033[0m"<<endl; //master control mode: "backstage"
						}
//Lancio lancio=1 (attacco)
						if(lancio==1 || lancio==3){
							if(lancio==3) dadi=5;
								else if(jolly==1 && cont_round%2!=0) dadi=rand()%4+1; //master control mode: "jolly"
							else dadi=rand()%3+1;
								if(backstage==1) cout<<"\033[35mDadi:"<<dadi<<"\033[0m"<<endl; //master control mode: "backstage"
							switch(dadi){
								case 1:
									if(cont_round%2!=0){
										cout<<"\033[34mFUOCO!!\033[0m"<<endl;
										vita_rossa=vita_rossa-cannonata;
									}
									else{
										cout<<"\033[31mFUOCO!!\033[0m"<<endl;
										vita_blu=vita_blu-cannonata;
									}
								break;
								case 2:
									if(cont_round%2!=0){
										cout<<"\033[34mFUOCO DOPPIO!!\033[0m"<<endl;
										vita_rossa=vita_rossa-doppia_cannonata;
									}
									else{
										cout<<"\033[31mFUOCO DOPPIO!!\033[0m"<<endl;
										vita_blu=vita_blu-doppia_cannonata;
									}
								break;
								case 3:
									if(cont_round%2!=0){
										cout<<"\033[34mFUOCO ALLE POLVERI!!\033[0m"<<endl;
										vita_rossa=vita_rossa-razzo;
									}
									else{
										cout<<"\033[31mFUOCO ALLE POLVERI!!\033[0m"<<endl;
										vita_blu=vita_blu-razzo;
									}
								break;
									//master control mode: "jolly"
								case 4:
									cout<<"\033[35mALL'ASSALTO!!\033[0m"<<endl;
									vita_rossa=vita_rossa-75;
								break;
									//master mode control: "berserk"
								default:
									if(vita_blu==1){
										vita_blu=26;
										cout<<"\033[31mBerserk inutilizzabile\033[0m"<<endl;
										cout<<"\033[32mLa tua torre si sta' rigenerando di vita: "<<vita_blu<<"\033[0m"<<endl;
									}
									else{
										cout<<"\033[35mBERSERK!!\033[0m"<<endl;
										vita_rossa=vita_rossa-(vita_blu-1);
										vita_blu=vita_blu-(vita_blu-1);
									}
							}
//Stampa vita da attacco
							if(cont_round%2!=0){
								if(cont_round%2!=0 && vita_rossa<=0){
									cout<<"La torre nemica e' stata sconfitta\n"<<endl;
									cout<<"\033[32mHAI VINTO!!\033[0m\n"<<endl;
									cont_v++;
									cont_round=0;
								}
								else cout<<"La torre nemica ha "<<vita_rossa<<" di vita"<<endl;
							}
							else{
								if(cont_round%2==0 && vita_blu<=0){
									cout<<"La tua torre e' stata sconfitta\n"<<endl;
									cout<<"\033[31mhai perso!!\033[0m\n"<<endl;
									cont_s++;
									cont_round=0;
								}
								else cout<<"La tua torre ha "<<vita_blu<<" di vita"<<endl;
							}
						}
//Lancio lancio=2 (cura)
						if(lancio==2){
								if(boost==1 && cont_round%2!=0) dadi=2; //master mode control: "boost"
							else dadi=rand()%3+1;
								if(backstage==1) cout<<"\033[35mDadi:"<<dadi<<"\033[0m"<<endl; //master control mode: "backstage"
							switch(dadi){
								case 1:
									cout<<"\033[32mCura minima!!\033[0m"<<endl;
									if(cont_round%2!=0){
										if(vita_blu<=125) vita_blu=vita_blu+25;
										else vita_blu=150;
										cout<<"La tua torre e' stata riparata: "<<vita_blu<<endl;
									}
									else{
										if(vita_rossa<=125) vita_rossa=vita_rossa+25;
										else vita_rossa=150;
										cout<<"La torre nemica e' stata riparata: "<<vita_rossa<<endl;
									}
								break;
								case 2:
									cout<<"\033[32mCura massima!!\033[0m"<<endl;
									if(cont_round%2!=0){
										if(boost==1) vita_blu=vita_blu+50; //master mode control: "boost"
										else{
											if(vita_blu<=100) vita_blu=vita_blu+50;
											else vita_blu=150;
										}
										cout<<"La tua torre e' stata riparata: "<<vita_blu<<endl;
									}
									else{
										if(vita_rossa<=100) vita_rossa=vita_rossa+50;
										else vita_rossa=150;
										cout<<"La torre nemica e' stata riparata: "<<vita_rossa<<endl;
									}
								break;
								case 3:
									cout<<"\033[32mCura dinamica!!\033[0m"<<endl;
									if(cont_round%2!=0){
										cont_dinamico_dispari++;
										if(vita_blu<=135) vita_blu=vita_blu+15;
										else vita_blu=150;
										cout<<"La tua torre si sta riparando: "<<vita_blu<<endl;
									}
									else{
										cont_dinamico_pari++;
										if(vita_rossa<=135) vita_rossa=vita_rossa+15;
										else vita_rossa=150;
										cout<<"La torre nemica si sta riparando: "<<vita_rossa<<endl;
									}
								break;
							}
						}
//Contatore dinamico
						if(cont_round%2!=0){
							if(cont_dinamico_dispari!=0){
								cont_dispari++;
								if(cont_dispari==4){
									cont_dinamico_dispari=0;
									cont_dispari=0;
								}
							}
						}
						else{
							if(cont_dinamico_pari!=0){
								cont_pari++;
								if(cont_pari==4){
									cont_dinamico_pari=0;
									cont_pari=0;
								}
							}
						}
//Stampa della vita delle torri
						if(cont_round%2==0 && cont_round!=0){
							cout<<"\nVita delle 2 torri: "<<endl;
							cout<<"\033[34m"<<vita_blu<<"\033[0m \033[33mVS\033[0m \033[31m"<<vita_rossa<<"\033[0m"<<endl;
						}
					}while(vita_blu>0 && vita_rossa>0);
				}
//Assegnazione 4° gioco
				vita_blu=100;
				vita_rossa=100;
				cont_dinamico_dispari=0;
				cont_dispari=0;
				cont_dinamico_pari=0;
				cont_pari=0;
//Segna punti
				segna_punti();
				cout<<endl;
//Giocare ancora o tornare alla scelta iniziale
				stamp_termina();	
			}while(restart!=2);
//Lista resoconto
			resoconto();
		break;
		case 5:
//Game start (5)
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
			do{
				do{
					cout<<"Benvenuti nel minigame: Tris."<<endl;
					cout<<"\033[33mPremere 1 per leggere le regole e il funzionamento del gioco.\033[0m"<<endl;
					cout<<"\033[36mPremere 2 per iniziare a giocare.\033[0m"<<endl;
					cin>>scelta_interna5;
					cout<<endl;
				}while(scelta_interna5!=1 && scelta_interna5!=2);
				if(scelta_interna5==1){
					cout<<"\033[33mECCO IL REGOLAMENTO:\033[0m"<<endl;
					cout<<"\033[33m1) Tris, e' un gioco basato sulla capacita' di riuscire a mettere le proprie figure in linea.\033[0m"<<endl;
					cout<<"\033[33m2) In questo gioco l'utenete potra' scegliere dove piazzare le sue figure e soprattutto potra' scegliere se giocare da solo contro il computer o con un amico.\033[0m"<<endl;
					cout<<endl;
				}
			}while(scelta_interna5!=2);
//Assegnazione int in comune
			stamp_assegnazioni();
//Inizio principale
			do{
				if(scelta_interna5==2){
					cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
					cout<<endl;
					cout<<"\033[36msi comincia!!\033[0m"<<endl;
					cout<<endl;
					cout<<"Vuoi giocare contro il computer o con un amico??"<<endl;
					cout<<"(1) single player, (2) multiplayer: ";
					cin>>scelta_multiplayer_tris;
//Creazione della matrice del tris
					create_tris();
//Inizio turni
					do{
//Conta turni
						conta_turni_tris++;
//Verifica
						if(conta_turni_tris==5)
							verifica_tris=true;
//Turno 1
						turno1_tris();
//Turno 2
						if(verifica_tris==false && scelta_multiplayer_tris==2)
							turno2_tris();
//Turno 3, turno del computer
						if(verifica_tris==false && scelta_multiplayer_tris==1){
							turno3_computer_tris();
							if(backstage==1) cout<<"\033[35mVerifica del tris:"<<verifica_tris<<"\033[0m"<<endl; //master control mode: "backstage"
						}
							
					}while(verifica_tris!=true);
//Assegnazione 5° gioco
					verifica_tris=false;
					conta_turni_tris=0;
				}
//Giocare ancora o tornare alla scelta iniziale
				stamp_termina();	
			}while(restart!=2);
//Lista resoconto
			resoconto();
		break;
		case 6:
//Game start (6)
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
			do{
				do{
					cout<<"Benvenuti nel minigame: Dama."<<endl;
					cout<<"\033[33mPremere 1 per leggere le regole e il funzionamento del gioco.\033[0m"<<endl;
					cout<<"\033[36mPremere 2 per iniziare a giocare.\033[0m"<<endl;
					cin>>scelta_interna6;
					cout<<endl;
				}while(scelta_interna6!=1 && scelta_interna6!=2);
				if(scelta_interna6==1){
					cout<<"\033[33mECCO IL REGOLAMENTO:\033[0m"<<endl;
					cout<<"\033[33m1) Dama, e' un gioco basato sulla strategia in cui il tuo obbiettivo sara' vincere contro il tuo avversario.\033[0m"<<endl;
					cout<<"\033[33m2) In questo gioco l'utenete dovra' sfidare il suo compagno in una battaglia di strategia e tecnica.\033[0m"<<endl;
					cout<<endl;
				}
			}while(scelta_interna6!=2);
//Assegnazione int in comune
			stamp_assegnazioni();
//Inizio principale
			do{
				if(scelta_interna6==2){
					cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
					cout<<endl;
					cout<<"\033[36msi comincia!!\033[0m"<<endl;
					cout<<endl;
//Creazione matrice della dama
					create_matrice_dama();
//Visualizzazione matrice della dama
					view_matrice_dama();
					cout<<endl;
					do{
//1° turno dama + Verifica pedine dama
						if(verifica_pedine_dama()){
							turno_1_dama();
							verifica_pedine_dama();
//Visualizzazione matrice della dama
							view_matrice_dama();
						}
//2° turno dama + Verifica pedine dama
						if(verifica_pedine_dama()){
							turno_2_dama();
							verifica_pedine_dama();
//Visualizzazione matrice della dama
							view_matrice_dama();
						}
//Verifica pedine dama
					}while(verifica_pedine_dama());
//Assegnazione 6° gioco
					pedine_blu_dama=12;
					pedine_rosse_dama=12;
				}
//Giocare ancora o tornare alla scelta iniziale
				stamp_termina();	
			}while(restart!=2);
//Lista resoconto
			resoconto();
		break;
		case 7:
			cout<<"Gioco mancante.\n"<<endl;
		break;
		case 8:
			cout<<"Gioco mancante.\n"<<endl;
		break;
		case 9:
			cout<<"Gioco mancante.\n"<<endl;
		break;
//Lobby
		case 10:
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
			cout<<endl;
			cout<<"\033[3"<<scelta_colore<<"mX          XXXXXXXXXX    XXXXXXXX    XXXXXXXX    X       X\033[0m"<<endl;
			cout<<"\033[3"<<scelta_colore<<"mX          X        X    X       X   X       X    X     X \033[0m"<<endl;
			cout<<"\033[3"<<scelta_colore<<"mX          X        X    X       X   X       X     X   X  \033[0m"<<endl;
			cout<<"\033[3"<<scelta_colore<<"mX          X        X    XXXXXXXX    XXXXXXXX       X X   \033[0m"<<endl;
			cout<<"\033[3"<<scelta_colore<<"mX          X        X    X       X   X       X       X    \033[0m"<<endl;
			cout<<"\033[3"<<scelta_colore<<"mX          X        X    X       X   X       X       X    \033[0m"<<endl;
			cout<<"\033[3"<<scelta_colore<<"mXXXXXXXX   XXXXXXXXXX    XXXXXXXX    XXXXXXXX        X    \033[0m"<<endl;
			cout<<endl;
			cout<<"Ecco il resoconto \033[3"<<scelta_colore<<"m"<<utente<<"\033[0m:"<<endl;
//Resoconto
			cout<<"Partite giocate: "<<resoconto_partite<<endl;
			cout<<"\033[32mVittorie:  "<<resoconto_v<<"\033[0m"<<endl;
			cout<<"\033[31mSconfitte: "<<resoconto_s<<"\033[0m"<<endl;
			cout<<"\033[34mPareggi:   "<<resoconto_p<<"\033[0m"<<endl;
			cout<<endl;
			if(backstage==1)
				cout<<"\033[35m"<<boost<<" "<<jolly<<" "<<berserk<<" "<<backstage<<"\033[0m\n"<<endl;
//Master control
			if(corrispondenza_master_utente==true)
				if(verifica_master_control_password())
					master_control_mode();
//Master color
			if(backstage==1)
				scelta_colore=5;
			else
				scelta_colore=scambio_colore_master_control;
//Reload System
			if(reload==true){
				riprovare=2;	
			}
//Uscita dalla lobby
			else
				stamp_spegimento();
		break;
//Spegnimento rapido (0)
		default:
			stamp_spegimento();
		}//fine dello switch
//Fine del sistema
			if(scelta_gioco==1 || scelta_gioco==2 || scelta_gioco==3 || scelta_gioco==4 || scelta_gioco==5 || scelta_gioco==6)
				stamp_spegimento();
			cout<<"\033[35m##########################################################################################################################################################\033[0m"<<endl;
		}while(riprovare!=2);
		if(reload==true)
			system("cls");
	}while(reload!=false);
	system("PAUSE");
	return 0;
}
