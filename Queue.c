#include <stdio.h>
#include <stdlib.h>


struct node { 
int data;
struct node * next;

};

struct node * temp= NULL;
struct node * front= NULL; // Ba�taki d�g�m� tutar
struct node * rear = NULL; // kuyruktaki son d�g�m� tutar


void elemanEkle(int veri )
{
	
	struct node * eleman= (struct node * ) malloc ( sizeof( struct node ));
	eleman->data= veri;
	//kuyrugun bo� mu dolu oldugunu bak�yor
	if( front==NULL  )
	{
		front= eleman;
		front->next= front;
		rear= eleman;
		rear->next= NULL;
		
	}
	else if (front->next==front ){
		rear->next= eleman;
		rear= eleman;
		rear->next= NULL;
		front->next=rear;
	}
	else{
		rear->next= eleman;
		rear= eleman;
		rear->next= NULL;
	}
}
void elemanCikar()
{
    //kuruk bo�sa
	if( front==NULL)
	printf("kuyruk bostur \n");
	else{
		//ilk giren d�g�m� silmesi i�in
		temp= front->next;
		free(front);
		front= temp;
	}
}	
void yazdir(){


if( front==NULL)

printf(" kuyruk bostur \n");	
	else{
		
		temp= front;
		
		while( temp->next!=NULL ){
			//ba�tan sona bakarak d�g�mleri yazd�rmas� i�in
			printf("%d ", temp->data );
			temp= temp->next;
		}
		printf("%d\n", temp->data );
	}
}

int main(){
	//degi�kenleri tan�mlad�m
	int secim ,sayi;
	while(1 )
	{
		//kullan�c�dan i�lemleri yazd�rd�m
		printf("1--ekleme  \n");
		printf("2--cikarma  \n");
		printf("3--goruntuleme \n");
		printf("4--cikis  \n");
		//kullanc�dan se�mesini istedim
		printf(" seciminiz:  \n");
		scanf("%d", &secim);
		switch(secim){
			case 1: printf("sayi girin  \n:");
			scanf("%d" ,&sayi);
			
			elemanEkle(sayi);
			break;
			case 2: elemanCikar();
			break;
			case 3:
			yazdir();
			break;
			case 4: return 0;
			
			
		}
			}
}


