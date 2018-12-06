#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <simlib.h>
#include "peceni.h"
#include "orezavani.h"
#include "sypani.h"
#include "auto_spekani.h"
#include "globals.h"
#include <math.h> 
void printStat(const Histogram *hist, const Stat *stat)
{
     std::cout << ">>>> " << hist->Name() << " <<<<" << std::endl;
     for (unsigned i = 0; i < hist->Count(); i++)
     {
       double s = 0;
        if(stat->Number()!=0)
        {
          s = (*hist)[i+1] * stat->MeanValue() / hist->Step() * 100;
        }
          if (s > 100.0)
               s = 100.0;
          printf("%d.den\t%.2f%%\n", i+1, s);
      
     }
     std::cout << "##############" << std::endl;
}

int main(int argc, char **argv)
{
     (void)argc;
     (void)argv;
     Globals::TTL = 604800.0;
     int opt;
     bool help = false;
     int tmp = 0;
     while ((opt = getopt(argc, argv, "t:h")) != -1) {
          switch (opt) {
          case 't':
                    Globals::TTL = atof(optarg);
                    tmp = ceil(Globals::TTL/(60*60*24));
                    if(tmp==0)
                      tmp = 1;
                    Baleni::Fhist.Init(0, 60*60*24,tmp);
                    AutoSpekani::Fhist.Init(0, 60*60*24,tmp);
                    Sypani::Fhist.Init(0, 60*60*24, tmp);
                    Spekani::Fhist.Init(0, 60*60*24, tmp);
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
     //std::cout<<"Links: "<<links<<"\nProcess: "<<process<<"\nGenerateTime: "<<generateTime<<std::endl;
     Print("Výroba lázeňských oplatků\n");
     SetOutput("model.out");
     Init(0, Globals::TTL);           // experiment initialization for time 0..1000
     (new Peceni())->Activate(); // customer generator
     Run();                      // simulation

     printStat(&Sypani::Fhist, &Sypani::Fstat);
     std::cout << "#### " << "Počet oplatků které čekají "<<Vlhceni::Output << " ####" <<std::endl;
     printStat(&Spekani::Fhist, &Spekani::Fstat);
     std::cout << "#### " << "Počet oplatků které čekají "<<Spekani::Input << " ####" <<std::endl;
     printStat(&AutoSpekani::Fhist, &AutoSpekani::Fstat);
     std::cout << "#### " << "Počet oplatků které čekají "<<Vlhceni::Output << " ####" <<std::endl;
     printStat(&Baleni::Fhist, &Baleni::Fstat);
     std::cout << "#### " << "Počet krabic které byly vytvořeny "<<Baleni::Output << " ####" <<std::endl;

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
     std::cout << "#### " << "Průměr" << " ####" << std::endl;
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