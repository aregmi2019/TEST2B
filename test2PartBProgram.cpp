////////////////////////////////////////////////////////////////////
//                                                                //
//test2PartBProgram                                               //
//Grade Book Program                                              //
//Sagar Khatiwada, Binaya Sigdel, Sujan Dhakal, Abhishek Regmi              //
//November 06 2019                                                //
//                                                                //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////CONSTANTS//////////////////////////////////////////////////////
const int STUDENTS=20;
const int CLASSES=5;

///////////////////////////////////////////FUNCTIONS PROTOTYPES//////////////////////////////////////////////////
void readData(ifstream& inputFile,string firstName[],string lastName[],float scores[STUDENTS][CLASSES]);//Function used to read data from file
//the function below is used to create the report
void writeData(ofstream& outputFile, string firstName[],string lastName[],float scores[STUDENTS][CLASSES], float avg[], char grade[], float avgForEach[],float& avgForAll);
void finalGrade(float scores[STUDENTS][CLASSES], float avg[],char grade[]);//function used to calculate the average and final grade for each student
void classAndTestAvg(float scores[STUDENTS][CLASSES],float avgForEach[], float &avgForAll);//function used to calcualte the class average and test average.
float highTestGrade(float scores[STUDENTS][CLASSES]);//returns the highest test grade of the class
float highClassGrade(float avg[STUDENTS]);//returns the highest final grade for the class
void pause(string message);

////////////////////////////////////////////////MAIN FUNCTION/////////////////////////////////////////////////////
int main()
{
    string firstName[STUDENTS];
	string lastName[STUDENTS];
	float scores[STUDENTS][CLASSES];
	float avg[STUDENTS];
	float avgEachClass[CLASSES];
	float avgForAll;
	char grade[STUDENTS];
    ifstream infile;
	ofstream outfile;
    infile.open("CSCI1306.txt");
    outfile.open("GradeReport.txt");
    pause("Opening File");
    if (!infile)
    {
        cout << "There was a problem opening the file. Press any key to close.\n";
        return 0;
    }
    pause("Reading File");
    readData(infile, firstName, lastName, scores);
    pause("Processing Data");
	finalGrade(scores, avg, grade);
	classAndTestAvg(scores, avgEachClass, avgForAll);
	pause("Creating Report");
	writeData(outfile, firstName, lastName, scores, avg, grade,avgEachClass, avgForAll);
	infile.close();
	outfile.close();
	pause("Process Completed.");
	pause("Exit");
    return 0;
}

////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////

//******************************************READ DATA FROM THE FILE****************************************//
void readData(ifstream& inputFile,string firstName[],string lastName[] ,float scores[STUDENTS][CLASSES]){
	int counter=0;
	do
    {
      inputFile>>firstName[counter]>>lastName[counter];
      for(int i=0; i<CLASSES;i++){
      	inputFile>>scores[counter][i];
	  }
      counter++;
	}  while(inputFile && counter<STUDENTS );
return;
}

//******************************************WRITE DATA TO THE FILE****************************************//
void writeData(ofstream& outputFile, string firstName[],string lastName[],float scores[STUDENTS][CLASSES], float avg[], char grade[], float avgForEach[],float& avgForAll){	
	for (int i=0; i<STUDENTS; i++){
		outputFile<<left<<setw(15)<<firstName[i]<<setw(15)<<lastName[i];
		for (int j=0; j<CLASSES; j++){
			outputFile<<right<<setw(8)<<setprecision(2)<<fixed<<scores[i][j];
		}
		outputFile<<setw(8)<<avg[i]<<setw(8)<<grade[i]<<endl;
	}
	outputFile<<endl<<left<<setw(30)<<"Average for each class: ";
	for(int i=0; i<CLASSES;i++){
		outputFile<<right<<setw(8)<<avgForEach[i];
	}
	outputFile<<endl<<left<<setw(30)<<"Overall average: "<<right<<setw(8)<<avgForAll<<endl;
	outputFile<<left<<setw(30)<<"The Highest Test Grade is: "<<right<<setw(8)<<highTestGrade(scores)<<endl;
	outputFile<<left<<setw(30)<<"The Highest Class Grade is: "<<right<<setw(8)<<highClassGrade(avg);
return;
}

//***************************CALCULATES THE FINAL AVERAGE AND GRADE FOR EACH STUDENT*****************************//	
void finalGrade(float scores[STUDENTS][CLASSES], float avg[], char grade[]){
	float sum=0;
	for (int i=0; i<STUDENTS; i++){
		sum=0;
		for (int j=0; j<CLASSES; j++){
			sum=sum+scores[i][j];
			if (j==(CLASSES-1)){
				sum=sum+scores[i][j];
				avg[i]=sum/6.00;
				if (avg[i]<100){grade[i]='A';}
				if (avg[i]>=60 && avg[i]<70){grade[i]='D';}
				if (avg[i]>=70 && avg[i]<80){grade[i]='C';}
				if (avg[i]>=80 && avg[i]<90){grade[i]='B';}
				if (avg[i]>=90 && avg[i]<100){grade[i]='A';}
			}
		}
	}
	return ;	
}

//**************************************CALCULATES THE OVERALL AND TEST AVERAGE****************************************//
void classAndTestAvg(float scores[STUDENTS][CLASSES],float avgForEach[], float &avgForAll){
	float sum=0;
	float sumForAll=0;
	int counter=0;
	for (int i=0; i<CLASSES; i++){
		sum=0;
		for (int j=0; j<STUDENTS; j++){
			counter++;
			sum=sum+scores[j][i];
			sumForAll=sumForAll+scores[j][i];
			if (j==(STUDENTS-1)){
				avgForEach[i]=sum/STUDENTS;
			}
		}
	}
	avgForAll=sumForAll/counter;
}

//**************************************RETURNS THE HIGHEST TEST GRADE FOR ALL STUDENTS****************************************//
float highTestGrade(float scores[STUDENTS][CLASSES]){
	float largestGrade=0;
	for (int i=0; i<STUDENTS;i++){
		for (int j=0; j<CLASSES;j++){
			if(largestGrade<scores[i][j]){
				largestGrade=scores[i][j];
			}
		}
	}
	return largestGrade;
}

//*********************************************RETURNS THE HIGHEST CLASS GRADE**************************************************//
float highClassGrade(float avg[STUDENTS]){
	float largestGrade=0;
	for (int i=0; i<STUDENTS;i++){
			if(largestGrade<avg[i]){
				largestGrade=avg[i];
			}
		}
	return largestGrade;
}

//*****************************************PAUSES THE PROGRAM AND PRINTS A MESSAGE ****************************************//
void pause(string message){
		do{
			cout<<"\nPress enter to continue...";
		}while (cin.get()!='\n');//validates that the user press enter to continue.
		cout<<message<<string(3, '.');
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

