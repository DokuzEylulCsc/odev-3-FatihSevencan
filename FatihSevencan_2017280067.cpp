#include<fstream>
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

string sorusayisi;
string cevapanahtari;
string OgrenciNumarasi[100];
int OgrenciPuanlari[100];
int ogrencisirasi=0;


int girdi();
int cikti();
int sirala();



int main () {
  girdi();
  sirala();
  cikti();
}
int girdi(){  //www.cplusplus.com/doc/tutorial/files/
	string line;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    getline (myfile,line) ;
  	sorusayisi=line;
	getline (myfile,line) ;
	cevapanahtari=line;
	int ogrencipuani;//Her satırda değişiyor
	
	
    while ( getline (myfile,line) )
    { 
		ogrencipuani=0;
  			  
    	int VirgulSayisi=0;  	
    	int i=0; //satirin harf sayisini tutar 
    	int cevapsirasi=0;
    	string ogrencicevabi;
    	while(i<line.length()){
    		
			if(line[i]==','){
    			VirgulSayisi++;	
				if(line[i+1]==','){//arka arkaya iki virgül varsa 
					cevapsirasi++;
					cevapsirasi++;
				}	
			}
			else if(VirgulSayisi==0){
				OgrenciNumarasi[ogrencisirasi]=OgrenciNumarasi[ogrencisirasi]+line[i];
			}
			else 
    		{
				if(cevapanahtari[cevapsirasi]==line[i])ogrencipuani+=4;
    			else ogrencipuani-=1;
				cevapsirasi++;
				cevapsirasi++;			
			}
			
    		i++;	
		}
	if(ogrencipuani<0)ogrencipuani=0;	

	OgrenciPuanlari[ogrencisirasi]=ogrencipuani;

	ogrencisirasi++;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

	
  return 0;
}
int cikti(){
	 ofstream myfile ("output.txt");
  if (myfile.is_open())
  {
  	int i=0;
  	while(i<ogrencisirasi){
    myfile << OgrenciNumarasi[i]<<","<<OgrenciPuanlari[i]<<" ";//ogrenci no ve puani burada dosyaya yaziliyor
   
    i++;
	  }
	  
   //////////////////////////////////////Hesaplama işlemleri Yapılıyor... 
   int toplampuan=0;
	for(int i=0;i<ogrencisirasi;i++){
		toplampuan+=OgrenciPuanlari[i];
	}
	int Ortalama=0;
		Ortalama=toplampuan/ogrencisirasi;
	int enbuyuk=0;
	int enkucuk=100;
	int aciklik=0;
	int medyan;
	for(int i = 0; i <ogrencisirasi ; i++)
	{
		if(enkucuk > OgrenciPuanlari[i] )
		enkucuk = OgrenciPuanlari[i];
		
		if(enbuyuk < OgrenciPuanlari[i] )
		enbuyuk = OgrenciPuanlari[i];
}

	
	if (ogrencisirasi%2==0)
	{
		int m1 = OgrenciPuanlari[ogrencisirasi  / 2 -1];
		int m2 = OgrenciPuanlari[ogrencisirasi / 2];
		 medyan=(m1+m2)/2;
	
	}
	else
	{
		 medyan = OgrenciPuanlari[ogrencisirasi  / 2  ];
		
	}
	aciklik=enbuyuk-enkucuk;
	
myfile<<enbuyuk<<","<<enkucuk<<","<<Ortalama<<","<<medyan<<","<<aciklik;
	
   
   
   /////////////////////////////// 
    myfile.close();
  }

  else cout << "......";

  return 0;
}
int sirala(){//http://www.firmcodes.com/sorting-algorithms-in-c/Siralama işlemi yapıldı
for(int i=0; i<ogrencisirasi; i++)
	{
		for(int j=0; j<ogrencisirasi-1; j++)
		{
			if( OgrenciPuanlari[j] < OgrenciPuanlari[j+1] )
			{
				int temp = OgrenciPuanlari[j];
				string temp2 = OgrenciNumarasi[j];
				
				OgrenciPuanlari[j] = OgrenciPuanlari[j+1];
				OgrenciNumarasi[j] = OgrenciNumarasi[j+1];
				
				OgrenciPuanlari[j+1] = temp;
				OgrenciNumarasi[j+1] = temp2;
			}
		}
	}
}
