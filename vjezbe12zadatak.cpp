#include <iostream>
#include <string>

using namespace std;


struct igrac
{
    string ime;
    char tip;
    int pobjede = 0;
};


void mapaReset(char (&mapa)[3][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            mapa[i][j] = '_';
        }
    }
}


void prikazMape(char (&mapa)[3][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}


bool provjeraKraja(char (&mapa)[3][3], igrac (&igraci)[2])
{
    for (int i=0; i<2; i++)
    {
        char znak = igraci[i].tip;
        if (mapa[0][0] == znak && mapa[0][1] == znak && mapa[0][2] == znak ||
            mapa[1][0] == znak && mapa[1][1] == znak && mapa[1][2] == znak ||
            mapa[2][0] == znak && mapa[2][1] == znak && mapa[2][2] == znak ||
            mapa[0][0] == znak && mapa[1][0] == znak && mapa[2][0] == znak ||
            mapa[0][1] == znak && mapa[1][1] == znak && mapa[2][1] == znak ||
            mapa[0][2] == znak && mapa[1][2] == znak && mapa[2][2] == znak ||
            mapa[0][0] == znak && mapa[1][1] == znak && mapa[2][2] == znak ||
            mapa[0][2] == znak && mapa[1][1] == znak && mapa[2][0] == znak)
        {
            igraci[i].pobjede += 1;
            cout << igraci[i].ime << " je pobjedio!" << endl;
            return true;
        }
    }

    bool izjednaceno = true;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (mapa[i][j] == '_')
                izjednaceno = false;
        }
    }
    if (izjednaceno)
    {
        cout << "nitko nije pobjedio." << endl;
        return true;
    }

    return false;
}


void unos(char (&mapa)[3][3], igrac (&igraci)[2], int iter)
{
    int x=-1, y=-1;
    cout << igraci[iter%2].ime << endl;
    while (x > 2 || x < 0 || y > 2 || y < 0 || mapa[y][x] != '_')
    {
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
    }
    mapa[y][x] = igraci[iter%2].tip;
}


void statistika(igrac (&igraci)[2])
{
    cout << igraci[0].ime << ": " << igraci[0].pobjede << " ";
    cout << igraci[1].ime << ": " << igraci[1].pobjede << endl;
}



int main()
{
    char mapa[3][3];
    igrac igraci[2];

    cout << "ime 1. igraca: ";
    getline(cin, igraci[0].ime);
    igraci[0].tip = 'X';
    cout << "ime 2. igraca: ";
    getline(cin, igraci[1].ime);
    igraci[1].tip = 'O';

    while (true)
    {
        mapaReset(mapa);
        int iteracija = 0;
        while (true)
        {
            prikazMape(mapa);
            if (provjeraKraja(mapa, igraci))
                break;
            unos(mapa, igraci, iteracija);
            iteracija++;
        }
        statistika(igraci);
        cout << "jos jedna runda? (y/n) ";
        char odgovor;
        cin >> odgovor;
        if (odgovor == 'n')
            break;
    }

    return 0;
}
