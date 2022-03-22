#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct klasmen {
    string nama;
    int main;
    int menang;
    int kalah;
    int seri;
    int gol;
    int kebobolan;
    int point;
    int nilai;
};

klasmen k[16];

void inisialisasi()
{
    int i;
    k[0].nama="AREMA"; k[1].nama="BORNEO FC"; k[2].nama="PERSIB"; k[3].nama="PERSIJA";
    k[4].nama="BARITO PUTERA"; k[5].nama="MADURA UNITED"; k[6].nama="PERSEBAYA"; k[7].nama="PERSELA";
    k[8].nama="PERSIPURA"; k[9].nama="SEMEN PADANG"; k[10].nama="PSIS"; k[11].nama="PSM";
    k[12].nama="PERSIRAJA"; k[13].nama="PERSITA"; k[14].nama="PS SLEMAN"; k[15].nama="PERSIBA";

    for (i=0; i<16; i++)
    {
    k[i].main=0;
    k[i].menang=0;
    k[i].kalah=0;
    k[i].seri=0;
    k[i].gol=0;
    k[i].kebobolan=0;
    k[i].point=0;
    k[i].nilai=0;

    }
}

void tampil_klasmen()
{
    int i;
    cout<<"======================KLASMEN======================"<<endl;
    cout<<"==================================================="<<endl;
    cout<<"N0  NAMA KLUB             Ma Me Ka Se go Ke +/- Ni "<<endl;
    cout<<"==================================================="<<endl;

    for (i=0; i<16; i++){
        if (i<9)
            cout<<" 0"<<i+1<<"   ";
        else
            cout<<" "<<i+1<<"   ";

    cout<<k[i].nama;
    if (k[i].nama=="AREMA"){
        cout<<"               ";
    }else if(k[i].nama=="BORNEO FC"){
        cout<<"           ";
    }else if(k[i].nama=="PERSIB"){
        cout<<"              ";
    }else if(k[i].nama=="PERSIJA"){
        cout<<"             ";
    }else if(k[i].nama=="BARITO PUTERA"){
        cout<<"       ";
    }else if(k[i].nama=="MADURA UNITED"){
        cout<<"       ";
    }else if(k[i].nama=="PERSEBAYA"){
        cout<<"           ";
    }else if(k[i].nama=="PERSELA"){
        cout<<"             ";
    }else if(k[i].nama=="PERSIPURA"){
        cout<<"           ";
    }else if(k[i].nama=="SEMEN PADANG"){
        cout<<"        ";
    }else if(k[i].nama=="PSIS"){
        cout<<"                ";
    }else if(k[i].nama=="PSM"){
        cout<<"                 ";
    }else if(k[i].nama=="PERSIRAJA"){
        cout<<"           ";
    }else if(k[i].nama=="PERSITA"){
        cout<<"             ";
    }else if(k[i].nama=="PS SLEMAN"){
        cout<<"           ";
    }else if(k[i].nama=="PERSIBA"){
        cout<<"             ";
    }
    cout<<k[i].main<<"  ";
    cout<<k[i].menang<<"  ";
    cout<<k[i].kalah<<"  ";
    cout<<k[i].seri<<"  ";
    cout<<k[i].gol<<"  ";
    cout<<k[i].kebobolan<<"  ";
    cout<<k[i].point<<"  ";
        if(k[i].point<0){
    cout<<k[i].nilai<<" ";
        }else{
    cout<<" ";
    cout<<k[i].nilai<<"  ";
        }
    cout<<endl;
    }
    cout<<"==================================================="<<endl;
    cout<<"==================================================="<<endl<<endl;
}

void pertandingan()
{
    int i;
    int g1,g2,win,lose,match1,match2,draw;
    string karakter;
    string k1,k2;
    int logic;
    cout<<"Input hasil Pertandingan"<<endl<<endl;

    input_k1:
    getline(cin,karakter);
    cout<<"Nama klub ke-1      : "; getline(cin,k1);
    cout<<"Jumlah gol klub ke-1: "; cin>>g1;
    for (i=0; i<16; i++)
        {
            k[i].nama;
            if(k[i].nama!=k1)
            {
                logic=1;
            }else if(k[i].nama==k1)
            {
                goto input_k2;
            }
        }
        if(logic==1)
        {
            cout<<"Masukkan nama klub yang benar"<<endl<<endl;
            goto input_k1;
        }


    input_k2:
    getline(cin,karakter);
    cout<<"Nama klub ke-2      : "; getline(cin,k2);
    cout<<"Jumlah gol klub ke-2: "; cin>>g2;

    for (i=0; i<16; i++)
        {
            k[i].nama;
            if(k[i].nama!=k2)
            {
                logic=1;
            }else if(k[i].nama==k2)
            {
                goto loop;
            }
        }
        if(logic==1)
        {
            cout<<"Masukkan nama klub yang benar"<<endl<<endl;
            goto input_k2;
        }

    loop:
    for(i=0; i<16; i++){
        if(k1==k[i].nama){
            match1=1;
            k[i].main=k[i].main+match1;
            k[i].gol=k[i].gol+g1;
            k[i].kebobolan=k[i].kebobolan+g2;
            k[i].point=k[i].point+g1-g2;
            if(g1>g2){
                win=1;
                k[i].menang=k[i].menang+win;
                k[i].nilai=k[i].nilai+3;
            }else if(g2>g1){
                lose=1;
                k[i].kalah=k[i].kalah+lose;
                k[i].nilai=k[i].nilai+0;
            }else{
                draw=1;
                k[i].seri=k[i].seri+draw;
                k[i].nilai+=1;
            }
            break;
        }
    }

    for(i=0; i<16; i++){
        if(k2==k[i].nama){
            match2=1;
            k[i].main=k[i].main+match2;
            k[i].gol=k[i].gol+g2;
            k[i].kebobolan=k[i].kebobolan+g1;
            k[i].point=k[i].point+g2-g1;
            if(g2>g1){
                win=1;
                k[i].menang=k[i].menang+win;
                k[i].nilai=k[i].nilai+3;
            }else if(g2<g1){
                lose=1;
                k[i].kalah=k[i].kalah+lose;
                k[i].nilai=k[i].nilai+0;
            }else{
                draw=1;
                k[i].seri=k[i].seri+draw;
                k[i].nilai+=1;
            }
            break;
        }
    }

}


void sorting_klasmen(){
    int tmp;
    string tmp_string;
    for(int i=0; i<16-1; i++){
        for(int j=i+1; j<16; j++){
            if (k[i].nilai<k[j].nilai){
                tmp=k[i].nilai;
                k[i].nilai=k[j].nilai;
                k[j].nilai=tmp;

                tmp_string=k[j].nama;
                k[j].nama=k[i].nama;
                k[i].nama=tmp_string;

                tmp=k[i].main;
                k[i].main=k[j].main;
                k[j].main=tmp;

                tmp=k[i].menang;
                k[i].menang=k[j].menang;
                k[j].menang=tmp;

                tmp=k[i].kalah;
                k[i].kalah=k[j].kalah;
                k[j].kalah=tmp;

                tmp=k[i].seri;
                k[i].seri=k[j].seri;
                k[j].seri=tmp;

                tmp=k[i].gol;
                k[i].gol=k[j].gol;
                k[j].gol=tmp;

                tmp=k[i].point;
                k[i].point=k[j].point;
                k[j].point=tmp;

                tmp=k[i].kebobolan;
                k[i].kebobolan=k[j].kebobolan;
                k[j].kebobolan=tmp;

            }else if (k[i].nilai==k[j].nilai){
                if(k[i].point<k[j].point){
                tmp=k[i].nilai;
                k[i].nilai=k[j].nilai;
                k[j].nilai=tmp;

                tmp_string=k[j].nama;
                k[j].nama=k[i].nama;
                k[i].nama=tmp_string;

                tmp=k[i].main;
                k[i].main=k[j].main;
                k[j].main=tmp;

                tmp=k[i].menang;
                k[i].menang=k[j].menang;
                k[j].menang=tmp;

                tmp=k[i].kalah;
                k[i].kalah=k[j].kalah;
                k[j].kalah=tmp;

                tmp=k[i].seri;
                k[i].seri=k[j].seri;
                k[j].seri=tmp;

                tmp=k[i].gol;
                k[i].gol=k[j].gol;
                k[j].gol=tmp;

                tmp=k[i].point;
                k[i].point=k[j].point;
                k[j].point=tmp;

                tmp=k[i].kebobolan;
                k[i].kebobolan=k[j].kebobolan;
                k[j].kebobolan=tmp;

            }
        }
    }

}
}

int main()
{
    int menu;
    string Back;
    inisialisasi();

    pilih:
    cout<<"===========LIGA1==========="<<endl;
    cout<<"|1| Lihat Klasmen        ||"<<endl;
    cout<<"|2| Input pertandingan   ||"<<endl;
    cout<<"|3| Tutup aplikasi       ||"<<endl;
    cout<<">>>Pilih Menu: "; cin>>menu;


    if(menu==1){
        system("cls");
        sorting_klasmen();
        tampil_klasmen();
        cout<<"Kembali ke menu?(Y/N)"; cin>>Back;
        if(Back=="Y"){
            system("cls");
            goto pilih;
        }else if(Back=="N"){
            system("cls");
        }

    }else if(menu==2){
        system("cls");
        pertandingan();
        cout<<"Kembali ke menu?(Y/N)"; cin>>Back;
        if(Back=="Y"){
            system("cls");
            goto pilih;
        }else if(Back=="N"){
            system("cls");
        }
    }else if(menu==3){
    system("cls");
    }


    return 0;
}
