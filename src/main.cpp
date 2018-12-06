#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <simlib.h>
#include "peceni.h"
#include "orezavani.h"
#include "sypani.h"
#include "auto_spekani.h"

void printStat(const Histogram *hist, const Stat *stat)
{
     std::cout << ">>>> " << hist->Name() << " <<<<" << std::endl;
     for (unsigned i = 0; i < hist->Count(); i++)
     {
          double s = (*hist)[i] * stat->MeanValue() / hist->Step() * 100;
          if (s > 100.0)
               s = 100.0;
          printf("%d.den\t%.2f%%\n", i + 1, s);
     }
     std::cout << "##############" << std::endl;
}

int main(int argc, char **argv)
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
     const int ENDTIME = 2 * 604800;
     Init(0, ENDTIME);           // experiment initialization for time 0..1000
     (new Peceni())->Activate(); // customer generator
     Run();                      // simulation

     printStat(&Sypani::Fhist, &Sypani::Fstat);
     printStat(&Spekani::Fhist, &Spekani::Fstat);
     printStat(&AutoSpekani::Fhist, &AutoSpekani::Fstat);
     printStat(&Baleni::Fhist, &Baleni::Fstat);

     Sypani::Fstat.Output();
     Sypani::Fhist.Output();
     Spekani::Fstat.Output();
     Spekani::Fhist.Output();
     AutoSpekani::Fhist.Output();
     Orezavani::Fstat.Output();
     Mazani::Fstat1.Output();
     Mazani::Fstat2.Output();
     Mazani::Fhist.Output();
     Vlhceni::FstatMala.Output();
     Vlhceni::FstatVelka.Output();
     Vazeni::Fstat.Output();
     Baleni::Fstat.Output();
     Baleni::Fhist.Output();
     std::cout << "#### " << "Prumner" << " ####" << std::endl;
     std::cout << "Sypani:\t\t" << Sypani::Sumtime / Time * 100 << "\%" << std::endl;
     std::cout << "Spekani:\t" << Spekani::Sumtime / Time * 100 << "\%" << std::endl;
     std::cout << "AutoSpekani:\t" << AutoSpekani::Sumtime / Time * 100 << "\%" << std::endl;
     std::cout << "Orezavani:\t" << Orezavani::Sumtime / Time * 100 << "\%" << std::endl;
     std::cout << "Mazání:\t\t" << Mazani::Sumtime / Time * 100 << "\%" << std::endl;
     std::cout << "Malá vlhčírna:\t" << Vlhceni::SumtimeMala / Time * 100 << "\%" << std::endl;
     std::cout << "Velká vlhčírna:\t" << Vlhceni::SumtimeVelka / Time * 100 << "\%" << std::endl;
     std::cout << "Baleni:\t\t" << Baleni::Sumtime / Time * 100 << "\%" << std::endl;
     std::cout << "Vazeni:\t\t" << Vazeni::Sumtime / Time * 100 << "\%" << std::endl;
     return EXIT_SUCCESS;
}