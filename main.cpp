#include <iostream>
#include <cstring>
#include<fstream>
#include<string.h>
using namespace std;

ifstream fin;
ofstream fout;

struct Nod
{   char denumire[50];
	char autor[50];
    int an;
    Nod *dr, *st;
};

    struct Nod *root1=NULL;
    struct Nod *root2=NULL;
    struct Nod *root3=NULL;

    Nod* creareNodNou(char *denumire,char *autor,int an)
    {   Nod *nodNou=new Nod;
        strcpy(nodNou->denumire,denumire);
        strcpy(nodNou->autor,autor);
        nodNou->an=an;
        nodNou->dr=NULL;
        nodNou->st=NULL;
        return nodNou;
    }

    void parcurgInorder(Nod *temp)
    {   if(temp!=NULL){
            parcurgInorder(temp->st);
            cout<<"\""<<temp->denumire<<"\" - "<<temp->autor<<" "<<temp->an<<endl;
            parcurgInorder(temp->dr);
                      }
    }

     void parcurgPreorder(Nod *temp)
     {  if(temp!=NULL){
            cout<<"\""<<temp->denumire<<"\" - "<<temp->autor<<" "<<temp->an<<endl;
            parcurgPreorder(temp->st);
            parcurgPreorder(temp->dr);
                      }
     }

     void parcurgPostorder(Nod *temp)
     {  if(temp!=NULL){
            parcurgPostorder(temp->st);
            parcurgPostorder(temp->dr);
            cout<<"\""<<temp->denumire<<"\" - "<<temp->autor<<" "<<temp->an<<endl;
                      }
     }

     void stergArbore(Nod *&nod)
     {  if(nod!=NULL){
            stergArbore(nod->st);
            stergArbore(nod->dr);
            delete nod; nod=NULL;
                     }
     }

     Nod *cautAn(int an, Nod *nod)
     {  if(nod!=NULL){
            if(nod->an==an) return nod;
            if(an<nod->an) cautAn(an,nod->st);
            else cautAn(an,nod->dr);
                     }
         else return NULL;
     }

     Nod *cautDenumire(char *denumire, Nod *nod)
     {  if(nod!=NULL){
            if(strcmp(nod->denumire,denumire)==0) return nod;
            if(strcmp(denumire,nod->denumire)<0) cautDenumire(denumire,nod->st);
            else cautDenumire(denumire,nod->dr);
                     }
         else return NULL;
     }

     Nod *cautAutor(char *autor, Nod *nod)
     {  if(nod!=NULL){
            if(strcmp(nod->autor,autor)==0) return nod;
            if(strcmp(autor,nod->autor)<0) cautAutor(autor,nod->st);
            else cautAutor(autor,nod->dr);
                     }
         else return NULL;
   }

    Nod *caut1(char *denumire)
    {return cautDenumire(denumire, root1);}

    Nod *caut2(char *autor)
    {return cautAutor(autor, root2);}

    Nod *caut3(int an)
    {return cautAn(an, root3);}

    void stergArbore1()
    {stergArbore(root1);}

    void stergArbore2()
    {stergArbore(root2);}

    void stergArbore3()
    {stergArbore(root3);}

    void adaugNod1(char *denumire, char *autor, int an)
    {  if(root1==NULL) root1=creareNodNou(denumire,autor,an);
        else{Nod *temp=root1;
             while(true){
                if(strcmp(temp->denumire,denumire)>0){
                    if(temp->st==NULL){temp->st=creareNodNou(denumire,autor,an);
                                       break;}
                    else temp=temp->st;}
                else if(strcmp(temp->denumire,denumire)<=0){
                    if(temp->dr==NULL){temp->dr = creareNodNou(denumire,autor,an);
                                       break;}
                    else temp=temp->dr;}
                        }
            }
    }

    void adaugNod2(char *denumire, char *autor, int an)
    {  if(root2==NULL) root2=creareNodNou(denumire,autor,an);
        else{Nod *temp=root2;
             while(true){
                if(strcmp(temp->autor,autor)>0){
                    if(temp->st==NULL){temp->st=creareNodNou(denumire,autor,an);
                                       break;}
                    else temp=temp->st;}
                else if(strcmp(temp->autor,autor)<=0){
                    if(temp->dr==NULL){temp->dr = creareNodNou(denumire,autor,an);
                                       break;}
                    else temp=temp->dr;}
                        }
            }
    }

    void adaugNod3(char *denumire, char *autor, int an)
    {  if(root3==NULL) root3=creareNodNou(denumire,autor,an);
        else{Nod *temp=root3;
             while(true){
                if(temp->an > an){
                    if(temp->st==NULL){temp->st=creareNodNou(denumire,autor,an);
                                       break;}
                    else temp=temp->st;}
                else if(temp->an <= an){
                    if(temp->dr==NULL){temp->dr = creareNodNou(denumire,autor,an);
                                       break;}
                    else temp=temp->dr;}
                        }
            }
    }

    void inorder(int x)
    {  cout<<endl<<"Parcurgere inordine dupa ";
       if(x==1){cout<<"denumire: "<<endl; parcurgInorder(root1);}
       else if(x==2){cout<<"autor: "<<endl; parcurgInorder(root2);}
       else if(x==3){cout<<"an: "<<endl; parcurgInorder(root3);}
       cout<<endl<<endl;
    }

    void preorder(int x)
    {  cout<<endl<<"Parcurgere preordine dupa ";
       if(x==1){cout<<"denumire: "<<endl; parcurgPreorder(root1);}
       else if(x==2){cout<<"autor: "<<endl; parcurgPreorder(root2);}
       else if(x==3){cout<<"an: "<<endl; parcurgPreorder(root3);}
       cout<<endl<<endl;
    }

    void postorder(int x)
    {  cout<<endl<<"Parcurgere postordine dupa ";
       if(x==1){cout<<"denumire: "<<endl; parcurgPostorder(root1);}
       if(x==2){cout<<"autor: "<<endl; parcurgPostorder(root2);}
       if(x==3){cout<<"an: "<<endl; parcurgPostorder(root3);}
       cout<<endl<<endl;
    }

    void StergAux(Nod *&p, Nod *&nod)
   {// nod - nodul care trebuie sters
    // p - pointer cu care identificăm nodul cel mai din dreapta
    if(p->dr)
        StergAux(p->dr,nod);
     else
     {  strcpy(nod->denumire,p->denumire);
        strcpy(nod->autor,p->autor);
        nod->an=p->an;
        Nod *aux=p;
        p=p->st;
        delete aux;
     }
   }

int Stergere1(Nod *&nod , char *denumire)
{  if(nod!=NULL){
     if(strcmp(nod->denumire,denumire)==0){// nodul trebuie șters
        if(nod->st==NULL && nod->dr==NULL)
            { delete nod;
              nod = NULL;
              return 1;
            }
        else if(nod->dr==NULL){
                    Nod *aux=nod;
                    nod=nod->st;
                    delete aux;
                    return 1;
                              }
        else if(nod->st == NULL){
                    Nod *aux=nod;
                    nod=nod->dr;
                    delete aux;
                    return 1;
                                }
        else{StergAux(nod->st, nod);
             return 1;}
                  }
     else if(strcmp(nod->denumire,denumire)>0)
           Stergere1(nod->st,denumire);
     else
        Stergere1(nod->dr,denumire);
                }
    else return 0; // valoarea x nu apare în arbore
}

int Stergere2(Nod *&nod , char *autor)
{  if(nod!=NULL){
     if(strcmp(nod->autor,autor)==0){// nodul trebuie șters
        if(nod->st==NULL && nod->dr==NULL)
            { delete nod;
              nod = NULL;
              return 1;
            }
        else if(nod->dr==NULL){
                    Nod *aux=nod;
                    nod=nod->st;
                    delete aux;
                    return 1;
                              }
        else if(nod->st == NULL){
                    Nod *aux=nod;
                    nod=nod->dr;
                    delete aux;
                    return 1;
                                }
        else{StergAux(nod->st, nod);
             return 1;}
                  }
     else if(strcmp(nod->autor,autor)>0)
           Stergere2(nod->st,autor);
     else
        Stergere2(nod->dr,autor);
                }
    else return 0; // valoarea x nu apare în arbore
}

int Stergere3(Nod *&nod , int an)
{  if(nod!=NULL){
     if(nod->an==an){// nodul trebuie șters
        if(nod->st==NULL && nod->dr==NULL)
            { delete nod;
              nod = NULL;
              return 1;
            }
        else if(nod->dr==NULL){
                    Nod *aux=nod;
                    nod=nod->st;
                    delete aux;
                    return 1;
                              }
        else if(nod->st == NULL){
                    Nod *aux=nod;
                    nod=nod->dr;
                    delete aux;
                    return 1;
                                }
        else{StergAux(nod->st, nod);
             return 1;}
                  }
     else if(nod->an > an)
           Stergere3(nod->st,an);
     else
        Stergere3(nod->dr,an);
                }
    else return 0; // valoarea x nu apare în arbore
}

int stergDenumire(char *denumire)
    {return Stergere1(root1,denumire);}

int stergAutor(char *autor)
    {return Stergere2(root2,autor);}

int stergAn(int an)
    {return Stergere3(root3,an);}

Nod* minim(struct Nod *nod)
      {struct Nod *temp=nod;
       while(temp->st!=NULL)temp=temp->st;

       return temp;
      }

Nod* maxim(struct Nod *nod)
      {struct Nod *temp=nod;
       while(temp->dr!=NULL)temp=temp->dr;

       return temp;
      }


void scriere_in_fisier(Nod *temp)
     {  if(temp!=NULL){
            fout<<temp->denumire<<"-"<<temp->autor<<","<<temp->an<<"\n";
            scriere_in_fisier(temp->st);
            scriere_in_fisier(temp->dr);
                      }
     }
void cautare()
{   cout<<"\t CRITERII:\n";
    cout<<"\t 1.Denumire\n";
    cout<<"\t 2.Autor\n";
    cout<<"\t 3.An\n";
    cout<<"\nAlegeti criteriul: ";
    int x; cin>>x;
    switch(x)
    {case 1:
        {cout<<"Introduceti denumirea: ";
         char s[50];cin.get();
         cin.get(s,50);
         Nod *nod=caut1(s);
         if(nod==NULL) cout<<"\nNu exista carti cu aceasta denumire!"<<endl<<endl;
         else {cout<<"\nCartile care au denumirea \""<<s<<"\"  sunt: "<<endl;
               while(nod!=NULL)
            {cout<<"\""<<nod->denumire<<"\" - "<<nod->autor<<", "<<nod->an<<endl;
             nod=cautDenumire(s,nod->dr);
            }}cout<<endl;
         break;
        }
    case 2:
        {cout<<"Introduceti numele autorului: ";
         char s[50];cin.get();
         cin.get(s,50);
         Nod *nod=caut2(s);
         if(nod==NULL) cout<<"\nNu exista carti scrise de acest autor!"<<endl<<endl;
         else {cout<<"\nCartile scrise de "<<s<<"  sunt: "<<endl;
               while(nod!=NULL)
            {cout<<"\""<<nod->denumire<<"\" - "<<nod->autor<<", "<<nod->an<<endl;
             nod=cautAutor(s,nod->dr);
            }}cout<<endl;

        break;
        }
    case 3:
        {cout<<"Introduceti anul: ";
         int s;
         cin>>s;
         Nod *nod=caut3(s);
         if(nod==NULL) cout<<"\nNu exista carti scrise in acest an!"<<endl<<endl;
         else {cout<<"\nCartile scrise in anul "<<s<<"  sunt: "<<endl;
               while(nod!=NULL)
            {cout<<"\""<<nod->denumire<<"\" - "<<nod->autor<<", "<<nod->an<<endl;
             nod=cautAn(s,nod->dr);
            }}cout<<endl;

        break;
        }
    default:cout<<"Valoare invalida\n\n";
    }
}

void adaugare()
{   char denumire[50],autor[50]; int an;
    cout<<"\nDenumire: ";
    cin.get();
    cin.get(denumire,50);
    cout<<"\nAutor: ";
    cin.get();
    cin.get(autor,50);
    cout<<"\nAn: ";
    cin.get();
    cin>>an;
    adaugNod1(denumire,autor,an);
    adaugNod2(denumire,autor,an);
    adaugNod3(denumire,autor,an);
}

void parcurgeri()
{
    cout<<"\tPARCURGERI:\n";
    cout<<"\t1.Preordine\n";
    cout<<"\t2.Inordine\n";
    cout<<"\t3.Postordine\n";
    cout<<"\nAlegeti tipul de parcurgere: ";
    int x; cin>>x;
    switch(x)
    {case 1:
        {cout<<"\t CRITERII:\n";
         cout<<"\t 1.Denumire\n";
         cout<<"\t 2.Autor\n";
         cout<<"\t 3.An\n";
         cout<<"\nAlegeti criteriul: ";
         int y; cin>>y;
         switch(y)
         {case 1:
             {preorder(1);
              break;}
          case 2:
             {preorder(2);
              break;}
          case 3:
             {preorder(3);
              break;}
          default:cout<<"Valoare invalida\n\n";
         }
         break;
        }
     case 2:
        {cout<<"\t CRITERII:\n";
         cout<<"\t 1.Denumire\n";
         cout<<"\t 2.Autor\n";
         cout<<"\t 3.An\n";
         cout<<"\nAlegeti criteriul: ";
         int y; cin>>y;
         switch(y)
         {case 1:
             {inorder(1);
              break;}
          case 2:
             {inorder(2);
              break;}
          case 3:
             {inorder(3);
              break;}
          default:cout<<"Valoare invalida\n\n";
         }
        break;
        }
     case 3:
        {cout<<"\t CRITERII:\n";
         cout<<"\t 1.Denumire\n";
         cout<<"\t 2.Autor\n";
         cout<<"\t 3.An\n";
         cout<<"\nAlegeti criteriul: ";
         int y; cin>>y;
         switch(y)
         {case 1:
             {postorder(1);
              break;}
          case 2:
             {postorder(2);
              break;}
          case 3:
             {postorder(3);
              break;}
          default:cout<<"Valoare invalida\n\n";
         }
        break;
        }
    default:cout<<"Valoare invalida\n\n";
    }
}

void maxmin()
{   Nod *nod;
    cout<<"1.Cea mai veche carte(minim)\n";
    cout<<"2.Cea mai noua carte(maxim)\n";
    cout<<"Alegeti: ";
    int x; cin>>x;
    switch(x)
    {case 1:
        {nod=minim(root3);
         cout << "Cea mai veche carte este: "<<"\""<<nod->denumire<<"\" - "<<nod->autor<<" "<<nod->an<<endl<<endl;
         break;}
    case 2:
        {nod=maxim(root3);
         cout << "Cea mai noua carte este: "<<"\""<<nod->denumire<<"\" - "<<nod->autor<<" "<<nod->an<<endl<<endl;
         break;}
    default: cout<<"Valoare invalida\n\n";
    }
}

void stergere()
{   cout<<"\t CRITERII:\n";
    cout<<"\t 1.Denumire\n";
    cout<<"\t 2.Autor\n";
    cout<<"\t 3.An\n";
    cout<<"\nAlegeti criteriul: ";
    int x; cin>>x;
    switch(x)
    {case 1:
        {cout<<"Introduceti denumirea: ";
         char s[50],t[50]; int a;
         cin.get(); cin.get(s,50);
         Nod *nod=caut1(s);
         if(nod==NULL) cout<<"\nNu exista carti cu aceasta denumire!"<<endl<<endl;
         else {while(nod!=NULL)
            {strcpy(t,nod->autor);
             a=nod->an;
             stergDenumire(s);
             stergAutor(t);
             stergAn(a);
             nod=caut1(s);
            }cout<<"\nCartile care au denumirea \""<<s<<"\"  au fost sterse"<<endl;
            }cout<<endl;
         break;
        }
    case 2:
        {cout<<"Introduceti numele autorului: ";
         char s[50],t[50]; int a;
         cin.get(); cin.get(t,50);
         Nod *nod=caut2(t);
         if(nod==NULL) cout<<"\nNu exista carti scrise de acest autor!"<<endl<<endl;
         else {while(nod!=NULL)
            {strcpy(s,nod->denumire);
             a=nod->an;
             stergDenumire(s);
             stergAutor(t);
             stergAn(a);
             nod=caut2(t);
            }cout<<"\nCartile scrise de "<<t<<"  au fost sterse"<<endl;
            }cout<<endl;
        break;
        }
    case 3:
        {cout<<"Introduceti anul: ";
         char s[50],t[50]; int a;
         cin>>a;
         Nod *nod=caut3(a);
         if(nod==NULL) cout<<"\nNu exista carti scrise in acest an!"<<endl<<endl;
         else {while(nod!=NULL)
            {strcpy(s,nod->denumire);
             strcpy(t,nod->autor);
             stergDenumire(s);
             stergAutor(t);
             stergAn(a);
             nod=caut3(a);
            }cout<<"\nCartile scrise in anul "<<a<<" au fost sterse"<<endl;
            }cout<<endl;
        break;
        }
    default:cout<<"Valoare invalida\n\n";
    }
}

int main() {

    char denumire[50],autor[50],s_an[10];

    fin.open("date.txt");
    while(fin.getline (denumire,50,'-') && fin.getline (autor,50,',') && fin.getline(s_an,10))
    {   int an=atoi(s_an);
        adaugNod1(denumire,autor,an);
        adaugNod2(denumire,autor,an);
        adaugNod3(denumire,autor,an);
    }
    fin.close();

    int op=1;
    cout<<"\n\t\t Bine ati venit in MINI-BIBLIOTECA ! \n\n\n";

    while(op!=0){
    cout<<"\t OPERATII:\n";
    cout<<"\t 1.Cautare\n";
    cout<<"\t 2.Adaugare\n";
    cout<<"\t 3.Stergere\n";
    cout<<"\t 4.Parcurgere\n";
    cout<<"\t 5.Minim/Maxim\n";
    cout<<"\t 0.Iesire\n";
    cout<<endl;
    cout<<"Alegeti operatia: ";
    cin>>op;

    switch(op)
    {case 0: break; //iesire
     case 1:
        {cautare();
         break;}
    case 2:
        {adaugare();
         break;}
    case 3:
        {stergere();
         break;}
    case 4:
        {parcurgeri();
         break;}
    case 5:
        {maxmin();
         break;}
    default: cout<<"Valoare invalida"<<endl;
    }}

   fout.open("date.txt");
   scriere_in_fisier(root3);
   fout.close();

    return 0;
}
