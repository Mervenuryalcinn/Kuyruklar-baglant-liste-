#include <stdio.h>
#include <stdlib.h>


struct node { 
int data;
struct node * next;

};

struct node * temp= NULL;
struct node * front= NULL; // Baþtaki dügümü tutar
struct node * rear = NULL; // kuyruktaki son dügümü tutar


void elemanEkle(int veri )
{
	
	struct node * eleman= (struct node * ) malloc ( sizeof( struct node ));
	eleman->data= veri;
	//kuyrugun boþ mu dolu oldugunu bakýyor
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
    //kuruk boþsa
	if( front==NULL)
	printf("kuyruk bostur \n");
	else{
		//ilk giren dügümü silmesi için
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
			//baþtan sona bakarak dügümleri yazdýrmasý için
			printf("%d ", temp->data );
			temp= temp->next;
		}
		printf("%d\n", temp->data );
	}
}

int main(){
	//degiþkenleri tanýmladým
	int secim ,sayi;
	while(1 )
	{
		//kullanýcýdan iþlemleri yazdýrdým
		printf("1--ekleme  \n");
		printf("2--cikarma  \n");
		printf("3--goruntuleme \n");
		printf("4--cikis  \n");
		//kullancýdan seçmesini istedim
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


