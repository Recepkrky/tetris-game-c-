//
//  main.c
//  22011068
//
//  Created by Recep Karakaya on 25.12.2023.
//
#include <time.h>
#include<stdio.h>
#include <stdlib.h>
int main (){
    int enyuksekskor=0,puan = 0,n,m,e=0,flag=0,count=0,islem;
    char dondurme;
    int i,k,j;
    int sekil1[8][4][4]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int donme1[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int tetrimino[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printf("TETRIS OYUNUNA HOSGELDINIZ !!!\n\n    MENU\n1.OYUNA BASLA \n2.OYUNDAN CIK\n");
    scanf("%d",&islem);
    srand(time(NULL));
    dondurme = 'b' ;
    while(islem==1 && e<1 && dondurme != 'q'){
        int OyunTahtasi[30][20]={0};
        printf("Oyun sahasini olusturmak icin n ve m degerlerini giriniz.");
        scanf("%d %d",&n,&m);
        //aldigimiz degere uygun nxn matris olusturma ve bu matrisin tum elemanlarinin 0 yapma
        printf("OYUN BASLIYOR\n");
        //matrisi yazdirma
        for (i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d ",OyunTahtasi[i][j]);
            }
            printf("\n");
        }
        for(j=0;j<m;j++){
            printf("- ");
        }
        printf("\n");
        for(j=0;j<m;j++){
            printf("%d ",j+1);
        }
        printf("\n");
        dondurme = 'b' ;
        while(e<1 && dondurme!= 'q'){
            int p = rand() % 8 ;
            printf("Guncel Tetrimino: \n");
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    tetrimino[i][j]=sekil1[p][i][j];
                }
            }
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    if(tetrimino[i][j]==1)
                        printf("%d ",tetrimino[i][j]);
                    else if(tetrimino[i][j]==0)
                        printf("  ");
                }
                printf("\n");
            }
            dondurme = 'b' ;
            while(dondurme != 'a' && dondurme != 'q' ){
                printf("Yerlestirmek icin a tusuna basin.\nSaga  dondurmek icin d tusuna basin.\nSola  dondurmek icin s tusuna basin.\nOyundan cikmak icin q tusuna basin.\n");
                scanf(" %c",&dondurme);
                if(dondurme== 'd' ){
                    //saga dondurme ve yazdirma
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++)donme1[j][3-i] = tetrimino[i][j];
                    }
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++)tetrimino[i][j] = donme1[i][j];
                    }
                    printf("saga donmus hali:\n");
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++){
                            if(tetrimino[i][j]==1)
                                printf("%d ",tetrimino[i][j]);
                            else if(tetrimino[i][j]==0)
                                printf("  ");
                        }
                        printf("\n");
                    }
                }
                else if (dondurme=='s'){
                    //sola dondurme ve yazdirma
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++)donme1[3-j][i] = tetrimino[i][j];
                    }
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++)tetrimino[i][j] = donme1[i][j];
                    }
                    printf("sola dondurmus hali:\n");
                    for(i=0;i<4;i++){
                        for(j=0;j<4;j++){
                            if(tetrimino[i][j]==1)
                                printf("%d ",tetrimino[i][j]);
                            else if(tetrimino[i][j]==0)
                                printf("  ");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
            }
            if(dondurme!='q'){
                //Oyun tahtasini tekrar yazdirma
                for (i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        printf("%d ",OyunTahtasi[i][j]);
                    }
                    printf("\n");
                }
                for(j=0;j<m;j++){
                    printf("- ");
                }
                printf("\n");
                for(j=0;j<m;j++){
                    printf("%d ",j+1);
                }
                printf("\n");
                // kullanicidan aldigimiz x degerini yerlestirmek icin x degerinin guncelleme
                int x;
                printf("Sekli yerlestirmek icin seklin en solunu baz alarak x koordinatini giriniz.");
                scanf("%d",&x);
                x=x-1;
                j=0,i=3;
                while(tetrimino[i][j]!=1 && j<=3){
                    while(tetrimino[i][j]!=1 && i>=0){
                        i--;
                    }
                    if (i==-1) i=3,j++;
                }
                x=x-j;
                
                //tetriminomuzun uzunlugunu bulma
                int b=0;
                j=0,i=3;
                while(tetrimino[i][j]!=1 && j<=3){
                    while(tetrimino[i][j]!=1 && i>=0){
                        i--;
                    }
                    if(tetrimino[i][j]==1){
                        b++;
                    }
                    i=3;
                    j++;
                }
                //Oyun tahtasinda seklin yerlesecegi yerin altini kontrol etme
                int z=0;
                flag=0;
                while(flag!=1){
                    for (i=0; i<4; i++) {
                        for (j=0; j<4; j++) {
                            if(tetrimino[i][j]==1) {
                                if( OyunTahtasi[i+z+1][j+x] == 1) flag=1;
                                else if(i+z+1 == n) flag=1;
                            }
                        }
                    }
                    z++;
                }
                z--;
                // seklin altini kontrol yaptiktan sonra sekli oyun tahtasiyla toplama
                for (i=0; i<4; i++) {
                    for (j=0; j<4; j++) {
                        OyunTahtasi[i+z][j+x]+=tetrimino[i][j];
                    }
                }
                //Oyun tahtasini tekrar yazdirma
                for (i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        printf("%d ",OyunTahtasi[i][j]);
                    }
                    printf("\n");
                }
                for(j=0;j<m;j++){
                    printf("- ");
                }
                printf("\n");
                for(j=0;j<m;j++){
                    printf("%d ",j+1);
                }
                printf("\n");
                // herhangi bir satir full 1 olursa o satiri yok etme
                for (i=n-1;i>0;i--){
                    for(j=0;j<m;j++){
                        if(OyunTahtasi[i][j]==1)count++;
                    }
                    //satir full 1 olduktan sonra o satiri silip ust satiradaki sekilleri bir alt satira dusurme
                    if(count==m){
                        i++;
                        while(i!=0){
                            i--;
                            for(j=0;j<m;j++){
                                OyunTahtasi[i][j]=OyunTahtasi[i-1][j];
                            }
                        }
                        //en ust satiri full 0 yapma
                        for(j=0;j<m;j++){
                            OyunTahtasi[0][j]=0;
                        }
                        puan=puan+n-i;
                    }
                    count=0;
                }
                //en uste 1 geldiginde  oyunu bitirme
                for(j=0;j<m;j++){
                    if(OyunTahtasi[0][j]==1)e++;
                }
            }
        }
        //puan en yuksek skordan buyukse en yuksek skoru guncelleme
        if(enyuksekskor<puan)enyuksekskor=puan;
        printf("\nOYUN BITTI !! \n");
        printf("EN YUKSEK SKORUNUZ: %d\n",enyuksekskor);
        if(dondurme!='q'){
            if(e>=1)e=0;
            printf("OYUNU TEKRAR OYNAMAK ICIN 1 e OYUNDAN CIKMAK ICIN 2 ye BASINIZ");
            scanf("%d",&islem);
        }
    }
    return 0;
}
