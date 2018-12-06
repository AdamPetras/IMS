#include <iostream>
#include <getopt.h>
#include <string>
#include <simlib.h>
#include "peceni.h"
#include "orezavani.h"
#include "sypani.h"
#include "auto_spekani.h"

int main(int argc,char**argv)
{
    (void)argc;
    (void)argv;
     /*int links = 0;
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
     }*/
    //std::cout<<"Links: "<<links<<"\nProcess: "<<process<<"\nGenerateTime: "<<generateTime<<std::endl;
     Print("Výroba lázeňských oplatků\n");
     SetOutput("model.out");
     const int ENDTIME = 2*604800;
     Init(0,ENDTIME); // experiment initialization for time 0..1000 
     (new Peceni())->Activate(); // customer generator 
     Run(); // simulation 

     Sypani::Fstat.Output();
     AutoSpekani::Fstat.Output();
     Orezavani::Fstat.Output();
     Mazani::Fstat1.Output();
     Mazani::Fstat2.Output();
     Vlhceni::FstatMala.Output();
     Vlhceni::FstatVelka.Output();
     Baleni::Fstat.Output();
     Vazeni::Fstat.Output();
     Spekani::Fstat.Output();
     std::cout << "Sypani:\t\t" << Sypani::Sumtime/Time*100<<"\%"<< std::endl;
     std::cout << "Spekani:\t" << Spekani::Sumtime/Time*100<<"\%"<< std::endl;
     std::cout << "AutoSpekani:\t" << AutoSpekani::Sumtime/Time*100<<"\%"<< std::endl;
     std::cout<<"Orezavani:\t"<<Orezavani::Sumtime/Time*100<<"\%"<<std::endl;
     std::cout<<"Mazání:\t\t"<<Mazani::Sumtime/Time*100<<"\%"<<std::endl;
     std::cout<<"Malá vlhčírna:\t"<<Vlhceni::SumtimeMala/Time*100<<"\%"<<std::endl;
     std::cout<<"Velká vlhčírna:\t"<<Vlhceni::SumtimeVelka/Time*100<<"\%"<<std::endl;
     std::cout<<"Baleni:\t\t"<<Baleni::Sumtime/Time*100<<"\%"<<std::endl;
     std::cout<<"Vazeni:\t\t"<<Vazeni::Sumtime/Time*100<<"\%"<<std::endl;
     std::cout<<"ostatok syp:\t\t"<<Vlhceni::Output<<std::endl;
     return EXIT_SUCCESS;
}