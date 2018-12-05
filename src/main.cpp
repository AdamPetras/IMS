#include <iostream>
#include <getopt.h>
#include <string>
#include <simlib.h>

Facility Box("Box");
Histogram Table("Table",0,25,20);

class Customer : public Process 
{ 
     double Prichod; // atribute of each customer 
     void Behavior() 
     {
          Prichod = Time;
          Seize(Box);
          Wait(10);
          Release(Box);
          Table(Time-Prichod);
     } 
};

class Generator : public Event 
{
     void Behavior() 
     { 
          (new Customer)->Activate();
          Activate(Time+Exponential(1e3/150));
     }     
};

int main(int argc,char**argv)
{
     int links = 0;
     int process = 0;
     float generateTime = 0;
     int opt;
     bool help = false;
     while ((opt = getopt(argc, argv, "l:i:t:h")) != -1) {
          switch (opt) {
          case 'l':
                    links = atoi(optarg);
               break;
          case 'i':
                    process = atoi(optarg);
               break;
          case 't':
                    generateTime = atof(optarg);
               break;
          case 'h':
                    help = true;
               break;
          default:
            std::cerr << "Argument ERROR!" << std::endl;
               exit(EXIT_FAILURE);
        }
     }
     if(help)
     {
          std::cout<<"ims [-l links] [-i process] [-t generateTime]\
                    \n\t-l : počet obslužných linek, které jsou v systému\
                    \n\t-i : počet procesů\
                    \n\t-t : čas, kdy se budou vytvářet jednotlivé procesy"<<std::endl;
               return EXIT_SUCCESS;
     }
     std::cout<<"Links: "<<links<<"\nProcess: "<<process<<"\nGenerateTime: "<<generateTime<<std::endl;
     Print(" model2 - SIMLIB/C++ example\n");
     SetOutput("model2.out"); 
     Init(0,1000); // experiment initialization for time 0..1000 
     (new Generator)->Activate(); // customer generator 
     Run(); // simulation 
     Box.Output(); // print of results 
     Table.Output();
     
     return EXIT_SUCCESS;
}