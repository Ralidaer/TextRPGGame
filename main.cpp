#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <conio.h>
#include <fstream>

using namespace std;

class Equipment{
    protected:
        int HPPotions;
        int ManaPotions;
        int Weapon;
        int Armor;
        int Belt;
    public:
        Equipment(){
            Belt=1;
            Weapon=1;
            Armor=1;
            ManaPotions=1;
            HPPotions=1;
        }
    friend class Character;
};
class Character{
	protected:
		string name;
		Equipment eq;
		int level;
		int exp;
		int explim;
		int durability;
		int health;
		int maxhealth;
		int mana;
		int maxmana;
		int defence;
		int agility;
		int force;
		int physicaldamage;
		int magicdamage;
	public:
		Character(string name,int durability,double maxhealth,double maxmana,double defence,int agility,int force,double physicaldamage,double magicdamage):name(name),level(1),exp(0),explim(100),durability(durability),maxhealth(maxhealth),health(maxhealth),mana(maxmana),maxmana(maxmana),defence(defence),agility(agility),force(force),physicaldamage(physicaldamage),magicdamage(magicdamage){}
		Character(){};
		string toString()const{
			stringstream ss;
			ss<<"Klasa postaci: "<<klasa()<<endl<<"Nazwa postaci: "<<name<<endl<<"Poziom: "<<level<<endl<<"Doswiadczenie: "<<exp<<endl<<"Doswiadczenie do nastepnego poziomu: "<<explim<<endl<<"Wytrzymalosc: "<<durability<<endl<<"Max zdrowie: "<<maxhealth<<endl<<"Zdrowie: "<<health<<endl<<"Max Mana: "<<maxmana<<endl<<"Mana: "<<mana<<endl<<"Obrona: "<<defence<<endl<<"Zrecznosc: "<<agility<<endl<<"Moc: "<<force<<endl<<"Obrazenia fizyczne: "<<physicaldamage<<endl<<"Obrazenia magiczne: "<<magicdamage<<endl<<special();
			return ss.str();
		}
		string eqToString()const{
            stringstream ss;
            ss<<"Mikstury zycia: "<<eq.HPPotions<<endl<<"Mikstrury many: "<<eq.ManaPotions<<endl<<"Bron: "<<eq.Weapon<<endl<<"Pancerz: "<<eq.Armor<<endl<<"Pas: "<<eq.Belt<<endl;
            return ss.str();
        }
		virtual string special()const{
            return "Brak";
		}
		virtual string klasa()const{
            return "Character";
		};
		virtual int getMocSpecjalna(){
            return 0;
		};
		virtual void blessing(int forma){
		};
        virtual void levelup(double wsp){
			exp=0;
			explim+=50;
			level++;
			system("cls");
			int a=5;
			int ans;
			do{
                cout<<"Punktow do wydania: "<<a<<endl<<"Wytrzymalosc: "<<durability<<endl<<"Moc: "<<force<<endl<<"Zrecznosc: "<<agility<<endl<<"1. Wytrzymalosc +1 (Zdrowie +2, Mana +2)"<<endl<<"2. Moc +1 (Obrazenia fizyczne +"<<wsp<<" Obrazenia magiczne +"<<2*(4-wsp)<<")"<<endl<<"3. Zrecznosc +1"<<endl<<endl;
                cin>>ans;
                if (ans==2){
                    force++;
                    a--;
                    physicaldamage+=wsp;
                    magicdamage+=2*(4-wsp);
                }
                else if (ans==1){
					durability++;
					a--;
                }
                else if (ans==3){
                    agility++;
					a--;
                }
                system("cls");
			}while(a>0);
			system("cls");
		}
        void change(){
			maxhealth=2*durability;
			maxmana=2*durability;
			health=maxhealth;
			mana=maxmana;
		}
		int getZdrowie(){
			return health;
		}
		int getMana(){
			return mana;
		}
		int getMaxZdrowie(){
			return maxhealth;
		}
		int getMaxMana(){
			return maxmana;
		}
		int getLevel(){
            return level;
        }
        int getMagicDamage(){
            return magicdamage;
        }
        int getExp(){
			return exp;
		}
		int getObrona(){
            return defence;
        }
		int getEqWeapon(){
            return eq.Weapon;
        }
        int getPhysicalDamage(){
            return physicaldamage;
        }
        int getAgility(){
            return agility;
        }
		int getMaxExp(){
			return explim;
		}
        void setExp(int exp){
            this->exp+=exp;
        }
        void dropHPPotions(){
            if(eq.HPPotions==eq.Belt){
                cout<<"Z pokonanego stwora wypadla mikstura zycia"<<endl;
                cout<<"Nie masz miejsca na nowe mikstury"<<endl;
            }
            else{
                eq.HPPotions++;
                cout<<"Z pokonanego stwora wypadla mikstura zycia"<<endl;
            }
        }
        void dropManaPotions(){
            if(eq.ManaPotions==eq.Belt){
                cout<<"Z pokonanego stwora wypadla mikstura many"<<endl;
                cout<<"Nie masz miejsca na nowe mikstury"<<endl;
            }
            else{
                eq.ManaPotions++;
                cout<<"Z pokonanego stwora wypadla mikstura many"<<endl;
            }
        }
        void dropWeapon(){
            eq.Weapon++;
        }
        void dropArmor(){
            eq.Armor++;
        }
        void dropBelt(){
            eq.Belt++;
        }
		void setName(string name){
            this->name=name;
		}
		string getName(){
            return name;
		}
		void setZdrowie(double heal){
		    system("cls");
		    if(eq.HPPotions>0){
                if(health>=maxhealth)
                    cout<<"Masz pelne zdrowie"<<endl;
                else{
                    health+=heal;
                    eq.HPPotions--;
                    if(health>=maxhealth){
                        cout<<"Uzdrowiles sie calkowicie"<<endl;
                        health=maxhealth;
                    }
                    else
                        cout<<"Uzdrowiles sie o "<<heal;
                }
			}else
                cout<<"Nie masz mikstur"<<endl;
		}
		void setMana(double heal){
		    if(heal>0){
		    system("cls");
		    if(eq.ManaPotions>0){
                if(mana>=maxmana)
                    cout<<"Masz pelna mane"<<endl;
                else{
                    mana+=heal;
                    eq.ManaPotions--;
                    if(mana>=maxmana){
                        cout<<"Uzupelniles mane calkowicie"<<endl;
                        mana=maxmana;
                    }
                    else
                        cout<<"Uzupelniles mane o "<<heal;
                }
			}else
                cout<<"Nie masz mikstur"<<endl;
            }else
                mana+=heal;
		}
		void damage(int obr){
            if(health-obr>=0)
                health=health-obr;
            else
                health=0;
        }
        void wczytaj(int &mocSpecjalna){
		    string klasa,sciezka,linia;
            ifstream plik;
                sciezka="save.csv";
                        plik.open(sciezka);
                        string temp;
                        plik>>linia;
                        istringstream ss(linia);
                        getline(ss, klasa,';');
                        getline(ss, name, ';');
                        getline(ss, temp, ';');
                        level = atof(temp.c_str());
                        getline(ss, temp, ';');
                        exp = atof(temp.c_str());
                        getline(ss, temp, ';');
                        explim = atof(temp.c_str());
                        getline(ss, temp, ';');
                        durability = atof(temp.c_str());
                        getline(ss, temp, ';');
                        health = atof(temp.c_str());
                        getline(ss, temp, ';');
                        maxhealth = atof(temp.c_str());
                        getline(ss, temp, ';');
                        mana = atof(temp.c_str());
                        getline(ss, temp, ';');
                        maxmana = atof(temp.c_str());
                        getline(ss, temp, ';');
                        defence = atof(temp.c_str());
                        getline(ss, temp, ';');
                        agility = atof(temp.c_str());
                        getline(ss, temp, ';');
                        force = atof(temp.c_str());
                        getline(ss, temp, ';');
                        physicaldamage = atof(temp.c_str());
                        getline(ss, temp, ';');
                        magicdamage = atof(temp.c_str());
                        getline(ss, temp, ';');
                        mocSpecjalna = atof(temp.c_str());
                        getline(ss, temp, ';');
                        eq.HPPotions = atof(temp.c_str());
                        getline(ss, temp, ';');
                        eq.ManaPotions = atof(temp.c_str());
                        getline(ss, temp, ';');
                        eq.Weapon = atof(temp.c_str());
                        getline(ss, temp, ';');
                        eq.Armor = atof(temp.c_str());
                        getline(ss, temp, ';');
                        eq.Belt = atof(temp.c_str());

                        plik.close();
		}
		void zapis(){
            ofstream zapis;
            zapis.open("save.csv");
            zapis<<klasa()<<";"<<name<<";"<<level<<";"<<exp<<";"<<explim<<";"<<durability<<";"<<health<<";"<<maxhealth<<";"<<mana<<";"<<maxmana<<";"<<defence<<";"<<agility<<";"<<force<<";"<<physicaldamage<<";"<<magicdamage<<";"<<getMocSpecjalna()<<";"<<eq.HPPotions<<";"<<eq.ManaPotions<<";"<<eq.Weapon<<";"<<eq.Armor<<";"<<eq.Belt<<endl;
        }
    friend ostream &operator <<(ostream &strumien, Character const &postac);
    friend string klasaWczytana();
    friend class Equipment;
    friend class Monster;
};

ostream &operator <<(ostream &strumien,Character const& postac){
	strumien<<postac.toString();
	return strumien;
}

string klasaWczytana(){
    string klasa,sciezka,linia;
    ifstream plik;
        sciezka="save.csv";
            plik.open(sciezka);
            string temp;
            plik>>linia;
            istringstream ss(linia);
            getline(ss,klasa,';');
            plik.close();
return klasa;
}

class Druid : public Character{
	private:
		int form;
	public:
		Druid(string name):form(5),Character(name,25,50,50,7,4,20,20,20){}
		~Druid(){};
        string special()const{
            stringstream ss;
            ss<<"Sila formy: "<<form<<endl;
		return ss.str();
        }
        string klasa()const{
            return "Druid";
        }
        void levelup(double wsp){
            form+=5;
            Character::levelup(2);
            change();
        }
        void blessing(int forma){
            system("cls");
            if(forma>0){
                cout<<"Zmieniasz forme w wilkolaka"<<endl<<"Twoje statystyki zwiekszaja sie"<<endl<<endl;
                cout<<"Zycie +"<<forma<<endl<<"Mana +"<<forma<<endl<<"Obrona +"<<forma<<endl<<"Zrecznosc +"<<forma<<endl<<"Sila +"<<forma<<endl<<"Obrazenia fizyczne +"<<forma<<endl<<"Obrazenia magiczne +"<<forma<<endl;
                getch();
            }
            if(health<=0)
                health=1;
            health+=forma;
            maxhealth+=forma;
            mana+=forma;
            maxmana+=forma;
            defence+=forma;
            agility+=forma;
            force+=forma;
            physicaldamage+=2*forma;
            magicdamage+=forma-3;
            system("cls");
        }
        int getMocSpecjalna(){return form;}
        void setMocSpecjalna(int form){this->form=form;}
};

class Palladin : public Character{
	private:
		int faith;
	public:
		Palladin(string name):faith(10),Character(name,30,60,30,10,5,20,30,10){}
		~Palladin(){};
		string special()const{
			stringstream ss;
			ss<<"Wiara: "<<faith<<endl;
            return ss.str();
        }
        string klasa()const{
            return "Paladyn";
        }
       void levelup(double wsp){
                faith+=5;
                Character::levelup(3);
                change();
        }
        int getMocSpecjalna(){
            return faith;
        }
        void blessing(int wiara){
            system("cls");
            health+=wiara;
            maxhealth+=wiara;
            defence+=wiara;
            if(health<=0)
                health=1;
            if(wiara>0){
                cout<<"Blogoslawisz swoje cialo"<<endl<<"Twoje statystyki zwiekszaja sie"<<endl<<endl;
                cout<<"Zycie +"<<wiara<<endl<<"Obrona +"<<wiara<<endl;
                getch();
                system("cls");
                if(health>=maxhealth)
                    cout<<"Masz pelne zycie"<<endl;
                else{
                    health+=wiara;
                    if(health>=maxhealth){
                        cout<<"Uzupelniles zdrowie calkowicie"<<endl;
                        health=maxhealth;
                    }
                    else
                        cout<<"Uzupelniles zdrowie o "<<wiara;
                }
                getch();
                system("cls");
            }
            system("cls");
        }
        void setMocSpecjalna(int faith){
            this->faith=faith;
        }
};

class Necromancer : public Character{
	private:
		int summon;
	public:
		Necromancer(string name):summon(1),Character(name,20,40,60,5,2,20,10,30){}
		~Necromancer(){};
		string special()const{
			stringstream ss;
			ss<<"Przywolanie: "<<summon<<endl;
		return ss.str();
		}
		string klasa()const{
			return "Nekromatna";
		}
		void levelup(double wsp){
			summon++;
			Character::levelup(1);
			change();
		}
		int getMocSpecjalna(){return summon;}
        void setMocSpecjalna(int summon){this->summon=summon;}
};

class Skeleton{
	protected:
		int health;
		int physicaldamage;
    public:
        Skeleton(){
            health=0;
            physicaldamage=0;
        }
        void improve(int zycie, int atak){
            health+=zycie;
            physicaldamage+=atak;
        }
        int getPhysicaldamage(){
            return physicaldamage;
        }
};

class Monster{
    private:
        int level;
        int health;
        int physicaldamage;
    public:
        Monster(int level):level(level),health(50+level*10),physicaldamage(5+(level)*5){}
        ~Monster(){};
        int getZdrowie(){
            return health;
        }
        void damage(int obr){
            if(health-obr>=0)
                health=health-obr;
            else
                health=0;
        }
        int atak(Character &hero){
            int obra=rand()%hero.getAgility()+hero.defence;
            if(obra>physicaldamage){
                cout<<"Unikales ataku"<<endl;
                return 0;
            }else
                return physicaldamage-obra;
        }
};

int obrazenia(Character &hero){
    int atak=hero.getEqWeapon()*10+hero.getPhysicalDamage();
    return atak+rand()%(hero.getAgility());

}

void drop(Character &hero){
    if(rand()%7==1){
        hero.dropHPPotions();
    }
    else if(rand()%10==2){
        hero.dropManaPotions();
    }
    else if(rand()%10==3){
        hero.dropWeapon();
        cout<<"Z pokonanego stwora wypadlo czesc broni (ulepszono bron)"<<endl;
    }
    else if(rand()%10==4){
        hero.dropArmor();
        cout<<"Z pokonanego stwora wypadlo czesc zbroi (ulepszono pancerz)"<<endl;
    }
    else if(rand()%10==5){
        hero.dropBelt();
        cout<<"Z pokonanego stwora wypadla czesc pasa (mozesz nosic wiecej mikstur)"<<endl;
    }
    else
        cout<<"Z pokonanego stwora nic nie wypadlo"<<endl;
}

bool walka(Character &hero){
    int obrbohater,obrpotwor,czyForma=0,czySzkielet=0,czyWiara=0;
    cout<<"Napotykasz na swojej drodze potwora"<<endl;
    Monster monster(hero.getLevel());
    Skeleton skeleton;
    fflush(stdin);
    getch();
    int a,b;
    system("cls");
    do{
        do{
        cout<<setw(15)<<hero.getName()<<setw(15)<<"Potwor"<<endl<<setw(10)<<"Zdrowie: "<<setw(5)<<hero.getZdrowie()<<setw(15)<<monster.getZdrowie()<<setw(10)<<endl<<"Mana: "<<setw(5)<<hero.getMana()<<endl<<endl;
        cout<<"1. Uzyj eliksiru"<<endl<<"2. Atakuj"<<endl<<"3. Uzyj zaklecia"<<endl;
        cin>>a;
        if(a==1 || a==2 || a==3){
            switch(a){
                case 1:
                    do{
                        system("cls");
                        cout<<"Zdrowie: "<<hero.getZdrowie()<<"("<<hero.getMaxZdrowie()<<")"<<endl<<"Mana: "<<hero.getMana()<<"("<<hero.getMaxMana()<<")"<<endl<<"1. Uzyj eliksiru zycia(+30 HP)"<<endl<<"2. Uzyj eliksiru many(+30 MP)"<<endl<<"3. Powrot"<<endl<<endl;
                        cin>>b;
                        switch(b){
                            case 1:
                                hero.setZdrowie(30);
                                getch();
                                system("cls");
                                b=0;
                                break;
                            case 2:
                                hero.setMana(30);
                                getch();
                                system("cls");
                                b=0;
                                break;
                            case 3:
                                system("cls");
                                break;
                        }
                    }while(b!=1 && b!=2 && b!=3);
                    a=0;
                    break;
                case 2:
                    system("cls");
                    obrbohater=obrazenia(hero);
                    cout<<setw(15)<<hero.getName()<<setw(15)<<"Potwor"<<endl<<setw(10)<<"Zdrowie: "<<setw(5)<<hero.getZdrowie()<<setw(15)<<monster.getZdrowie()<<setw(10)<<endl<<"Mana: "<<setw(5)<<hero.getMana()<<endl<<endl;
                    monster.damage(obrbohater);
                    cout<<"Zadales potworowi: "<<obrbohater<<" obrazen"<<endl;
                    fflush(stdin);
                    getch();
                    system("cls");
                    break;
                case 3:

                        system("cls");
                        if(hero.klasa()=="Druid"){
                            int obrpnacza;
                            do{
                                cout<<"1. Pnacza(-10 MP)"<<endl<<"2. Przemiana(-10 MP)"<<endl<<"3. Powrot"<<endl;
                                cin>>b;
                                if(b==1 || b==2 || b==3){
                                    switch(b){
                                        case 1:
                                            system("cls");
                                            if(hero.getMana()>=10){
                                                hero.setMana(-10);
                                                cout<<"Zsylasz na przeciwnika pnacza"<<endl;
                                                obrpnacza=hero.getMagicDamage()*2;
                                                monster.damage(obrpnacza);
                                                cout<<"Zadales potworowi: "<<obrpnacza<<" obrazen"<<endl<<endl;
                                            }else{
                                                cout<<"Nie masz wystarczajaco many"<<endl;
                                                b=0;
                                            }
                                            getch();
                                            system("cls");
                                            break;
                                        case 2:
                                            if(czyForma==0){
                                            if(hero.getMana()>=10){
                                                czyForma=1;
                                                hero.setMana(-10);
                                                hero.blessing(hero.getMocSpecjalna());
                                            }else{
                                                cout<<"Nie masz wystarczajaco many"<<endl;
                                                b=0;
                                            }
                                            }else{
                                                system("cls");
                                                cout<<"Zmieniles juz forme"<<endl;
                                                getch();
                                                system("cls");
                                                b=0;
                                            }
                                            break;
                                        case 3:
                                            system("cls");
                                            a=0;
                                            break;
                                    }
                                }else system("cls");
                            }while(b!=1 && b!=2 && b!=3);
                        }else if(hero.klasa()=="Paladyn"){
                            int obrmlot;
                            do{
                                cout<<"1. Mlot(-10 MP)"<<endl<<"2. Blogoslawienstwo(-10 MP)"<<endl<<"3. Powrot"<<endl;
                                cin>>b;
                                    if(b==1 || b==2 || b==3){
                                        switch(b){
                                            case 1:
                                                if(hero.getMana()>=10){
                                                    hero.setMana(-10);
                                                    system("cls");
                                                    cout<<"Rzucasz w przeciwnika magicznym mlotem"<<endl;
                                                    obrmlot=hero.getMagicDamage();
                                                    monster.damage(obrmlot);
                                                    cout<<"Zadales potworowi: "<<obrmlot<<" obrazen"<<endl<<endl;
                                                    getch();
                                                    system("cls");
                                                }else{
                                                    system("cls");
                                                    cout<<"Nie masz wystarczajaco many"<<endl;
                                                    b=0;
                                                }
                                                break;
                                            case 2:
                                                if(hero.getMana()>=10){
                                                    czyWiara++;
                                                    hero.setMana(-10);
                                                    hero.blessing(hero.getMocSpecjalna());
                                                }else{
                                                    cout<<"Nie masz wystarczajaco many"<<endl;
                                                    b=0;
                                                }
                                                break;
                                            case 3:
                                                system("cls");
                                                a=0;
                                                break;
                                        }
                                    }else system("cls");
                            }while(b!=1 && b!=2 && b!=3);
                        }else if(hero.klasa()=="Nekromatna"){
                            int obrzeby;
                            do{
                                cout<<"1. Zeby(-10 MP)"<<endl<<"2. Przyzwij smierc(-10 MP)"<<endl<<"3. Powrot"<<endl;
                                cin>>b;
                                    if(b==1 || b==2 || b==3){
                                        switch(b){
                                            case 1:
                                                if(hero.getMana()>=10){
                                                    hero.setMana(-10);
                                                    system("cls");
                                                    cout<<"Zasypujesz przeciwnika magicznymi klami"<<endl;
                                                    obrzeby=hero.getMagicDamage()*2;
                                                    monster.damage(obrzeby);
                                                    cout<<"Zadales potworowi: "<<obrzeby<<" obrazen"<<endl<<endl;
                                                    getch();
                                                    system("cls");
                                                }else{
                                                    cout<<"Nie masz wystarczajaco many"<<endl;
                                                b=0;
                                            }
                                                break;
                                            case 2:
                                                if(hero.getMana()>=10){
                                                    if(czySzkielet+1>hero.getMocSpecjalna()){
                                                        system("cls");
                                                        cout<<"Nie mozesz miec wiecej szkieletow"<<endl;
                                                        b=0;
                                                    }else{
                                                    czySzkielet++;
                                                    hero.setMana(-10);
                                                    skeleton.improve(hero.getZdrowie()/2,hero.getMagicDamage()/2);
                                                    system("cls");
                                                    }
                                                    cout<<"Masz : "<<czySzkielet<<" szkieletow"<<endl;
                                                    getch();
                                                    system("cls");
                                                }else{
                                                    cout<<"Nie masz wystarczajaco many"<<endl;
                                                    b=0;
                                                }
                                                break;
                                            case 3:
                                                system("cls");
                                                a=0;
                                                break;
                                        }
                                    }else system("cls");
                                }while(b!=1 && b!=2 && b!=3);

                        }

                    break;
            }
        }else system("cls");
        }while(a!=1 && a!=2 & a!=3);
        system("cls");
        cout<<setw(15)<<hero.getName()<<setw(15)<<"Potwor"<<endl<<setw(10)<<"Zdrowie: "<<setw(5)<<hero.getZdrowie()<<setw(15)<<monster.getZdrowie()<<setw(10)<<endl<<"Mana: "<<setw(5)<<hero.getMana()<<endl<<endl;
        fflush(stdin);
        getch();
        if(hero.getZdrowie()<=0 || monster.getZdrowie()<=0)
            break;
        if(czySzkielet>0){
            system("cls");
            cout<<"Twoje szkielety zaatakowaly przeciwnika"<<endl;
            cout<<"Twoje szkielety zadaly potworowi: "<<skeleton.getPhysicaldamage()<<" obrazen"<<endl<<endl;
            getch();
            system("cls");
            monster.damage(skeleton.getPhysicaldamage());
            cout<<setw(15)<<hero.getName()<<setw(15)<<"Potwor"<<endl<<setw(10)<<"Zdrowie: "<<setw(5)<<hero.getZdrowie()<<setw(15)<<monster.getZdrowie()<<setw(10)<<endl<<"Mana: "<<setw(5)<<hero.getMana()<<endl<<endl;
            fflush(stdin);
            getch();
            system("cls");
        }
        obrpotwor=monster.atak(hero);
        hero.damage(obrpotwor);
        cout<<"Potwor zadal ci : "<<obrpotwor<<" obrazen"<<endl;
        fflush(stdin);
        getch();
        system("cls");
        cout<<setw(15)<<hero.getName()<<setw(15)<<"Potwor"<<endl<<setw(10)<<"Zdrowie: "<<setw(5)<<hero.getZdrowie()<<setw(15)<<monster.getZdrowie()<<setw(10)<<endl<<"Mana: "<<setw(5)<<hero.getMana()<<endl<<endl;
        fflush(stdin);
        getch();
        system("cls");
    }while(hero.getZdrowie()>0 && monster.getZdrowie()>0);
    if(hero.getZdrowie()>0){
            if(hero.klasa()=="Druid")
                if(czyForma==1)
                    hero.blessing(-hero.getMocSpecjalna());
            if(hero.klasa()=="Paladyn")
                if(czyWiara>0)
                    hero.blessing(-czyWiara*hero.getMocSpecjalna());
        return true;
    }
    else
        return false;
}

void gra(Character &hero){
    system("cls");
    cout<<hero<<endl;
    cout<<"Wcisnij cokolwiek by kontunuowac";
    getch();
    system("cls");
    int a,b;
    bool czyWygral=true;
    do{
        cout<<"MENU"<<endl<<"1. Zobacz statystyki"<<endl<<"2. Zobacz ekwipunek"<<endl<<"3. Zapisz gre"<<endl<<"4. Wyrusz w podroz"<<endl<<"5. Koniec gry"<<endl<<endl;
        cin>>a;
        if(a==1 || a==2 || a==3 || a==4 || a==5){
            system("cls");
            switch(a){
                case 1:
                    system("cls");
                    cout<<hero<<endl;
                    cout<<"Wcisnij cokolwiek by kontunuowac";
                    getch();
                    system("cls");
                    a=0;
                    break;
                case 2:
                    system("cls");
                    cout<<hero.eqToString()<<endl;
                    cout<<"Wcisnij cokolwiek by kontunuowac";
                    getch();
                    system("cls");
                    a=0;
                    break;
                case 3:
                    hero.zapis();
                    system("cls");
                    cout<<"Pomyslnie zapisano"<<endl<<endl<<"Wcisnij cokolwiek by kontunuowac";
                    getch();
                    system("cls");
                    a=0;
                    break;
                case 4:
                    system("cls");
                    do{
                        cout<<"Zdrowie: "<<hero.getZdrowie()<<"("<<hero.getMaxZdrowie()<<")"<<endl<<"Mana: "<<hero.getMana()<<"("<<hero.getMaxMana()<<")"<<endl<<"1. Uzyj eliksiru"<<endl<<"2. Wyrusz"<<endl<<"3. Powrot"<<endl<<endl;
                        cin>>a;
                        if(a==1 || a==2 || a==3){
                            system("cls");
                            switch(a){
                                case 1:
                                    system("cls");
                                    do{
                                    cout<<"Zdrowie: "<<hero.getZdrowie()<<"("<<hero.getMaxZdrowie()<<")"<<endl<<"Mana: "<<hero.getMana()<<"("<<hero.getMaxMana()<<")"<<endl<<"1. Uzyj eliksiru zycia(+30 HP)"<<endl<<"2. Uzyj eliksiru many(+30 MP)"<<endl<<"3. Powrot"<<endl<<endl;
                                    cin>>b;
                                    if(b==1 || b==2 || b==3){
                                        switch(b){
                                        case 1:
                                            hero.setZdrowie(30);
                                            getch();
                                            system("cls");
                                            b=0;
                                            break;
                                        case 2:
                                            hero.setMana(30);
                                            getch();
                                            system("cls");
                                            b=0;
                                            break;
                                        case 3:
                                            system("cls");

                                            break;
                                        }

                                    }else system("cls");
                                    }while(b!=1 && b!=2 && b!=3);
                                    a=0;
                                    break;
                                case 2:
                                    czyWygral=walka(hero);
                                    if(czyWygral){
                                        cout<<"Wygrales!!!"<<endl;
                                        getch();
                                        system("cls");
                                        cout<<"Zdobyles "<<20<<" doswiadczenia"<<endl;
                                        getch();
                                        hero.setExp(20);
                                        system("cls");
                                        drop(hero);
                                        if(hero.getExp()>=hero.getMaxExp()){
                                        cout<<"Twoj poziom sie zwiekszyl"<<endl;
                                            getch();
                                            hero.levelup(1);
                                        }
                                        getch();
                                        system("cls");
                                        a=0;
                                    }
                                    else{
                                        cout<<"Przegrales, koniec gry"<<endl;
                                    }
                                    break;
                                case 3:
                                    break;
                            }
                        }else system("cls");
                    }while(a!=1 && a!=2 && a!=3);
                    if(!czyWygral)
                        break;
                    a=0;
                    break;
                case 5:
                    cout<<"Zegnaj poszukiwaczu"<<endl;
                    break;
                }
        }else
        system("cls");
    }while(a!=1 && a!=2 && a!=3 && a!=4 && a!=5);
}

int main(){
    srand (time(NULL));
	int a;
	do{
		cout<<"1. Nowa gra"<<endl<<"2. Wczytaj gre"<<endl<<endl;
		cin>>a;
		if(a!=1 && a!=2)
			system("cls");
	}while(a!=1 && a!=2);
	if(a==2){
        int mocSpecjalna;
        if(klasaWczytana()=="Druid"){
            Druid d1("nowy");
            d1.wczytaj(mocSpecjalna);
            d1.setMocSpecjalna(mocSpecjalna);

            gra(d1);
        }
        else if(klasaWczytana() == "Paladyn"){
            Palladin p1("nowy");
            p1.wczytaj(mocSpecjalna);
            p1.setMocSpecjalna(mocSpecjalna);
            gra(p1);
        }
        else{
            Necromancer n1("nowy");
            n1.wczytaj(mocSpecjalna);
            n1.setMocSpecjalna(mocSpecjalna);
            gra(n1);
        }
    }
    if(a==1){
        system("cls");
        cout<<setw(50)<<"Diabolo"<<endl<<"W w swiecie pelnym mroku, zepsucia i smutku pojawiasz sie ty, poszukiwacz ktoremy przyjdzie zmienic losy calego swiata"<<endl<<endl<<"Wybierz postac ktora stawi czola Mrocznej Trojce"<<endl<<"1. Druid"<<endl<<"2. Paladyn"<<endl<<"3. Nekromatna"<<endl<<endl;
        do{
            cin>>a;
            if(a!=1 && a!=2 && a!=3){
                system("cls");
                cout<<"Wybierz postac ktora stawi czola Mrocznej Trojce"<<endl<<"1. Druid"<<endl<<"2. Paladyn"<<endl<<"3. Nekromatna"<<endl<<endl<<"Podaj poprawny numer: ";
            }
        }while(a!=1 && a!=2 && a!=3);
        cout<<"Podaj imie dla postaci: ";
        string imie;
        fflush(stdin);
        getline(cin, imie);
        if(a==1){
            Druid d1("nowy");
            d1.setName(imie);
            gra(d1);
        }else if(a==2){
            Palladin p1("nowy");
            p1.setName(imie);
            gra(p1);
        }else{
            Necromancer n1("nowy");
            n1.setName(imie);
            gra(n1);
        }
    }
return 0;
}
