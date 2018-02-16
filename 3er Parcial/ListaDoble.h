#include "Nodo.h"

class ListaDoble
{
	private:
		Nodo *lista;
		char jugador[50];
		int contadorNodo;
		int puntaje;

	public:
		ListaDoble()
		{
			lista=NULL;
			contadorNodo=0;
			puntaje=0;
		}
		void insertarAlFinal(int);
		void impresionArchivos();
		void impresion();
		void impresionLista();
		void generarLista();
		void listaTetris(int,int);
		void juegoSnake();
		void juegoTetris();
		int posicionAIndice(int x);
		void deleteNumber(int,int );
		void siguienteNumero(int,Nodo * );
		void deleteNodo(Nodo *Actual);
		
};

void ListaDoble::impresionArchivos()
{
	Nodo* Aux=new Nodo();
	FILE *archivoPDF,*archivoQR,*archivoDB;
	archivoQR=fopen("C:\\JuegoSnake\\PuntajeJugador.txt","w");
	archivoPDF=fopen("C:\\JuegoSnake\\Puntajes.txt","a+");
	archivoDB=fopen("C:\\JuegoSnake\\DB.txt","w");
	
	Aux=lista;
	printf("Jugador: %s.\n\n",jugador);
	fprintf(archivoPDF,"Jugador: %s\n\n",jugador);
	fprintf(archivoQR,"Jugador: %s.\n\n",jugador);
	if(Aux == NULL)
	{
	  	printf("Usted ha finalizado el juego sin haber comido ningun numero.\n\n");
    	fprintf(archivoPDF,"Usted ha finalizado el juego sin haber comido ningun numero.\n\n");	
    	fprintf(archivoQR,"Usted ha finalizado el juego sin haber comido ningun numero.\n\n");
    }
	else
    {
	    printf("\t\tNumeros comidos.\n\n ==> ");
	    fprintf(archivoPDF,"\t\tNumeros comidos.\n\n ==> ");
	    fprintf(archivoQR,"\t\tNumeros comidos.\n\n ==> ");
		while(Aux != NULL)
		{
	        printf("%d, ",Aux->getNumero());
	        fprintf(archivoPDF,"%d, ",Aux->getNumero());
	        fprintf(archivoQR,"%d, ",Aux->getNumero());
	        Aux=Aux->getSiguienteDireccion();
	    }
		printf("\b\b. \n\nSu Puntaje es: %d\n\n",contadorNodo);
		fprintf(archivoPDF,"\b\b\b. \n\nSu Puntaje es: %d\n\n----------------------------------------------------\n",contadorNodo);	
		fprintf(archivoQR,"\b\b\b. \n\nSu Puntaje es: %d",contadorNodo);
	}
	fprintf(archivoDB,"%s;%d",jugador,contadorNodo);
	fclose(archivoPDF);
	fclose(archivoQR);
	fclose(archivoDB);
}

void ListaDoble::impresion()
{
	Nodo* Aux=new Nodo();
	
	Aux=lista;
	printf("Jugador: %s.\n\n",jugador);

	if(Aux == NULL)
	  	printf("Usted ha finalizado el juego sin haber comido ningun numero.\n\n");
	else
    {
	    printf("\t\tNumeros comidos.\n\n ==> ");
		while(Aux != NULL)
		{
	        printf("%d, ",Aux->getNumero());
	        Aux=Aux->getSiguienteDireccion();
	    }
		printf("\b\b. \n\nSu Puntaje es: %d\n\n",contadorNodo);	
	}
}

void ListaDoble::impresionLista()
{
	int x=8,y;
	Nodo* Aux=new Nodo();
	Aux=lista;

	while(Aux != NULL)
	{   
		y=34;
		switch(Aux->getNumero())
		{
			case 0:
				color(1);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);
				break;
			
			case 1:
				color(2);
				gotoxy(x,y++);
				printf(" %c%c  \n",219,219);gotoxy(x,y++);
				printf("%c %c  \n",219,219);gotoxy(x,y++);
				printf("  %c   \n",219);gotoxy(x,y++);
				printf("  %c   \n",219);gotoxy(x,y++);
				printf("%c%c%c%c%c",220,220,219,220,220,220,220);gotoxy(x,y++);
				break;
			
				
			case 2:
				color(3);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("   %c \n",219);gotoxy(x,y++);
				printf(" %c%c  \n",220,219);gotoxy(x,y++);
				printf("%c%c%c%c%c",219,220,220,220,220,220,220);gotoxy(x,y++);
				break;
			
				
			case 3:
				color(4);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("   %c \n",219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);gotoxy(x,y++);
				break;
		
			case 4:
				color(6);
				gotoxy(x,y++);
				printf("   %c%c\n",219,219);gotoxy(x,y++);
				printf("  %c %c\n",219,219);gotoxy(x,y++);
				printf(" %c  %c\n",219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c\n",219,220,220,220,219);gotoxy(x,y++);
				printf("    %c\n",219);gotoxy(x,y++);
				break;
	
			case 5:
				color(7);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf(" %c   \n",219);gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,220);gotoxy(x,y++);
				printf("   %c \n",219);gotoxy(x,y++);
				printf(" %c%c  ",219,219);gotoxy(x,y++);
				break;
				
			case 6:
				color(12);
				gotoxy(x,y++);
				printf("  %c%c \n",220,219);gotoxy(x,y++);
				printf(" %c   \n",219);gotoxy(x,y++);
				printf("%c%c%c%c\n",219,220,220,220);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);gotoxy(x,y++);
				break;
				
			case 7:
				color(9);
				gotoxy(x,y++);
			    printf("%c%c%c%c%c\n",220,220,220,220,220,220,220);gotoxy(x,y++);
				printf("    %c\n",219);gotoxy(x,y++);
				printf("   %c\n",219);gotoxy(x,y++);
				printf("  %c\n",219);gotoxy(x,y++);
				printf(" %c   ",219);gotoxy(x,y++);
				break;		
				
			case 8:
				color(10);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);gotoxy(x,y++);
			    break;
				
			case 9:
				color(11);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c\n",219,220,220,220,219);gotoxy(x,y++);
				printf("    %c\n",219);gotoxy(x,y++);
				printf(" %c%c%c ",220,220,219);gotoxy(x,y++);
			    break;
		}
		x+=6;
        Aux=Aux->getSiguienteDireccion();
    }
}

void ListaDoble::insertarAlFinal(int numero)
{
	Nodo* Nuevo=new Nodo();
	Nodo* Actual=new Nodo();
		
	if(contadorNodo==0)
	{	
		Actual->setNumero(numero);
		Actual->setAnteriorDireccion(NULL);
		Actual->setSiguienteDireccion(NULL);
		lista=Actual;	
	}
	else
	{
		Actual=lista;
		while(Actual->getSiguienteDireccion()!=NULL)
		{
			Actual=Actual->getSiguienteDireccion();
		}
		Nuevo->	setNumero(numero);
        Nuevo->	setSiguienteDireccion(NULL);
        Actual->setSiguienteDireccion(Nuevo);
        Nuevo->	setAnteriorDireccion(Actual);
	}
	contadorNodo++;
}

void ListaDoble::generarLista()
{
	Nodo* Aux=new Nodo();
	int numero,i;
	
	srand(time(NULL));
	for(i=0;i<5;i++)
	{
		numero=rand()%10;
		insertarAlFinal(numero);
	}
}

int aleatorio(int caso)
{
	if(caso==1)
		return rand()%10;
	else
		if(caso==2)
			return rand()%(39-4+1)+4;
		else
			return rand()%(99-2+1)+2;
}

void margen()
{  
	color(121);
    for(int i=2; i < 100; i++)
	{
    	//PARTE SUPERIOR
    	gotoxy (i, 3); printf("%c",178);
    	//PARTE INFERIOR
        gotoxy(i, 40); printf("%c",178);
    }
    for(int j=4; j < 40; j++)
	{
    	//PARTE IZQUIERDA
        gotoxy (2,j);  printf("%c",178);
        //PARTE DERECHA
        gotoxy(100,j);  printf("%c",178);
    }
    //ESQUINAS
    gotoxy  (2,3);	printf("%c",178);
    gotoxy (2,40);	printf("%c",178);
    gotoxy (100,3);	printf("%c",178);
    gotoxy(100,40);	printf("%c",178);
	color(15); 
}


void ListaDoble::juegoSnake()
{
	bool primera=true;
	char tecla=0;
	int x=3,y=4;
	int col,fil;
	int numero;
	
	srand(time(NULL));
	lista=NULL;
	contadorNodo=0;
	
	do
	{
		printf("Ingrese el nombre del jugador: ");
		gets(jugador);
		fflush(stdin);
	}while(validacionCaracter(jugador));
	
	do{
		system("cls");
		margen();
		gotoxy(0,0);
		printf("\t\t\t::::::::::::::::::::Juego del Snake::::::::::::::::");
		if(primera)
		{
			col=aleatorio(3);
			fil=aleatorio(2);
			numero=aleatorio(1);			
			primera=false;	
		}
		if((col==x+2||col==x)&&(fil==y))
		{
			col=aleatorio(3);
			fil=aleatorio(2);
			insertarAlFinal(numero);
			numero=aleatorio(1);		
		}
		gotoxy(col,fil);
		printf("%d",numero);
		gotoxy(x,y); //Posicion del caracter
		printf("<=>");	
		tecla=getch();
		switch(tecla)
		{
			case TECLA_ARRIBA:
				y--;
				if(y<=3)
					y=39;			
				break;
			case TECLA_ABAJO:
				y++;
				if(y>=40)
					y=4;
				break;
			case TECLA_DERECHA:
				x++;
				if(x>=98)
					x=3;
				break;
			case TECLA_IZQUIERDA:
				x--;
				if(x<=3)
					x=97;
				break;
		}
	}while(tecla!=TECLA_ENTER);
	system("cls");
	impresionArchivos();
}

void ListaDoble::listaTetris(int posicion,int numero)
{
	Nodo *Aux=new Nodo();
	Nodo *Actual=new Nodo();
	Nodo *Nuevo=lista;
	int cont;
	
	while(Nuevo!=NULL)
	{
		if(numero==Nuevo->getNumero())
		{
			cont++;
			break;
		}
		Nuevo=Nuevo->getSiguienteDireccion();
	}
	
	switch(posicion)
	{
		case 1:
			if(cont>0)
			{
				Nuevo=Nuevo->getSiguienteDireccion();
				Nuevo->setAnteriorDireccion(NULL);
				lista=Nuevo;
				contadorNodo--;	
			}
			else
			{

				Aux->setNumero(numero);
				Aux->setSiguienteDireccion(lista);
				Aux->setAnteriorDireccion(NULL);
				Actual->setAnteriorDireccion(Aux);	
				lista=Aux;
				contadorNodo++;
			}
			break;
		
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		case 5:
			break;
			
		/*case 1:
			break;
			
		case 1:
			break;
			
		case 1:
			break;
			
		case 1:
			break;	*/	
	}
	/*while(Nuevo!=NULL)
	{
		if(numero==Nuevo->getNumero())
		{
			cont++;
			break;
		}
		Nuevo=Nuevo->getSiguienteDireccion();
	}
	if(cont>0)
	{
		if(contadorNodo==1&&posicion==1)
		{
			delete lista;
			lista=NULL;
			contadorNodo--;
		}
		else
		{
			if(posicion==1)
			{
				Nuevo=Nuevo->getSiguienteDireccion();
				Nuevo->setAnteriorDireccion(NULL);
				lista=Nuevo;
				contadorNodo--;			
			}
			else
			{
				if(contadorNodo==posicion)
				{
					Nuevo=Nuevo->getAnteriorDireccion();
					Nuevo->setSiguienteDireccion(NULL);
					contadorNodo--;							
				}
			}
		}
	}
	//else meter segun la posicion*/
}

int ListaDoble::posicionAIndice(int x){
	return (x-8)/6;
}
void ListaDoble::deleteNodo(Nodo *Actual){
	Nodo* Siguiente=new Nodo();
	Nodo* Anterior=new Nodo();
	if(Actual->getAnteriorDireccion()!=NULL&&Actual->getSiguienteDireccion()!=NULL){
		Anterior=Actual->getAnteriorDireccion();
		Siguiente=Actual->getSiguienteDireccion();
		Anterior->setSiguienteDireccion(Siguiente);
		Siguiente->setAnteriorDireccion(Anterior);
		delete(Actual);
	}else if(Actual->getAnteriorDireccion()==NULL){
		lista=Actual->getSiguienteDireccion();
		delete(Actual);
	}else if(Actual->getSiguienteDireccion()==NULL){
		Anterior=Actual->getAnteriorDireccion();
		Anterior->setSiguienteDireccion(NULL);
		delete(Actual);
	}
}

void ListaDoble::siguienteNumero(int numero,Nodo *aux){
	if(aux==NULL||(aux->getNumero()!=(numero+1))){
		return ;
	}else{
		if(aux->getNumero()==(numero+1)){
			puntaje++;
			deleteNodo(aux);
		}
	}
}
void ListaDoble::deleteNumber(int indice,int numero){
	int cont=0;
	Nodo* Actual=new Nodo();
	Actual=lista;
	while(Actual!=NULL){
		if(indice==cont){
			if(Actual->getNumero()==numero){//borra el numero 
				puntaje++;
				deleteNodo(Actual);
				siguienteNumero(numero,Actual);
			}else{
				insertarAlFinal(numero);
			}
			Actual=NULL;
		}else{
			Actual=Actual->getSiguienteDireccion();
		}
		cont++;
	}
}

void ListaDoble::juegoTetris()
{
	bool primera=true;
	char tecla=0;
	int x=32,y=4;
	int col,fil;
	int numero;
	
	srand(time(NULL));
	lista=NULL;
	contadorNodo=puntaje=0;
	
	do
	{
		printf("Ingrese el nombre del jugador: ");
		gets(jugador);
		fflush(stdin);
	}while(validacionCaracter(jugador));
	generarLista();
	
	do
	{
		system("cls");
		margen();
		gotoxy(0,0);
		printf("\t\t\t::::::::::::::::::::Juego del Tetris::::::::::::::::");
		if(primera)
		{
			numero=aleatorio(1);			
			primera=false;	
			gotoxy(4,45);
			printf("puntaje %d",puntaje);
			system("pause");
		}
		if((x==10)&&(y==33)) /// aqui mandar cuando encuentre el numero
		{
			listaTetris(1,numero);
			numero=aleatorio(1);
			x=34;y=4;	
		}
		impresionLista();
		gotoxy(x,y);
		numbers(numero,x,y);
		color(15);
		tecla=getch();	
		switch(tecla)
		{
			case TECLA_ABAJO:
				y++;
				if(y>=28){
					deleteNumber(posicionAIndice(x),numero);
					y=4;
					primera=true;
				}
					
				break;
			case TECLA_DERECHA:
				x+=6;
				if(x>=100)
					x=10;
				break;
			case TECLA_IZQUIERDA:
				x-=6;
				if(x<=2)
					x=94;
				break;
			case 's': case 'S':
				gotoxy(4,45);
				printf("Su juego sera guardado. Usted Regresara al menu principal...   ");
				tecla=TECLA_ENTER;
				system("pause");
				break;
		}
	}while(tecla!=TECLA_ENTER || contadorNodo==11 ||contadorNodo==0);
	system("cls");
	//impresionArchivos();
}


