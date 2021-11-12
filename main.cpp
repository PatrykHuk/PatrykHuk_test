#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>



void wypisz(int T[],int p,int q){
    std::cout<<"[ ";
    for(int i=p;i<=q-1;i++)
        std::cout << T[i]<< ", ";
    std::cout << T[q]<<" ]"<<std::endl;

}  //funkcja wypisująca podtablice, których suma wynosi 0


bool czy_sie_powtarza(int T[],int poczatek,int koniec){
    int n=koniec-poczatek+1;        //długość podtablicy
    for(int i=0;i<poczatek;i++){    //sprawdzamy, czy podtablica o długości n zaczynająca się w T[i] jest taka sama jak tablica o długości n zaczynająca się w T[poczatek]
            int j=0;
        while(T[i+j]==T[poczatek+j]&&j<n)
            j++;
        if(j==n)
            return true;
    }
    return false;
}   //funkcja sprawdzająca, czy dana podtablica wystąpiła więcej niż jeden raz

void szukaj(int T[],int n)
{
    bool czy_istnieje=0;    //zmienna sprawdzajacaa czy funkcja znalazla podtablice o sumie 0
    for(int i=0;i<n;i++)
    {
        int S=0;            //suma podtablicy
        for(int j=i;j<n;j++)
        {
            S+=T[j];
            if(S==0&&czy_sie_powtarza(T,i,j)==0)    //wypisujemy podtablice, gdy jej suma wynosi 0 i nie wypisalismy wczesniej identycznej podtablicy
            {
                    if(czy_istnieje==0)
                    {
                        czy_istnieje=1;
                    }

            }
        }
    }
}
void test(int n, int wmin, int wmax)
{
    srand(time(NULL));
    int T[n];
    for(int i=0;i<n;i++)
        T[i]=rand()%(wmax-wmin+1)+wmin;
    auto start = std::chrono::high_resolution_clock::now();
    szukaj(T,n);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Dlugosc tablicy: "<< n <<std::endl<<"Czas trwania programu: "<< (double)duration.count()/1000000<< " s" << std::endl;

}

int main()
{
    for(int i=0; i<10; i++)
    {
        test(1000,-10,10);
    }
    return 0;
}
