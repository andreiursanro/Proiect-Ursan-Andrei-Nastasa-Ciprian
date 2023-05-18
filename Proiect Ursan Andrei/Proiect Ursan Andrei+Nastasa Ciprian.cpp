#include <iostream>
using namespace std;

//clasa masina
class Masina {
    // atributele clasei
    char* marca;
    char* culoare;
    int an;
    float pret;
    int putere;
    int nr_loc;
public:
    //constructor implicit
    Masina(const char* m = "", const char* c = "", int a = 0, float pr = 10, int pt = 0, int nr = 0) {

        marca = new char[strlen(m) + 1]; //alocam dimensiunea pentru string
        strcpy_s(marca, strlen(m) + 1, m);//copiem din parametrul constructorului in atribut

        culoare = new char[strlen(c) + 1];
        strcpy_s(culoare, strlen(c) + 1, c);

        an = a;
        pret = pr;
        putere = pt;
        nr_loc = nr;
    }
    //constructor de copiere
    Masina(const Masina& m) {
        marca = new char[strlen(m.marca) + 1];
        strcpy_s(marca, strlen(m.marca) + 1, m.marca);

        culoare = new char[strlen(m.culoare) + 1];
        strcpy_s(culoare, strlen(m.culoare) + 1, m.culoare);

        an = m.an;
        pret = m.pret;
        putere = m.putere;
        nr_loc = m.nr_loc;
    }
    //destructor
    ~Masina() {
        delete[]marca;
        delete[]culoare;
    }
    void afisareDate() {
        cout << "Marca: " << marca << endl;

        cout << "Culoare: " << culoare << endl;

        cout << "An fabricatie: " << an << endl;

        cout << "Putere: " << putere << endl;

        cout << "Numar locuri: " << nr_loc << endl;

        cout << "Pret: " << pret << "RON\n";
    }
    void citireDate() {
        cin.ignore();//curatam buffer ul de cin

        cout << "Marca: ";
        //cin >> marca;
        cin.getline(marca, 200);

        cout << "Culoare: ";
        //cin >> culoare;
        cin.getline(culoare, 200);

        cout << "An fabricatie: ";
        cin >> an;

        cout << "Putere: ";
        cin >> putere;

        cout << "Numar locuri: ";
        cin >> nr_loc;

        cout << "Pret: ";
        cin >> pret;
    }
    //setare parametri
    void setMarca(const char* m) {
        marca = new char[strlen(m) + 1];
        strcpy_s(marca, strlen(m) + 1, m);
    }
    void setCuloare(const char* c) {
        culoare = new char[strlen(c) + 1];
        strcpy_s(culoare, strlen(c) + 1, c);
    }
    void setAn(int a) {
        an = a;
    }
    void setPret(float p) {
        pret = p;
    }
    void setPutere(int p) {
        putere = p;
    }
    void setNrLoc(int n) {
        nr_loc = n;
    }
    //get
    const char* getMarca() {
        return marca;
    }
    const char* getCuloare() {
        return culoare;
    }
    int getAn() {
        return an;
    }
    float getPret() {
        return pret;
    }
    int getPutere() {
        return putere;
    }
    int getNrLoc() {
        return nr_loc;
    }
    //suprascrierea operatorului de atribuire
    Masina& operator=(const Masina& m) {
        marca = new char[strlen(m.marca) + 1];
        strcpy_s(marca, strlen(m.marca) + 1, m.marca);

        culoare = new char[strlen(m.culoare) + 1];
        strcpy_s(culoare, strlen(m.culoare) + 1, m.culoare);

        an = m.an;
        pret = m.pret;
        putere = m.putere;
        nr_loc = m.nr_loc;

        return *this;
    }
};

//clasa parc auto
class ParcAuto {
    //atributele clasei
    int nrMasini;
    // pointer de tip masina a pentru a se transforma in vector
    Masina* m;
public:
    //constructor
    ParcAuto(int n) {
        nrMasini = n;
        m = new Masina[nrMasini + 1];
    }
    //desctructor
    ~ParcAuto() {
        delete[]m;
    }
    //functie pentru a afisa datele tuturor masinilor
    void afisareMasini() {
        for (int i = 0; i < nrMasini; i++) {
            cout << "\nMasina nr " << i + 1 << "\n";
            m[i].afisareDate();
        }

    }
    void afisareTabel() {
        cout << "Nr. Crt. || Marca || Culoare || Pret(RON) || Putere || An Fab. || Nr. Loc. ||\n";
        for (int i = 0; i < nrMasini; i++) {
            cout << i + 1 << "            " << m[i].getMarca() << "        " << m[i].getCuloare() << "      ";
            cout << m[i].getPret() << "        " << m[i].getPutere() << "         ";
            cout << m[i].getAn() << "         " << m[i].getNrLoc() << endl;
        }
    }
    //crestere preturile masinilor cu un procent
    void acualizarePreturi(int procent) {
        for (int i = 0; i < nrMasini; i++) {
            m[i].setPret(m[i].getPret() + m[i].getPret() * procent / 100.0);
        }
    }
    // afisare datele masinilor fabricate intrun anumit an
    void afisareMasiniAn(int a) {
        for (int i = 0; i < nrMasini; i++) {
            if (m[i].getAn() == a) {
                cout << "\nMasina nr " << i + 1 << "\n";
                m[i].afisareDate();
            }
        }
    }
    // editeaza datele unei masini dupa id-ul din lista
    void actualizareMasinaDupaNumar(int nr) {
        nr--;
        if (nr >= nrMasini || nr < 0) {
            cout << "Masina nr" << nr << "nu exista!\n";
        }
        else {
            m[nr].citireDate();
            cout << "A fost actualizata masina: \n";
            m[nr].afisareDate();
        }
    }
    // afiseasa datele unei masini dupa id
    void afisareDateMasinaDupaNumar(int nr) {
        nr--;
        if (nr >= nrMasini || nr < 0) {
            cout << "Masina nr" << nr << "nu exista!\n";
        }
        else {
            cout << "Afisare data masina nr:" << nr + 1 << "\n";
            m[nr].afisareDate();
        }

    }
    //seteaza o masina
    void setMasina(int i, Masina aux) {
        m[i] = aux;
    }
    // sterge o masina
    void eliminareMasina(int nr) {
        nr--;
        if (nr < 0 || nr > nrMasini) {
            cout << "Masina nu exista!";
        }
        else {
            for (int i = nr; i < nrMasini - 1; i++) {
                m[i] = m[i + 1];
            }
            nrMasini--;
        }
    }
    void adaugaMasina(Masina x) {

        //declaram vectorul aux cu dimensiunea mai mare cu 1 decat ce avem
        Masina* aux;
        aux = new Masina[nrMasini + 2];

        for (int i = 0; i < nrMasini; i++) {
            aux[i] = m[i];//copiem obiect cu obiect din m in aux
        }
        aux[nrMasini] = x; // pe ultima pozitie din aux punem elementul de introdus

        nrMasini++;//crestem numatorul de masini

        m = aux; //inlocium datele cu aux in care am introdus obiectul

    }
};
void afisareMeniu() {
    cout << "======== MENIU PARC AUTO ========\n";
    cout << "1. Afisare Date sub forma de lista\n";
    cout << "2. Afisare Date sub forma de tabel\n";
    cout << "3. Adauga masina\n";
    cout << "4. Sterge masina dupa ID\n";
    cout << "5. Afisare masini care sunt fabricate intr-un anumit an\n";
    cout << "6. Afisare date masina dupa ID\n";
    cout << "7. Editeaza datele unei masini dupa ID\n";
    cout << "8. Creste preturile cu un procent\n";
    cout << "9. Iesire din program\n";
    cout << "Introduce optiunea: ";
}
int main()
{
    int a = 0, i, opt = 1, p;

    ParcAuto parc(5);

    Masina aux("Opel", "Negru", 2000, 10000, 150, 4);
    parc.setMasina(0, aux);

    aux = Masina("Lexus", "Negru", 2000, 10000, 150, 4);
    parc.setMasina(1, aux);

    aux = Masina("Seat", "Rosu", 2005, 1000, 70, 2);
    parc.setMasina(2, aux);

    aux = Masina("VW", "Verde", 2002, 2600, 100, 4);
    parc.setMasina(3, aux);

    aux = Masina("Ford", "Alb", 2010, 5000, 170, 5);
    parc.setMasina(4, aux);

    afisareMeniu();

    while (opt) {
        cin >> opt;
        switch (opt)
        {
        case 1: {
            //parc.afisareMasini();
            parc.afisareMasini();
            break;
        }
        case 2: {
            parc.afisareTabel();
            break;
        }
        case 3: {
            aux.citireDate();
            parc.adaugaMasina(aux);
            break;
        }
        case 4: {
            cout << "Dati ID-ul masinii pentru a fi stearsa:";
            cin >> i;
            parc.eliminareMasina(i);
            break;
        }
        case 5: {
            cout << "Dati an de fabricatie: ";
            cin >> a;
            parc.afisareMasiniAn(a);
            break;
        }
        case 6: {
            cout << "Dati un index pentru a afisa datele unei masini: ";
            cin >> i;
            parc.afisareDateMasinaDupaNumar(i);
            break;
        }
        case 7: {
            cout << "Dati un index pentru a actualiza datele unei masini: ";
            cin >> i;
            parc.actualizareMasinaDupaNumar(i);
            break;
        }
        case 8: {
            cout << "Procent de crestere: ";
            cin >> p;
            parc.acualizarePreturi(p);
            break;
        }
        case 9: {
            return 0;
        }
        default:
            cout << "Optiune incorecta!\n";
            break;
        }
        afisareMeniu();
    }

    return 0;
}