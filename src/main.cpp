#include <iostream>
#include <getopt.h>
#include <string>
#include <simlib.h>
#include "peceni.h"

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
     Init(0,604800); // experiment initialization for time 0..1000 
     (new Peceni())->Activate(); // customer generator 
     Run(); // simulation 
     return EXIT_SUCCESS;
}