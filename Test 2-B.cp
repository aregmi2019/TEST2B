#include <iostream> 

using namespace std; 

int main()
{ 

   double Grade1; 
   double Grade2; 
   double Grade3; 
   double AvgGrade; 
   double Total = 0; 
   double AverageTotal = 0; 
   int Students = 0; 
   int n = 0; 
int StudentNumber; 

   cout << "Enter the number of students in class : "; 
   cin >> Students; 

  

   while (n < Students) {

       StudentNumber = n + 1; 

       cout << "Please enter three numeric grades for student number " << StudentNumber << ". "; 
       cin >> Grade1; 
       cin >> Grade2; 
       cin >> Grade3; 
      
       Total = (Grade1 + Grade2 + Grade3); 
       AverageTotal = AverageTotal + Total; 
       AvgGrade = (Total / 3); 

       cout << "Student number " << StudentNumber << " grades: " << Grade1 << " " << Grade2 << " " << Grade3 << " average: " << AvgGrade << " "; 
      
       n = n + 1; 

      
       if ( AvgGrade >= 90)
           cout << " letter grade: A!\n";
       else
           if ( AvgGrade >= 80) 
               cout << " letter grade: B.\n";
           else
               if ( AvgGrade >= 70) 
                   cout << " letter: grade: C.\n";
               else
                   if ( AvgGrade >= 60) 
                       cout << " letter grade: D.\n";
                   else 
                       cout << " letter grade: F.\n";
       cout << "\n"; 
   }
      
   cout << "The class average: " << AverageTotal / (StudentNumber * 3) << "\n" ; 
  
 
   return 0;
  
}
