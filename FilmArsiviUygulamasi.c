//Ramazan ÖLMEZ 14253503
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
struct filmArsivi{
    char ad[50];
    int yil;
    char yonetmen[50];
    char senarist[50];
    char basrolOyuncu[50];
};
void filmEkle();
void filmListele();
void filmSil();
void filmAra();
void filmGuncelle();
FILE *fp;
int main(){
int secim;
printf("Lutfen bir secim yapiniz.");
do{
    printf("\n1. Film ekle");
    printf("\n2. Filmleri listele (yayinlanma yili göre)");
    printf("\n3. Film guncelle");
    printf("\n4. Film sil");
    printf("\n5. Film ara (film adi, yayinlanma yili, yonetmeni, senaristi, bas rol oyuncusuna göre)");
    printf("\n6. Cikis\n");
    scanf("%d",&secim);
    if(secim==1){
        printf("\nSeciminiz:1\n");
        filmEkle();
    }
    else if(secim==2){
        printf("\nSeciminiz:2\n");
        filmListele();
        
    }
    else if(secim==3){
        printf("\nSeciminiz:3\n");
        filmGuncelle();
    }
    else if(secim==4){
        printf("\nSeciminiz:4\n");
        filmSil();
    }
    else if(secim==5){
        printf("\nSeciminiz:5\n");
        filmAra();
    }
    else{
        
    }
}
while(secim!=6);
}
void filmEkle(){
	struct filmArsivi film;
	FILE *fp;
    printf("Eklemek istediginiz filmin tum bilgilerini giriniz.\n");
    printf("Filmin adi:");
    fflush(stdin);
    gets(film.ad);
    printf("\nFilmin yayinlanma yili:");
    fflush(stdin);
    scanf("%d",&film.yil);
    printf("\nFilmin yonetmeni:");
    fflush(stdin);
    gets(film.yonetmen);
    printf("\nFilmin senaristi:");
    fflush(stdin);
    gets(film.senarist);
    printf("\nFilmin basrolOyuncusu:");
    fflush(stdin);
    gets(film.basrolOyuncu);
    fp=fopen("ornek.txt","a");
    if(fp==NULL){
        printf("Dosya bulunamadi.");
    }
    else{
    	
        fprintf(fp,"%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
        printf("\nFilm basarili bir sekilde eklenmistir.\n");
    }
    fflush(stdin);
    printf("Kayit basariyla eklenmistir.");
    fclose(fp);
    

}
void filmListele(){
    struct filmArsivi film;
    static struct filmArsivi dynamic_film[1000];
    static struct filmArsivi film_temp;
    int n = 0;
    int sayac;
    int sayac2;
    int secim;
    FILE *fp;
    fp=fopen("ornek.txt","r");
    printf("Siralama yapmak istediginiz kolonu seciniz:");
    printf("\n1-Film adina gore alfabetik siralama");
    printf("\n2-Film yilina gore artan sekilde sirali siralama");
    printf("\n3-Dosyaya kayit sirasina gore\n");
    fflush(stdin);
    scanf("%d",&secim);
    if(secim==1){
    	fflush(stdin);
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		fflush(stdin);
		while(!feof(fp)){
			dynamic_film[n]=film;
			n++;
			fflush(stdin);
			fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
			fflush(stdin);
		}
		for(sayac=0;sayac<n;sayac++){
			for(sayac2=0;sayac2<n;sayac2++){
				if(strcmp(dynamic_film[sayac2].ad,dynamic_film[sayac2+1].ad)>0){
					film_temp=dynamic_film[sayac2+1];
					dynamic_film[sayac2+1]=dynamic_film[sayac2];
					dynamic_film[sayac2]=film_temp;
				}
			}
		}
		for(sayac=1;sayac<n+1;sayac++){
			fflush(stdin);
			printf("\n%s %d %s %s %s\n",dynamic_film[sayac].ad,dynamic_film[sayac].yil,dynamic_film[sayac].yonetmen,dynamic_film[sayac].senarist,dynamic_film[sayac].basrolOyuncu);
			fflush(stdin);
		}
	}
	else if(secim==2){
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		while(!feof(fp)){
			dynamic_film[n]=film;
			n++;
			fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		}
		for(sayac=0;sayac<n;sayac++){
			for(sayac2=0;sayac2<n;sayac2++){
				if(dynamic_film[sayac2].yil>dynamic_film[sayac2+1].yil){
					film_temp=dynamic_film[sayac2+1];
					dynamic_film[sayac2+1]=dynamic_film[sayac2];
					dynamic_film[sayac2]=film_temp;
				}
			}
		}
		for(sayac=1;sayac<n+1;sayac++){
			fflush(stdin);
			printf("\n%s %d %s %s %s\n",dynamic_film[sayac].ad,dynamic_film[sayac].yil,dynamic_film[sayac].yonetmen,dynamic_film[sayac].senarist,dynamic_film[sayac].basrolOyuncu);
			fflush(stdin);
		}
	}
	else if(secim==3){
		while(!feof(fp)){
        fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
        
        printf("\n%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
        fflush(stdin);
    	} 
	}
	else{
		main();
	}
	fclose(fp);
}

void filmGuncelle(){
	struct filmArsivi film,guncel;
	FILE *fp,*tempp;
	char isim[50];
	printf("Guncellemek istediginiz ismi giriniz:");
	fflush(stdin);
	gets(isim);
	fp=fopen("ornek.txt","r");
	tempp=fopen("temp.txt","w");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",guncel.ad,&guncel.yil,guncel.yonetmen,guncel.senarist,guncel.basrolOyuncu);
		if(strcmp(guncel.ad,isim)==0){
			printf("Yeni isim giriniz:");
			scanf("%s",&guncel.ad);
			printf("\nYeni tarih giriniz:");
			scanf("%d",&guncel.yil);
			printf("\nYeni yonetmen:");
			scanf("%s",&guncel.yonetmen);
			printf("\nYeni senarist:");
			scanf("%s",&guncel.senarist);
			printf("\nYeni basrol oyuncusu:");
			scanf("%s",&guncel.basrolOyuncu);
		}
		fprintf(tempp,"%s %d %s %s %s\n",guncel.ad,guncel.yil,guncel.yonetmen,guncel.senarist,guncel.basrolOyuncu);
	}
	fclose(fp);
	fclose(tempp);
	remove("ornek.txt");
	rename("temp.txt","ornek.txt");
}
void filmSil(){
	FILE *fp,*tempp;
	struct filmArsivi film,sil;
	char isim[50];
	int flag=0;
	printf("Silmek istediginiz filmin adini giriniz:");
	fflush(stdin);
	gets(isim);
	int secim;
	fp=fopen("ornek.txt","r");
	tempp=fopen("ornekk.txt","w");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",sil.ad,&sil.yil,sil.yonetmen,sil.senarist,sil.basrolOyuncu);
		if(strcmp(sil.ad,isim)==0){
			if(feof(fp)){
				flag=1;
			}
			fscanf(fp,"%s %d %s %s %s",sil.ad,&sil.yil,sil.yonetmen,sil.senarist,sil.basrolOyuncu);
		}
		if(flag)
			break;
		fprintf(tempp,"%s %d %s %s %s\n",sil.ad,sil.yil,sil.yonetmen,sil.senarist,sil.basrolOyuncu);
	}
	fclose(fp);
	fclose(tempp);
	printf("Silme islemini onayliyor musunuz? (1:Evet 2:Hayir) ");
	scanf("%d",&secim);
	if(secim==1){
	remove("ornek.txt");
	rename("ornekk.txt","ornek.txt");
	}
	else{
	remove("ornekk.txt");
	}
}

void filmAra(){
	struct filmArsivi film;
	FILE *fp;
	char isim[50];
	int secim;
	int yil;
	printf("\n1-Film adina gore arama:");
	printf("\n2-Yayinlanma yilina gore arama:");
	printf("\n3-Yonetmen adina gore arama:");
	printf("\n4-Senarist adina gore arama:");
	printf("\n5-BasrolOyuncusuna gore arama:");
	printf("\nHangi aramayi yapmak istiyorsunuz:");
	scanf("%d",&secim);
	if(secim==1){
	printf("\nAramak istediginiz film ismini giriniz:");
	fflush(stdin);
	gets(isim);
	fp=fopen("ornek.txt","rb");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		if(strcmp(film.ad,isim)==0){
			printf("\n%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		}
	}
	fclose(fp);
	}
	if(secim==2){
		printf("\nAramak istediginiz film yilini giriniz:");
	fflush(stdin);
	scanf("%d",&yil);
	fp=fopen("ornek.txt","rb");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		if(film.yil==yil){
			printf("\n%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		}
	}
	fclose(fp);
	}
	if(secim==3){
		printf("\nAramak istediginiz yonetmen ismini giriniz:");
	fflush(stdin);
	gets(isim);
	fp=fopen("ornek.txt","rb");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		if(strcmp(film.yonetmen,isim)==0){
			printf("\n%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		}
	}
	fclose(fp);
	}
	if(secim==4){
		printf("\nAramak istediginiz senarist ismini giriniz:");
	fflush(stdin);
	gets(isim);
	fp=fopen("ornek.txt","rb");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		if(strcmp(film.senarist,isim)==0){
			printf("\n%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		}
	}
	fclose(fp);
	}
	if(secim==5){
		printf("\nAramak istediginiz basrol ismini giriniz:");
	fflush(stdin);
	gets(isim);
	fp=fopen("ornek.txt","rb");
	while(!feof(fp)){
		fscanf(fp,"%s %d %s %s %s\n",film.ad,&film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		if(strcmp(film.basrolOyuncu,isim)==0){
			printf("\n%s %d %s %s %s\n",film.ad,film.yil,film.yonetmen,film.senarist,film.basrolOyuncu);
		}
	}
	fclose(fp);
	}
}
