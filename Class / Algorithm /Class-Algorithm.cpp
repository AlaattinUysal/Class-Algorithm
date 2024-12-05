//Abdulkerim çiçek 425476
//Alaattin uysal 425492

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class Student
{
    public:
    Student(int size);
    ~Student();
    void readfromCSV(string FileName);
    void average();
    void print(string e);
    void print();

    private:
    string* Ad;
    string* OgrNo;
    float* AraSinav;
    float* Sinav2;
    float* Odev;
    float* Final;
    int* DevamSayisi;
    float* ort;
    int boyut;
};


Student::Student(int size){
    boyut=size;
    Ad=new string[size];
    OgrNo=new string[size];
    AraSinav=new float[size];
    Sinav2=new float[size];
    Odev=new float[size];
    Final=new float[size];
    ort=new float[size];
    DevamSayisi=new int[size];

    for(int i=0;i<boyut;i++){
        Ad[i]="";
        OgrNo[i]="";
        AraSinav[i]=0;
        Sinav2[i]=0;
        Odev[i]=0;
        Final[i]=0;
        ort[i]=0;
        DevamSayisi[i]=0;
    }

}
Student::~Student(){
    delete[] Ad;
    delete[] OgrNo;
    delete[] AraSinav;
    delete[] Sinav2;
    delete[] Odev;
    delete[] Final;
    delete[] ort;
    delete[] DevamSayisi;
}

void Student::readfromCSV(string filename){
    ifstream myReadFile(filename);
    if (!myReadFile.is_open()) {
        cout << "Dosya acilmadi! " << filename << endl;
        return;
    }

    string myText;
    int index = 0; // Hangi öğrenciyi doldurduğumuzu takip eder
    
    getline(myReadFile, myText);  // İlk satırdaki başlıkları atla

    while (getline(myReadFile, myText)) {
        string temp = "";
        int field = 0; //alan no

        for (int i = 0; i < myText.length(); i++) {
            if (myText[i] == ',' || i == myText.length() - 1) {// Eğer virgül ya da son karakter ise
                if (i == myText.length() - 1) {
                temp += myText[i];
                }

                //alanlari sirayla ata
                if (field == 0)
                    Ad[index] = temp;
                else if (field == 1)
                    OgrNo[index] = temp;
                else if (field == 2)
                    AraSinav[index] = stof(temp); // string to float
                else if (field == 3)
                    Sinav2[index] = stof(temp);
                else if (field == 4)
                    Odev[index] = stof(temp);
                else if (field == 5)
                    Final[index] = stof(temp);
                else if (field == 6)
                    DevamSayisi[index] = stoi(temp); 
                    
                // Geçici stringi temizle ve sıradaki alana geç
                temp = "";
                field++;
            } 
            else {
                temp += myText[i]; // karakterleri biriktir
            }
        }
        index++; // Sonraki öğrenciye geç
    }
    myReadFile.close();
}

void Student::print(){
    cout<<left;
    cout<<endl<<endl
        <<setw(7)<<"ort"
        <<setw(4)<<"No"
        <<setw(8)<<"AraSnv"
        <<setw(5)<<"Snv2"
        <<setw(5)<<"Odev"
        <<setw(7)<<"Final"
        <<setw(7)<<"Devam"
        <<setw(12)<<"Isim"
        <<endl;
    for(int i=0;i<boyut;i++){
        cout<<setw(7)<<ort[i]
        <<setw(5)<<OgrNo[i]
        <<setw(8)<<AraSinav[i]
        <<setw(5)<<Sinav2[i]
        <<setw(5)<<Odev[i]
        <<setw(7)<<Final[i]
        <<setw(5)<<DevamSayisi[i]
        <<setw(12)<<Ad[i]<< endl;
    }
}

void Student::print(string e){
    cout<<left;
    if(e =="1"){
        cout
            <<setw(7)<<"ort"
            <<setw(4)<<"No"
            <<setw(8)<<"AraSnv"
            <<setw(5)<<"Snv2"
            <<setw(5)<<"Odev"
            <<setw(7)<<"Final"
            <<setw(7)<<"Devam"
            <<setw(12)<<"Isim"
            <<endl;
        for(int i=0;i<boyut;i++){
            if(ort[i]>=50){
                cout<<setw(7)<<ort[i]
                <<setw(5)<<OgrNo[i]
                <<setw(8)<<AraSinav[i]
                <<setw(5)<<Sinav2[i]
                <<setw(5)<<Odev[i]
                <<setw(7)<<Final[i]
                <<setw(5)<<DevamSayisi[i]
                <<setw(12)<<Ad[i]<< endl;
            }
        }
    }
    else if (e == "0"){
        cout
            <<setw(7)<<"ort"
            <<setw(4)<<"No"
            <<setw(8)<<"AraSnv"
            <<setw(5)<<"Snv2"
            <<setw(5)<<"Odev"
            <<setw(7)<<"Final"
            <<setw(7)<<"Devam"
            <<setw(12)<<"Isim"
            <<endl;        
        for(int i=0;i<boyut;i++){
            if(ort[i]<50){
                cout
                <<setw(7)<<ort[i]
                <<setw(5)<<OgrNo[i]
                <<setw(8)<<AraSinav[i]
                <<setw(5)<<Sinav2[i]
                <<setw(5)<<Odev[i]
                <<setw(7)<<Final[i]
                <<setw(5)<<DevamSayisi[i]
                <<setw(12)<<Ad[i]<< endl;
            }
        }
    }
    else{
        ofstream Dosya(e+".txt");
        if(!Dosya.is_open()){
            cout<<"Dosya acilamadi.";
        }
        else{
            Dosya<<left;
            Dosya<<"Kalanlar"<<endl;
            Dosya
                <<setw(7)<<"ort"
                <<setw(4)<<"No"
                <<setw(8)<<"AraSnv"
                <<setw(5)<<"Snv2"
                <<setw(5)<<"Odev"
                <<setw(7)<<"Final"
                <<setw(7)<<"Devam"
                <<setw(12)<<"Isim"
                <<endl;
            for(int i=0;i<boyut;i++){
                if(ort[i]<50){
                    Dosya<<setw(7)<<ort[i]
                    <<setw(5)<<OgrNo[i]
                    <<setw(8)<<AraSinav[i]
                    <<setw(5)<<Sinav2[i]
                    <<setw(5)<<Odev[i]
                    <<setw(7)<<Final[i]
                    <<setw(5)<<DevamSayisi[i]
                    <<setw(12)<<Ad[i]<< endl;
                }
            }
            Dosya<<endl<<endl<<"Gecenler"<<endl;
            Dosya
                <<setw(7)<<"ort"
                <<setw(4)<<"No"
                <<setw(8)<<"AraSnv"
                <<setw(5)<<"Snv2"
                <<setw(5)<<"Odev"
                <<setw(7)<<"Final"
                <<setw(7)<<"Devam"
                <<setw(12)<<"Isim"
                <<endl;            
            for(int i=0;i<boyut;i++){
                if(ort[i]>=50){
                    Dosya<<setw(7)<<ort[i]
                    <<setw(5)<<OgrNo[i]
                    <<setw(8)<<AraSinav[i]
                    <<setw(5)<<Sinav2[i]
                    <<setw(5)<<Odev[i]
                    <<setw(7)<<Final[i]
                    <<setw(5)<<DevamSayisi[i]
                    <<setw(12)<<Ad[i]<< endl;
                }
            }
        }
    }
}

int CheckSize(){// dosyanın boyutunu kontrol eder ve boyutu geri dönderir
    ifstream Dosya("girdi.csv");
    int i=0;
    string line;
    getline(Dosya,line);
    while(getline(Dosya,line)){
        i++;
    }
    return i;
}

void Student::average(){// ortalamayı hesaplar ve classa atar
    for(int i=0;i<boyut;i++){
        ort[i]=(AraSinav[i]*20+Sinav2[i]*20+Odev[i]*20+Final[i]*40)/100;
    }
}

int main(){
    Student elem(CheckSize());
    string kod;
    elem.readfromCSV("girdi.csv");
    elem.average();
    elem.print();
    cout<<"1: geçenleri ekrana yazdir"<<endl;
    cout<<"0: kalanlari ekrana yazdir"<<endl;
    cout<<"dosyaismi giriniz (sonuclari dosyaya yazar): ";
    cin>>kod;
    elem.print(kod);
}
