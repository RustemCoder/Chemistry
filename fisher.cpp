#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std ;
int main()
{
	ifstream fin("1.txt") ;
	setlocale(LC_ALL,"Russian");
double sum =0;
double coeff_Student[20]={6.314,2.920,2.353,2.132,2.015,1.943,1.895,1.860,1.833,1.812,1.796,1.782,1.771,1.761,1.753,1.746,1.740,1.734,1.729,1.725};
int  degree_of_freedom ;
cout<<" Ââåäèòå êîëè÷åñòâî ñòåïåíåé ñâîáîäû:";
cin>>degree_of_freedom;
double 	coefficent_of_student ;
coefficent_of_student = coeff_Student[degree_of_freedom-1] ;
double Sb ;
int Level;
cout<<"Â çàâèñèìîñòè îò ôàêòîðà âàøà ìàòðèöà áóäåò ìåíÿòüñÿ!"<<endl;
cout<<"\n";
int factor ;
cout<<"Ââåäèòå  ÷èñëî ôàêòîðîâ:";
cin>>factor ;
cout<<"\n";
cout<<"Ââåäèòå êîëè÷åñòâî óðîâíåé: ";
cin>>Level;
cout<<"\n";
double si ;
int n ;
cout<<"Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ â öåíòðå ïëàíà: ";
cin>>n;
double average_y; 
// ôàêòîð
int row ,column,k=2;
if(factor==2 && Level==2)
{
row = pow(2,factor);
column =5;
}
else if(factor==3 && Level==2)
{
 row = pow(2,factor);
column = 8 ;
}

else if(factor==3 && Level==3)
{
row = 32;
column =pow(factor,2)+1;	
	
}


cout<<row<<"  "<<column;  
double **Array = new double *[row];

for(int i=0;i<row;i++)
{

Array[i]= new double [column];

}

for(int i=0;i<row;i++)
{
for(int j=0;j<column;j++)
{
cin>>Array[i][j];
}
}
//fin.close();
// Ñîçäàíèå âåêòîðà äëÿ êîýôôèöåíòîâ
if(Level ==2 && factor==3)
{
	vector <double> Coefficients(6,0);
vector <double> Coefficients_Regression(10,0);
for(int i=0;i<1;i++)
{
for(int k=0;k<row;k++)
{
for(int j=0;j<column;j++)
{
if(k==1)
{
Coefficients[i]= Coefficients[i] + Array[j][k]*Array[j][k+6];
}
if(k==2)
{
Coefficients[i+1]= Coefficients[i+1] + Array[j][k]*Array[j][k+5];
}

if(k==3)
{
Coefficients[i+2]= Coefficients[i+2] + Array[j][k]*Array[j][k+4];
}
if( k==4)
{
Coefficients[i+3]= Coefficients[i+3] + Array[j][k]*Array[j][k+3];
}
if(k==5)
{
Coefficients[i+4]= Coefficients[i+4] + Array[j][k]*Array[j][k+2];
}
if(k==6)
{
Coefficients[i+5]= Coefficients[i+5] + Array[j][k+1]*Array[j][k];
}

}
sum = sum+ Array[k][7];
}

}

for(int i=0;i<6;i++)
{
Coefficients[i]=Coefficients[i]/4;
}

for(int i=0; i<10;i++)
{
if(i>0 && i<7)
{
Coefficients_Regression[i]=Coefficients[i-1]/2;
}
else
{
Coefficients_Regression[i]=sum/8;
}


}


cout<<"D[p]="<<Coefficients[0]<<"\t"<<"D[C]="<<Coefficients[1]<<"\t"<<"D[T]="<<Coefficients[2]<<"\t"<<
"D[P*C]="<<Coefficients[3]<<"\t"<<"D[P*T]="<<Coefficients[4]<<"\t"<<"D[C*T]="<<Coefficients[5]<<endl;



cout<<"\n";
for(int i=0;i<10;i++)
{
cout<<"b["<<i<<"]="<<Coefficients_Regression[i]<<"\t";
}
cout<<"\n";
}




else if (factor==3 && Level ==3)
{
	
	
vector <double> Coefficients_Regression(10,0);
vector <double>  Coefficients_T(10,0);


for(int i=0;i<1;i++)
{
	for(int j=0;j<row-5;j++)
	{
		
		for(int k=0;k<column;k++)
		{
			
			Coefficients_Regression[i]=Coefficients_Regression[i]+Array[j][9];
			if(k==0)
		
			{
				Coefficients_Regression[i+1]=Coefficients_Regression[i+1]+Array[j][k]*Array[j][9];
				
			}
			if(k==1)
			{
				Coefficients_Regression[i+2]=Coefficients_Regression[i+2]+Array[j][k]*Array[j][9];
			}
			if(k==2)
			{
			Coefficients_Regression[i+3]=Coefficients_Regression[i+3]+Array[j][k]*Array[j][9];	
			}
			
			if(k==3)
			{
				Coefficients_Regression[i+4]=Coefficients_Regression[i+4]+Array[j][k]*Array[j][9];
			}
			if(k==4)
			{
				Coefficients_Regression[i+5]=Coefficients_Regression[i+5]+Array[j][k]*Array[j][9];
			}
			if(k==5)
			{
				Coefficients_Regression[i+6]=Coefficients_Regression[i+6]+Array[j][k]*Array[j][9];
			}
			if(k==6)
			{
				Coefficients_Regression[i+7]=Coefficients_Regression[i+7]+Array[j][k]*Array[j][9];
			}
			if(k==7)
			{
				Coefficients_Regression[i+8]=Coefficients_Regression[i+8]+Array[j][k]*Array[j][9];
			}
			if(k==8)
			{
				
				Coefficients_Regression[i+9]=Coefficients_Regression[i]+Array[j][k]*Array[j][9];
			}
			
		}
	}
	
	
}	



	for(int j=27;j<33;j++)
{
average_y = average_y+Array[j][9];

}
double svoz ;
average_y= average_y/6;

for(int i=0;i<6;i++)
{
	for(int j=27;j<33;j++)
	{
		si =  si +pow((Array[j][9]-average_y),2 );
	}
}

svoz= sqrt(si/(n-1));
Sb =svoz/sqrt(n);

	for(int i=0;i<Coefficients_Regression.size();i++)
	{
		
			Coefficients_Regression[i]=Coefficients_Regression[i]/27;
			Coefficients_T[i]=Coefficients_Regression[i]/Sb;
	
	}
	
	
	for(int i=0;i<Coefficients_Regression.size();i++)
	{
          	
		if(Coefficients_T[i]>coefficent_of_student)
		{
			
		Coefficients_Regression[i]=Coefficients_Regression[i];
	
	   }
	   else if(Coefficients_T[i]<coefficent_of_student)
	   { Coefficients_Regression[i]=0.0;
	   }
	  			
	}

vector <float> y_calculation(32,0)	;
	
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<8;j++)
		y_calculation[i]=Coefficients_Regression[0]+Coefficients_Regression[j+1]*Array[i][j];
		
	}
	double Yi_Average = 0.0 ;
	for(int i =0;i<=26;i++)
	{
	  Yi_Average=Yi_Average+y_calculation[i]	;
	}
	
	Yi_Average = Yi_Average/27;
	
	double sum_ofy_cal=0 ;
	double sum_of_y_av=0 ;
	

	for(int i=0;i<32;i++)
	{
		
		sum_ofy_cal=sum_ofy_cal+pow(y_calculation[i]-Array[i][9],2);
		sum_of_y_av=sum_of_y_av+pow(y_calculation[i]-Yi_Average,2);
	}
	
	double fisher_calculation;
	
	fisher_calculation = sum_of_y_av*(n-factor-1)/(sum_ofy_cal*factor);
	
	
	double  fisher_table = 3.1081;
	
	
	if(fisher_calculation<fisher_table)
	{
		
		cout<<"Âàøà ìîäåëü çíà÷èìà â öåëîì"<<"\n";
	}
}	
	return 0 ;

}
